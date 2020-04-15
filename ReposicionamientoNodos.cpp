/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReposicionamientoNodos.cpp
 * Author: luisGonzalez
 * 
 * Created on 10 de abril de 2020, 12:40 PM
 */

#include "ReposicionamientoNodos.h"
#include "NodoHash.h"
#include "AVL.h"
#include "FuncionesHash.h"
#include "OrdenamientoSeleccion.h"
#include <iostream>

ReposicionamientoNodos::ReposicionamientoNodos() {
}

Nodo* ReposicionamientoNodos::BuscarPorFuncion(int totalNodos, int nuevoNodo, TablaHash *&tabla, NodoHash *nodoUsado) {
    FuncionesHash *funcion = new FuncionesHash();
    AVL *arbolUsado = nodoUsado->Get_AVL();
    int nodoActual = nodoUsado->Get_id();
    arbolUsado->Set_Actual(arbolUsado->Get_Raiz());
    int valorFuncion;
    while (!arbolUsado->Vacio(arbolUsado->Get_Actual())) {

        string tipo = arbolUsado->Get_Actual()->Get_tipo();

        if (arbolUsado->Get_Actual()->Get_Bandera() == "ACTIVO") {
            if (tipo == "Integer") {
                int entero = arbolUsado->Get_Actual()->Get_entero();
                if (entero >= nuevoNodo + 1) {
                    valorFuncion = funcion->funcionEntero(entero, nuevoNodo + 1);
                    VerificarFuncionesHash(arbolUsado, valorFuncion, nuevoNodo, tabla, nodoActual);
                }
            } else if (tipo == "Double") {
                double decimal = arbolUsado->Get_Actual()->Get_decimal();
                int conver = decimal;
                if (conver >= nuevoNodo + 1) {
                    valorFuncion = funcion->funcionDecimal(decimal, nuevoNodo + 1);
                    VerificarFuncionesHash(arbolUsado, valorFuncion, nuevoNodo, tabla, nodoActual);
                }
            } else if (tipo == "Char") {
                char caracter = arbolUsado->Get_Actual()->Get_caracter();
                int valor = caracter;
                if (valor >= nuevoNodo + 1) {
                    valorFuncion = funcion->funcionChar(caracter, nuevoNodo + 1);
                    VerificarFuncionesHash(arbolUsado, valorFuncion, nuevoNodo, tabla, nodoActual);
                }
            } else if (tipo == "String") {
                string cadena = arbolUsado->Get_Actual()->Get_cadena();
                if (cadena.length() >= nuevoNodo + 1) {
                    valorFuncion = funcion->funcionString(cadena, nuevoNodo + 1);
                    VerificarFuncionesHash(arbolUsado, valorFuncion, nuevoNodo, tabla, nodoActual);
                }
            }
        }
        if (arbolUsado->Get_Actual()->Get_izquierda() == NULL && arbolUsado->Get_Actual()->Get_derecha() == NULL) {
            break;
        } else {
            if (arbolUsado->Get_Actual()->Get_izquierda()) arbolUsado->Set_Actual(arbolUsado->Get_Actual()->Get_izquierda());

            if (arbolUsado->Get_Actual()->Get_derecha()) arbolUsado->Set_Actual(arbolUsado->Get_Actual()->Get_derecha());
        }

    }
}

void ReposicionamientoNodos::VerificarFuncionesHash2(Nodo* nodo, int funcionHash, int nuevoNodo, TablaHash *&tabla, int nodoActual) {

    if (nuevoNodo != nodoActual) {
        nodo->Set_Bandera("DESACTIVO");
        string tipo = nodo->Get_tipo();
        int noColumna = nodo->Get_NoColumna();
        int tupla = nodo->Get_tupla();
        string columna = nodo->Get_Columna();
        string nombreTabla = nodo->Get_NombreTabla();
        int totalColumnas = nodo->Get_TotalColumnas();
        Nodo *nodoAInsertar = new Nodo();

        //VERIFICAR AQUI SEGUN EL TIPO YA SEA STRING, DOUBLE, CHAR O INTEGER YA QUE ESO GENERA UN BUCLE SEGUN PARECE
        nodoAInsertar->Set_NombreTabla(nombreTabla);
        nodoAInsertar->Set_tipo(tipo);
        nodoAInsertar->Set_Columna(columna);
        nodoAInsertar->Set_TotalColumnas(totalColumnas);
        if (tipo == "Integer") {
            int entero = nodo->Get_entero();
            nodoAInsertar->Set_entero(entero);

        } else if (tipo == "Double") {
            double decimal = nodo->Get_decimal();
            nodoAInsertar->Set_decimal(decimal);
        } else if (tipo == "Char") {
            char caracter = nodo->Get_caracter();
            nodoAInsertar->Set_caracter(caracter);
        } else if (tipo == "String") {
            string cadena = nodo->Get_cadena();
            nodoAInsertar->Set_cadena(cadena);
        }
        nodoAInsertar->Set_tupla(tupla);
        nodoAInsertar->Set_NoColumna(noColumna);
        NodoHash* nodoTabla = tabla->buscarNodo(funcionHash);
        //tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
        nodoTabla->Get_AVL()->Insertar(nodoAInsertar);

    }
}

