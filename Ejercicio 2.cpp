#include <iostream>
using namespace std;

int chocolate[4][6];

void llenarLaMatriz(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 6; j++){
			cout << "Ingrese la dulzura para la fila " << i+1 << " columna " << j+1 << " (1-9): ";
			cin >> chocolate[i][j];
		}
	}
}

int sumarMatriz(){
	int suma = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 6; j++){
			suma += chocolate[i][j];
		}
	}
	return suma;
}

int main(){
	llenarLaMatriz();
	int suma = sumarMatriz();
	double Promedio = suma / 24.0;
	cout << "\nPromedio: " << Promedio << endl;
}
