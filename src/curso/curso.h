/*
 * curso.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef CURSO_CURSO_H_
#define CURSO_CURSO_H_

#include <string>

class curso {

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

	curso();
	virtual ~curso();

	curso  (std::string id="empty",
	            std::string descripcion= "empty",
	            std::string nombre="empty",
	            std::string fechaInicio= "empty",
	            std::string fechaFinal="empty",
	            float alcance=0,
				int plazasCubiertas=0,
	    		int plazasMax=0);

	    inline std::string get_id(){return id_;}
	    inline std::string get_descripcion(){return descripcion_;}
	    inline std::string get_nombre(){return nombre_;}
	    inline std::string get_fechaInicio(){return fechaInicio_;}
	    inline std::string get_fechaFinal(){return fechaFinal_;}
	    inline float alcance(){return alcance_;}
	    inline int plazasCubiertas(){return plazasCubiertas_;}
	    inline int plazasMax(){return plazasMax_;}

	    inline void set_id (std::string id) {id_=id;}
	    inline void set_descripcion (std::string descripcion) {descripcion_=descripcion;}
	    inline void set_nombre (std::string nombre) {nombre_=nombre;}
	    inline void set_address (std::string fechaInicio) {fechaInicio_=fechaInicio;}
	    inline void set_province (std::string fechaFinal) {fechaFinal_=fechaFinal;}
	    float alcance (float alcance);
	    int plazasCubiertas (int plazasCubiertas);
	    int plazasMax (int plazasMax);

};

#endif /* CURSO_CURSO_H_ */
