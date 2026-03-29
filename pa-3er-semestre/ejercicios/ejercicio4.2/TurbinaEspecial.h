#ifndef UNTITLED_TURBINAESPECIAL_H
#define UNTITLED_TURBINAESPECIAL_H
#include "Turbina.h"


class TurbinaEspecial: public Turbina {
    private:
     double coef;
    public:
    TurbinaEspecial(double coef,double potencia,bool activa);
  

};


#endif //UNTITLED_TURBINAESPECIAL_H