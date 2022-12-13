/*
 * admincursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by: mayumar
 */

#ifndef ADMIN_CURSOS_ADMINCURSOS_H_
#define ADMIN_CURSOS_ADMINCURSOS_H_

#include "../usuario/usuario.h"
#include "../curso/curso.h"
#include "../ponente/ponente.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

class Admin_Cursos: public Usuario {

	public:

		inline Admin_Cursos(std::string nombre="empty",
							std::string apellidos= "empty",
							std::string dni="empty",
							std::string correo= "empty",
							std::string contraseña="empty",
							std::string usuario="empty"):Usuario(nombre, apellidos, dni,
																 correo, contraseña, usuario){}
																 
		inline ~Admin_Cursos(){}

		bool add_curso(Curso curso);
		bool mod_curso(std::string id);
		bool del_curso(std::string id);
    
    	bool add_usuario(Usuario usuario);
		bool mod_usuario(std::string dni);
		bool del_usuario(std::string dni);
    
		bool ver_lista_de_inscritos(std::string id);
		bool del_inscripcion(struct inscripciones inscripcion);

		bool add_ponente(Ponente ponente);
		bool mod_ponente(std::string dni);
		bool del_ponente(std::string dni);
};

struct inscripciones{
	std::string id_curso;
	std::string dni;
};

#endif /* ADMIN_CURSOS_ADMINCURSOS_H_ */
