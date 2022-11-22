/*
 * recursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by : mayumar
 */

#ifndef RECURSOS_RECURSOS_H_
#define RECURSOS_RECURSOS_H_

#include <string>

class Recursos {

	private:

		std::string curso_;
		std::string tipo_;
		int aforo_;

	public:

		inline Recursos (std::string curso="empty",
						 std::string tipo= "empty",
						 int aforo=0): curso_(curso), tipo_(tipo), aforo_(aforo){}

		inline ~Recursos(){}

		inline std::string get_curso() const {return curso_;}
		inline std::string get_tipo() const {return tipo_;}
		inline int set_aforo() const {return aforo_;}

		inline void set_curso (std::string curso) {curso_=curso;}
		inline void set_tipo (std::string tipo) {tipo_=tipo;}
		inline void set_aforo (int aforo) {aforo_=aforo;}

};

#endif /* RECURSOS_RECURSOS_H_ */
