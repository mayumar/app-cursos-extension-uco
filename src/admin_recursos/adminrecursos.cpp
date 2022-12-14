/*
 * adminrecursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "adminrecursos.h"
#include <fstream>
#include<iostream>

bool Admin_Recursos::add_recurso(Recursos recurso){
	std::fstream file_r, file_c;
	Recursos r;
	Curso c;
	bool found=false;

	//Buscamos si el recurso ya existe
	file_r.open("src/bd/recursos.txt", std::fstream::in);
	if(!file_r.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}

	while(file_r-r){
		if(r.get_id()==recurso.get_id()){
			std::cout<<std::endl<<"Error, el recurso ya se encuentra en la base de datos"<<std::endl;
			file_r.close();
			return false;
		}
	}
	file_r.close();

	//Buscamos si el curso que se ha introducido existe
	file_c.open("src/bd/cursos.txt", std::fstream::in);
	if(!file_c.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(file_c-c && !found){
		if(c.get_id()==recurso.get_curso()){
			found=true;
		}
	}
	
	if(!found){
		std::cout<<std::endl<<"Error, el ID del curso no es correcto"<<std::endl;
		file_c.close();
		return false;
	}

	//Añadimos recurso
	file_r.open("src/bd/recursos.txt", std::fstream::app);
	if(!file_r.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}
	file_r<<recurso;

	file_r.close();
	return true;
}

bool Admin_Recursos::mod_recurso(std::string id){
	Recursos recurso, recurso_mod;
	Curso curso;
	bool found=false;
	std::ifstream fs, fc;
	std::ofstream fstemp;

	//Buscamos si se encuentra el recurso en la base de datos
	fs.open("src/bd/recursos.txt");
	if(!fs){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}

	while(fs-recurso && !found){
		if(recurso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el recurso no se encuentra en la base de datos"<<std::endl;
		fs.close();
		return false;
	}
	fs.close();

	std::cout<<"》Introduzca los datos modificados: "<<std::endl;
	std::cin>>recurso_mod;

	//Buscamos que el id introducido no esté ya en la base de datos
	if(recurso_mod.get_id()!=id){
		fs.open("src/bd/recursos.txt");
		if(!fs){
			std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
			return false;
		}

		while(fs-recurso){
			if(recurso.get_id()==recurso_mod.get_id()){
				std::cout<<std::endl<<"Error, el ID del recurso ya se encuentra en la base de datos"<<std::endl;
				fs.close();
				return false;
			}
		}
		fs.close();
	}

	//Buscamos si el curso introducido está en la base de datos
	fc.open("src/bd/cursos.txt");
	found=false;
	if(!fc){
		std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
		fc.close();
		return false;
	}

	while(fc-curso){
		if(curso.get_id()==recurso_mod.get_curso()){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el ID del curso no es correcto"<<std::endl;
		fs.close();
		return false;
	}
	fc.close();

	//Modificamos el recurso
	fs.open("src/bd/recursos.txt");
	fstemp.open("src/bd/recursostemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}

	while(fs-recurso){
		if(recurso.get_id()==id){
			recurso=recurso_mod;
		}
		fstemp<<recurso;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/recursos.txt");
	rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
	return true;
}

bool Admin_Recursos::del_recurso(std::string id){
	Recursos recurso;
	std::ifstream fs;
	std::ofstream fstemp;
	bool found=false;
	
	//Eliminamos el recurso
	fs.open("src/bd/recursos.txt");
	fstemp.open("src/bd/recursostemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}
		
	while(fs-recurso){
		if(recurso.get_id()!=id){
			fstemp<<recurso;
		}else if(recurso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el recurso no se encuentra en la base de datos"<<std::endl;
		fs.close();
		fstemp.close();
		remove("src/bd/recursos.txt");
		rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
		return false;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/recursos.txt");
	rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
	return true;
}

bool Admin_Recursos::ver_lista_recursos(std::string id){
	std::ifstream recursos;
	Recursos recurso;
	int i=0;

	recursos.open("src/bd/recursos.txt");
	if(!recursos){
		std::cout<<std::endl<<"Error al acceder a la información de los recursos"<<std::endl;
		return false;
	}

	while(recursos-recurso){
		if(recurso.get_curso()==id){
			std::cout<<std::endl;
			std::cout<<"ID: "<<recurso.get_id()<<std::endl;
			std::cout<<"Tipo de recurso: "<<recurso.get_tipo()<<std::endl;
			if(recurso.get_tipo()=="Aula" || recurso.get_tipo()=="aula" || recurso.get_tipo()=="AULA"){
				std::cout<<"Aforo: "<<recurso.get_aforo()<<std::endl;
			}
			i++;
		}
	}

	recursos.close();

	if(i==0){
		std::cout<<std::endl<<"No hay recursos asociados a este curso"<<std::endl;
	}
	
	return true;
}
