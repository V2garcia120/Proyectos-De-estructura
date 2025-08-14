#include <thread>// Libreria para manejar el tiempo
#include <chrono>// Libreria para manejar el tiempo
#include <iostream>// Libreria para manejar el tiempo
#include <random>//Libreria para generar numeros aleatorios
#include <limits>// Libreria para manejar limites de entrada
#include "constantes.h"// Libreria que contiene las constantes del juego
#include "mfunciones.h"// Libreria que contiene las funciones del juego
using namespace std;
using namespace this_thread;
using namespace chrono;

int main()
{
    //Generar numeros aleatorios
    random_device nr;
    mt19937 gen(nr());
    uniform_int_distribution<> dist(MIN, MAX);

    //Declaracion de variables
    int clave[LONGITUD]; //Combinación secreta
    int jugadas[LONGITUD]; //Jugadas en cada intento
    int historial_jugadas[MAX_INTENTOS][LONGITUD]; //Historial de jugadas
	string historial_pistas[MAX_INTENTOS][LONGITUD]; //Historial de pistas
    int intentos = 0; //Cantidad de intentos
    int valor; 
    int aciertos;

	//imprimir logo y mensaje de bienvenida
	printLogo();
    cout << "\nBienvenidos a MasterMind\n\n";
    sleep_for(seconds(1));
    printInstructions();
	sleep_for(seconds(1));
    cout << "\n";
	pause();
	clearScreen();
    cout << "Iniciando MasterMind en version Begginers\n";
    sleep_for(seconds(1));
    cout << "Generando semilla";
    
    //inicializando arrays para que no tengan valores basura
    fill(clave, clave + LONGITUD, 0);
    fill(jugadas, jugadas + LONGITUD, 0);
	for (int i = 0; i < MAX_INTENTOS; ++i)
        for (int j = 0; j < LONGITUD; ++j)
            historial_jugadas[i][j] = 0;
	for (int i = 0; i < MAX_INTENTOS; ++i)
        for (int j = 0; j < LONGITUD; ++j)
            historial_pistas[i][j] = "X";

    //loop para guardar la clave
    for (int i = 0; i < LONGITUD; i++)
    {
        int num;
        sleep_for(milliseconds(500));
        cout << ".";
        do
        {
            num = dist(gen);
        } while (numeroEn(clave, num));
        clave[i] = num;
    }

    cout << "\n\nJuego Iniciado!\n\n";
	pause();
	clearScreen();
	bool gano = false; //bandera para saber si se ha ganado
	cout << "La clave ha sido generada, comienza a adivinarla!\n\n";
	sleep_for(seconds(1));
    //loop para hacer los intentos
    for (int i = 0; i < MAX_INTENTOS && !gano; i++)
    {
       intentos++;
	   clearScreen();   
	   historial_de_jugadas(historial_jugadas,historial_pistas, intentos - 1);
       cout << "\nIntento # "<< intentos << "\n";

       //loop para registrar las jugadas
       for (int j = 0; j < LONGITUD; j++ )
       {
           cout << "Introduzca el numero " << j + 1 << ": ";
           valor = getInt();
           if (numeroEn(jugadas, valor))
           {
               cout << "Ya has seleccionado este numero, intenta otro. \n";
               continue; 
           }
           jugadas[j] = valor;
		   //guardando las jugadas en el historial
		   historial_jugadas[i][j] = jugadas[j];
		
       }
       cout << '\n';

       aciertos = marcar_pistas_y_aciertos(clave, jugadas,historial_pistas, intentos - 1);
       if (aciertos == LONGITUD)
       {
           gano = true;
       }
       //vaciando el array de las jugadas
       fill(jugadas, jugadas + LONGITUD, 0);
    
    }

    if (gano)
    {
		clearScreen();
		historial_de_jugadas(historial_jugadas, historial_pistas, intentos);
        cout << "la clave era: ";
        for (int i = 0; i < LONGITUD; i++) { cout << clave[i]; }
		cout << "\ncalificacion: " << calificacion(intentos) << "\n";
        cout << "\n\nFelicidades haz adivinado la clave\n\nGracias por jugar a MasterMInd!";
		cout << "\n\nPresiona enter para salir";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); // Espera a que el usuario presione Enter
        clearScreen();
        cout << "hecho por: Vismil Garcia,Vismil Garcia, Jeremy Garcia, Hesler Cuevas, Diana Lantigua, Josephine Rosario, Ivan Joa. \n";
        sleep_for(seconds(1));
        clearScreen();
        cout << "Cerrando MasterMind";
        sleep_for(seconds(1));
		clearScreen();
    }
    else
    {
        cout << "\n\nGracias por participar, la clave era: ";
        for (int i = 0; i < LONGITUD; i++) { cout << clave[i]; }
		cout << "\n\nMejor suerte la proxima vez!\n";
		cout << "\n\nPresiona enter para salir";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get(); // Espera a que el usuario presione Enter
		clearScreen();
		cout << "Gracias por jugar a MasterMInd!";
		sleep_for(seconds(1));
		clearScreen();
		cout << "hecho por: Vismil Garcia, Jeremy Garcia, Hesler Cuevas, Diana Lantigua, Josephine Rosario, Ivan Joa. \n";
		sleep_for(seconds(1));
		clearScreen();
        cout << "Cerrando MasterMind";
		sleep_for(seconds(1));
		clearScreen();

    }
}


