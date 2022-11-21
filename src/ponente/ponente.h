/*
 * ponente.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef PONENTE_PONENTE_H_
#define PONENTE_PONENTE_H_

#include <string>

class ponente {

private:

    std::string curso_;

public:

	ponente();
	virtual ~ponente();

	ponente (std::string curso="empty");

		inline std::string get_curso(){return curso_;}

		inline void set_curso (std::string curso) {curso_=curso;}
};

#endif /* PONENTE_PONENTE_H_ */
