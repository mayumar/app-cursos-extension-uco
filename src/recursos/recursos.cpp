/*
 * recursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "recursos.h"
#include <iostream>

Recursos Recursos::operator=(Recursos &r){
    id_=r.id_;
    curso_=r.curso_;
    tipo_=r.tipo_;
    aforo_=r.aforo_;

    return *this;
}

std::istream &operator>>(std::istream &stream, Recursos &r){
    
    std::cout<<"ID del recurso: ";
    stream>>r.id_;
    std::cout<<"ID del curso asociado: ";
    stream>>r.curso_;
    std::cout<<"Tipo de recurso: ";
    stream>>r.tipo_;
    std::cout<<"Aforo (en caso de no ser un aula, escribir 0): ";
    stream>>r.aforo_;

    return stream;
}

std::istream &operator-(std::istream &stream, Recursos &r){
    stream>>r.id_;
    stream>>r.curso_;
    stream>>r.tipo_;
    stream>>r.aforo_;

    return stream;
}

std::ostream &operator<<(std::ostream &stream, Recursos &r){
    stream<<r.id_;
    stream<<r.curso_;
    stream<<r.tipo_;
    stream<<r.aforo_;

    return stream;
}