#include <iostream>
#include "../participante/participante.h"
#include "../admin_cursos/admincursos.h"
#include "../curso/curso.h"


int main(){

	int opt;
	std::string id_curso;
	Participante participante("Juanito", "Perez Perez", "DNI1");
	Admin_Cursos admin_c("nombre", "apellidos", "dni", "correo", "contraseña", "usuario");
	Curso curso_modif;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Opcion 1: Ver lista de los cursos actuales"<<std::endl;
    	std::cout<<"2. Opcion 2: Añadir un curso nuevo a la lista de los cursos actuales"<<std::endl;
		std::cout<<"3. Opcion 3"<<std::endl;
		std::cout<<"4. Opcion 4"<<std::endl;
		std::cout<<"5. Opcion 5"<<std::endl;
		std::cout<<"6. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>6){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		std::string curso_id;
		std::string curso_descripcion;
		std::string curso_nombre;
		std::string curso_fechaInicio;
		std::string curso_fechaFinal;
		std::string curso_alcance;
		std::string curso_plazasCubiertas;
		std::string curso_plazasMax;

		switch(opt){
			case 1:
				std::cout<<"Lista de los cursos:"<<std::endl;

			break;

			case 2:
				std::cout<<"Introduzca el id del curso al que desea inscribirse:"<<std::endl;
				std::cin>>id_curso;

				if(!participante.inscribirse(id_curso)){
					std::cout<<"Ha ocurrido un error, vuelva a intentarlo"<<std::endl;
				}else{
					std::cout<<"La inscripcion se ha realizado con éxito"<<std::endl;
				}
			break;

			case 3:
				std::cout<<"Introduzca el id del del curso a añadir"<<std::endl;
				std::cin>>curso_id;
				std::cout<<"Introduzca la descripción del curso a añadir "<<std::endl;
				std::cin>>curso_descripcion;
				std::cout<<"Introduzca el nombre del curso a añadir"<<std::endl;
				std::cin>>curso_nombre;
				std::cout<<"Introduzca la fecha de inicio del curso a añadir"<<std::endl;
				std::cin>>curso_fechaInicio;
				std::cout<<"Introduzca la fecha de finalización del curso a añadir"<<std::endl;
				std::cin>>curso_fechaFinal;
				std::cout<<"Introduzca el alcance del curso a añadir"<<std::endl;
				std::cin>>curso_alcance;
				std::cout<<"Introduzca el número de plazas cubiertas del curso a añadir"<<std::endl;
				std::cin>>curso_plazasCubiertas;
				std::cout<<"Introduzca el número máximo de plazas del curso a añadir"<<std::endl;
				std::cin>>curso_plazasMax;
			break;

			case 4:

				std::cout<<"Introduzca el id del curso que quiere modificar"<<std::endl;
				curso_modif.set_id(id_curso);
				std::cout<<"Introduzca el id del del curso a modificar"<<std::endl;
				std::cin>>curso_id;
				std::cout<<"Introduzca la descripción del curso a modificar"<<std::endl;
				std::cin>>curso_descripcion;
				std::cout<<"Introduzca el nombre del curso a modificar"<<std::endl;
				std::cin>>curso_nombre;
				std::cout<<"Introduzca la fecha de inicio del curso a amodificar"<<std::endl;
				std::cin>>curso_fechaInicio;
				std::cout<<"Introduzca la fecha de finalización del curso a modificar"<<std::endl;
				std::cin>>curso_fechaFinal;
				std::cout<<"Introduzca el alcance del curso a modificar"<<std::endl;
				std::cin>>curso_alcance;
				std::cout<<"Introduzca el número de plazas cubiertas del curso a modificar"<<std::endl;
				std::cin>>curso_plazasCubiertas;
				std::cout<<"Introduzca el número máximo de plazas del curso a modificar"<<std::endl;
				std::cin>>curso_plazasMax;

			break;

			case 5:
				std::cout<<"Introduzca el id del curso que quiere eliminar"<<std::endl;
				curso_modif.set_id(id_curso);
				std::cout<<"Introduzca el id del del curso a eliminar"<<std::endl;
				std::cin>>curso_id;
				std::cout<<"Introduzca la descripción del curso a eliminar"<<std::endl;
				std::cin>>curso_descripcion;
				std::cout<<"Introduzca el nombre del curso a eliminar"<<std::endl;
				std::cin>>curso_nombre;
				std::cout<<"Introduzca la fecha de inicio del curso a eliminar"<<std::endl;
				std::cin>>curso_fechaInicio;
				std::cout<<"Introduzca la fecha de finalización del curso a eliminar"<<std::endl;
				std::cin>>curso_fechaFinal;
				std::cout<<"Introduzca el alcance del curso a eliminar"<<std::endl;
				std::cin>>curso_alcance;
				std::cout<<"Introduzca el número de plazas cubiertas del curso a eliminar"<<std::endl;
				std::cin>>curso_plazasCubiertas;
				std::cout<<"Introduzca el número máximo de plazas del curso a eliminar"<<std::endl;
				std::cin>>curso_plazasMax;
			break;
		}

	}while(opt!=6);

	return 0;
}
