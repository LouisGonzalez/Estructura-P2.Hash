/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graphviz.cpp
 * Author: luisGonzalez
 * 
 * Created on 12 de abril de 2020, 01:28 AM
 */

#include "Graphviz.h"
#include "NodoHash.h"
#include "Nodo.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Graphviz::Graphviz() {
}

void Graphviz::grafoGlobal(ListaTablas *&lista, TablaHash *&primero, TablaHash *&ultimo) {
    TablaHash *tablaAux = primero;
    ofstream salidaGraph("grafica.dot");
    salidaGraph << "digraph G { " << endl;
    salidaGraph << "rankdir=LR;" << endl;
    if (primero != NULL) {
        int contGeneral = 0;
        while (tablaAux != NULL) {
            salidaGraph << "node [shape=record,width=.1,height=.1];" << endl;
            NodoHash *nodoAux = tablaAux->Get_primero();
            int totalNodos = tablaAux->Get_TotalNodos();
            string arboles[totalNodos + 1];
            string *auxArbol = arboles;
            string nodosTabla;

            string datoConvertido = convertirIntString(contGeneral);

            int totalElementos = tablaAux->Get_TotalElementos();
            string idNodos[totalElementos + 1];
            string *auxArbol2 = idNodos;


            nodosTabla += "node" + datoConvertido + " [label = \"";
            if (tablaAux->Get_primero() != NULL) {
                while (nodoAux != NULL) {
                    AVL *arbolUsado = nodoAux->Get_AVL();
                    Nodo *aux = NULL;
                    nodosTabla += "<f";
                    string convertidoId = convertirIntString(nodoAux->Get_id());
                    nodosTabla += convertidoId;
                    nodosTabla += "> |";

                    InOrden2(aux, true, arbolUsado, auxArbol2, contGeneral);

                    InOrden(aux, true, arbolUsado, auxArbol, nodoAux->Get_id(), contGeneral);

                    nodoAux = nodoAux->Get_Siguiente();
                }

            }
            nodosTabla += "\" , height=2.5];";
            salidaGraph << nodosTabla << endl;


            for (int i = 0; i < totalElementos; i++) {
                if (idNodos[i] != "") {
                    salidaGraph << idNodos[i] << endl;
                }
            }
            salidaGraph << "\n" << endl;




            for (int i = 0; i < tablaAux->Get_TotalNodos(); i++) {
                if (arboles[i] != "") {
                    salidaGraph << arboles[i] << endl;
                }
            }
            salidaGraph << "\n" << endl;


            NodoHash *nodoAux2 = tablaAux->Get_primero();
            if (tablaAux->Get_primero() != NULL) {
                while (nodoAux2 != NULL) {
                    stringstream ss;
                    ss << nodoAux2->Get_id();
                    string convertido;
                    ss >> convertido;
                    stringstream ss2;
                    if (nodoAux2->Get_AVL()->Get_Raiz() != NULL) {
                        ss2 << nodoAux2->Get_AVL()->Get_Raiz()->Get_tupla();
                        string idConvertido = convertirIntString(nodoAux2->Get_AVL()->Get_NoArbol());
                        string id = convertirIntString(nodoAux2->Get_AVL()->Get_Raiz()->Get_id());
                        string convertido2;
                        ss2 >> convertido2;
                        string texto = "Nodo"+datoConvertido+idConvertido+id+convertido2;
                        
                        if (nodoAux2->Get_AVL()->Get_Raiz()->Get_izquierda() != NULL || nodoAux2->Get_AVL()->Get_Raiz()->Get_derecha() != NULL) {
                            salidaGraph << "node" << datoConvertido << ": f" << convertido << " -> " << texto << ";" << endl;
                        } else {
                            salidaGraph << "node" << datoConvertido << ": f" << convertido << " -> " << texto << ";" << endl;
                        }
                    }
                    nodoAux2 = nodoAux2->Get_Siguiente();
                }
            }




            tablaAux = tablaAux->Get_siguiente();
            contGeneral++;
        }
    }
    salidaGraph << "}" << endl;
    system("dot -Tpng grafica.dot -o imagen.png");

}

