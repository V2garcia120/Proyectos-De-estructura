#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n = 37;
	int anterior = 1;
	int sig = 0;
	double suma = 0;
	int i = 1;
	int ser;
	double potencia;

	while (i <= n)
	{
		ser = anterior + sig;
		anterior = sig;
		sig = ser;
		potencia = pow(2, i);
		suma += ser / potencia;
		i++;

	}
	double segundos = suma - int(suma);
	cout << "se atraso: "<<int(suma)<<" Minuto con "<< int(segundos*60)<< " segundos";
}
