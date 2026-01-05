#include<iostream>
using namespace std;
int contarPalabras(string oracion){
	int contador = 0;
	for(int i = 0; i < oracion.length(); i++){
		if(oracion[i] != ' ' && (i == 0 || oracion[i-1] == ' ')){
			contador++;
		}
	}
	return contador;
}
int main(){
	string oracion;
	int total;
	cout << "Ingrese una oracion: ";
	getline(cin, oracion);
	total = contarPalabras(oracion);
	cout << "Tiene " << total <<" palabras";
	return 0;
}