void Graphviz::dibujoGrafo(TablaHash *&tabla, string condicional) {
    // if(str)
    int contGeneral = 0;
    ofstream salidaGraph("grafica.dot");
    salidaGraph << "digraph G { " << endl;
    salidaGraph << "rankdir=LR;" << endl;
    salidaGraph << "node [shape=record,width=.1,height=.1];" << endl;
    int totalNodos = tabla->Get_TotalNodos();
    string arboles[totalNodos + 1];
    string *auxArbol = arboles;



    int totalElementos = tabla->Get_TotalElementos();
    string idNodos[totalElementos + 1];
    string *auxArbol2 = idNodos;


    string nodosTabla;
    nodosTabla += "node0 [label = \"";
    NodoHash *nodoAux = tabla->Get_primero();
    if (tabla->Get_primero() != NULL) {
        while (nodoAux != NULL) {
            AVL *arbolUsado = nodoAux->Get_AVL();
            Nodo *aux = NULL;
            nodosTabla += "<f";
            stringstream ss;
            ss << nodoAux->Get_id();
            string convertido;
            ss >> convertido;
            nodosTabla += convertido;
            nodosTabla += "> |";

            InOrden2(aux, true, arbolUsado, auxArbol2, contGeneral);





            InOrden(aux, true, arbolUsado, auxArbol, nodoAux->Get_id(), contGeneral);



            nodoAux = nodoAux->Get_Siguiente();

        }
    }
    nodosTabla += "\" , height=2.5];";
    salidaGraph << nodosTabla << endl;

    for (int i = 0; i < totalElementos; i++) {
        if (idNodos[i] != "") {
            salidaGraph << idNodos[i] << endl;
        }
    }
    salidaGraph << "\n" << endl;




    for (int i = 0; i < tabla->Get_TotalNodos(); i++) {
        if (arboles[i] != "") {
            salidaGraph << arboles[i] << endl;
        }
    }
    salidaGraph << "\n" << endl;


    NodoHash *nodoAux2 = tabla->Get_primero();
    if (tabla->Get_primero() != NULL) {
        while (nodoAux2 != NULL) {
            stringstream ss;
            ss << nodoAux2->Get_id();
            string convertido;
            ss >> convertido;
            stringstream ss2;
            if (nodoAux2->Get_AVL()->Get_Raiz() != NULL) {
                ss2 << nodoAux2->Get_AVL()->Get_Raiz()->Get_tupla();
                string convertido2;
                ss2 >> convertido2;

                string contadorConvertido = convertirIntString(contGeneral);
                string idConvertido = convertirIntString(nodoAux2->Get_AVL()->Get_NoArbol());
                string id = convertirIntString(nodoAux2->Get_AVL()->Get_Raiz()->Get_id());
                string puntero = "Nodo" + contadorConvertido + idConvertido+ id+ convertido2;
                if (nodoAux2->Get_AVL()->Get_Raiz()->Get_izquierda() != NULL || nodoAux2->Get_AVL()->Get_Raiz()->Get_derecha() != NULL) {
                    salidaGraph << "node0" << ": f" << convertido << " -> " << puntero << ";" << endl;
                } else {
                    salidaGraph << "node0" << ": f" << convertido << " -> " << puntero << ";" << endl;
                }
            }
            nodoAux2 = nodoAux2->Get_Siguiente();
        }
    }

    salidaGraph << "}" << endl;
    system("dot -Tpng grafica.dot -o imagen.png");
    //system("nohup display /home/luisitopapurey/Escritorio/Estructura de datos/P2.BaseDatosHash/imagen.png");


}

string* Graphviz::InOrden2(Nodo *nodo, bool r, AVL *arbol, string *vector, int contador) {
    if (arbol->Get_Raiz() != NULL) {
        if (r) {
            nodo = arbol->Get_Raiz();
            string tuplaConvertido = convertirIntString(nodo->Get_tupla());
            string idConvertido = convertirIntString(arbol->Get_NoArbol());
            string id = convertirIntString(nodo->Get_id());
            string contadorConvertido = convertirIntString(contador);
            string tipo = nodo->Get_tipo();
            string textoADevolver = verificarTipo(tipo, nodo);
            vector[nodo->Get_tupla()] += "Nodo" + contadorConvertido + idConvertido+ id+ tuplaConvertido + "[label = \"<f0>" + textoADevolver + "\" ];\n";

        }
        if (nodo->Get_izquierda()) {
            string contadorConvertido = convertirIntString(contador);
            string tuplaConvertido = convertirIntString(nodo->Get_izquierda()->Get_tupla());
            string idConvertido = convertirIntString(arbol->Get_NoArbol());
            string tipo = nodo->Get_izquierda()->Get_tipo();
            string id = convertirIntString(nodo->Get_izquierda()->Get_id());

            string textoADevolver = verificarTipo(tipo, nodo->Get_izquierda());

            vector[nodo->Get_tupla()] += "Nodo" + contadorConvertido + idConvertido+ id+ tuplaConvertido + "[label = \"<f0>" + textoADevolver + "\" ];\n";
            InOrden2(nodo->Get_izquierda(), false, arbol, vector, contador);
        }

        if (nodo->Get_derecha()) {
            string contadorConvertido = convertirIntString(contador);
            string idConvertido = convertirIntString(arbol->Get_NoArbol());
            string id = convertirIntString(nodo->Get_derecha()->Get_id());
            string tuplaConvertido = convertirIntString(nodo->Get_derecha()->Get_tupla());
            string tipo = nodo->Get_derecha()->Get_tipo();

            string textoADevolver = verificarTipo(tipo, nodo->Get_derecha());
            vector[nodo->Get_tupla()] += "Nodo" + contadorConvertido +idConvertido+ id+ tuplaConvertido + "[label = \"<f0>" + textoADevolver + "\"];\n";
            InOrden2(nodo->Get_derecha(), false, arbol, vector, contador);
        }

    }
    return vector;
}

