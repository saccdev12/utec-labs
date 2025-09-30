#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

tipoRet crearProducto(producto &listaProducto);
tipoRet comprar(producto &listaProducto, char *parametro[]);
tipoRet vender(producto &listaProducto, char *parametro[]);
tipoRet listar(producto listaProducto);


void muestroRetorno(tipoRet retorno);
void help();





#endif