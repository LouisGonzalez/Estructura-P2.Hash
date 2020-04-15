/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesHash.h
 * Author: luisGonzalez
 *
 * Created on 5 de abril de 2020, 04:55 PM
 */

#ifndef FUNCIONESHASH_H
#define FUNCIONESHASH_H
#include <string>
#include "TablaHash.h"
using namespace std;

class FuncionesHash {
public:
    FuncionesHash();
    FuncionesHash(const FuncionesHash& orig);
    int valorAscii(char);
    int funcionString(string, int);
    int funcionEntero(int, int);
    int funcionChar(char, int);
    int funcionDecimal(double, int);
    void reHashing(TablaHash*&);
    
    virtual ~FuncionesHash();
private:

};

#endif /* FUNCIONESHASH_H */

