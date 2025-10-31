#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>

// Constantes para la configuración del programa
const int BUFFER_SIZE = 5;        // Tamaño máximo del buffer
const int NUM_PRODUCTORES = 2;    // Número de productores
const int NUM_CONSUMIDORES = 2;   // Número de consumidores
const int TOTAL_ELEMENTOS = 20;   // Total de elementos a producir

// Variables globales para la sincronización
std::mutex mtx;                   // Mutex para acceso exclusivo al buffer
std::condition_variable buffer_no_lleno;  // CV: buffer no está lleno
std::condition_variable buffer_no_vacio;  // CV: buffer no está vacío

// Buffer compartido
std::queue<int> buffer;

// Contadores
int elementos_producidos = 0;
int elementos_consumidos = 0;

/**
 * Función del productor
 * @param id Identificador del productor
 */
void productor(int id) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 500); // Tiempo aleatorio entre 100-500ms
    
    while (true) {
        // Simular tiempo de producción
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
        
        // Bloquear el mutex antes de acceder al buffer
        std::unique_lock<std::mutex> lock(mtx);
        
        // Esperar si el buffer está lleno
        buffer_no_lleno.wait(lock, []() {
            return buffer.size() < BUFFER_SIZE;
        });
        
        // Verificar si ya se produjeron todos los elementos
        if (elementos_producidos >= TOTAL_ELEMENTOS) {
            lock.unlock();
            buffer_no_vacio.notify_all(); // Notificar a los consumidores
            break;
        }
        
        // Producir un elemento
        int elemento = ++elementos_producidos;
        buffer.push(elemento);
        
        std::cout << "Productor " << id << " produjo: " << elemento 
                  << " (Buffer size: " << buffer.size() << ")" << std::endl;
        
        // Liberar el lock y notificar a los consumidores
        lock.unlock();
        buffer_no_vacio.notify_all();
    }
    
    std::cout << "Productor " << id << " terminó." << std::endl;
}

/**
 * Función del consumidor
 * @param id Identificador del consumidor
 */
void consumidor(int id) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 500); // Tiempo aleatorio entre 100-500ms
    
    while (true) {
        // Simular tiempo de consumo
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
        
        // Bloquear el mutex antes de acceder al buffer
        std::unique_lock<std::mutex> lock(mtx);
        
        // Esperar si el buffer está vacío y aún hay elementos por consumir
        buffer_no_vacio.wait(lock, []() {
            return !buffer.empty() || elementos_consumidos >= TOTAL_ELEMENTOS;
        });
        
        // Verificar si ya se consumieron todos los elementos
        if (elementos_consumidos >= TOTAL_ELEMENTOS && buffer.empty()) {
            lock.unlock();
            break;
        }
        
        // Consumir un elemento
        int elemento = buffer.front();
        buffer.pop();
        elementos_consumidos++;
        
        std::cout << "Consumidor " << id << " consumió: " << elemento 
                  << " (Buffer size: " << buffer.size() << ")" << std::endl;
        
        // Liberar el lock y notificar a los productores
        lock.unlock();
        buffer_no_lleno.notify_all();
    }
    
    std::cout << "Consumidor " << id << " terminó." << std::endl;
}

/**
 * Función principal
 */
int main() {
    std::cout << "=== INICIANDO SIMULACIÓN PRODUCTOR-CONSUMIDOR ===" << std::endl;
    std::cout << "Configuración:" << std::endl;
    std::cout << "- Tamaño del buffer: " << BUFFER_SIZE << std::endl;
    std::cout << "- Número de productores: " << NUM_PRODUCTORES << std::endl;
    std::cout << "- Número de consumidores: " << NUM_CONSUMIDORES << std::endl;
    std::cout << "- Total de elementos a producir: " << TOTAL_ELEMENTOS << std::endl;
    std::cout << "=================================================" << std::endl;
    
    // Vectores para almacenar los hilos
    std::vector<std::thread> productores;
    std::vector<std::thread> consumidores;
    
    // Crear hilos de productores
    for (int i = 0; i < NUM_PRODUCTORES; ++i) {
        productores.emplace_back(productor, i + 1);
    }
    
    // Crear hilos de consumidores
    for (int i = 0; i < NUM_CONSUMIDORES; ++i) {
        consumidores.emplace_back(consumidor, i + 1);
    }
    
    // Esperar a que todos los productores terminen
    for (auto& p : productores) {
        p.join();
    }
    
    // Notificar a todos los consumidores que ya no habrá más producción
    buffer_no_vacio.notify_all();
    
    // Esperar a que todos los consumidores terminen
    for (auto& c : consumidores) {
        c.join();
    }
    
    std::cout << "=================================================" << std::endl;
    std::cout << "SIMULACIÓN COMPLETADA" << std::endl;
    std::cout << "Elementos producidos: " << elementos_producidos << std::endl;
    std::cout << "Elementos consumidos: " << elementos_consumidos << std::endl;
    std::cout << "Elementos restantes en buffer: " << buffer.size() << std::endl;
    
    return 0;
}