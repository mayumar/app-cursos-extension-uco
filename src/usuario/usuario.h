/*
 * usuario.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#ifndef USUARIO_USUARIO_H_
#define USUARIO_USUARIO_H_

#include <string>

class usuario {

private:

    std::string nombre_;
    std::string apellidos_;
    std::string dni_;
    std::string correo_;
    std::string contraseña_;
    std::string usuario_;

public:

	usuario();
	virtual ~usuario();

	usuario (std::string nombre="empty",
	             std::string apellidos= "empty",
	             std::string dni="empty",
	             std::string correo= "empty",
	             std::string contraseña="empty",
	             std::string nom_usuario="empty");

	    inline std::string get_nombre(){return nombre_;}
	    inline std::string get_apellidos(){return apellidos_;}
	    inline std::string get_dni(){return dni_;}
	    inline std::string get_correo(){return correo_;}
	    inline std::string get_contraseña(){return contraseña_;}
	    inline std::string get_usuario(){return usuario_;}

	    inline void set_nombre (std::string nombre) {nombre_=nombre;}
	    inline void set_name (std::string apellidos) {apellidos_=apellidos;}
	    inline void set_surname (std::string dni) {dni_=dni;}
	    inline void set_address (std::string correo) {correo_=correo;}
	    inline void set_town (std::string contraseña) {contraseña_=contraseña;}
	    inline void set_province (std::string usuario) {usuario_=usuario;}

	    void ver_lista_de_cursos();

};

#endif /* USUARIO_USUARIO_H_ */
