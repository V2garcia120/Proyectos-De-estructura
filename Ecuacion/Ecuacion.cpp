// Ecuacion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cctype>
#include <iostream>

int pedirNumero()
{
	bool valido = true;
	double numero;
	while (valido) 
	{
		std::cout << "Ingrese un numero: ";
		std::cin >> numero;
		if (std::cin.fail())
		{
			std::cout << "Por favor solo escribir numeros. \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
		}
		else
		{
			if (isalpha(std::cin.peek()))
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "No agregue caracteres extra\n";
				
			}
			else
			{
				return numero;
			}
			
		}
	}
}
int main()
{
	double x1, x2;
	double a;
	double b;
	double c;
	bool termino = false;
	while (termino)
	{
		std::cout << "Ecuacion de segundo grado: ax^2 + bx + c = 0\n";
		std::cout << "Ingrese los valores de a, b y c\n";
		a = pedirNumero();
		b = pedirNumero();
		c = pedirNumero();
		if (a == 0 && b == c)
		{
			std::cout << "las variables a y b no pueden ser 0";
		}
		else if (a == 0)
		{
			std::cout << "La solucion es: " << -b / a;
		}
		else 
		{
			double discriminante = (b * b) - (4 * a * c);
			if (discriminante < 0)
			{
				std::cout << "No tiene solucion en los numeros reales\n";
			}
			else if (discriminante == 0)
			{
				double x = -b / (2 * a);
				std::cout << "Tiene una solucion: x = " << x << "\n";
			}
			else
			{
				double x1 = (-b + sqrt(discriminante)) / (2 * a);
				double x2 = (-b - sqrt(discriminante)) / (2 * a);
				std::cout << "Tiene dos soluciones: x1 = " << x1 << " y x2 = " << x2 << "\n";

			}
		}
	}
}


