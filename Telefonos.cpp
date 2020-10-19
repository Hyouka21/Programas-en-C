#include <iostream>
#include <string.h>//libreria de string
#include <cstdlib>//libreria del atoi que sirve para convertir un string en numero
using namespace std;
int validacion(char s[]);
int main(){
	char telefonos[30];
	char divididos[10];
	string final;
	string arreglo[100];
	int numeros=0;
	char tel;
	int c=0,x=0,m=0,i=0,posicion;
	do{
		cout<<"ingrese los numeros de telefonos separados con una barra '/'(ingrese una barra al final tambien)  "<<endl;
		cin.getline(telefonos,30);
		}while(validacion(telefonos)!=0);
		do{
			while(numeros==0){
				char digito=telefonos[x];
				if(digito=='/'){numeros+=1;
				}else{x++;}
			}
			numeros=0;//x=10
			for(c;c<x;c++){
			 divididos[i]=telefonos[c];
			i++;
			}
			final=divididos;
			arreglo[m]=final;
			for(i=0;i<x;i++){
			 divididos[i]=' ';
			}
			x+=1;
			m++;
			i=0;
			c++;
	}while(x!=strlen(telefonos));
	m--;
	do{
	cout<<"ingrese la posicion del telefono que quiere mostrar"<<endl;
	cin>>posicion;
	}while(posicion>(m));
	cout<<arreglo[posicion];
	return 0;
}
int validacion(char s[]){
	int n=0;
	int l=strlen(s);
	char valor;
	if(l==0){n+=1;}//por si aprieta enter sin querer
	if(s[--l]!='/'){n+=1;}//para que el ultimo sea una /
	for(int x=0;x<l;x++){
	valor = s[x];
	if((valor >='0' && valor<='9')||valor=='/'){
		 n+=0;
	}else{ n+=1;}
}
	return n;
}
