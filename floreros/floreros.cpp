

#include <iostream>
using namespace std;


int main()
{
	int x;
	

	for (x=1; 6*x <= 100; x++)
	{
		int total = 6 * x;
		int restantes = total - 8;
		if (restantes % 11 == 0)
		{
			cout << "la cantidad total es: " << restantes << "\n";
		}
	}
	


}

