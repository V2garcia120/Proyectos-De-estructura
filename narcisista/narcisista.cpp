

#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int suma = 0;
	int digito = 0;
	for (int i = 100; i <1000; i++)
	{
		n = i;
		while(n > 0)
		{
			digito = n % 10;
			suma += digito * digito * digito;
			n = n / 10;
		}
		if (suma == i)
		{
			cout << suma << " es un cubo narcisista \n";
			suma = 0;
		}
		
	}
}
