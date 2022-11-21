/*
 * admincursos.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef ADMIN_CURSOS_ADMINCURSOS_H_
#define ADMIN_CURSOS_ADMINCURSOS_H_

#include "usuario.h"

class admin_cursos: public usuario {
public:
	admin_cursos();
	virtual ~admin_cursos();
};

#endif /* ADMIN_CURSOS_ADMINCURSOS_H_ */
