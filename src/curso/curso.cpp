/*
 * curso.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "curso.h"
#include <iostream>

std::istream &operator>>(std::istream &stream, Curso &c){
	stream>>c.id_;
	stream>>c.nombre_;
	stream>>c.descripcion_;
	stream>>c.fechaInicio_;
	stream>>c.fechaFinal_;
	stream>>c.plazasCubiertas_;
	stream>>c.plazasMax_;
	stream>>c.alcance_;

	return stream;
}
