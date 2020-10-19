/*Se desea guardar las notas de 20 alumnos de un curso de ingles.
 Por cada alumno se guarda: nombre y apellido,dni , mail, fecha de nacimiento (struct fecha).
  Tenga en cuenta que cada alumno puede tener cinco notas: escritura, lectura, gramatica, conversacion, literatura.
   Realice un programa que mientras el usuario lo desee, permita:
a- Ingresar los datos del alumno
b- Dado un alumno listar las notas que tiene. SI hay varios con ese apellido, listar todos
c- Mostrar el alumno con menor edad del curso, y el alumno con mayor edad del curso.*/
#include<iostream>
#include <string.h>//libreria string
#include <cstdlib>//libreria de atoi
using namespace std;
struct Fecha{
	int dia;
	int mes;
	int anio;
};
struct Alumnos{
	char nombre[20];
	int dni;
	char mail[20];
	double notas[5];
	Fecha fNac;
};
void mostrarDatos(int j,Alumnos alumno[]);
int validacion(char s[]);
int validacionDni(int n,Alumnos alu[],int s);
void ingNota(int a);
int validacionDouble(char s[]);
int validacionNombre(char nom[],Alumnos alu[],int s);
int main(){
	Alumnos alumno [20];
	char salir;
	char arr[20];
	int a,m=0,h=0,j,x=0,edadM=9999,edad=0;
	do{ 
	cout<<"---------Menu--------------"<<endl<<
	"1.Ingresar datos del alumno"<<endl<<
	"2.Mostrar datos del alumno (segun nombre)"<<endl<<
	"3.Mostrar el alumno mas grande"<<endl<<
	"4.Mostrar el alumno mas joven"<<endl<<
	"5.Salir"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"ingrese la opcion: ";
	cin>>a;
	fflush(stdin);
	cout<<endl;
	switch(a){
	case 1: do{
		do{
	cout<<"ingrese el nombre completo del alumno"<<endl;
	cin.getline(alumno[m].nombre,20);
	fflush(stdin);
	}while(strlen(alumno[m].nombre)==0);
		do{do{
	cout<<"ingrese el numero de dni del alumno "<<alumno[m].nombre<<endl;
	cin.getline(arr,20);
	fflush(stdin);
		}while(validacion(arr)!=0);
	alumno[m].dni =atoi(arr);
		}while(validacionDni(alumno[m].dni,alumno,m)!=0);
	cout<<"ingrese el mail del alumno"<<endl;
	cin.getline(alumno[m].mail,20);
	fflush(stdin);
	do{ do{
	ingNota(h);
	cin.getline(arr,20);
	fflush(stdin);
		}while(validacionDouble(arr)!=0);
	alumno[m].notas[h]=atof(arr);
	h++;
		}while(h<5);
		do{
	cout<<"ingrese el dia de nacimiento de "<<alumno[m].nombre<<endl;
	cin.getline(arr,20);
	fflush(stdin);
		}while(validacion(arr)!=0);
		alumno[m].fNac.dia=atoi(arr);
				do{
	cout<<"ingrese el mes de nacimiento de "<<alumno[m].nombre<<endl;
	cin.getline(arr,20);
	fflush(stdin);
		}while(validacion(arr)!=0);
		alumno[m].fNac.mes=atoi(arr);
			do{
	cout<<"ingrese el anio de nacimiento de "<<alumno[m].nombre<<endl;
	cin.getline(arr,20);
	fflush(stdin);
		}while(validacion(arr)!=0);
		alumno[m].fNac.anio=atoi(arr);
	h=0;
	m++;
		cout<<"si desea salir al menu principal ingrese 'y'(si desea seguir cargando datos ingrese cualquier caracter"<<endl;
		cin>>salir;
		fflush(stdin);
	}while(salir!='y');
	cout<<endl;
	break;
	
	case 2: cout<<endl;
	do{
	cout<<"Ingrese el nombre del alumno para mostrar notas"<<endl;
	cin.getline(arr,20);
	fflush(stdin);
	cout<<endl;
	}while(validacionNombre(arr,alumno,m)==0);//Dado un alumno listar las notas que tiene. SI hay varios con ese apellido, listar todos
   	while(x<m){
		if(strcmpi(alumno[x].nombre,arr)==0){ //strcmpi()compara cadenas sin importar las minusculas o mayusculas
		mostrarDatos(x,alumno);
		cout<<endl;
	}
	x++;} break;
	
	//Mostrar el alumno con menor edad del curso, y el alumno con mayor edad del curso
	case 3:
	cout<<"El alumno mas grande es: "<<endl;
	j=0;
	x=0;
	for( int r=0;r<m;r++){
		if(alumno[r].fNac.anio < edadM){ j=r;
		edadM=alumno[r].fNac.anio;}
	}
	mostrarDatos(j,alumno);
	cout<<endl;
	cout<<endl;
	break;
	case 4: cout<<"El alumno mas chico es: "<<endl;
	for( int r=0;r<m;r++){
		if(alumno[r].fNac.anio > edad){ x=r;
		edad=alumno[r].fNac.anio;
	}
	}
	mostrarDatos(x,alumno);
	break;
	case 5: cout<< "---------Gracias por utilizar nuestro servicio------------"<<endl;break;
	 default: cout<<"Solicitud invalida, por favor ingrese nuevamente"<<endl;break;
}}while(a!=5);
	return 0;
}
int validacionNombre(char nom[],Alumnos alu[],int s){
	int val=0;
if(s!=0){ 
	for(int x=0;x<s;x++)
	{
		if(strcmpi(alu[x].nombre,nom)!=0){ val+= 0;
		}else{val+=1;
		}
	}
}
	return val;
	
}
void mostrarDatos(int j,Alumnos alumno[]){
	cout<<"nombre: "<<alumno[j].nombre<<endl;
	cout<<"numero de dni: "<<alumno[j].dni<<endl;
	cout<<"fecha de nacimiento: "<<alumno[j].fNac.dia<<"/"<<alumno[j].fNac.mes<<"/"<<alumno[j].fNac.anio<<endl;
	cout<<"email: "<<alumno[j].mail<<endl;
	cout<<"nota de escritura: "<<alumno[j].notas[0]<<endl;
	cout<<"nota de lectura: "<<alumno[j].notas[1]<<endl;
	cout<<"nota de gramatica: "<<alumno[j].notas[2]<<endl;
	cout<<"nota de conversacion: "<<alumno[j].notas[3]<<endl;
	cout<<"nota de escritura: "<<alumno[j].notas[4]<<endl;		
}
void ingNota(int a){
	switch(a){
		case 0: cout<<"ingrese la nota de escritura"<<endl;break;
		case 1: cout<<"ingrese la nota de lectura"<<endl;break;
		case 2: cout<<"ingrese la nota de gramatica"<<endl;break;
		case 3: cout<<"ingrese la nota de conversacion"<<endl;break;
		case 4: cout<<"ingrese la nota de literatura"<<endl;break;
	}
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
int validacionDni(int n,Alumnos alu[],int s){
	int val=0;
if(s!=0){ 
	for(int x=0;x<s;x++)
	{
		if(alu[x].dni == n){ val+= 1;
		}else{val+=0;
		}
	}
}
	return val;	
}
int validacionDouble(char s[]){
	int n=0;
	int l=strlen(s);
	char valor;
	if(l==0){n+=1;}//por si aprieta enter sin querer
	for(int x=0;x<l;x++){
	valor = s[x];
	if((valor >='0' && valor<='9')||valor=='.'){
		 n+=0;
	}else{ n+=1;}
}
	return n;
}

