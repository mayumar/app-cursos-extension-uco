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
};

#endif /* ADMIN_CURSOS_ADMINCURSOS_H_ */