/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.cpp
 * Author: luisGonzalez
 * 
 * Created on 4 de abril de 2020, 03:29 PM
 */

#include "AVL.h"
#include <iostream>
#include <string>
#include "FuncionesHash.h"
#include "NodoHash.h"
#include "TablaHash.h"

AVL::AVL() {
    raiz = NULL;
    contador = 0;
    altura = 0;
    actual = NULL;
    noArbol = 0;
}

void AVL::Set_NoArbol(int A){
    noArbol = A;
}

int AVL::Get_NoArbol(){
    return noArbol;
}

Nodo* AVL::Get_Actual() {
    return actual;
}

Nodo* AVL::Get_Raiz() {
    return raiz;
}

void AVL::Set_Actual(Nodo *A) {
    actual = A;
}

void AVL::Set_Raiz(Nodo *R) {
    raiz = R;
}

bool AVL::Vacio(Nodo* nodo) {
    return nodo == NULL;
}

void AVL::Insertar2(Nodo *nodo, Nodo *raiz, Nodo *actual) {
    Nodo *padre = NULL;
    bool coincidencia = false;
    actual = raiz;

    while (!Vacio(actual) && nodo->Get_id() != actual->Get_id()) {
        padre = actual;
        if (nodo->Get_Columna() == actual->Get_Columna() && nodo->Get_tupla() == actual->Get_tupla()) {
            coincidencia = true;
        }


        if (nodo->Get_id() > actual->Get_id()) {
            actual = actual->Get_derecha();
        } else if (nodo->Get_id() < actual->Get_id()) {
            actual = actual->Get_izquierda();
        }

    }
    if (!Vacio(padre)) {
        if (coincidencia == false) {
            if (actual != NULL) {
                if (nodo->Get_Columna() == actual->Get_Columna() && nodo->Get_tupla() == actual->Get_tupla()) {
                    coincidencia = true;
                }
            }
        }
    }


    if (!Vacio(actual)) {
        nodo->Set_id(nodo->Get_id() + 1);

        if (coincidencia == true) {
            nodo->Set_tupla(nodo->Get_tupla() + 1);
        }
        Insertar2(nodo, raiz, actual);
    } else if (Vacio(padre)) {
        raiz = nodo;
    
    } else if (Vacio(actual)) {
        if (coincidencia == true) {
            Insertar2(nodo, raiz, actual);

        } else {
            if (nodo->Get_id() < padre->Get_id()) {
                nodo->Set_padre(padre);
                padre->Set_izquierda(nodo);

                Equilibrar(padre, IZQUIERDO, true);
            } else if (nodo->Get_id() > padre->Get_id()) {
                nodo->Set_padre(padre);
                padre->Set_derecha(nodo);
                Equilibrar(padre, DERECHO, true);
            }
        }


    }

}

void AVL::Insertar(Nodo* nodo) {
    Nodo *padre = NULL;
    bool coincidencia = false;
    actual = raiz;


    while (!Vacio(actual) && nodo->Get_id() != actual->Get_id()) {
        padre = actual;
        if (nodo->Get_Columna() == actual->Get_Columna() && nodo->Get_tupla() == actual->Get_tupla()) {
            coincidencia = true;
        }

        if (nodo->Get_id() > actual->Get_id()) {
            actual = actual->Get_derecha();
        } else if (nodo->Get_id() < actual->Get_id()) {
            actual = actual->Get_izquierda();
        }

    }
    if (!Vacio(padre)) {
        if (coincidencia == false) {
            if (actual != NULL) {
                if (nodo->Get_Columna() == actual->Get_Columna() && nodo->Get_tupla() == actual->Get_tupla()) {
                    coincidencia = true;
                }
            }
        }
    }


    if (!Vacio(actual)) {
        nodo->Set_id(nodo->Get_id() + 1);

        if (coincidencia == true) {
            nodo->Set_tupla(nodo->Get_tupla() + 1);
        }
        Insertar(nodo);
    } else if (Vacio(padre)) {
        raiz = nodo;
    } else if (Vacio(actual)) {
        if (coincidencia == true) {
            nodo->Set_tupla(nodo->Get_tupla() + 1);
            Insertar(nodo);

        } else {
            if (nodo->Get_id() < padre->Get_id()) {
                nodo->Set_padre(padre);
                padre->Set_izquierda(nodo);

                Equilibrar(padre, IZQUIERDO, true);
            } else if (nodo->Get_id() > padre->Get_id()) {
                nodo->Set_padre(padre);
                padre->Set_derecha(nodo);
                Equilibrar(padre, DERECHO, true);
            }
        }


    }

}

