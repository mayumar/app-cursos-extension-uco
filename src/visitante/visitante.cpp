/*
 * visitante.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "visitante.h"
#include <fstream>
#include <iostream>
#include "../curso/curso.h"
#include "../usuario/usuario.h"




void Visitante:: ver_lista_de_cursos(){
	std::ifstream fichero;
	Curso curso;
	fichero.open("src/bd/cursos.txt"); //abre el fichero en modo lectura
	if(fichero.fail()){
		std::cout<< "No se pudo abrir la lista de los cursos actuales"<<std::endl;
		exit(-1);
	}

	while(fichero-curso){ //lee cada uno de los registros

		std::cout<<curso.get_nombre()<<" ("<<curso.get_id()<<")"<<std::endl;
		std::cout<<curso.get_descripcion()<<std::endl;
		std::cout<<"Fecha de Inicio: "<<curso.get_fechaInicio()<<std::endl;
		std::cout<<"Fecha de finalizacion: "<<curso.get_fechaFinal()<<std::endl;
		std::cout<<std::endl;
	}
	fichero.close();
}


bool Visitante:: registrarse(Usuario usuario ){
	std::fstream file_v;
	Usuario usuario_f;

	file_v.open("src/bd/usuarios.txt", std::fstream::in);
	if(!file_v.is_open()){
		std::cout<<"Error, no se ha podido acceder para su registro"<<std::endl;
		return false;
	}

	while(file_v-usuario_f){
		if(usuario.get_dni()==usuario_f.get_dni()){
			std::cout<<"Error, ya se encuentra registrado el usuario"<<std::endl;
			file_v.close();
			return false;
		}
	}

	file_v.close();

	file_v.open("src/bd/usuarios.txt", std::fstream::app);
	if(!file_v.is_open()){
		std::cout<<"Error, no se ha podido acceder para su registro"<<std::endl;
		return false;
	}

	file_v<<usuario;

	file_v.close();
	return true;
}



Rol Visitante::login(std::string user, std::string password){

	std::ifstream fichero;
	Usuario usuario;

	fichero.open("src/bd/usuarios.txt");
	if(!fichero.is_open()){
		std::cout<<"Error, no se ha podido acceder a la información del sistema"<<std::endl;
		return Rol::Empty;
	}

	while (fichero-usuario){
		if (usuario.get_usuario()==user && usuario.get_contraseña()==password){
			std::cout << "Ha iniciado sesión correctamente";
			return usuario.get_rol();
		}
	}

	fichero.close();
	return Rol::Empty;

}
