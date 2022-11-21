/*
 * estadisticas.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef ESTADISTICAS_ESTADISTICAS_H_
#define ESTADISTICAS_ESTADISTICAS_H_

#include <string>

class estadisticas {

private:

    std::string id_;
    std::string curso_;
    float valoracion_;
    std::string comentario_;

public:

	estadisticas();
	virtual ~estadisticas();

	estadisticas (std::string id="empty",
	              	  std::string curso= "empty",
					  float valoracion=0 ,
					  std::string comentario="empty");

	    inline std::string get_id(){return id_;}
	    inline std::string get_curso(){return curso_;}
	    inline float valoracion(){return valoracion_;}
	    inline std::string get_cometario(){return comentario_;}

	    inline void set_id (std::string id) {id_=id;}
	    inline void set_curso (std::string curso) {curso_=curso;}
	    float valoracion (float valoracion);
	    inline void set_comentario (std::string comentario) {comentario_=comentario;}

};

#endif /* ESTADISTICAS_ESTADISTICAS_H_ */
