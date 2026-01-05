#include <iostream>
using namespace std;
char tablero[6][6];
void InicializarTablero(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			tablero[i][j] = '~';
		}
	}
}
void barcoHorizontalmente(){
	int fila = rand() % 6;
	int colInicio = rand() % 4;
	for(int i = 0; i < 3; i++){
		tablero[fila][colInicio + i] = 'B';
	}
}
void mostratTablero(){
	cout << "\n--- TABLERO ---\n";
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			cout << tablero[i][j] << " ";
		}
		cout << endl;
	}
}
int torpedo(int fila, int columna){
	if(tablero[fila][columna] == 'B'){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	srand(time(0));
	int fila, columna;
	InicializarTablero();
	barcoHorizontalmente();
	cout << "\nIngresar fila (1 al 6): ";
	cin >> fila;
	if(fila <= 0 || fila > 6){
		cout << "Valor fuera del rango. Intente de nuevo: ";
		cin >> fila;
	}
	cout << "\nIngresar columna (1 al 6): ";
	cin >> columna;
	if(columna <= 0 || columna > 6){
		cout << "Valor fuera del rango (1-6). Intente de nuevo: ";
		cin >> columna;
	}
	fila--;
	columna--;
	
	if(torpedo(fila, columna) == 1){
		cout << "Toco el barco" << endl;
	} else {
		cout << "\nNo toco el barco" << endl;
	}
	return 0;
}
