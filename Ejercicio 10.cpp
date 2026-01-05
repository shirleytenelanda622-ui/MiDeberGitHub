#include <iostream>
#include <vector>
using namespace std;
struct Jugador {
    int id;
    string nombre;
    string posicion;
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores; // Vector anidado
};

vector<Equipo> equipos; // Lista global de equipos

void registrarEquipo() {
    Equipo e;
    cout << "ID del equipo: ";
    cin >> e.id;
    cin.ignore();
    cout << "Nombre del equipo: ";
    getline(cin, e.nombre);
    cout << "Nombre del entrenador: ";
    getline(cin, e.entrenador);
    e.jugadores.clear(); // Inicialmente sin jugadores
    equipos.push_back(e);
    cout << "Equipo registrado correctamente.\n";
}

void agregarJugador() {
    int idEquipo;
    cout << "ID del equipo al que se agregará el jugador: ";
    cin >> idEquipo;
    cin.ignore();

    bool encontrado = false;
    for(auto &e : equipos) {
        if(e.id == idEquipo) {
            Jugador j;
            cout << "ID del jugador: ";
            cin >> j.id;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, j.nombre);
            cout << "Posición: ";
            getline(cin, j.posicion);
            cout << "Edad: ";
            cin >> j.edad;
            e.jugadores.push_back(j);
            cout << "Jugador agregado correctamente al equipo " << e.nombre << ".\n";
            encontrado = true;
            break;
        }
    }
    if(!encontrado) {
        cout << "Equipo no encontrado.\n";
    }
}

void listarEquipos() {
    for(const auto &e : equipos) {
        cout << "\nID: " << e.id << " | Nombre: " << e.nombre 
             << " | Entrenador: " << e.entrenador << endl;
        if(e.jugadores.empty()) {
            cout << "  No hay jugadores registrados.\n";
        } else {
            for(const auto &j : e.jugadores) {
                cout << "  ID: " << j.id << " | Nombre: " << j.nombre 
                     << " | Posición: " << j.posicion 
                     << " | Edad: " << j.edad << endl;
            }
        }
        cout << "--------------------------\n";
    }
}

void buscarEquipo() {
    int id;
    cout << "ID del equipo a buscar: ";
    cin >> id;
    cin.ignore();
    bool encontrado = false;
    for(const auto &e : equipos) {
        if(e.id == id) {
            cout << "\nID: " << e.id << " | Nombre: " << e.nombre 
                 << " | Entrenador: " << e.entrenador << endl;
            if(e.jugadores.empty()) cout << "  No hay jugadores.\n";
            else {
                for(const auto &j : e.jugadores) {
                    cout << "  ID: " << j.id << " | Nombre: " << j.nombre 
                         << " | Posición: " << j.posicion 
                         << " | Edad: " << j.edad << endl;
                }
            }
            encontrado = true;
            break;
        }
    }
    if(!encontrado) cout << "Equipo no encontrado.\n";
}

void eliminarJugador() {
    int idEquipo, idJugador;
    cout << "ID del equipo: ";
    cin >> idEquipo;
    cout << "ID del jugador a eliminar: ";
    cin >> idJugador;
    bool encontradoEquipo = false, encontradoJugador = false;

    for(auto &e : equipos) {
        if(e.id == idEquipo) {
            encontradoEquipo = true;
            for(int i = 0; i < e.jugadores.size(); i++) {
                if(e.jugadores[i].id == idJugador) {
                    e.jugadores.erase(e.jugadores.begin() + i);
                    cout << "Jugador eliminado correctamente.\n";
                    encontradoJugador = true;
                    break;
                }
            }
            if(!encontradoJugador) cout << "Jugador no encontrado.\n";
            break;
        }
    }
    if(!encontradoEquipo) cout << "Equipo no encontrado.\n";
}

void filtrarPorEntrenador() {
    cin.ignore();
    string nombreEntrenador;
    cout << "Nombre del entrenador a filtrar: ";
    getline(cin, nombreEntrenador);
    bool encontrado = false;
    for(const auto &e : equipos) {
        if(e.entrenador == nombreEntrenador) {
            cout << "\nID: " << e.id << " | Nombre: " << e.nombre << endl;
            encontrado = true;
        }
    }
    if(!encontrado) cout << "No se encontraron equipos de este entrenador.\n";
}

void eliminarEquipo() {
    int id;
    cout << "ID del equipo a eliminar: ";
    cin >> id;
    for(int i = 0; i < equipos.size(); i++) {
        if(equipos[i].id == id) {
            equipos.erase(equipos.begin() + i);
            cout << "Equipo eliminado correctamente.\n";
            return;
        }
    }
    cout << "Equipo no encontrado.\n";
}

int main() {
    int opcion;
    do {
        cout << "\n--- MENÚ CLUB DEPORTIVO ---\n";
        cout << "1. Registrar equipo\n";
        cout << "2. Agregar jugador a un equipo\n";
        cout << "3. Listar equipos con jugadores\n";
        cout << "4. Buscar equipo por ID\n";
        cout << "5. Eliminar jugador de un equipo\n";
        cout << "6. Filtrar equipos por entrenador\n";
        cout << "7. Eliminar equipo completo\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarEquipo(); break;
            case 2: agregarJugador(); break;
            case 3: listarEquipos(); break;
            case 4: buscarEquipo(); break;
            case 5: eliminarJugador(); break;
            case 6: filtrarPorEntrenador(); break;
            case 7: eliminarEquipo(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while(opcion != 0);

    return 0;
}
