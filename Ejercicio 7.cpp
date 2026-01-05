#include <iostream>
#include <string>
using namespace std;

string chat[] = {
    "08:15//Roberto//Hola perdida, ¿como estas?",
    "08:17//Belen//Bien, gracias. ¿Y tu?",
    "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
    "08:21//Belen//Tu novia, ¿si te da permiso?",
	"08:22//Roberto//Cual novia?. Es una amiga nomas",
	"08:23//Roberto//mejor tu pide permiso a tu novio?"
};
string hora[6];
string usuarios[6];
string mensaje[6];

void mostrarHora(){
	for(int i = 0; i < 6; i++){
		int pos1 = chat[i].find("//");
		int pos2 = chat[i].find("//", pos1 +2);
		hora[i] = chat[i].substr(0, pos1);
		usuarios[i] = chat[i].substr(pos1+2, pos2-(pos1+2));
		mensaje[i] = chat[i].substr(pos2 +2);
		cout << hora[i] << " " << usuarios[i] << ": " << mensaje[i] << endl;
	}
}

int contarRoberto(){
	int contRoberto = 0;
	for(int i = 0; i < 6; i++){
		if(usuarios[i] == "Roberto"){
			contRoberto++;
		}
	}
	return contRoberto;
}
int contarBelen(){
	int contBelen = 0;
	for(int i = 0; i < 6; i++){
		if(usuarios[i] == "Belen"){
			contBelen++;
		}
	}
	return contBelen;
}
int main(){
	int contRoberto, contBelen;
	mostrarHora();
	contRoberto = contarRoberto();
	cout << "\nTotal mensajes enviados de Roberto: " << contRoberto;
	contBelen = contarBelen();
	cout << "\nTotal mensajes enviados de Belen: " << contBelen;
	return 0;
}

