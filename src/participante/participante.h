/*
 * participante.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by: mayumar
 */

#ifndef PARTICIPANTE_PARTICIPANTE_H_
#define PARTICIPANTE_PARTICIPANTE_H_

#include "../usuario/usuario.h"
#include "../admin_cursos/admincursos.h"
#include "../curso/curso.h"
#include <list>
#include <fstream>
#include <iostream>

class Participante: public Usuario {

	public:

		Participante(std::string nombre="empty",
					 std::string apellidos= "empty",
					 std::string dni="empty",
					 std::string correo= "empty",
					 std::string contraseña="empty",
					 std::string usuario="empty"):Usuario(nombre, apellidos, dni,
														  correo, contraseña, usuario){}
														  
		virtual ~Participante(){}

		bool inscribirse(std::string id_curso);
		bool ver_cursos_inscrito();

};

#endif /* PARTICIPANTE_PARTICIPANTE_H_ */
