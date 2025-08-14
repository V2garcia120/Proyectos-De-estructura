/*
    Tarea 1. Master Mind
  
    Master Mind es un juego que consiste en adivinar 4 números ocultos. Los números están en un
    rango de 1 a 6. Tendrá 10 intentos para adivinar a clave oculta de 4 números (o dígitos) entre 1
    y 6. La mejor calificación se obtendrá haciendo el mínimo de intentos para adivinar la clave.

   
   Autores: Vismil Garcia - 1128719, Jeremy Garcia - 1127276, Hesler Cuevas - 1127855, Diana Lantigua - 1126796, Josephine Rosario - 1127597 e Ivan Joa - 1127943.

   Fecha: 14/8/2025

*/
#include <thread>// // Permite crear y manejar múltiples hilos de ejecución en paralelo (lo usamos para pausar el programa)
#include <chrono>// Libreria para manejar el tiempo
#include <iostream>// Librerias para la entrada y salida.
#include <random>//Libreria para generar numeros aleatorios
#include <limits>// Libreria para manejar limites de entrada
#include "constantes.h"// header que contiene las constantes del juego
#include "mfunciones.h"// header que contiene las funciones del juego
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
	int clave[LONGITUD];//Combinacion Secreta generada por la computadora
	int jugadas[LONGITUD];//array que guarda las jugadas del usuario
	int historial_jugadas[MAX_INTENTOS][LONGITUD];//array que guarda el historial de jugadas del usuario
	int valor;//variable que guarda el valor introducido por el usuario
	int aciertos;//variable que guarda el numero de aciertos del usuario
	string historial_pistas[MAX_INTENTOS][LONGITUD];//array que guarda el historial de pistas del usuario
    // -----------------------------------------------------//
  
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
    // -----------------------------------------------------//
    

    //loop para generar y guardar la clave
    for (int i = 0; i < LONGITUD; i++)
    {
        int num;
        sleep_for(milliseconds(500));
        cout << ".";
        do
        {
            num = dist(gen);
        } while (numeroEstaEn(clave, num));
        clave[i] = num;
    }

    cout << "\n\nJuego Iniciado!\n\n";
	pause();
	clearScreen();
	//intentos = MAX_INTENTOS;
	bool gano = false; //bandera para saber si se ha ganado

	cout << "La clave ha sido generada, comienza a adivinarla!\n\n";
	sleep_for(seconds(1));

	int intentoActual = 0; //contador de intentos
    //loop para hacer los intentos
    for (intentoActual; intentoActual < MAX_INTENTOS && !gano; intentoActual++)
    {
	   clearScreen();   
       //display de jugadas
	   historial_de_jugadas(historial_jugadas,historial_pistas, intentoActual);
       cout << "\nIntento # "<< intentoActual + 1<< "\n";
       int j = 0;//reiniciando contador de vi

       //loop para registrar las jugadas
       while (j < LONGITUD )
       {
           cout << "introduzca el numero " << j + 1 << ": ";
           valor = pedirNumero();

		   // la funcion pedirNumero() devuelve -1 si la entrada no es valida
		   if (valor == -1) {  continue; } //si el numero no es valido, pedir otro
           if (numeroEstaEn(jugadas, valor))
           {
               cout << "Ya has seleccionado este numero, intenta otro. \n";
               continue; 
           }
           jugadas[j] = valor;

		   //guardando las jugadas en el historial
		   historial_jugadas[intentoActual][j] = jugadas[j];
           j++;
		
       }
       cout << '\n';

       aciertos = marcar_pistas_y_aciertos(clave, jugadas,historial_pistas,intentoActual);
       if (aciertos == LONGITUD)
       {
           gano = true;
       }
       //vaciando el array de las jugadas
       fill(jugadas, jugadas + LONGITUD, 0);
    
    }
    clearScreen();
    historial_de_jugadas(historial_jugadas, historial_pistas, intentoActual);
    if (gano)
    {
        cout << "la clave era: ";
        for (int vj = 0; vj < LONGITUD; vj++) { cout << clave[vj]<<" "; }
		cout << "\ncalificacion: " << calificacion(intentoActual) << "\n";
        cout << "\n\nFelicidades haz adivinado la clave\n\nGracias por jugar a MasterMInd!";
    }
    else
    {
        cout << "\n\nGracias por participar, la clave era: ";
        for (int vj = 0; vj < LONGITUD; vj++) { cout << clave[vj]<<" "; }
		cout << "\n\nMejor suerte la proxima vez!\n";
    }
    cout << "\n\nPresiona enter para salir";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Espera a que el usuario presione Enter
    clearScreen();
    cout << "Gracias por jugar a MasterMInd!";
    sleep_for(seconds(1));
    clearScreen();
    cout << "hecho por: Vismil Garcia, Jeremy Garcia, Hesler Cuevas, Diana Lantigua, Josephine Rosario y Ivan Joa. \n";
    sleep_for(seconds(1));
    clearScreen();
    cout << "Cerrando MasterMind";
    sleep_for(seconds(1));
    clearScreen();
}


