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
#include <fstream>

class Recursos{

	private:
		std::string id_;
		std::string curso_;
		std::string tipo_;
		int aforo_;

	public:

		inline Recursos (std::string id="empty",
						 std::string curso="empty",
						 std::string tipo= "empty",
						 int aforo=0): id_(id), curso_(curso), tipo_(tipo), aforo_(aforo){}

		inline ~Recursos(){}

		inline std::string get_curso() const {return curso_;}
		inline std::string get_tipo() const {return tipo_;}
		inline int get_aforo() const {return aforo_;}
		inline std::string get_id() const{ return id_;}

		inline void set_curso (std::string curso) {curso_=curso;}
		inline void set_tipo (std::string tipo) {tipo_=tipo;}
		inline void set_aforo (int aforo) {aforo_=aforo;}
		inline void set_id(std::string id){id_=id;}

		Recursos operator=(Recursos &r);

		friend std::istream &operator>>(std::istream &stream, Recursos &r);
		friend std::istream &operator-(std::istream &stream, Recursos &r);
		friend std::ostream &operator<<(std::ostream &stream, Recursos &r);

};

#endif /* RECURSOS_RECURSOS_H_ */
