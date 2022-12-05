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


Rol Visitante::login(Usuario usuario_log){

		std::ifstream fichero;
		std::string userName;
	    std::string userPassword;
	    Usuario usuario;

	    while (fichero-usuario){
	        std::cout << "Por favor introduzca su usuario: "<<std::endl;
	        std::cin >> userName;
	        std::cout << "Por favor introduzca su contraseña: "<<std::endl;
	        std::cin >> userPassword;

	        if (usuario.get_usuario()==usuario_log.get_usuario() && usuario.get_contraseña()==usuario_log.get_contraseña()){
	            std::cout << "Ha iniciado sesión correctamente";
	            return usuario.get_rol();
	        }
	        else{
	            std::cout << "Intento fallido, por favor intentelo de nuevo" << std::endl;
	        }
	    }
	    return Rol::Empty;
}
