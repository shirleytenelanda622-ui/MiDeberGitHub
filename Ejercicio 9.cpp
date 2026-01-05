#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Pelicula {
	int id;
	string titulo;
	string director;
	bool enCartelera;
};
vector<Pelicula> pelicula;

void registrarPelicula(){
	Pelicula datos;
	int estado;
	cout << "ID: ";
	cin >> datos.id;
	cout << "Titulo: ";
	cin.ignore();
	getline(cin, datos.titulo);
	cout << "Director: ";
	getline(cin, datos.director);
	cout << "Estado (1.Cartelera o 0.Fuera de cartelera): ";
	cin >> estado;
	datos.enCartelera = (estado == 1);
	pelicula.push_back(datos);
}

void listarPelicula(){
	for(int i = 0; i < pelicula.size(); i++){
		cout << "ID: " << pelicula[i].id << endl;
		cout << "Titulo: " << pelicula[i].titulo << endl;
		cout << "Director: " << pelicula[i].director << endl;
		cout << "Estado: ";
		if(pelicula[i].enCartelera){
			cout << "en cartelera" << endl;
		} else {
			cout << "fuera de cartelera" << endl;
		}
	}
}

bool buscarPelicula(int id){
	for(int i = 0; i < pelicula.size(); i++){
		if(pelicula[i].id == id){
			cout << endl;
			cout << "ID: " << pelicula[i].id << endl;
			cout << "Titulo: " << pelicula[i].titulo<< endl;
			cout << "Director: " << pelicula[i].director << endl;
			cout << "Estado: ";
				if(pelicula[i].enCartelera){
					cout << "en cartelera" << endl;
				} else {
					cout << "fuera de cartelera" << endl;
				}
			return true;
		}
	}
	return false;
}

bool cambiarEstado(int id){
	for(int i = 0; i < pelicula.size(); i++){
		if(pelicula[i].id == id){
			cout << endl;
			pelicula[i].enCartelera = !pelicula[i].enCartelera;
			return true;
		}
	}
	return false;
}

bool eliminarPelicula(int id){
	for(int i = 0; i < pelicula.size(); i++){
		if(pelicula[i].id == id){
			cout << "\n--- ELIMINANDO ESTUDIANTE ---";
			pelicula.erase(pelicula.begin() + i);
			return true;
		}
	}
	return false;
}

void filtrarPorEstado(bool estado){
    bool encontrado = false;

    for(int i = 0; i < pelicula.size(); i++){
        if(pelicula[i].enCartelera == estado){
            cout << "ID: " << pelicula[i].id << endl;
            cout << "Titulo: " << pelicula[i].titulo << endl;
            cout << "Director: " << pelicula[i].director << endl;
            cout << "Estado: ";
            if(pelicula[i].enCartelera){
                cout << "En cartelera" << endl;
            } else {
                cout << "Fuera de cartelera" << endl;
            }
            cout << "-------------------------" << endl;
            encontrado = true;
        }
    }

    if(!encontrado){
        cout << "No hay peliculas con ese estado." << endl;
    }
}


int main(){
	int opcion, id;
	bool estado;
	do{
		cout << "\n1. Registrar pelicula";
		cout << "\n2. Listar peliculas";
		cout << "\n3. Buscar pelicula por id";
		cout << "\n4. Cambiar estado";
		cout << "\n5. Eliminar pelicula";
		cout << "\n6. Filtrar por estado";
		cout << "\n0. Salir";
		cout << "\nOpcion: ";
		cin >> opcion;
		if (opcion == 1){
			cout << "\n--------------------------\n";
			registrarPelicula();
		}
		if(opcion == 2){
			cout << "\n--------------------------\n";
			listarPelicula();
		}
		if(opcion == 3){
			cout << "\n--------------------------\n";
			cout << "ID a buscar: ";
			cin >> id;
			buscarPelicula(id);
		}
		if(opcion == 4){
			cout << "\n--------------------------\n";
			cout << "ID a cambiar estado: ";
			cin >> id;
			cambiarEstado(id);
		}
		if(opcion == 5){
			cout << "\n--------------------------\n";
			cout << "ID a eliminar: ";
			cin >> id;
			eliminarPelicula(id);
		}
		if(opcion == 6){
			cout << "\n--------------------------\n";
			int est;
			cout << "Filtrar por estado (1= en cartelera, 0 = fuera de cartelera: ";
			cin >> est;
			estado = (est == 1);
			filtrarPorEstado(estado);
		}
		if(opcion == 0){
			cout << "\nSaliendo del programa...";
		}
	} while(opcion != 0);
	return 0;	
}

