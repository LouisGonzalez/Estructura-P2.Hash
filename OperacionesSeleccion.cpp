/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperacionesSeleccion.cpp
 * Author: luisGonzalez
 * 
 * Created on 8 de abril de 2020, 11:17 PM
 */

#include "OperacionesSeleccion.h"
#include <string>
#include <iostream>
#include "FuncionesHash.h"
#include "TablaHash.h"
#include "NodoHash.h"
#include "ReposicionamientoNodos.h"

OperacionesSeleccion::OperacionesSeleccion() {
}

string OperacionesSeleccion::verificarTipoColumna(string *tipoColumna, string *nombreColumna, string parametro, int rango) {
    string tipo = "";
    for (int i = 0; i < rango; i++) {
        if (nombreColumna[i] == parametro) {
            tipo = tipoColumna[i];
            break;
        }
    }
    return tipo;
}

void OperacionesSeleccion::seleccionarNodos(string tipo, string *arregloPalabras, TablaHash *&tabla) {
    FuncionesHash *funciones = new FuncionesHash();   
    string columnaCoincidencia = *(arregloPalabras + 5);;
    int nodoABuscar;
    Nodo *a = NULL;
    ReposicionamientoNodos *reposicionamiento = new ReposicionamientoNodos();
    if (tipo == "Integer") {
        int entero = stoi(*(arregloPalabras + 7));
        nodoABuscar = funciones->funcionEntero(entero, tabla->Get_TotalNodos());
        NodoHash* nodoAux = tabla->buscarNodo(nodoABuscar);
        Nodo *nodo = new Nodo();
        nodo->Set_Columna(columnaCoincidencia);
        nodo->Set_entero(entero);
        nodo->Set_NombreTabla(tabla->Get_nombreTabla());
        //MA;ANA HACER LOS METODOS DE BUSQUEDA DEPENDIENDO SI HAY PARAMETRO EN LA COLUMNA DE BUSQUEDA O NO
        //HACER LO DE GRAPVIHZ
        //EMPEZAR LOS RESUMENES      
          // nodoAux->Get_AVL()->BuscarDato(*(arregloPalabras+1), a, true, nodo, tipo);
           reposicionamiento->Buscar(*(arregloPalabras+1), a, true, nodo, tipo, nodoAux->Get_AVL(), tabla);
       
    } else if (tipo == "Char") {
        char caracter = *(arregloPalabras + 7)->c_str();
        nodoABuscar = funciones->funcionChar(caracter, tabla->Get_TotalNodos());
        
        NodoHash* nodoAux = tabla->buscarNodo(nodoABuscar);
        Nodo *nodo = new Nodo();
        nodo->Set_caracter(caracter);
        nodo->Set_Columna(columnaCoincidencia);
        nodo->Set_NombreTabla(tabla->Get_nombreTabla());
    //    nodoAux->Get_AVL()->BuscarDato(*(arregloPalabras+1), a, true, nodo, tipo);
          reposicionamiento->Buscar(*(arregloPalabras+1), a, true, nodo, tipo, nodoAux->Get_AVL(), tabla);
         
    } else if (tipo == "String") {
        string cadena = *(arregloPalabras + 7);
        nodoABuscar = funciones->funcionString(cadena, tabla->Get_TotalNodos());
        NodoHash* nodoAux = tabla->buscarNodo(nodoABuscar);
        Nodo *nodo = new Nodo();
        nodo->Set_Columna(columnaCoincidencia);
        nodo->Set_cadena(cadena);
        nodo->Set_NombreTabla(tabla->Get_nombreTabla());
      //  nodoAux->Get_AVL()->BuscarDato(*(arregloPalabras+1), a, true, nodo, tipo);
     reposicionamiento->Buscar(*(arregloPalabras+1), a, true, nodo, tipo, nodoAux->Get_AVL(), tabla);
     
     
     
              
    } else if (tipo == "Double") {
        double decimal = stod(*(arregloPalabras + 7));
        nodoABuscar = funciones->funcionDecimal(decimal, tabla->Get_TotalNodos());
        NodoHash* nodoAux = tabla->buscarNodo(nodoABuscar);
        
        Nodo *nodo = new Nodo();
        nodo->Set_Columna(columnaCoincidencia);
        nodo->Set_decimal(decimal);
        nodo->Set_NombreTabla(tabla->Get_nombreTabla());
          
     // nodoAux->Get_AVL()->BuscarDato(*(arregloPalabras+1), a, true, nodo, tipo);
            reposicionamiento->Buscar(*(arregloPalabras+1), a, true, nodo, tipo, nodoAux->Get_AVL(), tabla);
       
        
    }
}

OperacionesSeleccion::OperacionesSeleccion(const OperacionesSeleccion& orig) {
}

OperacionesSeleccion::~OperacionesSeleccion() {
}

