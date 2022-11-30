/*
 * usuario.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "usuario.h"
#include <fstream>
#include <iostream>
#include <string>
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

	while(fichero>>curso){ //lee cada uno de los registros
		std::string nombre1=curso.get_nombre();
		std::string nombre2;
		std::string descripcion1=curso.get_descripcion();
		std::string descripcion2;

		int tam_n=(int)nombre1.size();
		int tam_d=(int)descripcion1.size();

		for(int i=0; i<tam_n; i++){
			if(nombre1[i]=='_'){
				nombre2+=' ';
			}else{
				nombre2+=nombre1[i];
			}
		}

		for(int i=0; i<tam_d; i++){
			if(descripcion1[i]=='_'){
				descripcion2+=' ';
			}else{
				descripcion2+=descripcion1[i];
			}
		}


		std::cout<<nombre2<<" ("<<curso.get_id()<<")"<<std::endl;
		std::cout<<descripcion2<<std::endl;
		std::cout<<"Fecha de Inicio: "<<curso.get_fechaInicio()<<std::endl;
		std::cout<<"Fecha de finalizacion: "<<curso.get_fechaFinal()<<std::endl;
		std::cout<<"Plazas cubiertas: "<<curso.get_plazasCubiertas()<<"/"<<curso.get_plazasMax()<<std::endl;
		std::cout<<std::endl;
	}
	fichero.close(); //Cerramos el fichero

}
