// Piramide de bolas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int bolas = 10000;
	int quitar = 0;
	int bolasEnPiramide = 0;
	int capas = 0;
	int totalquitar = 0;

	while(!((bolas -= quitar * quitar) < 0))
	{
		totalquitar = quitar * quitar;
		bolasEnPiramide += totalquitar;
		std::cout << "bolas restantes: " << bolas << "\n";
		std::cout << "bolas en la piramide: " << bolasEnPiramide << "\n";
		std::cout << "quitadas en este turno: " << totalquitar << "\n";
		std::cout << "capas: " << capas << "\n";
		capas++;
		quitar++;
	}

  
}


