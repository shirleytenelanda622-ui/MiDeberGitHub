#include <iostream>
#include <string>
using namespace std;

void mostrarNumeros(string numeros){
	for(int i = 0; i < numeros.length();i++){
		if(numeros[i] == '='){
			break;
		} else if(numeros[i] >= '0' && numeros[i] <= '9'){
			cout << numeros[i] << " ";
		}
	}
}
string mostrarOperadores(string numeros){
	string operador;
	for(int i = 0; i < numeros.length(); i++){
		if(numeros[i] == '='){
			break;
		} else if(numeros[i] == '+' || numeros[i] == '-' || numeros[i] == '*' || numeros[i] == '/'){
			operador += numeros[i];
			operador += ' ';
		}
	}
	return operador;
}

void mostrarOtros(string numeros){
	for(int i = 0; i < numeros.length(); i++){
		if(numeros[i] == '='){
			break;
		} else if((numeros[i] != '+' && numeros[i] != '-'&& numeros[i] != '*' && numeros[i] != '/') && !(numeros[i] >= '0' && numeros[i] <= '9')){
			cout << numeros[i] << " ";
		}
	}
}

int main(){
	string numeros, operador;
	cout << "Ingresar funcion: ";
	cin >> numeros;
	cout << "Numeros: ";
	mostrarNumeros(numeros);
	operador = mostrarOperadores(numeros);
	cout << "\nOperadores: " << operador;
	cout << "\nOtros: ";
	mostrarOtros(numeros);
}
