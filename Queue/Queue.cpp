/*
   Tarea 3. Queue

    Una Cola (Queue) es una estructura de datos en donde el primero en entrar es el primero en salir. Para
    nuestro caso, haremos el problema un poco mas complejo añadiéndole lo que se conoce como
    prioridad. En los casos en que una Cola tiene prioridad se considera esta al momento de insertar un
    nuevo nodo a la estructura. La Cola tiene la siguiente forma para los nodos:
    struct Queue {
     int dato;
     Queue *next;
    };


   Autores: Vismil Garcia - 1128719, Jeremy Garcia - 1127276, Hesler Cuevas - 1127855, Diana Lantigua - 1126796, Josephine Rosario - 1127597 e Ivan Joa - 1127943.

   Fecha: 28/8/2025

*/


#include <limits>
#include <iostream>
using namespace std;
struct Nodo
{
    int val;
    Nodo* next;

    Nodo()
    {
        val = 0;
        next = nullptr;
    }
    Nodo(int x)//Constructor para iniciar un nodo con un dato
    {
        val = x;
        next = nullptr;
    }
};

void enqueue(Nodo*& first, Nodo*& last, int val, int prioridad);//nos peromite agregar un elemento a la cola
int getint();//nos permite obtener un entero de manera segura
int cantidadEle(Nodo*& first, Nodo*& last);//nos permite obtener la cantidad de elementos en la cola
void pause();//pausa la ejecucion hasta que el usuario presione enter
void dequeue(Nodo*& first, Nodo*& last);//elimina el primer elemento de la cola
void mostrar(Nodo*& first, Nodo*& last, bool eliminar);//muestra los elementos de la cola, si eliminar es true, elimina todos los elementos

int main()
{
    Nodo* first = NULL;
    Nodo* last = NULL;
    bool salir = false;
    int opcion = 0;
    while(!salir)
    {
        int prioridad = 0;
        int val = 0;
        cout << "\033[2J\033[1;1H";
        cout << "Opciones de la Cola                      Elementos en cola: "<<cantidadEle(first,last)<<"\n";
        cout << "                                         "; mostrar(first, last, false);
        cout << "\n1.Enqueue\n2.Dequeue\n3.vaciar todos los elementos\n4.salir\n\n";
        opcion = getint();
        if (opcion < 1 || opcion > 4)
        {
            cout << "Elija un numero en el rango de opciones.\n";
            pause();
        }
        switch (opcion)
        {
        case 1:
            cout << "\nValor\n";
            val = getint();
            cout << "\nprioridad\n";
            prioridad = getint();
            enqueue(first, last, val, prioridad);
            pause();
            break;
        case 2:
            dequeue(first, last);
            pause();
            break;
        case 3:
            mostrar(first, last, true);
            cout << "\nSe ha vaciado la cola" << endl;
            pause();
            break;
        case 4:
            salir = true;
            cout << "Gracias por usar!\n";
            pause();
            break;
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
int cantidadEle(Nodo *&first, Nodo *&last)
{
    int cantidad = 0;
    Nodo* aux = first;
	while (aux != nullptr)//recorremos la cola hasta el final
    {
        cantidad++;
        aux = aux->next;
    }
    return cantidad;

}
void enqueue(Nodo *&first, Nodo *&last, int val, int prioridad)
{
    int cantidad = cantidadEle(first, last);
    Nodo* actual = first;
    Nodo* anterior = NULL;
    Nodo* nuevo_nodo = new Nodo(val);
	//caso 1: cola vacia
    if (cantidad == 0)
    {
        first = last = nuevo_nodo;
        return;
    }
	//caso 2: prioridad 0
    if (prioridad == 0)
    {
        nuevo_nodo->next = first;
        first = nuevo_nodo;
        return;
    }
	//caso 3: prioridad mayor a 16 o mayor a la cantidad de elementos
    if (prioridad > 16 || prioridad > cantidad)
    {
        last->next = nuevo_nodo;
        last = nuevo_nodo;
        return;
    }
	//caso 4: prioridad entre 1 y 15
    int posicion = 0;
	while (actual != nullptr && posicion < prioridad)//nos movemos hasta la posicion deseada
    {
        anterior = actual;
        actual = actual->next;
        posicion++;
    }
	nuevo_nodo->next = actual;//insertamos el nuevo nodo en la posicion deseada
	if (anterior != nullptr)//si anterior es nulo, significa que estamos en la primera posicion
    {
        anterior->next = nuevo_nodo;
        return;
    }
	if (actual == nullptr)//si actual es nulo, significa que estamos en la ultima posicion
    {
        last = nuevo_nodo;
    }

}
void dequeue(Nodo *&first, Nodo*&last)
{
    Nodo* aux = nullptr;
    if (first == NULL&&last == NULL)//cola vacia
    {
        cout << "No hay elementos en la cola.\n";
        return;
    }
	else if (first == last)//cola con un solo elemento
    {
        cout << first->val << "\n";
        aux = first;
        delete aux;
        first = NULL;
        last = NULL;
        return;
    }
    else
    {
        cout << first->val << "\n";
        aux = first;
        first = first->next;
        delete aux;
        return;
    }
}
void mostrar(Nodo *&first, Nodo *&last, bool eliminar)
{
    Nodo* aux = nullptr;
    if (eliminar == true) 
    {
        while (first != NULL)
        {
            cout << first->val << " ";
            aux = first;
            first = first->next;
            delete aux;
        }
        first = NULL;
        last = NULL;
        return;
    }
    else
    {
        Nodo* temp = first;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        delete temp;
    }
}
void pause()
{
    cout << "Presiona enter para continuar...";
    // Clear any remaining input in the buffer
    if (cin.peek() != '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.get(); // Wait for Enter key
}