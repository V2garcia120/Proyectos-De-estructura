// Primos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void primos(int x);
int getint();
int main()
{
    cout << "Impresora de numeros primos" << endl;
    cout << "Hasta que numero quieres ver los numeros primos?" << endl;
    int numero = getint();
    primos(numero);



}
void primos(int x)
{
    if (x < 2) {
        cout << "no hay numeros primos menores que 2" << endl;
        return;
    }
    for (int i = 2; i<= x; i++){
        bool primo = true;
        for(int j = 2; j*j<=i; j++)
        {
            if (i%j == 0)
            {
                primo = false;
                break;
            }
           
        }
        if (primo){
            cout << i<< " ";
        }
    }

}
int getint()
{
    int numero = 0;
    bool valido = false;
    while (!valido)
    {
        cout << "Introduza el numero: ";
        cin >> numero;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Solo introduza numeros";
            continue;
        }
        else if (cin.peek() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "No agregue caraccteres extra\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return numero;
    }

}