/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SeparacionPalabras.h
 * Author: luisGonzalez
 *
 * Created on 5 de abril de 2020, 05:22 PM
 */

#ifndef SEPARACIONPALABRAS_H
#define SEPARACIONPALABRAS_H
#include <string>
#include "TablaHash.h"

using namespace std;

class SeparacionPalabras {
public:
    SeparacionPalabras();
    SeparacionPalabras(const SeparacionPalabras& orig);
    
    string* separacionColumnas(string, string, string);
    string* separacionColumnas2(string, string, string);
    string* separacionColumnas3(string, string, string);
    string* separacionColumnas4(string, string, string);
    
    void acumuladorColumnas(TablaHash*&, string);
    
    int totalColumnas(string, string);
    string quitarParentesisA(string);
    string quitarParentesisB(string);
    string quitarParentesis(string);
    
    virtual ~SeparacionPalabras();
private:

};

#endif /* SEPARACIONPALABRAS_H */

