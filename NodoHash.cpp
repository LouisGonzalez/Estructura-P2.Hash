/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoHash.cpp
 * Author: luisGonzalez
 * 
 * Created on 4 de abril de 2020, 02:55 PM
 */

#include "NodoHash.h"
#include "AVL.h"


NodoHash::NodoHash() {
    arbol = new AVL();
    id = 0;
    siguiente = NULL;
    anterior = NULL;
}

void NodoHash::Set_AVL(AVL* A){
    arbol = A;
}

void NodoHash::Set_id(int I){
    id = I;
}

void NodoHash::Set_Anterior(NodoHash* A){
    anterior = A;
}

void NodoHash::Set_Siguiente(NodoHash* S){
    siguiente = S;
}

NodoHash* NodoHash::Get_Anterior(){
    return anterior;
}

NodoHash* NodoHash::Get_Siguiente(){
    return siguiente;
}

AVL* NodoHash::Get_AVL(){
    return arbol;
}

int NodoHash::Get_id(){
    return id;
}   


NodoHash::NodoHash(const NodoHash& orig) {
}

NodoHash::~NodoHash() {
}

