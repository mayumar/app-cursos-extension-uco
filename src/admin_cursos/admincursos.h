/*
 * admincursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef ADMIN_CURSOS_ADMINCURSOS_H_
#define ADMIN_CURSOS_ADMINCURSOS_H_

#include "../usuario/usuario.h"

class admin_cursos: public usuario {
public:
	admin_cursos(std::string nombre="empty",
            std::string apellidos= "empty",
            std::string dni="empty",
            std::string correo= "empty",
            std::string contraseña="empty",
            std::string nom_usuario="empty"):usuario(nombre, apellidos, dni, correo, contraseña, nom_usuario){};
	virtual ~admin_cursos();
};

#endif /* ADMIN_CURSOS_ADMINCURSOS_H_ */
