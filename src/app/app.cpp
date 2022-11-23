#include <iostream>


int main(){

	int opt;

	do{
		std::cout<<std::endl;
		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cout<<"1. Opcion 1: Ver lista de los cursos actuales"<<std::endl;
		std::cout<<"2. Opcion 2"<<std::endl;
		std::cout<<"3. Opcion 3: Inscribirse a un curso"<<std::endl;
		std::cout<<"4. Opcion 4"<<std::endl;
		std::cout<<"5. Opcion 5"<<std::endl;
		std::cout<<"6. Salir"<<std::endl;
		std::cin>>opt;
		std::cout<<std::endl;

		if(opt<1 || opt>6){
			std::cout<<"Error: introduzca una de las opciones disponibles"<<std::endl;
		}

		switch(opt){
			case 1:
				std::cout<<"Lista de los cursos:"<<std::endl;

			break;

			case 2:
				std::cout<<"Opcion 2"<<std::endl;
			break;

			case 3:
				std::cout<<"Opcion 3"<<std::endl;
			break;

			case 4:
				std::cout<<"Opcion 4"<<std::endl;
			break;

			case 5:
				std::cout<<"Opcion 5"<<std::endl;
			break;
		}

	}while(opt!=6);

	return 0;
}
