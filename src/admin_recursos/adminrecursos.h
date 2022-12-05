/*
 * adminrecursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by: mayumar
 */

#ifndef ADMIN_RECURSOS_ADMINRECURSOS_H_
#define ADMIN_RECURSOS_ADMINRECURSOS_H_

#include "../usuario/usuario.h"

class Admin_Recursos: public Usuario {

	public:

		inline Admin_Recursos(std::string nombre="empty",
							  std::string apellidos= "empty",
							  std::string dni="empty",
							  std::string correo= "empty",
							  std::string contraseña="empty",
							  std::string usuario="empty"):Usuario(nombre, apellidos, dni, correo,
																   contraseña, usuario){}
		inline ~Admin_Recursos(){}
};

#endif /* ADMIN_RECURSOS_ADMINRECURSOS_H_ */
