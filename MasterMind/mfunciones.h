
#include "constantes.h"

#ifndef MISFUNCIONES_h
#define MISFUNCIONES_h

bool numeroEstaEn(int array[], int numero);
int marcar_pistas_y_aciertos(int clave[], int jugadas[], std::string historial_pista[][LONGITUD], int intentos);
int pedirNumero();
void clearScreen();
void pause();
void printLogo();
void printInstructions();
void historial_de_jugadas(int historialJugadas[][LONGITUD], std::string historialPistas[][LONGITUD], int intentos);
int calificacion(int intentos);
#endif