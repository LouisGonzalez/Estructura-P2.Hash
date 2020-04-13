/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luisGonzalez
 *
 * Created on 4 de abril de 2020, 11:35 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iosfwd>
#include <vector>
#include <string>
#include "TextoConsultas.h"
#include "ListaTablas.h"
#include <fstream>
#include "TablaHash.h"
#include "SeparacionPalabras.h"
#include "OperacionesInsercion.h"
#include "OperacionesSeleccion.h"
#include "FuncionesHash.h"
#include "Graphviz.h"


using namespace std;

/*
 * 
 */



int main() {
    bool peticiones = true;
    TextoConsultas *consultaTexto = new TextoConsultas();
    ListaTablas *tablasHash = new ListaTablas();
    FuncionesHash *funciones = new FuncionesHash();
    SeparacionPalabras *separacion = new SeparacionPalabras();
    OperacionesInsercion *insercion = new OperacionesInsercion();
    OperacionesSeleccion *seleccion = new OperacionesSeleccion();
    //Tabla que se usara para las consultas 
    TablaHash *tablaUsar = NULL;
    //NODOS PRIMERO Y ULTIMO DE LA LISTA DE TABLAS 
    TablaHash *primero = NULL, *ultimo = NULL;
    while (peticiones) {
        cout << "Bienvenido a la base de datos: Porfavor ingrese una peticion" << endl;
        string textoAnalizar;
        getline(cin, textoAnalizar);

        int contadorPalabras = consultaTexto->totalPalabras(textoAnalizar);

        string *arregloPalabras;
        arregloPalabras = consultaTexto->separacionTexto(textoAnalizar);

        if (*(arregloPalabras + 0) == "use") {
            tablaUsar = tablasHash->buscarTabla(primero, ultimo, *(arregloPalabras + 1));

            if (tablaUsar != NULL) {
                cout << tablaUsar->Get_nombreTabla() << " esta es la tabla que estas usando justo ahora" << endl;
            }
        } else if (*(arregloPalabras + 0) == "CREATE") {
            SeparacionPalabras *separacion = new SeparacionPalabras();
            TablaHash *tabla = new TablaHash();
            tabla->Set_nombreTabla(*(arregloPalabras + 2));
            string columnas = "";
            for (int i = 3; i <= contadorPalabras; i++) {
                columnas += *(arregloPalabras + i) + " ";
            }
            tabla->Set_NombreColumnas(columnas);
            int totalColumnas = ((contadorPalabras - 3)) / 2;
            tabla->Set_Columnas(totalColumnas);
            //CREA LOS PRIMEROS 5 CAMPOS DE LA TABLA
            tabla->crearNodosPrincipales();

            tablasHash->insertarTabla(primero, ultimo, tabla);
            separacion->acumuladorColumnas(tabla, tabla->Get_NombreColumna());
            tablaUsar = tabla;
        } else if (*(arregloPalabras + 0) == "SELECT") {
            TablaHash *tablaSelects = NULL;
            string nombreTabla = *(arregloPalabras + 3);
            tablaSelects = tablasHash->buscarTabla(primero, ultimo, nombreTabla);
            string condicional = "";
            string columnaCondicional = "";
            if (contadorPalabras >= 7) {
                condicional = *(arregloPalabras + 7);
                columnaCondicional = *(arregloPalabras + 5);
            }
            if (*(arregloPalabras + 1) == "*") {

            } else {
                string columnaParametro = *(arregloPalabras + 1);
                string delim = " ";
                string *datosConvertidos;
                datosConvertidos = separacion->separacionColumnas(tablaSelects->Get_NombreColumna(), delim, " ");
                int totalDatos = separacion->totalColumnas(tablaSelects->Get_NombreColumna(), " ") - 2;
                string tipoColumna[totalDatos / 2];
                string nombreColumna[totalDatos / 2];
                int aux = 0;
                int aux2 = 0;
                if (totalDatos > 2) {
                    for (int i = 0; i < totalDatos; i++) {
                        if (i % 2 == 0) {
                            tipoColumna[aux2] = *(datosConvertidos + i);
                            aux2++;
                        } else {
                            nombreColumna[aux] = *(datosConvertidos + i);
                            //QUITA LAS COMAS Y PARENTESIS DE LOS VALORES
                            nombreColumna[aux] = separacion->quitarParentesisB(nombreColumna[aux]);
                            aux++;
                        }
                    }
                    //QUITA EL PARENTESIS DEL PRIMER VALOR
                    tipoColumna[0] = separacion->quitarParentesisA(tipoColumna[0]);
                } else {
                    tipoColumna[0] = *(datosConvertidos + 0);
                    tipoColumna[0] = separacion->quitarParentesisA(tipoColumna[0]);
                    nombreColumna[0] = *(datosConvertidos + 1);
                    nombreColumna[0] = separacion->quitarParentesisB(nombreColumna[0]);
                }
                string tipo = seleccion->verificarTipoColumna(tipoColumna, nombreColumna, columnaCondicional, totalDatos / 2);
                seleccion->seleccionarNodos(tipo, arregloPalabras, tablaSelects);

            }






        } else if (*(arregloPalabras + 0) == "INSERT" && *(arregloPalabras + 1) == "INTO") {
            if (tablaUsar == NULL) {
            } else {
                string columna, dato, *columnas, *datos;
                columnas = &columna;
                datos = &dato;
                int contadorColumnas = separacion->totalColumnas(*(arregloPalabras + 3), ",");
                columnas = separacion->separacionColumnas(*(arregloPalabras + 3), ",", ",");
                if (contadorColumnas > 1) {
                    *(columnas + 0) = separacion->quitarParentesisA(*(columnas + 0));
                    *(columnas + contadorColumnas - 1) = separacion->quitarParentesisB(*(columnas + contadorColumnas - 1));
                } else {
            
                    *(columnas + 0) = separacion->quitarParentesis(*(columnas + 0));
                }
                int contadorDatos = separacion->totalColumnas(*(arregloPalabras + 5), ",");
                datos = separacion->separacionColumnas2(*(arregloPalabras + 5), ",", ",");
                if (contadorDatos > 1) {
                    *(datos + 0) = separacion->quitarParentesisA(*(datos + 0));
                    *(datos + contadorDatos - 1) = separacion->quitarParentesisB(*(datos + contadorDatos - 1));
                } else {
                    *(datos + 0) = separacion->quitarParentesis(*(datos + 0));
            
                }
                insercion->verificadorColumnas(tablaUsar->Get_NombreColumna(), columnas, datos, tablaUsar->Get_TotalNodos(), tablaUsar);
            }
        } else if (*(arregloPalabras + 0) == "GRAPHIC") {
            string condicional = *(arregloPalabras + 1);
            Graphviz *graficas = new Graphviz();
            if (*(arregloPalabras + 1) == "all") {

                graficas->grafoGlobal(tablasHash, primero, ultimo);


            } else {

                TablaHash *tablaGraficas = NULL;
                string nombreTabla = *(arregloPalabras + 1);
                tablaGraficas = tablasHash->buscarTabla(primero, ultimo, nombreTabla);

                graficas->dibujoGrafo(tablaGraficas, condicional);

            }
        } else if (*(arregloPalabras + 0) == "REPORTS") {
            if (primero != NULL) {
                SeparacionPalabras *separacion2 = new SeparacionPalabras();
                TablaHash *tablaReporte = NULL;
                string nombreTabla;
               char valor;
                cout << "1. Cantidad de datos dentro de la base de datos." << endl;
                cout << "2. Cantidad de filas de un mismo tipo de dato en una tabla." << endl;
                cout << "3. Cantidad de todas las columnas" << endl;
                cin >> valor;
                switch (valor) {
                    case '1':
                        cout << "1" << endl;
                        tablasHash->verTotalElementos(primero, ultimo);
                        break;
                    case '2':
                        
                        cout << "Escriba el nombre de la tabla donde desea buscar." << endl;
                        cin >> nombreTabla;
                        
                        
                        tablaReporte = tablasHash->buscarTabla(primero, ultimo, nombreTabla);
                        if (tablaReporte != NULL) {
                        
                            tablaReporte->verificarTotalColumnas(tablaReporte);
                        
                        } else {
                            cout << "Tabla no encontrada" << endl;
                        }
                        break;
                    case '3':
                        cout << "3" << endl;
                        tablasHash->verColumnasTotales(primero, ultimo);
                        break;
                    default:
                        cout << "Has ingresado una opcion invalida." << endl;
                        break;
                }

            } else {
                cout << "No hay tablas guardadas dentro de la base de datos." << endl;
            }
        } else if(*(arregloPalabras + 0) == "OUT"){
            cout << "Gracias por usar nuestro servicio" <<endl;
            peticiones = false;
        }



    }


    
    return 0;
}

