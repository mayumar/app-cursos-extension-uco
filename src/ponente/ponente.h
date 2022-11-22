/*
 * ponente.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified: mayumar
 */

#ifndef PONENTE_PONENTE_H_
#define PONENTE_PONENTE_H_

#include <string>
#include "../usuario/usuario.h"

class Ponente: public Usuario {

	private:

		std::string curso_;

	public:

		inline Ponente (std::string nombre="empty",
						std::string apellidos="empty",
						std::string dni="empty",
						std::string correo="empty",
						std::string contraseña="empty",
						std::string usuario="empty",
						std::string curso="empty"):Usuario(nombre, apellidos, dni,
														   correo, contraseña,
														   usuario), curso_(curso){}
    inline ~Ponente(){}

	inline std::string get_curso() const {return curso_;}

	inline void set_curso (std::string curso) {curso_=curso;}
};

#endif /* PONENTE_PONENTE_H_ */
