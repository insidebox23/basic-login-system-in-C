#include <stdio.h>

typedef struct {
	char name;
	int password;
} usrs;

typedef enum {
	cambiar_password = 1,
	cerrar_sesion
} sistema;

int login(usrs usr1){

	int loop = 0;         //Limite para saber si el usuario requiere mas acciones dentro de login
	int rsp;

	do {
		printf("Que deseas hacer (1 = cambiar password / 2 = cerrar sesion)?: ");
		while (scanf("%d", &rsp) <= 0 || rsp >= 3) {     //Mas adelante arreglar problemas de buffer de tipo caracter (tipicos bugs)
								//limpiar buffer de entrada (cuando tenga conocimiento de arrays y punteros)
			printf("Opcion invalida, intentalo denuevo\n");
		}

		switch (rsp) {
			case cambiar_password:
				printf("ingresa el nuevo password: ");
				while (scanf("%d", &usr1.password) <= 0 || usr1.password > 10000) {
					printf("Opcion invalida, intentalo denuevo\n");
				}
				break;
			case cerrar_sesion:
				return usr1.password;
		}

		printf("Deseas ejecutar otra opcion (1 = si / 2 = no)?: ");
		scanf("%d", &rsp);
		
		if (rsp == cerrar_sesion) loop = 1; 

	}while (loop == 0);

	return usr1.password;
	
}

int main(){

	usrs usr1 = {'b', 1234};
	int password_checker;

	for (int i = 0; i <= 2; i++) {
		printf("Ingresa la contraseña del usuario %c: ", usr1.name);
		scanf("%d", &password_checker);

		if (password_checker == usr1.password) {
			printf("Contraseña correcta, iniciando sesion...\n");
			usr1.password = login(usr1);
			i = 3;

		
		}else {
			if (i <= 1) printf("Contraseña incorrecta, intentalo denuevo\n");
			if (i == 2) printf("maximo de limite establecidos, cerrando sesion.....\n");
		
		}
	
	}


	return 0;

}
