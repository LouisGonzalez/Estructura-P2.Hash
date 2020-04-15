/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHash.cpp
 * Author: luisGonzalez
 * 
 * Created on 4 de abril de 2020, 02:54 PM
 */

#include "TablaHash.h"
#include <iostream>
#include "FuncionesHash.h"
#include "ReposicionamientoNodos.h"

TablaHash::TablaHash() {
    primero = NULL;
    ultimo = NULL;
    siguiente = NULL;
    anterior = NULL;
    nombreTabla = "";
    columnas = 0;
    nombreColumnas = "";
    totalNodos = 0;
    totalElementos = 0;
    totalColumnas = 0;
    ultimaTupla = 0;
    columnasString = 0;
    columnasInt = 0;
    columnasChar = 0;
    columnasDouble = 0;
}

void TablaHash::Set_ColumnasChar(int C){
    columnasChar = C;
}

void TablaHash::Set_ColumnasDouble(int D){
    columnasDouble = D;
}

void TablaHash::Set_ColumnasInt(int I){
    columnasInt = I;
}

void TablaHash::Set_ColumnasString(int S){
    columnasString = S;
}

void TablaHash::Set_UltimaTupla(int U){
    ultimaTupla = U;
}

void TablaHash::Set_TotalElementos(int T) {
    totalElementos = T;
}

void TablaHash::Set_TotalColumnas(int T){
    totalColumnas = T;
}

void TablaHash::Set_NombreColumnas(string N) {
    nombreColumnas = N;
}

void TablaHash::Set_TotalNodos(int T) {
    totalNodos = T;
}

void TablaHash::Set_nombreTabla(string N) {
    nombreTabla = N;
}

void TablaHash::Set_primero(NodoHash* P) {
    primero = P;
}

void TablaHash::Set_ultimo(NodoHash* U) {
    ultimo = U;
}

void TablaHash::Set_siguiente(TablaHash* S) {
    siguiente = S;
}

void TablaHash::Set_anterior(TablaHash* A) {
    anterior = A;
}

void TablaHash::Set_Columnas(int C) {
    columnas = C;
}

int TablaHash::Get_ColumnasChar(){
    return columnasChar;
}

int TablaHash::Get_ColumnasDouble(){
    return columnasDouble;
}

int TablaHash::Get_ColumnasInt(){
    return columnasInt;
}

int TablaHash::Get_ColumnasString(){
    return columnasString;
}

int TablaHash::Get_UltimaTupla(){
    return ultimaTupla;
}

int TablaHash::Get_TotalElementos() {
    return totalElementos;
}

int TablaHash::Get_TotalNodos() {
    return totalNodos;
}

int TablaHash::Get_TotalColumnas(){
    return totalColumnas;
}

string TablaHash::Get_NombreColumna() {
    return nombreColumnas;
}

int TablaHash::Get_Columnas() {
    return columnas;
}

string TablaHash::Get_nombreTabla() {
    return nombreTabla;
}

TablaHash* TablaHash::Get_siguiente() {
    return siguiente;
}

TablaHash* TablaHash::Get_anterior() {
    return anterior;
}

NodoHash* TablaHash::Get_primero() {
    return primero;
}

NodoHash* TablaHash::Get_ultimo() {
    return ultimo;
}

void TablaHash::insertarNodo(NodoHash *nodo) {
    NodoHash* aux = nodo;
    if (primero == NULL) {
        primero = nodo;
        primero->Set_Siguiente(NULL);
        primero->Set_Anterior(NULL);
        ultimo = primero;
    } else {
        ultimo->Set_Siguiente(aux);
        nodo->Set_Siguiente(NULL);
        nodo->Set_Anterior(ultimo);
        ultimo = aux;
    }
    totalNodos++;
}

//CREA LOS 5 CAMPOS INICIALES DE LA TABLA HASH

void TablaHash::crearNodosPrincipales() {
    for (int i = 0; i < 5; i++) {
        NodoHash* nodo = new NodoHash();
        nodo->Set_id(i);
        nodo->Get_AVL()->Set_NoArbol(i);
        insertarNodo(nodo);
    }
}

NodoHash* TablaHash::buscarNodo(int id) {
    NodoHash* nodoBuscado = primero;
    bool encontrado = false;
    if (primero != NULL) {
        while (nodoBuscado != NULL && encontrado != true) {
            if (nodoBuscado->Get_id() == id) {
                encontrado = true;
                break;
            }
            nodoBuscado = nodoBuscado->Get_Siguiente();
        }
        if (!encontrado) {
            cout << "Nodo no encontrado" << endl;
            nodoBuscado = NULL;
        } else {
        }
    } else {
        cout << "La lista se encuentra vacia." << endl;
    }
    return nodoBuscado;
}

void TablaHash::reposicionamientoNodos(int parametroFuncion, TablaHash *&tabla) {
    NodoHash *nodoAux = tabla->Get_primero();
    FuncionesHash *funcion = new FuncionesHash();
    if (tabla->Get_primero() != NULL) {
        while (nodoAux != NULL) {
            
            ReposicionamientoNodos *reposicionamiento = new ReposicionamientoNodos();
           
            reposicionamiento->BuscarPorFuncion(tabla->Get_TotalNodos(), parametroFuncion, tabla, nodoAux);

            
    
            nodoAux = nodoAux->Get_Siguiente();


        }
    }
}

void TablaHash::verificarTotalColumnas(TablaHash *&tabla){
    cout << "Total columnas tipo String:  " << tabla->Get_ColumnasString() << "." << endl;
    cout << "Total columnas tipo Integer: " << tabla->Get_ColumnasInt() << "." << endl;
    cout << "Total columnas tipo Char:    " << tabla->Get_ColumnasChar() << "." << endl;
    cout << "Total columnas tipo Double:  " << tabla->Get_ColumnasDouble() << "." << endl;
}

TablaHash::TablaHash(const TablaHash& orig) {
}

TablaHash::~TablaHash() {
}

