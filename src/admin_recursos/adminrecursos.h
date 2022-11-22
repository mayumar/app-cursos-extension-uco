/*
 * adminrecursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef ADMIN_RECURSOS_ADMINRECURSOS_H_
#define ADMIN_RECURSOS_ADMINRECURSOS_H_

#include "../usuario/usuario.h"

class admin_recursos: public usuario {
public:
	admin_recursos(std::string nombre="empty",
    std::string apellidos= "empty",
    std::string dni="empty",
    std::string correo= "empty",
    std::string contraseña="empty",
    std::string nom_usuario="empty"):usuario(nombre, apellidos, dni, correo, contraseña, nom_usuario){};
	virtual ~admin_recursos();
};

#endif /* ADMIN_RECURSOS_ADMINRECURSOS_H_ */
