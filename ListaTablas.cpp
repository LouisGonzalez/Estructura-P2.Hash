/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaTablas.cpp
 * Author: luisGonzalez
 * 
 * Created on 4 de abril de 2020, 06:57 PM
 */

#include "ListaTablas.h"
#include <iostream>

ListaTablas::ListaTablas() {
    primero == NULL;
    ultimo = NULL;
    totalColumnas = 0;
}

void ListaTablas::Set_primero(TablaHash* P) {
    primero = P;
}

void ListaTablas::Set_ultimo(TablaHash* U) {
    ultimo = U;
}

void ListaTablas::Set_TotalColumnas(int T) {
    totalColumnas = T;
}

int ListaTablas::Get_TotalColumnas() {
    return totalColumnas;
}

TablaHash* ListaTablas::Get_primero() {
    return primero;
}

TablaHash* ListaTablas::Get_ultimo() {
    return ultimo;
}

void ListaTablas::insertarTabla(TablaHash *&primero, TablaHash *&ultimo, TablaHash *nodoTabla) {
    TablaHash* nodo = nodoTabla;
    if (primero == NULL) {
        primero = nodo;
        primero->Set_siguiente(NULL);
        primero->Set_anterior(NULL);
        ultimo = primero;
    } else {
        ultimo->Set_siguiente(nodo);
        nodo->Set_siguiente(NULL);
        nodo->Set_anterior(ultimo);
        ultimo = nodo;
    }
}

TablaHash* ListaTablas::buscarTabla(TablaHash *&primero, TablaHash *&ultimo, string nombreTabla) {
    TablaHash* nodoBuscado = primero;
    bool encontrado = false;
    if (primero != NULL) {
        while (nodoBuscado != NULL && encontrado != true) {
            if (nodoBuscado->Get_nombreTabla() == nombreTabla) {
                encontrado = true;
                break;
            }
            nodoBuscado = nodoBuscado->Get_siguiente();
        }
        if (!encontrado) {
            cout << "Tabla no encontrada" << endl;
            nodoBuscado = NULL;
        }
    } else {
        cout << "La lista se encuentra vacia" << endl;
    }
    return nodoBuscado;
}

void ListaTablas::verColumnasTotales(TablaHash *&primero, TablaHash *&ultimo) {
    TablaHash* nodoBuscado = primero;
    int totalColumnas = 0;
    if (primero != NULL) {
        while (nodoBuscado != NULL) {
            int aux = nodoBuscado->Get_TotalColumnas();
            cout << "TOTAL COLUMNAS TABLA " << nodoBuscado->Get_nombreTabla() << ": " << aux << " columnas." << endl;
            totalColumnas = totalColumnas + aux;
            nodoBuscado = nodoBuscado->Get_siguiente();
        }
    }
    cout << "COLUMNAS TOTALES: " << totalColumnas << " columnas." << endl;
}

void ListaTablas::verTotalElementos(TablaHash *&primero, TablaHash *&ultimo){
    TablaHash* nodoBuscado = primero;
    int totalElementos = 0;
    if(primero != NULL){
        while(nodoBuscado != NULL){
            int aux = nodoBuscado->Get_TotalElementos();
            cout << "TOTAL DATOS TABLA "<< nodoBuscado->Get_nombreTabla() <<": " << aux << " datos." << endl;
            totalElementos = totalElementos + aux;
            nodoBuscado = nodoBuscado->Get_siguiente();
        }
    }
    cout << "DATOS TOTALES: " <<  totalElementos << " datos." << endl;
}

ListaTablas::ListaTablas(const ListaTablas& orig) {
}

ListaTablas::~ListaTablas() {
}

