/*
 * curso.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by: mayumar
 */

#ifndef CURSO_CURSO_H_
#define CURSO_CURSO_H_

#include <string>
#include <fstream>

class Curso {

	private:

		std::string id_;
		std::string nombre_;
		std::string descripcion_;
		std::string fechaInicio_; //DD/MM/YY
		std::string fechaFinal_; //DD/MM/YY
		int plazasCubiertas_;
		int plazasMax_;
		float alcance_;

	public:

		inline Curso(std::string id="empty",
					 std::string nombre="empty",
					 std::string descripcion= "empty",
					 std::string fechaInicio= "empty",
					 std::string fechaFinal="empty",
					 int plazasCubiertas=0,
					 int plazasMax=0):id_(id), nombre_(nombre), descripcion_(descripcion),
									  fechaInicio_(fechaInicio), fechaFinal_(fechaFinal),
									  plazasCubiertas_(plazasCubiertas), plazasMax_(plazasMax),
									  alcance_(0.0){}
									  
		inline ~Curso(){}

		inline std::string get_id() const {return id_;}
		inline std::string get_descripcion() const {return descripcion_;}
		inline std::string get_nombre() const {return nombre_;}
		inline std::string get_fechaInicio() const {return fechaInicio_;}
		inline std::string get_fechaFinal() const {return fechaFinal_;}
		inline float get_alcance() {alcance_=plazasCubiertas_/(plazasMax_*1.0); return alcance_;}
		inline int get_plazasCubiertas() const {return plazasCubiertas_;}
		inline int get_plazasMax() const {return plazasMax_;}

		inline void set_id (std::string id) {id_=id;}
		inline void set_descripcion (std::string descripcion) {descripcion_=descripcion;}
		inline void set_nombre (std::string nombre) {nombre_=nombre;}
		inline void set_fechaInicio (std::string fechaInicio) {fechaInicio_=fechaInicio;}
		inline void set_fechaFinal (std::string fechaFinal) {fechaFinal_=fechaFinal;}
		inline void set_plazasCubiertas (int plazasCubiertas) {plazasCubiertas_=plazasCubiertas;}
		inline void set_plazasMax (int plazasMax) {plazasMax_=plazasMax;}
		inline void actualizar_alcance () {alcance_=plazasCubiertas_/(plazasMax_*1.0);}

		Curso operator=(Curso &c);

		friend std::istream &operator>>(std::istream &stream, Curso &c);
		friend std::istream &operator-(std::istream &stream, Curso &c);
		friend std::ostream &operator<<(std::ostream &stream, Curso &c);

};

#endif /* CURSO_CURSO_H_ */
