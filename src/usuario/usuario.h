/*
 * usuario.h
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 *      Modified: mayumar
 */

#ifndef USUARIO_USUARIO_H_
#define USUARIO_USUARIO_H_

#include <string>

enum class Rol {Empty, Participante, Admin_Cursos, Admin_Recursos, Ponente};
std::istream &operator>>(std::istream &stream, Rol &rol);

class Usuario {

	private:

		std::string nombre_;
		std::string apellidos_;
		std::string dni_;
		std::string correo_;
		std::string contraseña_;
		std::string usuario_;
		Rol rol_;

	public:

		inline Usuario (std::string nombre="empty",
					 	std::string apellidos= "empty",
						std::string dni="empty",
						std::string correo= "empty",
						std::string contraseña="empty",
						std::string usuario="empty",
						Rol rol=Rol::Empty): nombre_(nombre), apellidos_(apellidos),
												 dni_(dni), correo_(correo),
												 contraseña_(contraseña), usuario_(usuario),
												 rol_(rol){}
		inline ~Usuario(){}

		inline std::string get_nombre() const {return nombre_;}
		inline std::string get_apellidos() const {return apellidos_;}
		inline std::string get_dni() const {return dni_;}
		inline std::string get_correo() const {return correo_;}
		inline std::string get_contraseña() const {return contraseña_;}
		inline std::string get_usuario() const {return usuario_;}

		inline void set_nombre (std::string nombre) {nombre_=nombre;}
		inline void set_apellidos (std::string apellidos) {apellidos_=apellidos;}
		inline void set_dni (std::string dni) {dni_=dni;}
		inline void set_correo (std::string correo) {correo_=correo;}
		inline void set_contraseña (std::string contraseña) {contraseña_=contraseña;}
		inline void set_usuario (std::string usuario) {usuario_=usuario;}

		void ver_lista_de_cursos();

		friend std::istream &operator>>(std::istream &stream, Usuario &u);
		friend std::istream &operator-(std::istream &stream, Usuario &u);
		friend std::ostream &operator<<(std::ostream &stream, Usuario &u);

		Usuario operator=(Usuario &u);

};

#endif /* USUARIO_USUARIO_H_ */
