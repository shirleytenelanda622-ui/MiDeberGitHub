#include <iostream>
#include <vector>
using namespace std;
struct Estudiantes{
	int id;
	string nombre;
	string carrera;
	double promedio;
};
vector<Estudiantes> estudiantes;

void registrarEstudiante(){
	Estudiantes datos;
	cout << "Ingresar ID: ";
	cin >> datos.id;
	cout << "Nombre: ";
	cin.ignore();
	getline(cin, datos.nombre);
	cout << "Carrera: ";
	getline(cin, datos.carrera);
	cout << "Promedio academico: ";
	cin >> datos.promedio;
	estudiantes.push_back(datos);
}
void listarEstudiantes(){
	for(int i = 0; i < estudiantes.size(); i++){
		cout << "ID: " << estudiantes[i].id<< endl;
		cout << "Nombre: " << estudiantes[i].nombre << endl; 
		cout << "Carrera: " << estudiantes[i].carrera << endl;
		cout << "Promedio academico: " << estudiantes[i].promedio << endl;
		cout << endl;
	}
}
bool buscarEstudiante(int id){
	for(int i = 0; i <estudiantes.size(); i++){
		if(estudiantes[i].id == id){
			cout << endl;
			cout << "ID: " << estudiantes[i].id << endl;
			cout << "Nombre: " << estudiantes[i].nombre << endl;
			cout << "Carrera: " << estudiantes[i].carrera << endl;
			cout << "Promedio academico: " << estudiantes[i].nombre << endl;
			return true;
		}
	}
	return false;
}
bool actualizarEstudiante(int id){
	for(int i = 0; i < estudiantes.size(); i++){
		if(estudiantes[i].id == id){
			cout << endl;
			cout << "\n--- ACTAUZALIZAR ESTUDIANTE---";
			cout << "\nID: " << id;
			cout << "\nNombre: ";
			getline(cin, estudiantes[i].nombre);
			cout << "Carrera: ";
			getline(cin, estudiantes[i].carrera);
			cout << "Promedio academico: ";
			cin >> estudiantes[i].promedio;
			return true;
		}
	}
	return false;
}

bool eliminarEstudiante(int id){
	for(int i = 0; i < estudiantes.size(); i++){
		if(estudiantes[i].id == id){
			cout << "\n--- ELIMINANDO ESTUDIANTE ---";
			estudiantes.erase(estudiantes.begin() + i);
		}
	}
}

vector<Estudiantes> promediosAprobados(){
	vector<Estudiantes> aprobados;
	for(int i = 0; i < estudiantes.size(); i++){
		if(estudiantes[i].promedio >= 14){
			aprobados.push_back(estudiantes[i]);
		}
	}
	return aprobados;
}

int main(){
	int opcion, id;
	do{
		cout << "\n1. Registrar estudiante";
		cout << "\n2. Listar estudiantes";
		cout << "\n3. Buscar estudiante";
		cout << "\n4. Actualizar estudiante";
		cout << "\n5. Eliminar estudiante";
		cout << "\n6. Mostrar estudiantes aprobados";
		cout << "\n0. Salir";
		cout << "\nOpcion: ";
		cin >> opcion;
		if (opcion == 1){
			cout << "\n--------------------------\n";
			registrarEstudiante();
		}
		if(opcion == 2){
			cout << "\n--------------------------\n";
			listarEstudiantes();
		}
		if(opcion == 3){
			cout << "\n--------------------------\n";
			cout << "ID a buscar: ";
			cin >> id;
			buscarEstudiante(id);
		}
		if(opcion == 4){
			cout << "\n--------------------------\n";
			cout << "ID a actualizar: ";
			cin >> id;
			actualizarEstudiante(id);
		}
		if(opcion == 5){
			cout << "\n--------------------------\n";
			cout << "ID a eliminar: ";
			cin >> id;
			eliminarEstudiante(id);
		}
		if(opcion == 6){
			cout << "\n--------------------------\n";
			cout << "Estudiantes aprobados: ";
			promediosAprobados();
		}
		if(opcion == 0){
			cout << "\nSaliendo del programa...";
		}
	} while(opcion != 0);
	return 0;
}
