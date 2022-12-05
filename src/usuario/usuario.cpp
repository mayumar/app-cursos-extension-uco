/*
 * usuario.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "usuario.h"
#include <fstream>
#include <iostream>
#include "../curso/curso.h"

/* Funcion que muestra una lista de cursos
 * created on: 22 nov.2022
 * 	Author: Fatiicn
 */
void Usuario:: ver_lista_de_cursos(){
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
		std::cout<<"Plazas cubiertas: "<<curso.get_plazasCubiertas()<<"/"<<curso.get_plazasMax()<<std::endl;
		std::cout<<std::endl;
	}
	fichero.close(); //Cerramos el fichero

}

Usuario Usuario::operator=(Usuario u){
	nombre_=u.nombre_;
	apellidos_=u.apellidos_;
	dni_=u.dni_;
	correo_=u.correo_;
	contraseña_=u.contraseña_;
	usuario_=u.usuario_;
	rol_=u.rol_;

	return *this;
}

std::istream &operator-(std::istream &stream, Usuario &u){

	stream>>u.dni_;
	stream>>u.correo_;
	stream.get();
	getline(stream, u.nombre_);
	getline(stream, u.apellidos_);
	stream>>u.usuario_;
	stream>>u.contraseña_;
	stream>>u.rol_;
	stream.get();

	return stream;
}

std::ostream &operator<<(std::ostream &stream, Usuario &u){
	stream<<u.dni_<<std::endl;
	stream<<u.correo_<<std::endl;
	stream<<u.nombre_<<std::endl;
	stream<<u.apellidos_<<std::endl;
	stream<<u.usuario_<<std::endl;
	stream<<u.contraseña_<<std::endl;
	stream<<int(u.rol_)<<std::endl;

		return stream;
	}

std::istream &operator>>(std::istream &stream, Rol &rol){
	int rol_i;
	stream>>rol_i;

	if(rol_i==0){
		rol=Rol::Empty;
	}else if(rol_i==1){
		rol=Rol::Participante;
	}else if(rol_i==2){
		rol=Rol::Admin_Cursos;
	}else if(rol_i==3){
		rol=Rol::Admin_Recursos;
	}else if(rol_i==4){
		rol=Rol::Ponente;
	}

	return stream;
}

std::istream &operator>>(std::istream &stream, Usuario &u){

	std::cout<<"DNI: ";
	stream>>u.dni_;
	std::cout<<"Correo: ";
	stream>>u.correo_;
	stream.get();
	std::cout<<"Nombre: ";
	getline(stream, u.nombre_);
	std::cout<<"Apellidos: ";
	getline(stream, u.apellidos_);
	std::cout<<"Usuario: ";
	stream>>u.usuario_;
	std::cout<<"Contraseña: ";
	stream>>u.contraseña_;
	std::cout<<"Rol, Introduzca uno de los siguientes números:"<<std::endl;
	std::cout<<"1 -> Participante"<<std::endl;
	std::cout<<"2 -> Administrador de Cursos"<<std::endl;
	std::cout<<"3 -> Administrador de Recursos"<<std::endl;
	std::cout<<"4 -> Ponente"<<std::endl;
	stream>>u.rol_;
	stream.get();

	return stream;
}





