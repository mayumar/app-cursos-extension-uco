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
#include "../recursos/recursos.h"
#include "../curso/curso.h"
#include <string>

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
		bool add_recurso (Recursos recurso);
		bool mod_recurso(std::string id);
		bool del_recurso(std::string id);
};

#endif /* ADMIN_RECURSOS_ADMINRECURSOS_H_ */
