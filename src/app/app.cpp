#include <iostream>
#include <string>
#include "app.h"
#include "../visitante/visitante.h"

int main(){
	int opt;
	Visitante visitante;
	Usuario usuario;
	Participante participante("Juan", "Perez", "DNI1");
	Admin_Cursos admin_c;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Ver los cursos activos"<<std::endl;
		std::cout<<"2. Iniciar sesión"<<std::endl;
		std::cout<<"3. Registrarse"<<std::endl;
		std::cout<<"4. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>4){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		//Menú para visitantes
		switch(opt){
			case 1:
				std::cout<<"Cursos activos:"<<std::endl<<std::endl;
				visitante.ver_lista_de_cursos();
			break;

			case 2:
				//std::cout<<"Iniciar sesión"<<std::endl;
			break;

			case 3:

				std::cout<<"Introduzca los datos de la cuenta: "<<std::endl;
				std::cin>>usuario;
				if(!visitante.registrarse(usuario)){
					std::cout<<"Error: no se ha podido realizar el registro"<<std::endl;
				}else{
					std::cout<<"El registro ha sido realizado con éxito"<<std::endl;
				}

			break;
			//Debug mode
			case 5:
				participanteMenu(participante);
			break;

			case 6:
				adminCursosMenu(admin_c);
			break;
		}

	}while(opt!=4);

	return 0;
}


//Menú para participantes
void participanteMenu(Participante participante){
	int opt;
	std::string id_curso;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Ver los cursos activos"<<std::endl;
		std::cout<<"2. Inscribirse en un curso"<<std::endl;
		std::cout<<"3. Ver cursos a los que estoy inscrito"<<std::endl;
		std::cout<<"4. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>4){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		switch(opt){
			case 1:
				std::cout<<"Cursos activos:"<<std::endl<<std::endl;
				participante.ver_lista_de_cursos();
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
				std::cout<<"Ver cursos inscrito"<<std::endl;
			break;
		}

	}while(opt!=4);
}


//Menú para administrador de cursos
void adminCursosMenu(Admin_Cursos admin){
	int opt;
	Curso curso;
	std::string curso_id;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Añadir cuenta al sistema"<<std::endl;
		std::cout<<"2. Modificar cuenta del sistema"<<std::endl;
		std::cout<<"3. Eliminar cuenta del sistema"<<std::endl;
		std::cout<<"4. Añadir curso al sistema"<<std::endl;
		std::cout<<"5. Modificar curso del sistema"<<std::endl;
		std::cout<<"6. Eliminar curso del sistema"<<std::endl;
		std::cout<<"7. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>7){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		switch(opt){
			case 1:
				std::cout<<"Añadir cuenta"<<std::endl;
			break;

			case 2:
				std::cout<<"Modificar cuenta"<<std::endl;
			break;

			case 3:
				std::cout<<"Eliminar cuenta"<<std::endl;
			break;

			case 4:
				std::cout<<"Introduzca los datos del curso a añadir: "<<std::endl;
				std::cin>>curso;
				admin.add_curso(curso);
			break;

			case 5:
				std::cout<<"Introduzca el id del curso a modificar y los datos modificados"<<std::endl;
				std::cin>>curso;
				admin.mod_curso(curso);
			break;

			case 6:
				std::cout<<"Introduzca el id del curso a eliminar"<<std::endl;
				std::cin>>curso_id;
				admin.del_curso(curso_id);
			break;
		}

	}while(opt!=7);
}


//Menú Administrador de recursos
void adminRecursosMenu(Admin_Recursos admin){
	int opt;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Añadir recurso al sistema"<<std::endl;
		std::cout<<"2. Modificar recurso del sistema"<<std::endl;
		std::cout<<"3. Eliminar recurso del sistema"<<std::endl;
		std::cout<<"4. Salir"<<std::endl;
		std::cin>>opt;

		if(opt<1 || opt>7){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		switch(opt){
			case 1:
				std::cout<<"Añadir recurso"<<std::endl;
			break;

			case 2:
				std::cout<<"Modificar recurso"<<std::endl;
			break;

			case 3:
				std::cout<<"Eliminar recurso"<<std::endl;
			break;
		}

	}while(opt!=0);

}





