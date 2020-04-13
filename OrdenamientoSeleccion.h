/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenamientoSeleccion.h
 * Author: luisGonzalez
 *
 * Created on 11 de abril de 2020, 10:27 PM
 */

#ifndef ORDENAMIENTOSELECCION_H
#define ORDENAMIENTOSELECCION_H
#include "TablaHash.h"
#include "NodoHash.h"
#include "Nodo.h"
#include "AVL.h"
#include <string>

using namespace std;

class OrdenamientoSeleccion {
public:
    OrdenamientoSeleccion();
    
    string* busquedaNodoTablas(string, int, TablaHash*&, string*);
    string* busquedaArboles(string, int, TablaHash*&, NodoHash*, string*);
    string* recorridoInOrden(string, int, Nodo*, bool, AVL*, string*);
    string* busquedaDatos(string, int, Nodo*, string*);
    
    OrdenamientoSeleccion(const OrdenamientoSeleccion& orig);
    virtual ~OrdenamientoSeleccion();
private:

};

#endif /* ORDENAMIENTOSELECCION_H */

    