#include <iostream>
#include <limits>
#include "constantes.h"
#include "mfunciones.h"
using namespace std;


// Esta función imprime el logo de MasterMind
void printLogo() {
    // This function prints the MasterMind logo
    cout << "  __  __           _____ _______ ______ _____  __  __ _____ _   _ _____  \n";
    cout << " |  \\/  |   /\\    / ____|__   __|  ____|  __ \\|  \\/  |_   _| \\ | |  __ \\ \n";
    cout << " | \\  / |  /  \\  | (___    | |  | |__  | |__) | \\  / | | | |  \\| | |  | |\n";
    cout << " | |\\/| | / /\\ \\  \\___ \\   | |  |  __| |  _  /| |\\/| | | | | . ` | |  | |\n";
    cout << " | |  | |/ ____ \\ ____) |  | |  | |____| | \\ \\| |  | |_| |_| |\\  | |__| |\n";
    cout << " |_|  |_/_/    \\_\\_____/   |_|  |______|_|  \\_\\_|  |_|_____|_| \\_|_____/ \n";

}


// Esta función imprime las instrucciones del juego
void printInstructions() {
    // This function prints the game instructions
    cout << "Instructions:\n";
    cout << "1. La computadora generara un codigo aleatorio entre (1-6).\n";
    cout << "2. Tienes que adivinar la combinacion en un numero limitado de intentos.\n";
    cout << "3. Luego de cada intento resiviras unas pistas:\n";
    cout << "   - 'C' para indicar lugar correcto y numero correcto.\n";
    cout << "   - 'F' para numero correcto pero lugar incorrecto.\n";
    cout << "   - 'X' para numero incorrecto.\n";
}


//Esta función pausa el programa hasta que el usuario presione Enter
void pause()
{
    cout << "Presiona enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


//Esta función limpia la pantalla de la consola
void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // codigos ANSI para limpiar la pantalla y mover el cursor a la esquina superior izquierda
}


//busca si esxite un numero en el array
bool numeroEstaEn(int array[], int numero)
{
   
    for (int i = 0; i < LONGITUD; i++)
    {
        if (array[i] == numero)
        {
            return true;
        }
    }
    return false;
}


// Esta función imprime el historial de jugadas
void historial_de_jugadas(int historialJugadas[][LONGITUD],string historialPistas[][LONGITUD], int intentos) {
    cout << "Historial de jugadas:\n";

	// intentos es equivalente al numero de filas de los array

   
    for (int i = 0; i < intentos; i++)
    {
        cout << "Intento #" << (i + 1) << ": ";
        for (int j = 0; j < LONGITUD; j++)
        {

            cout << historialJugadas[i][j] << " ";
        }
        cout << "|| ";
        for (int j = 0; j < LONGITUD; j++)
        {
            cout << historialPistas[i][j] << " ";
        }
        cout << "\n";
    }
}


//funcion que pide un entero y devuelve 0 si no es valido
int pedirNumero()
{
    int numero;
    cin >> numero;
    if (cin.fail())
    {
        cout << "Por favor solo escribir numeros. \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    else if (numero < MIN || numero > MAX)//validando que este en el rango
    {
        cout << "Solo escribir numeros entre " << MIN << " y " << MAX << "\n";
        return -1;
    }
    else
    {
        if (cin.peek() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "No agregue caracteres extra\n";

            return -1;
        }
        return numero;
    }


}


//funcion que marca las pistas y aciertos
int marcar_pistas_y_aciertos(int clave[],int jugadas[],string historial_pista[][LONGITUD],int intento_actual
)
{
    int aciertos = 0;
    //arrays para marcar si en esa posicion hay una coincidencia
    bool clave_usada[LONGITUD] = { false };
    bool jugada_usada[LONGITUD] = { false };

    //guarda las C de las coincidencias y marca las otras como X
    for (int i = 0; i < LONGITUD; i++)
    {
        if (clave[i] == jugadas[i])
        {
            historial_pista[intento_actual][i] = "C";
            aciertos++;
            clave_usada[i] = true;
            jugada_usada[i] = true;
            
        }
        else
        {
            historial_pista[intento_actual][i] = "X";
        }
    }

    //guarda las F si las hay
    for (int i = 0; i < LONGITUD; i++)
    {
        if (historial_pista[intento_actual][i] == "C") continue;
        for (int k = 0; k < LONGITUD; k++)
        {
            if (!clave_usada[k] && !jugada_usada[i] && clave[k] == jugadas[i])
            {
                historial_pista[intento_actual][i] = "F";
                clave_usada[k] = true;
                jugada_usada[i] = true;
                break;
            }
        }
    }
    return aciertos;
}


// Esta función calcula la calificación del jugador
int calificacion(int intentos)
{
    // Esta función calcula la calificación del jugador
	int calificacion = MAX_INTENTOS - intentos;
	return calificacion;

}