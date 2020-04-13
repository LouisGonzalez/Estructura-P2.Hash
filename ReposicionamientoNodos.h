/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReposicionamientoNodos.h
 * Author: luisGonzalez
 *
 * Created on 10 de abril de 2020, 12:40 PM
 */

#ifndef REPOSICIONAMIENTONODOS_H
#define REPOSICIONAMIENTONODOS_H
#include "Nodo.h"
#include "TablaHash.h"
#include "AVL.h"
#include <string>
#include "NodoHash.h"   

using namespace std;

class ReposicionamientoNodos {
public:
    ReposicionamientoNodos();
    
    Nodo* BuscarPorFuncion(int, int, TablaHash*&, NodoHash*);
    
    void VerificarFuncionesHash(AVL*, int, int, TablaHash*&, int);
    
    void InOrden(AVL*);
    static int orden;
    void Buscar(string, Nodo*, bool, Nodo*, string, AVL*, TablaHash*&);
    void BuscarCadena(string, Nodo*, Nodo*, string, AVL*, TablaHash*&);
    
    
    ReposicionamientoNodos(const ReposicionamientoNodos& orig);
    virtual ~ReposicionamientoNodos();
private:

};

#endif /* REPOSICIONAMIENTONODOS_H */