void AVL::Equilibrar(Nodo* nodo, int rama, bool nuevo) {
    bool salir = false;
    while (nodo && !salir) {
        if (nuevo) {
            if (rama == IZQUIERDO) nodo->Set_FE(nodo->Get_FE() - 1);
            else nodo->Set_FE(nodo->Get_FE() + 1);
        } else {
            if (rama == IZQUIERDO) nodo->Set_FE(nodo->Get_FE() + 1);
            else nodo->Set_FE(nodo->Get_FE() - 1);
        }
        if (nodo->Get_FE() == 0) {
            salir = true;
        } else if (nodo->Get_FE() == -2) {
            if (nodo->Get_izquierda()->Get_FE() == 1) RDD(nodo);
            else RSD(nodo);
            salir = true;
        } else if (nodo->Get_FE() == 2) {
            if (nodo->Get_derecha()->Get_FE() == -1) RDI(nodo);
            else RSI(nodo);
            salir = true;
        }
        if (nodo->Get_padre()) {
            if (nodo->Get_padre()->Get_derecha() == nodo) rama = DERECHO;
            else rama = IZQUIERDO;
        
        }
            nodo = nodo->Get_padre();

    }
}

void AVL::RDD(Nodo* nodo) {
    Nodo *Padre = nodo->Get_padre();
    Nodo *P = nodo;
    Nodo *Q = P->Get_izquierda();
    Nodo *R = Q->Get_derecha();
    Nodo *B = R->Get_izquierda();
    Nodo *C = R->Get_derecha();

    if (Padre) {
        if (Padre->Get_derecha() == nodo) Padre->Set_derecha(R);
        else Padre->Set_izquierda(R);
    } else {
        raiz = R;
    }

    Q->Set_derecha(B);
    P->Set_izquierda(C);
    R->Set_izquierda(Q);
    R->Set_derecha(P);

    R->Set_padre(Padre);
    P->Set_padre(R);
    Q->Set_padre(R);
    if (B) B->Set_padre(Q);
    if (C) C->Set_padre(P);

    switch (R->Get_FE()) {
        case -1: Q->Set_FE(0);
            P->Set_FE(1);
            break;
        case 0: Q->Set_FE(0);
            P->Set_FE(0);
            break;
        case 1: Q->Set_FE(-1);
            P->Set_FE(0);
            break;
    }
    R->Set_FE(0);
}

void AVL::RDI(Nodo* nodo) {
    Nodo *Padre = nodo->Get_padre();
    Nodo *P = nodo;
    Nodo *Q = P->Get_derecha();
    Nodo *R = Q->Get_izquierda();
    Nodo *B = R->Get_izquierda();
    Nodo *C = R->Get_derecha();

    if (Padre) {
        if (Padre->Get_derecha() == nodo) Padre->Set_derecha(R);
        else Padre->Set_izquierda(R);
    } else {
        raiz = R;
    }

    P->Set_derecha(B);
    Q->Set_izquierda(C);
    R->Set_izquierda(P);
    R->Set_derecha(Q);

    R->Set_padre(Padre);
    P->Set_padre(Q->Get_padre());

    R->Set_padre(Padre);
    P->Set_padre(R);
    Q->Set_padre(R);
    if (B) B->Set_padre(P);
    if (C) C->Set_padre(Q);

    switch (R->Get_FE()) {
        case -1: P->Set_FE(0);
            Q->Set_FE(1);
            break;
        case 0: P->Set_FE(0);
            Q->Set_FE(0);
            break;
        case 1: P->Set_FE(-1);
            Q->Set_FE(0);
            break;
    }
    R->Set_FE(0);
}

void AVL::RSD(Nodo* nodo) {
    Nodo *Padre = nodo->Get_padre();
    Nodo *P = nodo;
    Nodo *Q = P->Get_izquierda();
    Nodo *B = Q->Get_derecha();

    if (Padre) {
        if (Padre->Get_derecha() == P) Padre->Set_derecha(Q);
        else Padre->Set_izquierda(Q);
    } else {
        raiz = Q;
    }

    P->Set_izquierda(B);
    Q->Set_derecha(P);

    P->Set_padre(Q);
    if (B) B->Set_padre(P);
    Q->Set_padre(Padre);

    P->Set_FE(0);
    Q->Set_FE(0);
}

void AVL::RSI(Nodo* nodo) {
    Nodo *Padre = nodo->Get_padre();
    Nodo *P = nodo;
    Nodo *Q = P->Get_derecha();
    Nodo *B = Q->Get_izquierda();

    if (Padre) {
        if (Padre->Get_derecha() == P) Padre->Set_derecha(Q);
        else Padre->Set_izquierda(Q);
    } else {
        raiz = Q;
    }

    P->Set_derecha(B);
    Q->Set_izquierda(P);

    P->Set_padre(Q);
    if (B) B->Set_padre(P);
    Q->Set_padre(Padre);

    P->Set_FE(0);
    Q->Set_FE(0);
}

