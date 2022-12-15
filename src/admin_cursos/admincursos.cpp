/*
 * admincursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "admincursos.h"


bool Admin_Cursos::add_curso(Curso curso){
	std::fstream file_c;
	Curso c;

	file_c.open("src/bd/cursos.txt", std::fstream::in);
	if(!file_c.is_open()){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(file_c-c){
		if(c.get_id()==curso.get_id()){
			file_c.close();
			std::cout<<std::endl<<"Error, el curso ya se encuentra en la base de datos"<<std::endl;
			return false;
		}
	}
	file_c.close();

	file_c.open("src/bd/cursos.txt", std::fstream::app);
	if(!file_c.is_open()){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	file_c<<curso;

	file_c.close();
	return true;

}

bool Admin_Cursos::mod_curso(std::string id){
	Curso curso, curso_modif;
	bool found=false;
	std::ifstream fs;
	std::ofstream fstemp;

	//Buscamos si el curso existe
	fs.open("src/bd/cursos.txt");
	if(!fs){
		std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso && !found){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el curso no se encuentra en la base de datos"<<std::endl;
		fs.close();
		return false;
	}
	fs.close();

	std::cout<<"》Introduzca los datos modificados: "<<std::endl;
	std::cin>>curso_modif;

	//Comprobamos que el id introducido no se encuentre ya en la base de datos
	if(curso_modif.get_id()!=id){	
		fs.open("src/bd/cursos.txt");
		if(!fs){
			std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
			return false;
		}

		while(fs-curso){
			if(curso.get_id()==curso_modif.get_id()){
				std::cout<<std::endl<<"El id introducido ya se encuentra en la base de datos, pruebe otro"<<std::endl;
				fs.close();
				return false;
			}
		}
		fs.close();
	}

	//Modificamos el curso
	fs.open("src/bd/cursos.txt");
	fstemp.open("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==id){
			curso= curso_modif;
		}
		fstemp<<curso;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/cursos.txt");
	rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
	return true;
}

bool Admin_Cursos::del_curso(std::string id){
	Curso curso;
	std::ifstream fs;
	std::ofstream fstemp;
	bool found=false;

	//Borramos el curso
	fs.open("src/bd/cursos.txt");
	fstemp.open("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()!=id){
			fstemp<<curso;
		}else if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el curso no se encuentra en la base de datos"<<std::endl;
		fs.close();
		fstemp.close();
		remove("src/bd/cursos.txt");
		rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
		return false;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/cursos.txt");
	rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
	return true;
}


bool Admin_Cursos::add_usuario(Usuario usuario){
	std::fstream file;
	Usuario u;

	file.open("src/bd/usuarios.txt", std::fstream::in);
	if(!file){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(file-u){
		if(u.get_dni()==usuario.get_dni()){
			std::cout<<std::endl<<"Error, el usuario ya se encuentra en la base de datos"<<std::endl;
			file.close();
			return false;
		}

		if(usuario.get_rol()==Rol::Admin_Cursos && u.get_rol()==Rol::Admin_Cursos){
			std::cout<<std::endl<<"》AVISO《"<<std::endl;
			std::cout<<"Ya existe un administrador de cursos"<<std::endl;
			std::cout<<"Tener varias cuentas podría generar problemas"<<std::endl;
		}

		if(usuario.get_rol()==Rol::Admin_Recursos && u.get_rol()==Rol::Admin_Recursos){
			std::cout<<std::endl<<"》AVISO《"<<std::endl;
			std::cout<<"Ya existe un administrador de cursos"<<std::endl;
			std::cout<<"Tener varias cuentas podría generar problemas"<<std::endl;
		}
	}
	file.close();

	file.open("src/bd/usuarios.txt", std::fstream::app);
	if(!file){
		std::cout<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	file<<usuario;

	file.close();
	return true;
}

bool Admin_Cursos::mod_usuario(std::string dni){
	std::ifstream fu;
	std::ofstream futemp;
	Usuario usuario, usuario_mod;
	bool found=false;

	//Buscamos si el usuario existe
	fu.open("src/bd/usuarios.txt");
	if(!fu){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(fu-usuario && !found){
		if(usuario.get_dni()==dni){
			found=true;
		}
	}

	if(!found){
		fu.close();
		std::cout<<std::endl<<"Error, el usuario no se encuentra en la base de datos"<<std::endl;
		return false;
	}
	fu.close();

	std::cout<<std::endl<<"》Introduzca los datos modificados: "<<std::endl;
	std::cin>>usuario_mod;

	//Comprobamos si el dni introducido se encuentra ya en el sistema
	if(usuario_mod.get_dni()!=dni){
		fu.open("src/bd/usuarios.txt");
		found=false;
		if(!fu){
			std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
			return false;
		}

		while(fu-usuario){
			if(usuario.get_dni()==usuario_mod.get_dni()){
				std::cout<<std::endl<<"El dni que se intenta introducir ya se encuentra en la base de datos"<<std::endl;
				fu.close();
				return false;
			}
		}
		fu.close();
	}

	//Modificamos el usuario
	fu.open("src/bd/usuarios.txt");
	futemp.open("src/bd/usuariostemp.txt");
	if(!fu || !futemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(fu-usuario){
		if(usuario.get_dni()==dni){
			usuario=usuario_mod;
		}
		futemp<<usuario;
	}

	fu.close();
	futemp.close();
	remove("src/bd/usuarios.txt");
	rename("src/bd/usuariostemp.txt", "src/bd/usuarios.txt");
	return true;
}

bool Admin_Cursos::del_usuario(std::string dni){
	std::ifstream fu;
	std::ofstream futemp;
	Usuario usuario;
	bool found=false;

	//Eliminamos el usuario
	fu.open("src/bd/usuarios.txt");
	futemp.open("src/bd/usuariostemp.txt");
	if(!fu || !futemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(fu-usuario){
		if(usuario.get_dni()!=dni){
			futemp<<usuario;
		}else if(usuario.get_dni()==dni){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el usuario no se encuentra en la base de datos"<<std::endl;
		fu.close();
		futemp.close();
		remove("src/bd/usuarios.txt");
		rename("src/bd/usuariostemp.txt", "src/bd/usuarios.txt");
		return false;
	}

	fu.close();
	futemp.close();
	remove("src/bd/usuarios.txt");
	rename("src/bd/usuariostemp.txt", "src/bd/usuarios.txt");
	return true;
}


bool Admin_Cursos::ver_lista_de_inscritos(std::string id){

	std::ifstream inscritos;
	std::ifstream usuarios;
	std::ifstream cursos;
	Usuario usuario;
	Curso curso;
	struct inscripciones inscripcion;
	int i=0;
	bool found=false;
	std::list<Usuario> lista_usuarios;
	std::list<Usuario>::iterator it;

	cursos.open("src/bd/cursos.txt");
	if(!cursos){
		std::cout<<std::endl<<"Error, se ha podido acceder a la información de los cursos"<<std::endl;
		return 0;
	}

	while(cursos-curso && !found){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el curso con id "<<id<<" no existe"<<std::endl;
		cursos.close();
		return false;
	}
	cursos.close();

	inscritos.open("src/bd/inscripciones.txt");
	usuarios.open("src/bd/usuarios.txt");
	if(!inscritos || !usuarios){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

	//Cargamos usuarios.txt en una lista ¯
	while(usuarios-usuario){
		lista_usuarios.push_back(usuario);
	}
	usuarios.close();

	std::cout<<std::endl;
	std::cout<<"INSCRITOS "<<id<<std::endl;
	std::cout<<"¯¯¯¯¯¯¯¯¯¯¯¯";

	while(inscritos>>inscripcion.id_curso){
		  inscritos>>inscripcion.dni; //leemos cada registro de inscripciones.txt
		if(inscripcion.id_curso==id){
			for(it=lista_usuarios.begin(); it!=lista_usuarios.end(); it++){
				if(inscripcion.dni==it->get_dni()){
					std::cout<<std::endl;
					std::cout<<"Nombre: " <<it->get_nombre()<<std::endl;
					std::cout<<"Apellidos: " <<it->get_apellidos()<<std::endl;
					std::cout<<"DNI: "<<it->get_dni()<<std::endl;
					std::cout<<"Correo: " <<it->get_correo()<<std::endl;
					std::cout<<"Usuario: " <<it->get_usuario()<<std::endl;
				}
			}
			i++;
		}
	}
	inscritos.close();

	inscritos.open("src/bd/listaespera.txt");
	if(!inscritos){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}// 《 》

	std::cout<<std::endl;
	std::cout<<"EN LISTA DE ESPERA "<<id<<std::endl;
	std::cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";

	while(inscritos>>inscripcion.id_curso){
		  inscritos>>inscripcion.dni; //leemos cada registro de listaespera.txt
		if(inscripcion.id_curso==id){
			for(it=lista_usuarios.begin(); it!=lista_usuarios.end(); it++){
				if(inscripcion.dni==it->get_dni()){
					std::cout<<std::endl;
					std::cout<<"Nombre: " <<it->get_nombre()<<std::endl;
					std::cout<<"Apellidos: " <<it->get_apellidos()<<std::endl;
					std::cout<<"DNI: "<<it->get_dni()<<std::endl;
					std::cout<<"Correo: " <<it->get_correo()<<std::endl;
					std::cout<<"Usuario: " <<it->get_usuario()<<std::endl;
				}
			}
			i++;
		}
	}
	inscritos.close();

	if(i==0){
		std::cout<<std::endl<<"No hay inscripciones en este curso"<<std::endl;
	}

	return true;
}

bool Admin_Cursos::del_inscripcion(struct inscripciones inscripcion){
	std::fstream file_i, file_c, file_e;
	struct inscripciones i;
	Curso curso;
	bool encontrado=false, found=false;
	int plazas;
	std::list<struct inscripciones> lista_inscritos;
	std::list<Curso> lista_cursos;
	std::list<struct inscripciones> lista_espera;
	std::list<struct inscripciones>::iterator it_i, it_e;
	std::list<Curso>::iterator it_c;

	file_i.open("src/bd/inscripciones.txt", std::fstream::in);
	file_c.open("src/bd/cursos.txt", std::fstream::in);
	file_e.open("src/bd/listaespera.txt", std::fstream::in);
	if(!file_i || !file_c || !file_e){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	while(file_i>>i.id_curso){
		  file_i>>i.dni;
		  
		lista_inscritos.push_back(i);
	}
	file_i.close();

	while(file_c-curso){
		lista_cursos.push_back(curso);
	}
	file_c.close();

	while(file_e>>i.id_curso){
		  file_e>>i.dni;
		
		lista_espera.push_back(i);
	}
	file_e.close();
	it_e=lista_espera.begin();

	//Buscamos la inscripción a eliminar
	for(it_i=lista_inscritos.begin(); it_i!=lista_inscritos.end() && !encontrado; it_i++){
		if(it_i->dni==inscripcion.dni && it_i->id_curso==inscripcion.id_curso){

			//Buscamos el curso cuya inscripción hemos borrado
			for(it_c=lista_cursos.begin(); it_c!=lista_cursos.end(); it_c++){
				if(it_c->get_id()==inscripcion.id_curso){

					//Había usuarios en lista de espera
					if(it_c->get_plazasCubiertas()==it_c->get_plazasMax()){

						for(it_e=lista_espera.begin(); it_e!=lista_espera.end() && found==false; it_e++){
							if(it_e->id_curso==inscripcion.id_curso){
								found=true;

								lista_inscritos.push_back(*it_e);
								lista_espera.erase(it_e);
								
								file_e.open("src/bd/listaespera.txt", std::fstream::out);
								if(!file_e){
									std::cout<<std::endl<<"Error, no se ha podido acceder a la informacion de la lista de espera"<<std::endl;
									return false;
								}

								for(it_e=lista_espera.begin(); it_e!=lista_espera.end(); it_e++){
									file_e<<it_e->id_curso<<std::endl;
									file_e<<it_e->dni<<std::endl;
								}
								file_e.close();
							}
						}
						
					//No hay cursos en lista de espera
					}else{
						plazas=it_c->get_plazasCubiertas();
						plazas--;

						if(plazas<0){
							plazas=0;
						}

						it_c->set_plazasCubiertas(plazas);
						it_c->actualizar_alcance();

					}

				}
			}

			lista_inscritos.erase(it_i);
			encontrado=true;
		}
	}

	if(!encontrado){
		std::cout<<std::endl<<"Error, no se ha encontrado la inscripción"<<std::endl;
		return false;
	}

	file_i.open("src/bd/inscripciones.txt", std::fstream::out);
	file_c.open("src/bd/cursos.txt", std::fstream::out);
	if(!file_i || !file_c){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	for(it_i=lista_inscritos.begin(); it_i!=lista_inscritos.end(); it_i++){
		file_i<<it_i->id_curso<<std::endl;
		file_i<<it_i->dni<<std::endl;
	}
	file_i.close();

	for(it_c=lista_cursos.begin(); it_c!=lista_cursos.end(); it_c++){
		file_c<<*it_c;
	}
	file_c.close();

	return true;
}


bool Admin_Cursos::add_ponente(Ponente ponente){
	std::fstream file_p, file_c;
	Ponente p;
	Curso c;
	bool found=false;

	//Buscamos si el ponente ya existe
	file_p.open("src/bd/ponentes.txt", std::fstream::in);
	if(!file_p){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
		return false;
	}

	while(file_p-p){
		if(p.get_dni()==ponente.get_dni()){
			std::cout<<std::endl<<"Error, el ponente ya se encuentra en la base de datos"<<std::endl;
			file_p.close();
			return false;
		}
	}
	file_p.close();

	//Buscamos si el curso que se ha introducido existe
	file_c.open("src/bd/cursos.txt", std::fstream::in);
	if(!file_c){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}
	
	while(file_c-c && !found){
		if(c.get_id()==ponente.get_curso()){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el ID del curso no es correcto"<<std::endl;
		file_c.close();
		return false;
	}

	//Añadimos ponente
	file_p.open("src/bd/ponentes.txt", std::fstream::app);
	if(!file_p){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
		return false;
	}
	file_p<<ponente;

	file_p.close();
	return true;
}

bool Admin_Cursos::mod_ponente(std::string dni){
	Ponente ponente, ponente_mod;
	Curso curso;
	bool found=false;
	std::ifstream fs, fc;
	std::ofstream fstemp;

	//Buscamos si se encuentra el ponente en la base de datos
	fs.open("src/bd/ponentes.txt");
	if(!fs){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
		return false;
	}

	while(fs-ponente && !found){
		if(ponente.get_dni()==dni){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el ponente no se encuentra en la base de datos"<<std::endl;
		fs.close();
		return false;
	}
	fs.close();

	std::cout<<"》Introduzca los datos modificados: "<<std::endl;
	std::cin>>ponente_mod;

	//Buscamos que el dni introducido no esté ya en la base de datos
	if(ponente_mod.get_dni()!=dni){
		fs.open("src/bd/ponentes.txt");
		if(!fs){
			std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
			fs.close();
			return false;
		}

		while(fs-ponente){
			if(ponente.get_dni()==ponente_mod.get_dni()){
				std::cout<<std::endl<<"Error, el dni introducido ya se encuentra en la base de datos, pruebe otro"<<std::endl;
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
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fc-curso && !found){
		if(curso.get_id()==ponente.get_curso()){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el ID del curso no es correcto"<<std::endl;
		fs.close();
		return false;
	}
	fs.close();

	//Modificamos el ponente
	fs.open("src/bd/ponentes.txt");
	fstemp.open("src/bd/ponentestemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
		return false;
	}

	while(fs-ponente){
		if(ponente.get_dni()==dni){
			ponente=ponente_mod;
		}
		fstemp<<ponente;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/ponentes.txt");
	rename("src/bd/ponentestemp.txt", "src/bd/ponentes.txt");
	return true;
}

bool Admin_Cursos::del_ponente(std::string dni){
	Ponente ponente;
	std::ifstream fs;
	std::ofstream fstemp;
	bool found=false;
	
	//Eliminamos el ponente
	fs.open("src/bd/ponentes.txt");
	fstemp.open("src/bd/ponentestemp.txt");
	if(!fs || !fstemp){
		std::cout<<std::endl<<"Error, no se ha podido acceder a la información de los ponentes"<<std::endl;
		return false;
	}

	while(fs-ponente){
		if(ponente.get_dni()!=dni){
			fstemp<<ponente;
		}else if(ponente.get_dni()==dni){
			found=true;
		}
	}

	if(!found){
		std::cout<<std::endl<<"Error, el ponente no se encuentra en la base de datos"<<std::endl;
		fs.close();
		fstemp.close();
		remove("src/bd/ponentes.txt");
		rename("src/bd/ponentestemp.txt", "src/bd/ponentes.txt");
		return false;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/ponentes.txt");
	rename("src/bd/ponentestemp.txt", "src/bd/ponentes.txt");
	return true;
}