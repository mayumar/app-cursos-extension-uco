#include <iostream>
#include "app.h"

int main(){
	int opt;


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
				std::cout<<"Cursos activos"<<std::endl;
			break;

			case 2:
				std::cout<<"Iniciar sesión"<<std::endl;
			break;

			case 3:
				std::cout<<"Registrarse"<<std::endl;
			break;
		}

	}while(opt!=4);

	return 0;
}


//Menú para participantes
void participanteMenu(){
	int opt;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Ver los cursos activos"<<std::endl;
		std::cout<<"2. Inscribirse en un grupo"<<std::endl;
		std::cout<<"3. Ver cursos a los que estoy inscrito"<<std::endl;
		std::cout<<"4. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>4){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		switch(opt){
			case 1:
				std::cout<<"Cursos activos"<<std::endl;
			break;

			case 2:
				std::cout<<"Inscribirse"<<std::endl;
			break;

			case 3:
				std::cout<<"Ver cursos inscrito"<<std::endl;
			break;
		}

	}while(opt!=4);
}


//Menú para administrador de cursos
void adminCursosMenu(){
	int opt;

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

		//Menú para visitantes
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
				std::cout<<"Añadir curso"<<std::endl;
			break;

			case 5:
				std::cout<<"Modificar curso"<<std::endl;
			break;

			case 6:
				std::cout<<"ELiminar curso"<<std::endl;
			break;
		}

	}while(opt!=7);
}


//Menú Administrador de recursos
void adminRecursosMenu(){
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





