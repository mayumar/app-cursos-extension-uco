/*
 * estadisticas.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified by: mayumar
 */

#ifndef ESTADISTICAS_ESTADISTICAS_H_
#define ESTADISTICAS_ESTADISTICAS_H_

#include <string>

class Estadisticas {

	private:

		std::string id_;
		std::string curso_;
		float valoracion_;
		std::string comentario_;

	public:

		inline Estadisticas (std::string id="empty",
							 std::string curso= "empty",
							 float valoracion=0 ,
							 std::string comentario="empty"):id_(id), curso_(curso),
															 valoracion_(valoracion),
															 comentario_(comentario){}
		inline ~Estadisticas(){}

	    inline std::string get_id() const {return id_;}
	    inline std::string get_curso() const {return curso_;}
	    inline float get_valoracion() const {return valoracion_;}
	    inline std::string get_cometario() const {return comentario_;}

	    inline void set_id (std::string id) {id_=id;}
	    inline void set_curso (std::string curso) {curso_=curso;}

};

#endif /* ESTADISTICAS_ESTADISTICAS_H_ */
