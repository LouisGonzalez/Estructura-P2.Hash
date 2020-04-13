/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoConsultas.cpp
 * Author: luisitopapurey
 * 
 * Created on 4 de abril de 2020, 12:10 PM
 */

#include "TextoConsultas.h"

TextoConsultas::TextoConsultas() {
}

TextoConsultas::TextoConsultas(const TextoConsultas& orig) {
}

int TextoConsultas::totalPalabras(string s){
    string delim = " ";
    int contadorPalabras = 1;
    auto start = 0U;
    auto end = s.find(delim);
    while (end != string::npos)
    {
        contadorPalabras++;
        start = end + delim.length();
        end = s.find(delim, start);
    }
    return contadorPalabras;
}

string* TextoConsultas::separacionTexto(string s){
    string delim = " ";
    int contadorPalabras = totalPalabras(s);
    
    auto start2 = 0U;
    auto end2 = s.find(delim);
    
    static string palabras[10000];
    int aux = 0;
    while (end2 != string::npos)
    {
        palabras[aux] = s.substr(start2, end2 - start2);
        start2 = end2 + delim.length();
        end2 = s.find(delim, start2);
        aux++;
    }

    palabras[contadorPalabras - 1] = s.substr(start2, end2);
    
    return palabras;    
    
}


TextoConsultas::~TextoConsultas() {
}

