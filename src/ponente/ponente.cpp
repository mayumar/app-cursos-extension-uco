/*
 * ponente.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "ponente.h"
#include <iostream>

Ponente Ponente::operator=(Ponente &p){
    nombre_=p.nombre_;
    apellidos_=p.apellidos_;
    dni_=p.dni_;
    curso_=p.curso_;

    return *this;
}

std::istream &operator>>(std::istream &stream, Ponente &p){

    std::cout<<"ID del curso: ";
    stream>>p.curso_;
    std::cout<<"DNI del ponente: ";
    stream>>p.dni_;
    stream.get();
    std::cout<<"Nombre del ponente: ";
    getline(stream, p.nombre_);
    std::cout<<"Apellidos del ponente: ";
    getline(stream, p.apellidos_);

    return stream;
}

std::istream &operator-(std::istream &stream, Ponente &p){
    stream>>p.curso_;
    stream>>p.dni_;
    stream.get();
    getline(stream, p.nombre_);
    getline(stream, p.apellidos_);

    return stream;
}

std::ostream &operator<<(std::ostream &stream, Ponente &p){
    stream<<p.curso_<<std::endl;
    stream<<p.dni_<<std::endl;
    stream<<p.nombre_<<std::endl;
    stream<<p.apellidos_<<std::endl;

    return stream;
}