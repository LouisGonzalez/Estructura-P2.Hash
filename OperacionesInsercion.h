/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperacionesInsercion.h
 * Author: luisGonzalez
 *
 * Created on 5 de abril de 2020, 06:09 PM
 */

#ifndef OPERACIONESINSERCION_H
#define OPERACIONESINSERCION_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include "TablaHash.h"

using namespace std;

class OperacionesInsercion {
public:
    OperacionesInsercion();
    
    bool verificadorColumnas(string, string*, string*, int, TablaHash*&);
    bool verificadorValores(string*, string*, int, string*, string*, TablaHash*&);
    
    OperacionesInsercion(const OperacionesInsercion& orig);
    virtual ~OperacionesInsercion();
private:
   
};

#endif /* OPERACIONESINSERCION_H */

