/*
 * recursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef RECURSOS_RECURSOS_H_
#define RECURSOS_RECURSOS_H_

#include <string>

class recursos {

private:

    std::string curso_;
    std::string tipo_;
    int aforo_;

public:

	recursos();
	virtual ~recursos();

	recursos (std::string curso="empty",
	          std::string tipo= "empty",
	          int aforo=0);

	    inline std::string get_curso(){return curso_;}
	    inline std::string get_tipo(){return tipo_;}
	    inline int aforo(){return aforo_;}

	    inline void set_curso (std::string curso) {curso_=curso;}
	    inline void set_tipo (std::string tipo) {tipo_=tipo;}
	    int aforo (int aforo);

};

#endif /* RECURSOS_RECURSOS_H_ */
