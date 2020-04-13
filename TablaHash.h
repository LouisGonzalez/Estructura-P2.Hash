/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHash.h
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 02:54 PM
 */

#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include "NodoHash.h"

using namespace std;

class TablaHash {
public:
    TablaHash();
    
    
    
    void Set_primero(NodoHash*);
    void Set_ultimo(NodoHash*);
    void Set_siguiente(TablaHash*);
    void Set_anterior(TablaHash*);
    void Set_nombreTabla(string);
    void Set_Columnas(int);
    void Set_NombreColumnas(string);
    void Set_TotalNodos(int);
    void Set_TotalElementos(int);
    void Set_UltimaTupla(int);
    void Set_TotalColumnas(int);
    
    void Set_ColumnasInt(int);
    void Set_ColumnasString(int);
    void Set_ColumnasDouble(int);
    void Set_ColumnasChar(int);
    
    int Get_ColumnasInt();
    int Get_ColumnasString();
    int Get_ColumnasDouble();
    int Get_ColumnasChar();
    
    int Get_TotalElementos();
    int Get_TotalNodos();
    int Get_TotalColumnas();
    int Get_UltimaTupla();
    string Get_NombreColumna();
    int Get_Columnas();
    string Get_nombreTabla();
    NodoHash* Get_primero();
    NodoHash* Get_ultimo();
    TablaHash* Get_siguiente();
    TablaHash* Get_anterior();
    
    void insertarNodo(NodoHash*);
    void crearNodosPrincipales();
    NodoHash* buscarNodo(int);
    
    void verificarTotalColumnas(TablaHash*&);
    
    void reposicionamientoNodos(int, TablaHash*&);
    
    TablaHash(const TablaHash& orig);
    virtual ~TablaHash();
private:
    NodoHash* primero;
    NodoHash* ultimo;
    string nombreTabla;
    int columnas;
    int totalElementos;
    int totalNodos;
    int ultimaTupla;
    int totalColumnas;
    int columnasString;
    int columnasInt;
    int columnasDouble;
    int columnasChar;
    string nombreColumnas;
    TablaHash* siguiente;
    TablaHash* anterior;
};

#endif /* TABLAHASH_H */

