/*Defina una estructura “contacto” donde guardar: nombre, teléfono, mail  y fecha de nacimiento ( estructura fecha) .
 Realice un programa que cargue un máximo de  40 contactos ( puede cargar menos contactos). El programa debe permitir, mientras el usuario lo desee:

    1-Ingresar  un contacto.
    2-Ingresar una fecha, y mostrar todos los contactos que cumplen años ese dia.
    3-Ingresar un nombre y mostrar los datos del primer contacto con ese nombre.
*/
#include <iostream>
#include <string.h>
#include <cstdlib>//libreria de atoi
using namespace std;
struct Fecha{
	int anio;
	int mes;
	int dia;
};
struct Contacto{
	char nombre[30];
	char apellido[30];
	int telefono;
	char mail[30];
	Fecha fNacimiento;
};
int validacionLetras(char s[]);// esta funcion sirve para controlar que las palabras no tenga numero ni espacio
int validacion(char s[]);
int main(){
	Contacto contacto [40];
	int opcion=0,m=0,h=0;
	int dia;
	int mes;
	int anio;
	int elegir;
	int comprobante=0;
	char nombre[30];
	char apellido[30];
	char arr[20];
	cout<<"......Bienvenido..........."<<endl;
	do{
		cout<<"1-Ingresar  un contacto."<<endl;
		cout<<"2-Ingresar una fecha, y mostrar todos los contactos que cumplen años ese dia."<<endl;
		cout<<"3-Ingresar un nombre y mostrar los datos del primer contacto con ese nombre."<<endl;
		cout<<"4-salir"<<endl;
		do{
		cout<<"Ingrese una opcion: ";
		cin.getline(arr,20);
		fflush(stdin);
		}while(validacion(arr)!=0);
		opcion=atoi(arr);
		switch(opcion){
			case 1:{
				do{
				cout<<"ingrese el nombre "<<endl;
				cin.getline(contacto[m].nombre,30);
				fflush(stdin);
				}while(validacionLetras(contacto[m].nombre)!=0);
				do{
				cout<<"ingrese el apellido "<<endl;
				cin.getline(contacto[m].apellido,30);
				fflush(stdin);
				}while(validacionLetras(contacto[m].nombre)!=0);
				do{				
				cout<<"ingrese el numero de telefono"<<endl;
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				contacto[m].telefono=atoi(arr);

				cout<<"ingrese el correo electronico"<<endl;
				cin.getline(contacto[m].mail,30);
				cout<<"ingrese su fecha de nacimiento"<<endl;
				do{do{
				cout<<"dia: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				contacto[m].fNacimiento.dia=atoi(arr);
				}while(contacto[m].fNacimiento.dia>31||contacto[m].fNacimiento.dia==0);
				do{do{
				cout<<"mes: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				contacto[m].fNacimiento.mes=atoi(arr);
				}while(contacto[m].fNacimiento.mes>12||contacto[m].fNacimiento.mes==0);
				do{do{
				cout<<"anio: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				contacto[m].fNacimiento.anio=atoi(arr);	
				}while(contacto[m].fNacimiento.anio>2020||contacto[m].fNacimiento.anio<1950);	
				m++;
				system("pause");//pausa para que puedas esperar y ver
						system("cls");	//limpia la pantalla	
				break;
			}
			case 2:{
				cout<<"ingrese la fecha para filtrar"<<endl;
				do{do{
				cout<<"dia: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				dia=atoi(arr);
				}while(dia>31||dia==0);
				do{do{
				cout<<"mes: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				mes=atoi(arr);
				}while(mes>12||mes==0);
				for(int x=0;x<m;x++){
					if((dia==contacto[x].fNacimiento.dia)&&(mes==contacto[x].fNacimiento.mes)){
						cout<<"nombre: "<<contacto[x].nombre<<" "<<contacto[x].apellido<<endl;
						cout<<"mail: "<<contacto[x].mail<<endl;
						cout<<"telefono: "<<contacto[x].telefono<<endl;
					}
				}
				system("pause");//pausa para que puedas esperar y ver
						system("cls");	//limpia la pantalla					
				break;
			}
			case 3:{
				do{
					do{
				cout<<"eliga que quiere comparar"<<endl;
				cout<<"1.Solo el nombre"<<endl;
				cout<<"2.Solo el apellido"<<endl;
				cout<<"ingrese la opcion: ";
				cin.getline(arr,20);
				fflush(stdin);
				}while(validacion(arr)!=0);
				elegir=atoi(arr);
				}while(elegir<1||elegir>2);	
				switch(elegir){
					case 1:{ 
						comprobante=0;
						h=0;
						do{
						cout<<"ingrese el nombre: ";
						cin.getline(nombre,30);
						fflush(stdin);
						}while(validacionLetras(nombre)!=0);
							while(comprobante==0){
							if(strcmpi(nombre,contacto[h].nombre)==0){
								comprobante+=1;}else{h++;}
							}
						cout<<"nombre: "<<contacto[h].nombre<<" "<<contacto[h].apellido<<endl;
						cout<<"mail: "<<contacto[h].mail<<endl;
						cout<<"telefono: "<<contacto[h].telefono<<endl;
						system("pause");//pausa para que puedas esperar y ver
						system("cls");	//limpia la pantalla							
							break;
						}
					case 2:{
						comprobante=0;
						h=0;
						do{
						cout<<"ingrese el apellido: ";
						cin.getline(apellido,30);
						fflush(stdin);
						}while(validacionLetras(apellido)!=0);
							while(comprobante==0){
							if(strcmpi(apellido,contacto[h].apellido)==0){
								comprobante+=1;}else{h++;}
							}
						cout<<"nombre: "<<contacto[h].nombre<<" "<<contacto[h].apellido<<endl;
						cout<<"mail: "<<contacto[h].mail<<endl;
						cout<<"telefono: "<<contacto[h].telefono<<endl;	
						system("pause");//pausa para que puedas esperar y ver
						system("cls");	//limpia la pantalla					
						break;
						}
				}
				break;
			}
			case 4:{
				cout<<"gracias por utilizar el programa"<<endl;
				system("pause");//pausa para que puedas esperar y ver
				break;
			}
		}
		system("cls");	//limpia la pantalla
	}while(opcion!=4);
	

	return 0;
}
int validacion(char s[]){
	int n=0;
	int l=strlen(s);
	char valor;
	if(l==0){n+=1;}//por si aprieta enter sin querer
	for(int x=0;x<l;x++){
	valor = s[x];
	if(valor >='0' && valor<='9'){
		 n+=0;
	}else{ n+=1;}
}
	return n;
}
int validacionLetras(char s[]){// esta funcion sirve para controlar que las palabras no tenga numero ni espacio
	int n=0;
	int l=strlen(s);
	char valor;
	if(l==0){n+=1;}//por si aprieta enter sin querer
	for(int x=0;x<l;x++){
	valor = s[x];
	if((valor >='0' && valor<='9')||valor==' '){
		 n+=1;
	}else{ n+=0;}
}
	return n;
}
