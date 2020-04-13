/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenamientoSeleccion.cpp
 * Author: luisGonzalez
 * 
 * Created on 11 de abril de 2020, 10:27 PM
 */

#include "OrdenamientoSeleccion.h"
#include "NodoHash.h"
#include <iostream>
#include <sstream>
#include <string>

OrdenamientoSeleccion::OrdenamientoSeleccion() {
}

string* OrdenamientoSeleccion::busquedaNodoTablas(string parametro, int tupla, TablaHash *&tabla, string *vector) {
    NodoHash *nodoAux = tabla->Get_primero();
    if (tabla->Get_primero() != NULL) {
        while (nodoAux != NULL) {
            busquedaArboles(parametro, tupla, tabla, nodoAux, vector);
            nodoAux = nodoAux->Get_Siguiente();
        }
    }
    return vector;
}

string* OrdenamientoSeleccion::busquedaArboles(string parametro, int tupla, TablaHash *&tabla, NodoHash *nodoAux, string *vector) {
    AVL *arbolUsado = nodoAux->Get_AVL();
    Nodo *aux = NULL;
    recorridoInOrden(parametro, tupla, aux, true, arbolUsado, vector);
    return vector;
}

string* OrdenamientoSeleccion::recorridoInOrden(string parametro, int tupla, Nodo *nodo, bool r, AVL *arbol, string *vector) {
    if (arbol->Get_Raiz() != NULL) {
        if (r) nodo = arbol->Get_Raiz();
        if (nodo->Get_izquierda()) recorridoInOrden(parametro, tupla, nodo->Get_izquierda(), false, arbol, vector);
        busquedaDatos(parametro, tupla, nodo, vector);
        if (nodo->Get_derecha()) recorridoInOrden(parametro, tupla, nodo->Get_derecha(), false, arbol, vector);
    }
    return vector;
}

string* OrdenamientoSeleccion::busquedaDatos(string parametro, int tupla, Nodo *nodo, string *vector) {
    if (parametro == "all") {
        if (tupla == nodo->Get_tupla()) {
            int noColumna = nodo->Get_NoColumna();
            string tipo = nodo->Get_tipo();
            if (tipo == "Integer") {
                stringstream ss;
                ss << nodo->Get_entero();
                string convertido;
                ss >> convertido;
                vector[noColumna] = convertido;
            } else if (tipo == "String") {
                string convertido = nodo->Get_cadena();
                vector[noColumna] = convertido;
            } else if (tipo == "Double") {
                stringstream ss;
                ss << nodo->Get_decimal();
                string convertido;
                ss >> convertido;
                vector[noColumna] = convertido;
            } else if (tipo == "Char") {
                string convertido(1, nodo->Get_caracter());
                vector[noColumna] = convertido;
            }
        }
    } else {
        if (tupla == nodo->Get_tupla() && nodo->Get_Columna() == parametro) {
            int noColumna = nodo->Get_NoColumna();   // nodo = nodo->Get_padre();

            string tipo = nodo->Get_tipo();
            if (tipo == "Integer") {
                stringstream ss;
                ss << nodo->Get_entero();
                string convertido;
                ss >> convertido;
                vector[noColumna] = convertido;
            } else if (tipo == "String") {
                string convertido = nodo->Get_cadena();
                vector[noColumna] = convertido;
            } else if (tipo == "Double") {
                stringstream ss;
                ss << nodo->Get_decimal();
                string convertido;
                vector[noColumna] = convertido;
                ss >> convertido;
            } else if (tipo == "Char") {
                string convertido(1, nodo->Get_caracter());
                vector[noColumna] = convertido;
            }
        }
    }
    return vector;
}

OrdenamientoSeleccion::OrdenamientoSeleccion(const OrdenamientoSeleccion& orig) {
}

OrdenamientoSeleccion::~OrdenamientoSeleccion() {
}

