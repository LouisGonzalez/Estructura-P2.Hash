/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: luisGonzalez
 * 
 * Created on 4 de abril de 2020, 02:58 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
    entero = 0;
    decimal = 0;
    cadena = "";
    caracter = ' ';
    tipo = "";
    tupla = 0;
    izquierda = NULL;
    derecha = NULL;
    padre = NULL;
    id = 0;
    FE = 0;
    columna = "";
    nombreTabla = "";
    bandera = "ACTIVO";
    noColumna = 0;
    totalColumnas = 0;
}

//SETS

void Nodo::Set_NombreTabla(string N){
    nombreTabla = N;
}

void Nodo::Set_TotalColumnas(int T){
    totalColumnas = T;
}

void Nodo::Set_cadena(string C){
    cadena = C;
}

void Nodo::Set_NoColumna(int N){
    noColumna = N;
}

void Nodo::Set_Bandera(string B){
    bandera = B;
}

void Nodo::Set_id(int I){
    id = I;
}

void Nodo::Set_Columna(string C){
    columna = C;
}

void Nodo::Set_FE(int F){
    FE = F;
}

void Nodo::Set_entero(int E){
    entero = E;
}

void Nodo::Set_decimal(double D){
    decimal = D;
}

void Nodo::Set_caracter(char C){
    caracter = C;
}
 
void Nodo::Set_tipo(string T){
    tipo = T;
}

void Nodo::Set_tupla(int T){
    tupla = T;
}

void Nodo::Set_izquierda(Nodo* I){
    izquierda = I;
}

void Nodo::Set_derecha(Nodo* D){
    derecha = D;
}

void Nodo::Set_padre(Nodo* P){
    padre = P;
}

//GETS

int Nodo::Get_TotalColumnas(){
    return totalColumnas;
}

int Nodo::Get_NoColumna(){
    return noColumna;
}

string Nodo::Get_NombreTabla(){
    return nombreTabla;
}

string Nodo::Get_Bandera(){
    return bandera;
}

string Nodo::Get_Columna(){
    return columna;
}

int Nodo::Get_FE(){
    return FE;
}

int Nodo::Get_id(){
    return id;
}

int Nodo::Get_entero(){
    return entero;
}

double Nodo::Get_decimal(){
    return decimal;
}

string Nodo::Get_cadena(){
    return cadena;
}

char Nodo::Get_caracter(){
    return caracter;
}

string Nodo::Get_tipo(){
    return tipo;
}

int Nodo::Get_tupla(){
    return tupla;
}

Nodo* Nodo::Get_izquierda(){
    return izquierda;
}

Nodo* Nodo::Get_derecha(){
    return derecha;
}

Nodo* Nodo::Get_padre(){
    return padre;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

