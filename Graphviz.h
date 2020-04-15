/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graphviz.h
 * Author: luisGonzalez
 *
 * Created on 12 de abril de 2020, 01:28 AM
 */

#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H
#include "TablaHash.h"
#include "Nodo.h"
#include "AVL.h"
#include <string>
#include <fstream>
#include "ListaTablas.h"

using namespace std;

class Graphviz {
public:
    Graphviz();
    
    void dibujoGrafo(TablaHash*&, string);
    string convertirIntString(int);
    string convertirDoubleString(double);
    string convertirCharString(char);
    void grafoGlobal(ListaTablas*&, TablaHash*&, TablaHash*&);
    string* InOrden(Nodo*, bool, AVL*, string*, int, int);
    void sentenciaNodos(TablaHash*&, NodoHash*);
    string* InOrden2(Nodo*, bool, AVL*, string*, int);
    string verificarTipo(string, Nodo*);
    Graphviz(const Graphviz& orig);
    virtual ~Graphviz();
private:

};

#endif /* GRAPHVIZ_H */

