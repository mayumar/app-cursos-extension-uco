/*
 * visitante.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef VISITANTE_VISITANTE_H_
#define VISITANTE_VISITANTE_H_

#include <string>

class Visitante {

	private:

		std::string ip_;

	public:

		Visitante (std::string ip="empty"): ip_(ip){}

		inline ~Visitante(){}

		inline std::string get_ip() const {return ip_;}

		inline void set_ip (std::string ip) {ip_=ip;}
};

#endif /* VISITANTE_VISITANTE_H_ */