/*void AVL::BuscarEntero(string columnaCondicional, Nodo *nodo) {
    actual = raiz;
    Nodo *nodoADevolver = NULL;
    bool encontrado = false;
    while (!Vacio(actual)) {
        if (nodo->Get_entero() == actual->Get_entero() && nodo->Get_Columna() == actual->Get_Columna()) {
            nodoADevolver = actual;
            cout << "Nodo encontrado bro" << endl;
            encontrado = true;
            break;
        } else {
            //USAMOS EL RECORRIDO INORDEN para ir buscando el nodo
            InOrden();
        }
    }
    if (encontrado == false) {

    }
}

void AVL::BuscarDecimal(string columnaCondicional, Nodo *nodo) {
    actual = raiz;
    Nodo *nodoADevolver = NULL;
    bool encontrado = false;
    while (!Vacio(actual)) {
        if (nodo->Get_decimal() == actual->Get_decimal() && nodo->Get_Columna() == actual->Get_Columna()) {
            nodoADevolver = actual;
            cout << "Nodo encontrado maquina" << endl;
            encontrado = true;
            break;
        } else {
            InOrden();
        }
    }
}

void AVL::BuscarCaracter(string columnaCondicional, Nodo *nodo) {
    actual = raiz;
    Nodo *nodoADevolver = NULL;
    bool encontrado = false;
    while (!Vacio(actual)) {
        if (nodo->Get_caracter() == actual->Get_caracter() && nodo->Get_Columna() == actual->Get_Columna()) {
            nodoADevolver = actual;
            cout << "Nodo encontrado mamut" << endl;
            encontrado = true;
            break;
        } else {
            InOrden();
        }
    }
}*/

void AVL::BuscarCadena(string columnaCondicional, Nodo *nodo, Nodo *nodoParametro, string tipo) {
    int noTupla;
    if (tipo == "String") {
        if (nodo->Get_cadena() == nodoParametro->Get_cadena() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
        }
    } else if (tipo == "Integer") {
        if (nodo->Get_entero() == nodoParametro->Get_entero() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
        }
    } else if (tipo == "Double") {
        if (nodo->Get_decimal() == nodoParametro->Get_decimal() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
        }
    } else if (tipo == "Char") {
        if (nodo->Get_caracter() == nodoParametro->Get_caracter() && nodo->Get_Columna() == nodoParametro->Get_Columna() && nodo->Get_NombreTabla() == nodoParametro->Get_NombreTabla()) {
            noTupla = nodo->Get_tupla();
        }
    }
}

void AVL::BuscarDato(string columnaCondicional, Nodo *nodo, bool r, Nodo *nodoParametro, string tipo) {
    if (raiz != NULL) {
        if (r) nodo = raiz;
        if (nodo->Get_izquierda()) BuscarDato(columnaCondicional, nodo->Get_izquierda(), false, nodoParametro, tipo);
        BuscarCadena(columnaCondicional, nodo, nodoParametro, tipo);
        if (nodo->Get_derecha()) BuscarDato(columnaCondicional, nodo->Get_derecha(), false, nodoParametro, tipo);
    } else {
    }
}

void AVL::InOrden() {
    if (actual->Get_izquierda()) actual = actual->Get_izquierda();
    if (actual->Get_derecha()) actual = actual->Get_derecha();

}

Nodo* AVL::BuscarPorFuncion(int totalNodos, int nuevoNodo) {
    actual = raiz;
    FuncionesHash* funcion = new FuncionesHash();
    Nodo *nodoADevolver = NULL;
    int nodoAInsertar;
    while (!Vacio(actual)) {
        string tipo = actual->Get_tipo();
        if (tipo == "Integer") {
            int entero = actual->Get_entero();
            nodoAInsertar = funcion->funcionEntero(entero, totalNodos);

            VerificarFuncionesHash(nodoAInsertar, nuevoNodo);


        } else if (tipo == "Double") {
            double decimal = actual->Get_decimal();
            nodoAInsertar = funcion->funcionDecimal(decimal, totalNodos);

            VerificarFuncionesHash(nodoAInsertar, nuevoNodo);

        } else if (tipo == "Char") {
            char caracter = actual->Get_caracter();
            nodoAInsertar = funcion->funcionChar(caracter, totalNodos);

            VerificarFuncionesHash(nodoAInsertar, nuevoNodo);

        } else if (tipo == "String") {
            string cadena = actual->Get_cadena();
            nodoAInsertar = funcion->funcionString(cadena, totalNodos);

            VerificarFuncionesHash(nodoAInsertar, nuevoNodo);









        }
    }

}

Nodo* AVL::VerificarFuncionesHash(int funcionHash, int nuevoNodo) {
    if (funcionHash == nuevoNodo) {
        Nodo *nodoAInsertar = actual;

        NodoHash *na;


    } else {
        InOrden();
    }
}

AVL::AVL(const AVL& orig) {
}

AVL::~AVL() {
}

