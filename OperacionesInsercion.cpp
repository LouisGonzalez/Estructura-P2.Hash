/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperacionesInsercion.cpp
 * Author: luisGonzalez
 * 
 * Created on 5 de abril de 2020, 06:09 PM
 */

#include <stdexcept>

#include "OperacionesInsercion.h"
#include "SeparacionPalabras.h"
#include "Nodo.h"
#include "FuncionesHash.h"
#include "ReposicionamientoNodos.h"
#include <string>

OperacionesInsercion::OperacionesInsercion() {
}


bool OperacionesInsercion::verificadorColumnas(string datosColumna, string *columna, string *valores, int nodosHash, TablaHash *&tabla) {
    SeparacionPalabras *separacion = new SeparacionPalabras();
    string *datosConvertidos;
    string delim = " ";
    datosConvertidos = separacion->separacionColumnas3(datosColumna, delim, " ");

    int totalDatos = separacion->totalColumnas(datosColumna, " ") - 2;

    
    string tipoColumna[totalDatos / 2];
    string nombreColumna[totalDatos / 2];
    if(tabla->Get_TotalColumnas() == 0){
        tabla->Set_TotalColumnas(totalDatos/2);
    }
    int aux = 0;
    int aux2 = 0;
    if (totalDatos > 2) {
        for (int i = 0; i < totalDatos; i++) {
            if (i % 2 == 0) {
                tipoColumna[aux2] = *(datosConvertidos + i);
                aux2++;
            } else {
                nombreColumna[aux] = *(datosConvertidos + i);
                //QUITA LAS COMAS Y PARENTESIS DE LOS VALORES
                nombreColumna[aux] = separacion->quitarParentesisB(nombreColumna[aux]);
                aux++;
            }
        }
        //QUITA EL PARENTESIS DEL PRIMER VALOR
        tipoColumna[0] = separacion->quitarParentesisA(tipoColumna[0]);
        verificadorValores(columna, valores, totalDatos / 2, tipoColumna, nombreColumna, tabla);
    } else {
        tipoColumna[0] = *(datosConvertidos + 0);
        tipoColumna[0] = separacion->quitarParentesisA(tipoColumna[0]);
        nombreColumna[0] = *(datosConvertidos + 1);
        nombreColumna[0] = separacion->quitarParentesisB(nombreColumna[0]);
        verificadorValores(columna, valores, totalDatos / 2, tipoColumna, nombreColumna, tabla);

    }
}


//MANANA VERIFICAR QUE TODO FUE PUESTO EN SU LUGAR CON LOS ARBOLES, APRENDER A USAR GRAPHVIZ Y A VER QUE SALE

bool OperacionesInsercion::verificadorValores(string *columnas, string *valores, int totalColumnas, string *tipoColumna, string *nombreColumna, TablaHash *&tabla) {
    bool todoBien = true;
    for (int i = 0; i < totalColumnas; i++) {
        if (*(columnas + i) != nombreColumna[i]) {
            todoBien = false;
            break;
        }
    }
    if (todoBien == true) {
        FuncionesHash *funciones = new FuncionesHash();
        for (int i = 0; i < totalColumnas; i++) {
            int nodoAInsertar;
            if (tipoColumna[i] == "Integer") {
                try {
                    int entero = stoi(*(valores + i));
                    //AGREGAR EL NODO ENTERO AQUI
                    nodoAInsertar = funciones->funcionEntero(entero, tabla->Get_TotalNodos());
                    Nodo *nodo = new Nodo();
                    nodo->Set_entero(entero);
                    nodo->Set_tipo("Integer");
                    nodo->Set_NombreTabla(tabla->Get_nombreTabla());
                    nodo->Set_Columna(nombreColumna[i]);
                   nodo->Set_tupla(tabla->Get_UltimaTupla());
                     nodo->Set_NoColumna(i);
                    nodo->Set_TotalColumnas(totalColumnas);
                    tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
                    NodoHash* NodoAux = tabla->buscarNodo(nodoAInsertar);
        
                    NodoAux->Get_AVL()->Insertar(nodo);
                    funciones->reHashing(tabla);
                } catch (std::invalid_argument const &e) {
                    todoBien = false;
                }
            } else if (tipoColumna[i] == "Double") {
                double decimal = stod(*(valores + i));
                //AGREGAR EL NODO DECIMAL AQUI
                nodoAInsertar = funciones->funcionDecimal(decimal, tabla->Get_TotalNodos());
                Nodo *nodo = new Nodo();
                nodo->Set_decimal(decimal);
                nodo->Set_TotalColumnas(totalColumnas);
                nodo->Set_tipo("Double");
                nodo->Set_NombreTabla(tabla->Get_nombreTabla());
                nodo->Set_NoColumna(i);
                nodo->Set_tupla(tabla->Get_UltimaTupla());
                tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
                
                nodo->Set_Columna(nombreColumna[i]);
                NodoHash* NodoAux = tabla->buscarNodo(nodoAInsertar);
        
                NodoAux->Get_AVL()->Insertar(nodo);

        
                funciones->reHashing(tabla);
            } else if (tipoColumna[i] == "Char") {
                char caracter = *(valores + i)->c_str();
                //AGREGAR EL NODO CARACTER AQUI
                nodoAInsertar = funciones->funcionChar(caracter, tabla->Get_TotalNodos());


         
                Nodo *nodo = new Nodo();
                nodo->Set_caracter(caracter);
                nodo->Set_tipo("Char");
                nodo->Set_TotalColumnas(totalColumnas);
                nodo->Set_NombreTabla(tabla->Get_nombreTabla());
                nodo->Set_NoColumna(i);
                tabla->Set_UltimaTupla(tabla->Get_UltimaTupla()+1);
                
                nodo->Set_Columna(nombreColumna[i]);
                NodoHash* NodoAux = tabla->buscarNodo(nodoAInsertar);
                tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
       
                NodoAux->Get_AVL()->Insertar(nodo);
                funciones->reHashing(tabla);

            } else if (tipoColumna[i] == "String") {
                string cadena = *(valores + i);
                //AGREGAR EL NODO STRING AQUI
                nodoAInsertar = funciones->funcionString(cadena, tabla->Get_TotalNodos());
                Nodo *nodo = new Nodo();
                nodo->Set_cadena(cadena);
                nodo->Set_NombreTabla(tabla->Get_nombreTabla());
                nodo->Set_NoColumna(i);
                nodo->Set_TotalColumnas(totalColumnas);
                nodo->Set_tupla(tabla->Get_UltimaTupla());
                nodo->Set_tipo("String");
                nodo->Set_Columna(nombreColumna[i]);
                NodoHash* NodoAux = tabla->buscarNodo(nodoAInsertar);
                tabla->Set_TotalElementos(tabla->Get_TotalElementos() + 1);
                NodoAux->Get_AVL()->Insertar(nodo);
                funciones->reHashing(tabla);
            } else {
                todoBien = false;
            }
            if (todoBien == false) {
                break;
            }
        }
        tabla->Set_UltimaTupla(tabla->Get_UltimaTupla()+1);
    }
    return todoBien;
}

OperacionesInsercion::OperacionesInsercion(const OperacionesInsercion& orig) {
}

OperacionesInsercion::~OperacionesInsercion() {
}

