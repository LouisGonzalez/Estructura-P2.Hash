/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 03:29 PM
 */

#ifndef AVL_H
#define AVL_H
#include <string>
#include "Nodo.h"


using namespace std;

class AVL {
public:
    AVL();
    void Insertar(Nodo*);
    void Reposicionamiento(Nodo*);
    
    void Insertar2(Nodo*, Nodo*, Nodo*);
    void Borrar(Nodo* nodo);
    bool Buscar(Nodo* nodo);
    void BuscarEntero(string, Nodo*);
    void BuscarDecimal(string, Nodo*);
    void BuscarCaracter(string, Nodo*);
    
    void BuscarDato(string, Nodo*, bool, Nodo*, string);
    
    void Set_NoArbol(int);
    
    void BuscarCadena(string, Nodo*, Nodo*, string);
    
    
    Nodo* Get_Raiz();
    Nodo* Get_Actual();
    int Get_NoArbol();
    
    
    void Set_Raiz(Nodo*);
    void Set_Actual(Nodo*);
    
    Nodo* BuscarPorFuncion(int, int);
    
    Nodo* VerificarFuncionesHash(int, int);
        
    bool Vacio(Nodo *nodo);
    bool EsHoja(Nodo* nodo) { return !nodo->Get_derecha() && !nodo->Get_izquierda(); }
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(const int dat);
    void Raiz() { actual = raiz; }
    void InOrden();
  
    void Equilibrar(Nodo* nodo, int, bool);
    void RSI(Nodo* nodo);   
    void RSD(Nodo* nodo);
    void RDI(Nodo* nodo);
    void RDD(Nodo* nodo);
    
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
    
    AVL(const AVL& orig);
    virtual ~AVL();
    
private:   
    enum { IZQUIERDO, DERECHO };
    Nodo *raiz;
    Nodo *actual;
    int contador;
    int altura;
    int noArbol;
};

#endif /* AVL_H */

