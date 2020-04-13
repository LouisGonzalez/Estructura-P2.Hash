/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaTablas.h
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 06:57 PM
 */

#ifndef LISTATABLAS_H
#define LISTATABLAS_H
#include "TablaHash.h"

class ListaTablas {
public:
    ListaTablas();
    
    void Set_primero(TablaHash*);
    void Set_ultimo(TablaHash*);
    void Set_TotalColumnas(int);
    void Set_TotalElementos(int);
    
    int Get_TotalElementos();
    int Get_TotalColumnas();
    TablaHash* Get_primero();
    TablaHash* Get_ultimo();    
    
    void verTotalElementos(TablaHash*&, TablaHash*&);
    
    void verColumnasTotales(TablaHash*&, TablaHash*&);
    
    void insertarTabla(TablaHash*&, TablaHash*&, TablaHash*);
    
    TablaHash* buscarTabla(TablaHash*&, TablaHash*&, string);
    
    ListaTablas(const ListaTablas& orig);
    virtual ~ListaTablas();
private:
    int totalColumnas;
    int totalElementos;
    TablaHash* primero;
    TablaHash* ultimo;
};

#endif /* LISTATABLAS_H */

