#ifndef UNTITLED_TURBINA_H
#define UNTITLED_TURBINA_H

class Turbina {
    protected:
      double potencia;
      bool activa;
    public:
    Turbina(double potencia,bool activa);
    ~Turbina();
    bool getActiva();
    double getPotencia();
};


#endif //UNTITLED_TURBINA_H