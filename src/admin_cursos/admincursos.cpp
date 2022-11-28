/*
 * admincursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "admincursos.h"
#include "../curso/curso.h"
#include <fstream>
#include <iostream>
#include <string>


bool Admin_Cursos::add_curso(Curso curso){

		std::fstream file_c;
		file_c.open("src/bd/cursos.txt", std::fstream::app);
		if(!file_c.is_open()){
			std::cout<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
			return false;
		}

		file_c<<curso.get_id()<<std::endl;
		file_c<<curso.get_descripcion()<<std::endl;
		file_c<<curso.get_nombre()<<std::endl;
		file_c<<curso.get_fechaInicio()<<std::endl;
		file_c<<curso.get_fechaFinal()<<std::endl;
		file_c<<curso.get_alcance()<<std::endl;
		file_c<<curso.get_plazasCubiertas()<<std::endl;
		file_c<<curso.get_plazasMax()<<std::endl;

		file_c.close();
		return true;

}

bool Admin_Cursos::mod_curso(Curso curso_modif){

	  Curso curso;
	  std::ifstream fs("cursos.txt");
	  std::ofstream fstemp("cursostemp.txt");
	  if(!fs || !fstemp){

	    std::cout << "Error al abrir el archivo" << std::endl;
	    return false;
	  }

	  while(fs>> curso){
		  if(curso.get_id()==curso_modif.get_id()){
			  curso= curso_modif;
		  }
		  fstemp<<curso;
	  }

	  fs.close();
	  fstemp.close();
	  remove("cursos.txt");
	  rename("cursostemp.txt", "cursos.txt");
	  return true;
	}



bool Admin_Cursos::del_curso(Curso curso_modif){


	  Curso curso;
	  std::ifstream fs("cursos.txt");
	  std::ofstream fstemp("cursostemp.txt");
	  if(!fs || !fstemp){

	    std::cout << "Error al abrir el archivo" << std::endl;
	    return false;
	  }

	  while(fs>> curso){
		  if(curso.get_id()!=curso_modif.get_id()){
			  fstemp<<curso;;
		  }
	  }

	  fs.close();
	  fstemp.close();
	  remove("cursos.txt");
	  rename("cursostemp.txt", "cursos.txt");
	  return true;
	}
