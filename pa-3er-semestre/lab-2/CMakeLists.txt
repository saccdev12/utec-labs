cmake_minimum_required(VERSION 4.2)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(negocio)
include_directories(negocio/datatypes)
include_directories(presentacion)

add_executable(lab_2
        negocio/datatypes/Date.h
        negocio/datatypes/DTCliente.cpp
        negocio/datatypes/DTCliente.h
        negocio/datatypes/DTInmobiliaria.cpp
        negocio/datatypes/DTInmobiliaria.h
        negocio/datatypes/DTInmueble.cpp
        negocio/datatypes/DTInmueble.h
        negocio/datatypes/DTInteres.h
        negocio/datatypes/DTListaPublicacion.cpp
        negocio/datatypes/DTListaPublicacion.h
        negocio/datatypes/DTPublicacion.cpp
        negocio/datatypes/DTPublicacion.h
        negocio/datatypes/DTRango.h
        negocio/ISistema.h
        negocio/Sistema.cpp
        negocio/Sistema.h
        presentacion/PantallaAltaPublicacion.cpp
        presentacion/PantallaAltaPublicacion.h
        presentacion/PantallaConsultarPublicaciones.cpp
        presentacion/PantallaConsultarPublicaciones.h
        main.cpp
        presentacion/PantallaAltaInmueble.cpp
        presentacion/PantallaAltaInmueble.h
        presentacion/PantallaRepresentarPropietario.cpp
        presentacion/PantallaRepresentarPropietario.h
        negocio/datatypes/DTInmuebleDetalles.h
        negocio/datatypes/DTCasa.h
        negocio/datatypes/DTTecho.h
        negocio/datatypes/DTApartamento.h
        negocio/datatypes/DTPropietario.h
        negocio/Propietario.h
        negocio/Inmueble.h
        negocio/Casa.h
        negocio/Apartamento.h
        negocio/datatypes/DTInmobiliariaDetalles.h)
