
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    std::cout << "Determinar el mayor numero \n";
    float Lista[5];
    int i;
   
    for (i = 0; i < 5; i++)
    {
        cout << "Escribe el numero " << i + 1 << ": ";
        while (!(cin >> Lista[i]))
        {
            cout << "Escrie solo numeros \n";
            cin.clear();
            cin.ignore();
        }
    }

    float j = Lista[i];
    for (i = 1; i < 5; i++)
    {
        if (Lista[i] > j)
        {
            j = Lista[i];
        }
    }
    std::cout << "El mayor es: " << j;
    return 0;
}

