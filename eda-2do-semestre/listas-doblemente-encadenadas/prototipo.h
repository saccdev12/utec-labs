#ifndef PROTOTIPO_H
#define PROTOTIPO_H
TipoRet crearLista(cabezal &l);
TipoRet insertar_al_principio(cabezal &l,int valor);
TipoRet insertar_al_final(cabezal &l,int valor);
TipoRet mostrar_ppio_fin(listaDoble primero);
TipoRet mostrar_fin_ppio(listaDoble ultimo);
TipoRet borrar_principio(cabezal &l);
TipoRet borrar_ultimo(cabezal &l);
void mostrarRetorno(TipoRet retorno);

cabezal creolista(cabezal l);
bool esvacio(listaDoble puntero);
void imprimo_ppio_fin(listaDoble primero);
cabezal insertarPpio(cabezal l, int v);
cabezal insertarFin(cabezal l, int v);
#endif