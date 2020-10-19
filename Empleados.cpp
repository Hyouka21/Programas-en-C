#include<iostream>
#include <string.h>//libreria string
#include <cstdlib>//libreria de atoi
using namespace std;
struct Sector{
int legajo[4];
double ventaTotal[4]; 
};
struct Empleados{
	char nombre [20];
	int legajo;
	int sector;
	double ventasDia[6];
	double ventasTotales;
};
void mostrarDia(int a);
void mostrarSector(int a);
int validacionLegajo(int n,Empleados emp[],int s);
int validacion(char s[]);
int validacionFloat(char a[]);
int main(){
	Empleados empleado[20];
	int sectores[4];//Bazar,accesorios,indumetaria,calzados
	int m=0,h=0,a;
	char arr[10];
	char salir;
   for(int n=0;n<4;n++){
   sector.ventaTotal[n]=0;
}
	Sector sector;
		do{ 
	cout<<"---------Menu--------------"<<endl<<
	"1.Ingresar datos del empleado"<<endl<<
	"2.Mostrar datos del empleado premiado segun sector"<<endl<<
	"3.Mostrar todos los empleados"<<endl<<
	"4.Salir"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"ingrese la opcion: ";
	cin>>a;
	fflush(stdin);
	cout<<endl;
	switch(a){
	case 1:do{
		do{
	cout<<"ingrese el nombre completo del empleado"<<endl;
	cin.getline(empleado[m].nombre,20);
	fflush(stdin);}while(strlen(empleado[m].nombre)==0);
do{
	do{
	cout<<"ingrese el numero de legajo que le va a asignar a "<<empleado[m].nombre<<endl;
	cin.getline(arr,10);
	fflush(stdin);
}while(validacion(arr)!=0);
	empleado[m].legajo=atoi(arr);
}while(validacionLegajo(empleado[m].legajo,empleado,m)!=0);
  do{
  do{
   cout<<"asigne el sector: ('0'Bazar,'1'Accesorios,'2'Indumentaria,'3'Calzados)"<<endl;
   	cin.getline(arr,10);
	fflush(stdin);
	}while(validacion(arr)!=0);
  empleado[m].sector=atoi(arr);
}while(empleado[m].sector>3 || empleado[m].sector<0); 
do{ 
	do{
	mostrarDia(h);
	cin.getline(arr,10);
	fflush(stdin);
	}while(validacionFloat(arr)!=0);
	empleado[m].ventasDia[h]=atof(arr);
	empleado[m].ventasTotales += empleado[m].ventasDia[h];
	h++;
}while(h<6);
h=0;
m++;
cout<<"si desea salir al menu principal ingrese 'y'(sino ingrese cualquier caracter para seguir cargando empleados) "<<endl;
cin>>salir;
fflush(stdin);
}while(m<20 && salir!='y');break;
//recorrer cada sector y almacenar los datos del mejor vendedor
case 2: for(int i=0;i<4;i++){
	 for(int f=0;f<m;f++){
	 	if(i==empleados[f].sector){
	 	if(sector.ventaTotal[i]<empleados[f].ventasTotales){
	 			sector.ventaTotal[i]=empleado[f].ventasTotales;
	 			sector.legajo[i]=empleado[f].legajo;
		 }
		 }
	 }
 }/* switch(empleado[f].sector){
 	case 0: if(sector.ventaTotal[0]<empleado[f].ventasTotales){
	 sector.ventaTotal[0]=empleado[f].ventasTotales;
	 sector.legajo[0]=empleado[f].legajo;}break;
 	case 1: if(sector.ventaTotal[1]<empleado[f].ventasTotales){
	 sector.ventaTotal[1]=empleado[f].ventasTotales;
	 sector.legajo[1]=empleado[f].legajo;}break;
 	case 2: if(sector.ventaTotal[2]<empleado[f].ventasTotales){
	 sector.ventaTotal[2]=empleado[f].ventasTotales;
	 sector.legajo[2]=empleado[f].legajo;}break;
 	case 3: if(sector.ventaTotal[3]<empleado[f].ventasTotales){
	 sector.ventaTotal[3]=empleado[f].ventasTotales;
	 sector.legajo[3]=empleado[f].legajo;}break;
	 }*/
//mostrar los datos de los empleados que fueron premiados
cout<<"los empleados que fueron premiados segun su sector son: "<<endl;
for(int q=0;q<4;q++){
	mostrarSector(q);
	cout<<"numero de legajo: "<<sector.legajo[q]<<endl;
	cout<<"ventas: "<<sector.ventaTotal[q]<<endl;
}break;
//muestra todos los empleados
case 3:for(int z=0;z<4;z++){
cout<<endl;
cout<<"legajo nro: "<<empleado[z].legajo<<endl;
cout<<empleado[z].nombre<<endl;
mostrarSector(empleado[z].sector);
cout<<empleado[z].ventasTotales;	
}break;
case 4: cout<<"gracias por utilizar nuestro servicio"<<endl;break;
default: cout<<"Solicitud invalida, por favor ingrese nuevamente"<<endl;break;
}}while(a!=4);
return 0;
}
void mostrarDia(int a){
	switch(a){
		case 0: cout<<"ingrese la venta del dia Lunes"<<endl;break;
		case 1: cout<<"ingrese la venta del dia Martes"<<endl;break;
		case 2: cout<<"ingrese la venta del dia Miercoles"<<endl;break;
		case 3: cout<<"ingrese la venta del dia Jueves"<<endl;break;
		case 4: cout<<"ingrese la venta del dia Viernes"<<endl;break;
		case 5: cout<<"ingrese la venta del dia Sabado"<<endl;break;
	}
}
void mostrarSector(int a){
	switch(a){
		case 0: cout<<"Sector Bazar"<<endl;break;
		case 1: cout<<"Sector Accesorios"<<endl;break;
		case 2: cout<<"Sector Indumentaria"<<endl;break;
		case 3: cout<<"Sector Calzados"<<endl;break;
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
int validacionFloat(char a[]){
	int n=0;
	int l=strlen(a);
	char valor;
	if(l==0){n+=1;}//por si aprieta enter sin querer
	for(int x=0;x<l;x++){
	valor = a[x];
	if((valor >='0' && valor<='9')||valor=='.'){
		 n+=0;
	}else{ n+=1;}
}
	return n;
}
int validacionLegajo(int n,Empleados emp[],int s){
	int val=0;
if(s!=0){ 
	for(int x=0;x<s;x++)
	{
		if(emp[x].legajo == n){ val+= 1;
		}else{val+=0;
		}
	}
}
	return val;
	
}
