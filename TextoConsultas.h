/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoConsultas.h
 * Author: luisitopapurey
 *
 * Created on 4 de abril de 2020, 12:10 PM
 */

#ifndef TEXTOCONSULTAS_H
#define TEXTOCONSULTAS_H
#include <string>
#include <vector>

using namespace std;

class TextoConsultas {
public:
    TextoConsultas();
    TextoConsultas(const TextoConsultas& orig);
    string* separacionTexto(string);
    int totalPalabras(string);
    virtual ~TextoConsultas();
private:

};

#endif /* TEXTOCONSULTAS_H */

