/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SeparacionPalabras.cpp
 * Author: luisGonzalez
 * 
 * Created on 5 de abril de 2020, 05:22 PM
 */

#include "SeparacionPalabras.h"
#include <string>
#include <iostream>
#include "SeparacionPalabras.h"


SeparacionPalabras::SeparacionPalabras() {
}

int SeparacionPalabras::totalColumnas(string texto, string delim) {
    int contadorPalabras = 1;
    auto start = 0U;
    auto end = texto.find(delim);
    while (end != string::npos) {
        contadorPalabras++;
        start = end + delim.length();
        end = texto.find(delim, start);
    }
    return contadorPalabras;
}

string* SeparacionPalabras::separacionColumnas(string texto, string delim, string delim2) {
    int contadorColumnas = totalColumnas(texto, delim2);
    static string columnass[10000];

    if (contadorColumnas == 1) {
        auto start = 0U;
        auto end = texto.find(delim);
        columnass[contadorColumnas - 1] = texto.substr(start, end);

    } else {
        auto start = 0U;
        auto end = texto.find(delim);

        int aux = 0;
        while (end != string::npos) {
            columnass[aux] = texto.substr(start, end - start);
            start = end + delim.length();
            end = texto.find(delim, start);
            aux++;
        }

        columnass[contadorColumnas - 1] = texto.substr(start, end);
    }
    return columnass;

}

string* SeparacionPalabras::separacionColumnas2(string texto, string delim, string delim2) {
    int contadorColumnas = totalColumnas(texto, delim2);
    static string columnass[10000];

    if (contadorColumnas == 1) {
        auto start = 0U;
        auto end = texto.find(delim);
        columnass[contadorColumnas - 1] = texto.substr(start, end);

    } else {
        auto start = 0U;
        auto end = texto.find(delim);

        int aux = 0;
        while (end != string::npos) {
            columnass[aux] = texto.substr(start, end - start);
            start = end + delim.length();
            end = texto.find(delim, start);
            aux++;
        }

        columnass[contadorColumnas - 1] = texto.substr(start, end);
    }
    return columnass;

}

string* SeparacionPalabras::separacionColumnas3(string texto, string delim, string delim2) {
    int contadorColumnas = totalColumnas(texto, delim2);
    static string columnass[10000];

    if (contadorColumnas == 1) {
        auto start = 0U;
        auto end = texto.find(delim);
        columnass[contadorColumnas - 1] = texto.substr(start, end);

    } else {
        auto start = 0U;
        auto end = texto.find(delim);

        int aux = 0;
        while (end != string::npos) {
            columnass[aux] = texto.substr(start, end - start);
            start = end + delim.length();
            end = texto.find(delim, start);
            aux++;
        }

        columnass[contadorColumnas - 1] = texto.substr(start, end);
    }
    return columnass;

}

string* SeparacionPalabras::separacionColumnas4(string texto, string delim, string delim2) {
    int contadorColumnas = totalColumnas(texto, delim2);
    static string columnass[10000];

    if (contadorColumnas == 1) {
        auto start = 0U;
        auto end = texto.find(delim);
        columnass[contadorColumnas - 1] = texto.substr(start, end);

    } else {
        auto start = 0U;
        auto end = texto.find(delim);

        int aux = 0;
        while (end != string::npos) {
            columnass[aux] = texto.substr(start, end - start);
            start = end + delim.length();
            end = texto.find(delim, start);
            aux++;
        }

        columnass[contadorColumnas - 1] = texto.substr(start, end);
    }
    return columnass;

}

string SeparacionPalabras::quitarParentesisA(string palabra) {
    string nuevaPalabra = "";
    for(int i = 0; i < palabra.length(); i++){
        if(palabra[i] == '('){
        } else {
            nuevaPalabra += palabra[i];
        }
    }
    return nuevaPalabra;
}

string SeparacionPalabras::quitarParentesisB(string palabra) {
    string nuevaPalabra = "";
    for(int i = 0; i < palabra.length(); i++){
        if(palabra[i] == ')' || palabra[i] == ','){
        } else {
            nuevaPalabra += palabra[i];
        }
    }
    return nuevaPalabra;
    
}

string SeparacionPalabras::quitarParentesis(string palabra) {
    string nuevaPalabra = "";
    for(int i = 0; i < palabra.length(); i++){
        if(palabra[i] == ')' || palabra[i] == '('){
      //      cout << "hola mundo"<<endl;
        }  else {
            nuevaPalabra += palabra[i];
        }
    }
    return nuevaPalabra;
}

void SeparacionPalabras::acumuladorColumnas(TablaHash *&tabla, string datosColumna){    
    string *datosConvertidos;
    string delim = " ";
    datosConvertidos = separacionColumnas4(datosColumna, delim, " ");
    int totalDatos = totalColumnas(datosColumna, " ")-2;
    string tipoColumna[totalDatos / 2];
    int aux = 0;
    if(totalDatos > 2){
        for(int i = 0; i < totalDatos; i++){
            if(i % 2 == 0){
                tipoColumna[aux] = *(datosConvertidos + i);
                aux++;
            }
        }
        tipoColumna[0] = quitarParentesisA(tipoColumna[0]);
    } else {
        tipoColumna[0] = *(datosConvertidos + 0);
        tipoColumna[0] = quitarParentesisA(tipoColumna[0]);
    }
    for(int i = 0; i < totalDatos/2; i++){
        if(tipoColumna[i] == "String"){
            tabla->Set_ColumnasString(tabla->Get_ColumnasString() + 1);
        } else if(tipoColumna[i] == "Integer"){
                tabla->Set_ColumnasInt(tabla->Get_ColumnasInt() + 1);
        } else if(tipoColumna[i] == "Char"){
            tabla->Set_ColumnasChar(tabla->Get_ColumnasChar() + 1);
        } else if(tipoColumna[i] == "Double"){
            tabla->Set_ColumnasDouble(tabla->Get_ColumnasDouble() + 1);
        }
    }
    
}

SeparacionPalabras::SeparacionPalabras(const SeparacionPalabras& orig) {
}

SeparacionPalabras::~SeparacionPalabras() {
}

