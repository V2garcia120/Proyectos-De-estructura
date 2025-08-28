
#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            cout << "Coca Cola\n";
        }
        else if (i % 3 == 0)
        {
            cout << "Coca\n";
        }
        else if (i % 5 == 0)
        {
            cout << "Cola\n";
        }
        else
        {
            cout << i << "\n";
        }
    }
}
