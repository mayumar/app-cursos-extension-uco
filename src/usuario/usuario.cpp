/*
 * usuario.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "usuario.h"

/* Funcion que muestra una lista de cursos
 * created on: 22 nov.2022
 * 	Author: Fatiicn
 */
void Usuario:: ver_lista_de_cursos(){
	std::ifstream fichero, ponentes;
	Curso curso;
	Ponente ponente;
	float alcance;
	std::list<Ponente> lista_ponentes;
	std::list<Ponente>::iterator it;

	fichero.open("src/bd/cursos.txt"); //abre el fichero en modo lectura
	ponentes.open("src/bd/ponentes.txt");
	if(fichero.fail() || !ponentes){
		std::cout<<std::endl<< "Error al acceder a la información de los cursos"<<std::endl;
		exit(-1);
	}

	while(ponentes-ponente){
		lista_ponentes.push_back(ponente);
	}
	ponentes.close();

	while(fichero-curso){ //lee cada uno de los registros
		alcance=curso.get_alcance();
		alcance=alcance*100;

		std::cout<<curso.get_nombre()<<" ("<<curso.get_id()<<")"<<std::endl;
		std::cout<<curso.get_descripcion()<<std::endl;
		std::cout<<"Precio: "<<curso.get_precio()<<"€"<<std::endl;
		std::cout<<"Fecha de Inicio: "<<curso.get_fechaInicio()<<std::endl;
		std::cout<<"Fecha de finalizacion: "<<curso.get_fechaFinal()<<std::endl;
		std::cout<<"Plazas cubiertas: "<<curso.get_plazasCubiertas()<<"/"<<curso.get_plazasMax()<<std::endl;
		std::cout<<"Alcance del curso: "<<alcance<<"%"<<std::endl;
		std::cout<<"Ponentes: "<<std::endl;
		for(it=lista_ponentes.begin(); it!=lista_ponentes.end(); it++){
			if(it->get_curso()==curso.get_id()){
				std::cout<<it->get_nombre()<<" "<<it->get_apellidos()<<" ("<<it->get_dni()<<")"<<std::endl;
			}
		}
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
	stream.get();
	getline(stream, u.nombre_);
	getline(stream, u.apellidos_);
	stream>>u.correo_;
	stream>>u.usuario_;
	stream>>u.contraseña_;
	stream>>u.rol_;
	stream.get();

	return stream;
}

std::ostream &operator<<(std::ostream &stream, Usuario &u){
	stream<<u.dni_<<std::endl;
	stream<<u.nombre_<<std::endl;
	stream<<u.apellidos_<<std::endl;
	stream<<u.correo_<<std::endl;
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
	}

	return stream;
}

std::istream &operator>>(std::istream &stream, Usuario &u){

	std::cout<<"DNI: ";
	stream>>u.dni_;
	stream.get();
	std::cout<<"Nombre: ";
	getline(stream, u.nombre_);
	std::cout<<"Apellidos: ";
	getline(stream, u.apellidos_);
	std::cout<<"Correo: ";
	stream>>u.correo_;
	std::cout<<"Usuario: ";
	stream>>u.usuario_;
	std::cout<<"Contraseña: ";
	stream>>u.contraseña_;
	std::cout<<std::endl<<"Rol, Introduzca uno de los siguientes números:"<<std::endl;
	std::cout<<"1 -> Participante"<<std::endl;
	std::cout<<"2 -> Administrador de Cursos"<<std::endl;
	std::cout<<"3 -> Administrador de Recursos"<<std::endl;
	stream>>u.rol_;
	stream.get();

	return stream;
}





