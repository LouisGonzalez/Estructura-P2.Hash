    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 02:58 PM
 */

#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;

class Nodo {
public:
    Nodo(); 
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    //SETS
    void Set_entero(int);
    void Set_decimal(double);
    void Set_cadena(string);
    void Set_caracter(char);
    void Set_tipo(string);
    void Set_tupla(int);
    void Set_izquierda(Nodo*);
    void Set_derecha(Nodo*);
    void Set_padre(Nodo*);
    void Set_FE(int);
    void Set_id(int);
    void Set_Columna(string);
    void Set_Bandera(string);
    void Set_NombreTabla(string);
    void Set_NoColumna(int);
    void Set_TotalColumnas(int);
    string Get_Bandera();
    string Get_NombreTabla();
    int Get_NoColumna();
    int Get_TotalColumnas();
    int Get_entero();
    int Get_id();
    string Get_Columna();
    double Get_decimal();
    string Get_cadena();
    int Get_FE();
    char Get_caracter();
    string Get_tipo();
    int Get_tupla();
    Nodo* Get_izquierda();
    Nodo* Get_derecha();
    Nodo* Get_padre();
   
    
private:
    int entero;
    string bandera;
    int id;
    int FE;
    double decimal;
    string cadena;
    char caracter;
    string tipo;
    int tupla;
    string columna;
    string nombreTabla;
    int noColumna;
    int totalColumnas;
    Nodo *izquierda;
    Nodo *derecha;
    Nodo *padre;
        
          
};

#endif /* NODO_H */

