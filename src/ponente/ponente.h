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

		std::string curso_;
		std::string dni_;
		std::string nombre_;
		std::string apellidos_;
		
	public:

		inline Ponente (std::string curso="empty",
						std::string dni="empty",				
						std::string nombre="empty",
						std::string apellidos="empty"):curso_(curso), dni_(dni),
													   nombre_(nombre), apellidos_(apellidos){}

		inline ~Ponente(){}

		inline std::string get_nombre() const {return nombre_;}
		inline std::string get_apellidos() const {return apellidos_;}
		inline std::string get_dni() const {return dni_;}
		inline std::string get_curso() const {return curso_;}

		inline void set_nombre (std::string nombre) {nombre_=nombre;}
		inline void set_apellidos (std::string apellidos) {apellidos_=apellidos;}
		inline void set_dni (std::string dni) {dni_=dni;}
		inline void set_curso (std::string curso) {curso_=curso;}

		Ponente operator=(Ponente &p);

		friend std::istream &operator>>(std::istream &stream, Ponente &p);
		friend std::istream &operator-(std::istream &stream, Ponente &p);
		friend std::ostream &operator<<(std::ostream &stream, Ponente &p);
};

#endif /* PONENTE_PONENTE_H_ */
