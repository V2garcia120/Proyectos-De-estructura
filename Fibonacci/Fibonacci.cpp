#include <iostream>
using namespace std;

int serieFibonacci(int x)
{
    if (x == 0) return 0;
    if (x == 1)return 1;

    return serieFibonacci(x-1)+serieFibonacci(x-2);
}
int main()
{
    int x;
    cout << "cual es la cantidad de elemtos de la serie de fibonacci quieres ver? ";
    cin >> x;
    for (int i = 1;i <= x;i++) {
        cout << serieFibonacci(i)<< " ";
    }
}
