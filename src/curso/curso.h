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

class Curso {

	private:

		std::string id_;
		std::string descripcion_;
		std::string nombre_;
		std::string fechaInicio_;
		std::string fechaFinal_;
		float alcance_;
		int plazasCubiertas_;
		int plazasMax_;

	public:

		inline Curso(std::string id="empty",
					 std::string descripcion= "empty",
					 std::string nombre="empty",
					 std::string fechaInicio= "empty",
					 std::string fechaFinal="empty",
					 float alcance=0.0,
					 int plazasCubiertas=0,
					 int plazasMax=0):id_(id), descripcion_(descripcion), nombre_(nombre),
									  fechaInicio_(fechaInicio), fechaFinal_(fechaFinal),
									  alcance_(alcance), plazasCubiertas_(plazasCubiertas),
									  plazasMax_(plazasMax){}
		inline ~Curso(){}

		inline std::string get_id() const {return id_;}
		inline std::string get_descripcion() const {return descripcion_;}
		inline std::string get_nombre() const {return nombre_;}
		inline std::string get_fechaInicio() const {return fechaInicio_;}
		inline std::string get_fechaFinal() const {return fechaFinal_;}
		inline float get_alcance() {alcance_=plazasCubiertas_/plazasMax_; return alcance_;}
		inline int get_plazasCubiertas() const {return plazasCubiertas_;}
		inline int get_plazasMax() const {return plazasMax_;}

		inline void set_id (std::string id) {id_=id;}
		inline void set_descripcion (std::string descripcion) {descripcion_=descripcion;}
		inline void set_nombre (std::string nombre) {nombre_=nombre;}
		inline void set_address (std::string fechaInicio) {fechaInicio_=fechaInicio;}
		inline void set_province (std::string fechaFinal) {fechaFinal_=fechaFinal;}
		inline void set_plazasCubiertas (int plazasCubiertas) {plazasCubiertas_=plazasCubiertas;}
		inline void set_plazasMax (int plazasMax) {plazasMax_=plazasMax;}

};

#endif /* CURSO_CURSO_H_ */