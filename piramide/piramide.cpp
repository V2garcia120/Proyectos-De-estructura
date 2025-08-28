#include <iostream>
using namespace std;
int main()
{
    int altura = 7;
	int j = 1;
    int i = 1;
    for (i = 1; i <= altura;i++)
    {
        cout << "*";
        if (i == j)
        {
            if (i == altura)
            {
				break;
			}
            cout << "\n";
            i = 0;
            j++;
			continue;
        }
    }
}

