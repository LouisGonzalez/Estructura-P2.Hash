/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperacionesSeleccion.h
 * Author: luisGonzalez
 *
 * Created on 8 de abril de 2020, 11:17 PM
 */

#ifndef OPERACIONESSELECCION_H
#define OPERACIONESSELECCION_H
#include <string>
#include "TablaHash.h"

using namespace std;

class OperacionesSeleccion {
public:
    OperacionesSeleccion();
    
    string verificarTipoColumna(string*, string*, string, int);
    void seleccionarNodos(string, string*, TablaHash*&);
    OperacionesSeleccion(const OperacionesSeleccion& orig);
    virtual ~OperacionesSeleccion();
private:

};

#endif /* OPERACIONESSELECCION_H */

