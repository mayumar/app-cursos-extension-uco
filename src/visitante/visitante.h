/*
 * visitante.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef VISITANTE_VISITANTE_H_
#define VISITANTE_VISITANTE_H_

#include <string>

class visitante {

private:

    std::string ip_;

public:

	visitante();
	virtual ~visitante();

	visitante (std::string ip="empty");

	    inline std::string get_ip(){return ip_;}

	    inline void set_ip (std::string ip) {ip_=ip;}
};

#endif /* VISITANTE_VISITANTE_H_ */
