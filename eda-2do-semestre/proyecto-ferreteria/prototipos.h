#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

tipoRet crearProducto(producto &listaProducto);
tipoRet comprar(producto &listaProducto, cadena parametro[]);
tipoRet vender(producto &listaProducto, cadena parametro[]);
tipoRet listar(producto listaProducto);


void muestroRetorno(tipoRet retorno);
void help();
void muestroParametros(cadena parametro[]);

producto creoProducto();
bool esVacioProducto(producto listaProducto);
producto comprarProducto(producto listaProducto, cadena parametro[]);




#endif
