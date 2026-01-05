#include <iostream>
#include <vector>
using namespace std;

struct PocionMagica{
	vector<string> ingredientes ;
	string nombre;
	int tiempoPreparacion;
	string efectoMagico;
};
void Pociones(PocionMagica pocion[]){
	pocion[0].nombre = "Pocion de Fuerza";
	pocion[0].tiempoPreparacion = 30;
	pocion[0].efectoMagico = "Aumenta la fuerza";
	pocion[0].ingredientes.push_back("Raiz de mandragora");
	pocion[0].ingredientes.push_back("Polvo de hierro");
	pocion[1].nombre = "Pocion de Invisibilidad";
	pocion[1].tiempoPreparacion = 45;
	pocion[1].efectoMagico = "Vuelve invisible";
	pocion[1].ingredientes.push_back("Hojas de sombra");
	pocion[1].ingredientes.push_back("Raiz de mandragora");
	pocion[2].nombre = "Pocion curativa";
	pocion[2].tiempoPreparacion = 20;
	pocion[2].efectoMagico = "Recupera la salud";
	pocion[2].ingredientes.push_back("Miel");
	pocion[2].ingredientes.push_back("Hierbas verdes");
}

bool buscarIngrediente(PocionMagica pocion[], string ingrediente){
	bool encontrado = false;
	cout << "Pociones que usan '" << ingrediente << "': ";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < pocion[i].ingredientes.size(); j++){
			if(pocion[i].ingredientes[j] == ingrediente){
				cout << "\n- " << pocion[i].nombre;
				encontrado = true;
			}
		}
	}
	return encontrado;
}

int main(){
	PocionMagica pocion[3];
	string ingrediente;
	Pociones(pocion);
	cout << "Ingrese un ingrediente para buscar: ";
	getline(cin, ingrediente);
	if(!buscarIngrediente(pocion, ingrediente)){
		cout << "No se encontro pociones con ese ingrediente";
	}
}