void ReposicionamientoNodos::VerificarFuncionesHash(AVL *arbol, int funcionHash, int nuevoNodo, TablaHash *&tabla, int nodoActual) {

    if (nuevoNodo != nodoActual) {
        arbol->Get_Actual()->Set_Bandera("DESACTIVO");
        string tipo = arbol->Get_Actual()->Get_tipo();
        int noColumna = arbol->Get_Actual()->Get_NoColumna();
        int tupla = arbol->Get_Actual()->Get_tupla();
        string columna = arbol->Get_Actual()->Get_Columna();
        string nombreTabla = arbol->Get_Actual()->Get_NombreTabla();
        int totalColumnas = arbol->Get_Actual()->Get_TotalColumnas();
        Nodo *nodoAInsertar = new Nodo();

        //VERIFICAR AQUI SEGUN EL TIPO YA SEA STRING, DOUBLE, CHAR O INTEGER YA QUE ESO GENERA UN BUCLE SEGUN PARECE
        nodoAInsertar->Set_NombreTabla(nombreTabla);
        nodoAInsertar->Set_tipo(tipo);
        nodoAInsertar->Set_Columna(columna);
        nodoAInsertar->Set_TotalColumnas(totalColumnas);
        if (tipo == "Integer") {
            int entero = arbol->Get_Actual()->Get_entero();
            nodoAInsertar->Set_entero(entero);

        } else if (tipo == "Double") {
            double decimal = arbol->Get_Actual()->Get_decimal();
            nodoAInsertar->Set_decimal(decimal);
        } else if (tipo == "Char") {
            char caracter = arbol->Get_Actual()->Get_caracter();
            nodoAInsertar->Set_caracter(caracter);
        } else if (tipo == "String") {
            string cadena = arbol->Get_Actual()->Get_cadena();
            nodoAInsertar->Set_cadena(cadena);
        }
        nodoAInsertar->Set_tupla(tupla);
        nodoAInsertar->Set_NoColumna(noColumna);
        NodoHash* nodoTabla = tabla->buscarNodo(funcionHash);
        //tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
        nodoTabla->Get_AVL()->Insertar(nodoAInsertar);

    }
}

void ReposicionamientoNodos::BuscarCadena(string columnaCondicional, Nodo *nodo, Nodo *nodoParametro, string tipo, AVL *arbol, TablaHash *&tabla) {
    OrdenamientoSeleccion *ordenamiento = new OrdenamientoSeleccion();
    int noTupla;
    string vector[nodo->Get_TotalColumnas() + 1];
    string *a = vector;
    if (tipo == "String") {
        if (nodo->Get_cadena() == nodoParametro->Get_cadena() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
            ordenamiento->busquedaNodoTablas(columnaCondicional, noTupla, tabla, a);
            string datos;
            for (int i = 0; i < nodo->Get_TotalColumnas(); i++) {
                datos += "|  " + vector[i] + "  |  ";
            }
            cout << datos << endl;
        }
    } else if (tipo == "Integer") {
        if (nodo->Get_entero() == nodoParametro->Get_entero() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
            ordenamiento->busquedaNodoTablas(columnaCondicional, noTupla, tabla, a);
            string datos;
            for (int i = 0; i < nodo->Get_TotalColumnas(); i++) {
                datos += "|  " + vector[i] + "  |  ";
            }
            cout << datos << endl;
        }
    } else if (tipo == "Double") {
        if (nodo->Get_decimal() == nodoParametro->Get_decimal() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
            ordenamiento->busquedaNodoTablas(columnaCondicional, noTupla, tabla, a);
            string datos;
            for (int i = 0; i < nodo->Get_TotalColumnas(); i++) {
                datos += "|  " + vector[i] + "  |  ";
            }
            cout << datos << endl;
        }
    } else if (tipo == "Char") {
        if (nodo->Get_caracter() == nodoParametro->Get_caracter() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
            ordenamiento->busquedaNodoTablas(columnaCondicional, noTupla, tabla, a);
            string datos;
            for (int i = 0; i < nodo->Get_TotalColumnas(); i++) {
                datos += "|  " + vector[i] + "  |  ";
            }
            cout << datos << endl;
        }
    }
}

void ReposicionamientoNodos::Buscar(string columnaCondicional, Nodo *nodo, bool r, Nodo *nodoParametro, string tipo, AVL *arbol, TablaHash *&tabla) {
    if (arbol->Get_Raiz() != NULL) {
        if (r) nodo = arbol->Get_Raiz();
        if (nodo->Get_izquierda()) Buscar(columnaCondicional, nodo->Get_izquierda(), false, nodoParametro, tipo, arbol, tabla);
        BuscarCadena(columnaCondicional, nodo, nodoParametro, tipo, arbol, tabla);
        if (nodo->Get_derecha()) Buscar(columnaCondicional, nodo->Get_derecha(), false, nodoParametro, tipo, arbol, tabla);
    }
}

void ReposicionamientoNodos::InOrden(AVL *arbol) {
    if (arbol->Get_Actual()->Get_izquierda()) arbol->Set_Actual(arbol->Get_Actual()->Get_izquierda());
    if (arbol->Get_Actual()->Get_derecha()) arbol->Set_Actual(arbol->Get_Actual()->Get_derecha());
}

ReposicionamientoNodos::ReposicionamientoNodos(const ReposicionamientoNodos& orig) {
}

ReposicionamientoNodos::~ReposicionamientoNodos() {
}

