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

class Ponente{

	private:

		std::string nombre_;
		std::string apellidos_;
		std::string dni_;
		std::string curso_;

	public:

		inline Ponente (std::string nombre="empty",
						std::string apellidos="empty",
						std::string dni="empty",
						std::string curso="empty"):nombre_(nombre), apellidos_(apellidos),
												   dni_(dni), curso_(curso){}

		inline ~Ponente(){}

		inline std::string get_nombre() const {return nombre_;}
		inline std::string get_apellidos() const {return apellidos_;}
		inline std::string get_dni() const {return dni_;}
		inline std::string get_curso() const {return curso_;}

		inline void set_nombre (std::string nombre) {nombre_=nombre;}
		inline void set_apellidos (std::string apellidos) {apellidos_=apellidos;}
		inline void set_dni (std::string dni) {dni_=dni;}
		inline void set_curso (std::string curso) {curso_=curso;}
};

#endif /* PONENTE_PONENTE_H_ */
