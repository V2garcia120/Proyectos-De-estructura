/*
   Tarea 2. Pila

    Una pila (stack) es una estructura de datos en donde el último en entrar es el primero en salir.
    Construir un programa C++ que simule una pila, utilizando una estructura de datos como la que
    sigue para los nodos:
    struct Pila {
    int dato;
    Pila *next;
    };



   Autores: Vismil Garcia - 1128719, Jeremy Garcia - 1127276, Hesler Cuevas - 1127855, Diana Lantigua - 1126796, Josephine Rosario - 1127597 e Ivan Joa - 1127943.

   Fecha: 28/8/2025

*/

#include <iostream>
#include <limits>

using namespace std;

//Pila
struct Nodo {
    int dato;
    Nodo* siguiente;
};
int sizePila = 0;

//Prototipo de función pilas
void push(Nodo*& pila, int n);
int top(Nodo*& pila);
void pop(Nodo*& pila);
bool empty(Nodo*& pila);
int size();

//Prototipo demás funciones
void desplegarMenu();
int pedirNumero(int MIN, int MAX);

int main() {
    Nodo* pila = NULL;

    bool termino = false;
    while (!termino) {
        desplegarMenu();

        int opcion = pedirNumero(1, 5);

        switch (opcion) {
        case 1: {
            //insertar en la pila
            int num = pedirNumero(INT_MIN, INT_MAX);

            push(pila, num);
            sizePila++;

            cout << "Numero agregado exitosamente!\n\n";
            system("pause");
            break;
        }
        case 2: {
            //imprimir tope
            if (empty(pila))
                cout << "La pila esta vacia\n\n";
            else
                cout << "El tope es: " << top(pila) << "\n\n";

            system("pause");
            break;
        }
        case 3: {
            //eliminar tope
            if (empty(pila))
                cout << "La pila esta vacia\n\n";
            else {
                int tope = top(pila);
                pop(pila);
                sizePila--;
                cout << "Tope eliminado exitosamente!\n";
                cout << "Valor eliminado: " << tope << "\n\n";
            }

            system("pause");
            break;
        }
        case 4: {
            //imprimir toda la pila
            if (empty(pila))
                cout << "La pila esta vacia\n\n";
            else {
                int ind = 1;
                while (!empty(pila)) {
                    cout << "[" << ind << "] " << top(pila) << "\n";
                    pop(pila);
                    ind++;
                    sizePila--;
                }
            }

            system("pause");
            break;
        }
        case 5: {
            //cerrar el programa
            cout << "\nGracias por utilizar nuestra pila!\n";
            termino = true;
            break;
        }
        }
    }
}

//Funciones pila
void push(Nodo*& pila, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;

    pila = nuevo_nodo;
}

int top(Nodo*& pila) {
    return pila->dato;
}

void pop(Nodo*& pila) {
    Nodo* aux = pila;
    pila = aux->siguiente;
    delete aux;
}

bool empty(Nodo*& pila) {
    if (pila == NULL)
        return true;

    return false;
}

int size() {
    return sizePila;
}

//Demás funciones
void desplegarMenu() {
    cout << "\033[2J\033[1;1H";
    cout << "Opciones de la pila\n";
    cout << "1.Push\n2.Top\n3.Pop\n4.Deplegar todos los elementos\n5.Salir" << "\n\n";
    cout << "Cantidad de elementos en la pila: " << size() << "\n\n";
}

int pedirNumero(int MIN, int MAX)
{
    int numero = 0;
    bool valido = false;
    while (!valido)
    {
        if (MAX == 5) //Si max es igual a 5 significa que queremos que el user ingrese para el menu
            cout << "Ingrese una de las opciones (1-5): ";
        else //De lo contrario queremos que ingrese el número a agregar a la pila
            cout << "Introduzca el numero entero a agregar: ";

        cin >> numero;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Solo introduza numeros\n";
        }
        else if (cin.peek() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "No agregue caracteres extra\n";
        }
        else if ((numero < MIN || numero > MAX)) {
            cout << "Solo escribir numeros entre " << MIN << " y " << MAX << "\n";
        }
        else
            valido = true;
    }
    return numero;
}