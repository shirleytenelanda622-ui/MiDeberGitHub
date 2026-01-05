#include <iostream>
#include <string>
using namespace std;

struct Vehiculo{
	string marca, modelo;
	int anio;
};
Vehiculo vehiculos[5];

void ingresarDatos(){
	for(int i = 0; i < 5; i++){
		cout << endl;
		cout << "--- VEHICULO " << i+1 << " ---" << endl;
		cout << "Ingresar la marca del vehiculo: ";
		getline(cin,vehiculos[i].marca);
		cout << "Modelo: ";
		getline(cin, vehiculos[i].modelo);
		cout << "Anio: ";
		cin >> vehiculos[i].anio;
		cin.ignore();
	}
}

Vehiculo vehiculoMasReciente(){
	int indiceMayor = 0;
	for(int i = 0; i < 5; i++){
		if(vehiculos[i].anio > vehiculos[indiceMayor].anio){
			indiceMayor = i;
		}
	}
	return vehiculos[indiceMayor];
}

int main(){
	ingresarDatos();
	Vehiculo reciente = vehiculoMasReciente();
	cout << endl;
	cout << "---- VEHICULO MAS RECIENTE ---" << endl;
	cout << "Modelo: " << reciente.modelo << endl;
	cout << "Marca: " << reciente.marca << endl;
	cout << "Anio: " << reciente.anio;
}
