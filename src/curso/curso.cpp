/*
 * curso.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "curso.h"
#include <iostream>

Curso Curso::operator=(Curso &c){
	id_=c.id_;
	nombre_=c.nombre_;
	descripcion_=c.descripcion_;
	fechaInicio_=c.fechaInicio_;
	fechaFinal_=c.fechaFinal_;
	plazasCubiertas_=c.plazasCubiertas_;
	plazasMax_=c.plazasMax_;
	alcance_=c.alcance_;

	return *this;
}

std::istream &operator>>(std::istream &stream, Curso &c){

	std::cout<<"Id: ";
	stream>>c.id_;
	stream.get();
	std::cout<<"Nombre: ";
	getline(stream, c.nombre_);
	std::cout<<"Descripcion: ";
	getline(stream, c.descripcion_);
	std::cout<<"Fecha de Inicio: ";
	stream>>c.fechaInicio_;
	std::cout<<"Fecha de Finalización: ";
	stream>>c.fechaFinal_;
	std::cout<<"Plazas cubiertas: ";
	stream>>c.plazasCubiertas_;
	std::cout<<"Plazas máximas: ";
	stream>>c.plazasMax_;
	stream.get();
	c.get_alcance();

	return stream;
}

std::istream &operator-(std::istream &stream, Curso &c){
	stream>>c.id_;
	stream.get();
	getline(stream, c.nombre_);
	getline(stream, c.descripcion_);
	stream>>c.fechaInicio_;
	stream>>c.fechaFinal_;
	stream>>c.plazasCubiertas_;
	stream>>c.plazasMax_;
	stream>>c.alcance_;
	stream.get();

	return stream;
}

std::ostream &operator<<(std::ostream &stream, Curso &c){
	stream<<c.id_<<std::endl;
	stream<<c.nombre_<<std::endl;
	stream<<c.descripcion_<<std::endl;
	stream<<c.fechaInicio_<<std::endl;
	stream<<c.fechaFinal_<<std::endl;
	stream<<c.plazasCubiertas_<<std::endl;
	stream<<c.plazasMax_<<std::endl;
	stream<<c.alcance_<<std::endl;

	return stream;
}
