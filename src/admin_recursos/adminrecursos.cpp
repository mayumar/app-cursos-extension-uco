/*
 * adminrecursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "adminrecursos.h"
#include <fstream>
#include<iostream>

bool Admin_Recursos ::add_recurso(Recursos recurso){
	std::fstream file_r, file_c;
	Recursos r;
	Curso c;
	bool found=false;

	//Buscamos si el recurso ya existe
	file_r.open("src/bd/recursos.txt", std::fstream::in);
	if(!file_r.is_open()){
		std::cout<<"Error, no se ha podido acceder a la informacion de los recursos"<<std::endl;
		return false;
	}

	while(file_r-r){
		if(r.get_id()==recurso.get_id()){
			file_r.close();
			return false;
		}
	}
	file_r.close();

	//Buscamos si el curso que se ha introducido existe
	file_c.open("src/bd/cursos.txt", std::fstream::in);
	if(!file_c.is_open()){
		std::cout<<"Error, no se ha podido acceder a la informacion de los cursos"<<std::endl;
		return false;
	}

	while(file_c-c){
		if(c.get_id()==recurso.get_curso()){
			found=true;
			std::cout<<"El curso ha sido encontrado"<<std::endl;
		}
	}
	
	if(!found){
		file_c.close();
		return false;
	}

	//Añadimos recurso
	file_r.open("src/bd/recursos.txt", std::fstream::app);
	if(!file_r.is_open()){
		std::cout<<"Error, no se ha podido acceder a la informacion de los recursos"<<std::endl;
		return false;
	}
	file_r<<recurso;

	file_r.close();
	return true;
}

bool Admin_Recursos::mod_recurso(std::string id){
	Recursos recurso, recurso_mod;
	bool found=false;
	std::ifstream fs("src/bd/recursos.txt");
	std::ofstream fstemp("src/bd/recursostemp.txt");
	if(!fs || !fstemp){
		std::cout<<"Error al abrir el archivo"<<std::endl;
		return false;
	}
	while(fs-recurso){
		if(recurso.get_id()==id){
			found=true;
		}
	}
	if(!found){
		fs.close();
		fstemp.close();
		remove("src/bd/recursos.txt");
		rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
		return false;
	}
	std::cout<<"Introduzca los dato a modificar: "<<std::endl;
	std::cin>>recurso_mod;
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
	bool found=false;
	std::ifstream fs("src/bd/recursos.txt");
	std::ofstream fstemp("src/bd/recursostemp.txt");
	if(!fs || !fstemp){
			std::cout<<"Error al abrir el archivo"<<std::endl;
			return false;
		}
		while(fs-recurso){
			if(recurso.get_id()==id){
				found=true;
			}
		}
	if(!found){
		fs.close();
		fstemp.close();
		remove("src/bd/recursos.txt");
		rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
		return false;
	}
	while(fs-recurso){
		if(recurso.get_id()!=id){
			fstemp<<recurso;
		}
	}
	fs.close();
	fstemp.close();
	remove("src/bd/recursos.txt");
	rename("src/bd/recursostemp.txt", "src/bd/recursos.txt");
	return true;

}


