/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesHash.cpp
 * Author: luisGonzalez
 * 
 * Created on 5 de abril de 2020, 04:55 PM
 */

#include "FuncionesHash.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "NodoHash.h"

FuncionesHash::FuncionesHash() {
}

int FuncionesHash::valorAscii(char letra){
    int valorAscii = letra;
    return valorAscii;
}

int FuncionesHash::funcionChar(char valor, int rango){
    int convertido = valorAscii(valor);
    int casilla = convertido % rango;
    return casilla;
}

int FuncionesHash::funcionDecimal(double valor, int rango){
    int convertido = (int) valor;
    if(convertido < rango){
        return convertido;
    } else {
        int casilla = convertido % rango;
        return casilla;
    }
}

int FuncionesHash::funcionEntero(int valor, int rango){
    if(valor < rango){
        return valor;
    } else {
        int casilla = valor % rango;
        return casilla;
    }
}

int FuncionesHash::funcionString(string valor, int rango){
    int convertido = valor.length();
    if(convertido < rango){
        return convertido;
    } else {
        int casilla = convertido % rango;
        return casilla;
    }
}

void FuncionesHash::reHashing(TablaHash *&tabla){
    double calculo = (double)tabla->Get_TotalElementos()/ (double)tabla->Get_TotalNodos();
    int factorCarga = calculo * 100;
   // cout << "El factor de carga es del: " << factorCarga << endl;
    if(factorCarga > 60){
        NodoHash* nodo = new NodoHash();
        nodo->Set_id(tabla->Get_TotalNodos());
        tabla->insertarNodo(nodo);
        
        tabla->reposicionamientoNodos(tabla->Get_TotalNodos()-1, tabla);
        
        reHashing(tabla);
    } else {
    }
}



FuncionesHash::FuncionesHash(const FuncionesHash& orig) {
}

FuncionesHash::~FuncionesHash() {
}