string* Graphviz::InOrden(Nodo *nodo, bool r, AVL *arbol, string *vector, int id, int contador) {

    if (arbol->Get_Raiz() != NULL) {
        if (r) nodo = arbol->Get_Raiz();
        if (nodo->Get_izquierda()) {
          

            string tuplaConvertida = convertirIntString(nodo->Get_tupla());
            string idConvertido = convertirIntString(arbol->Get_NoArbol());
            string idx = convertirIntString(nodo->Get_id());
            string tuplaConvertida2 = convertirIntString(nodo->Get_izquierda()->Get_tupla());
            string idConvertido2 = convertirIntString(arbol->Get_NoArbol());
            string idx2 = convertirIntString(nodo->Get_izquierda()->Get_id());
            string contadorConvertido = convertirIntString(contador);
            


            vector[id] += "Nodo" + contadorConvertido + idConvertido+ idx+tuplaConvertida + " -> " + "Nodo" + contadorConvertido + idConvertido2+ idx2+ tuplaConvertida2 + ";\n";


            InOrden(nodo->Get_izquierda(), false, arbol, vector, id, contador);
        }
        //PONER EL METODO QUE VAYA DIBUJANDO EL ARBOL POCO A POCO

        if (nodo->Get_derecha()) {

          
            string tuplaConvertida = convertirIntString(nodo->Get_tupla());
            string idConvertido = convertirIntString(arbol->Get_NoArbol());
            string idx = convertirIntString(nodo->Get_id());
            string tuplaConvertida2 = convertirIntString(nodo->Get_derecha()->Get_tupla());
            string idConvertido2 = convertirIntString(arbol->Get_NoArbol());
            string idx2 = convertirIntString(nodo->Get_derecha()->Get_id());
            string contadorConvertido = convertirIntString(contador);

          
            vector[id] += "Nodo" + contadorConvertido + idConvertido +idx + tuplaConvertida + " -> " + "Nodo" + contadorConvertido + idConvertido2+ idx2+ tuplaConvertida2 + ";\n";
            InOrden(nodo->Get_derecha(), false, arbol, vector, id, contador);
        }

    }
    return vector;
}

string Graphviz::verificarTipo(string tipo, Nodo *nodo) {
    string textoADevolver = "";
    if (tipo == "Integer") {
        int entero = nodo->Get_entero();
        textoADevolver = convertirIntString(entero);
    } else if (tipo == "Double") {
        double decimal = nodo->Get_decimal();
        textoADevolver = convertirDoubleString(decimal);
    } else if (tipo == "Char") {
        char caracter = nodo->Get_caracter();
        textoADevolver = convertirCharString(caracter);
    } else if (tipo == "String") {
        string cadena = nodo->Get_cadena();
        textoADevolver = cadena;
    }
    return textoADevolver;
}

string Graphviz::convertirIntString(int valor) {
    stringstream ss;
    ss << valor;
    string convertido;
    ss >> convertido;
    return convertido;
}

string Graphviz::convertirDoubleString(double decimal) {
    stringstream ss;
    ss << decimal;
    string convertido;
    ss >> convertido;
    return convertido;
}

string Graphviz::convertirCharString(char caracter) {
    stringstream ss;
    ss << caracter;
    string convertido;
    ss >> convertido;
    return convertido;
}

Graphviz::Graphviz(const Graphviz& orig) {
}

Graphviz::~Graphviz() {
}

