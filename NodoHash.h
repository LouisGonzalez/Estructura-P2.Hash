/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoHash.h
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 02:55 PM
 */

#ifndef NODOHASH_H
#define NODOHASH_H
#include "Nodo.h"
#include <string>
#include "AVL.h"

using namespace std;

class NodoHash {
public:
    NodoHash();
    void Set_id(int);
    void Set_Siguiente(NodoHash*);
    void Set_Anterior(NodoHash*);
    void Set_AVL(AVL*);
    int Get_id();
    NodoHash* Get_Siguiente();
    NodoHash* Get_Anterior();
    AVL* Get_AVL();
    NodoHash(const NodoHash& orig);
    virtual ~NodoHash();
private:
    int id;
    AVL* arbol;
    NodoHash* siguiente;
    NodoHash* anterior;
};

#endif /* NODOHASH_H */

