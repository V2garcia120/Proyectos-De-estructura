#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

struct Node
{
    int Data;
    int Priority;
    Node* next;
};

struct Queue
{
    Node* Front;
    Node* Back;
};

int getAction();
int GetInt(string s);
static void Enqueue(Queue*& queue);
static void Dequeue(Queue*& queue);
static void MostrarQueue(Queue*& queue);
static void DesplegarQueue(Queue*& queue);
static void esperarEnter();

int main()
{
    cout << "Bienvenido al Queue!" << endl;
    Queue* queue = new Queue();
    queue->Front = NULL;
    queue->Back = NULL;
    while (true)
    {
        switch (getAction())
        {
        case 1:
            Enqueue(queue);
            break;
        case 2:
            Dequeue(queue);
            break;
        case 3:
            DesplegarQueue(queue);
            break;
        case 4:
            MostrarQueue(queue);
            break;
        case 5:
            cout << "El programa se ha cerrado.";
            return 0;
            break;
        }
    }
}

int getAction()
{
    int x;
    while (true)
    {
        system("cls");
        cout << "1-Enqueue\n2-Dequeue\n3-Desplegar Queue\n4-Mostrar Queue\n5-Salir";
        do
        {
            x = GetInt("\nIngrese un valor para la accion que desea realizar: ");
        } while (x < 0 || x > 5);
        break;
    }
    return x;
}

int GetInt(string s)
{
    int x;
    string input;

    while (true) {
        cout << s;
        getline(cin, input);
        istringstream iss(input);
        if (iss >> x && iss.eof()) {
            return x;
        }
        else {
            cout << "\nEl valor que ingreso no es valido para lo que desea realizar.\n";
        }
    }
}

static void Enqueue(Queue*& queue)
{
    system("cls");
    int prioridad;
    do
    {
        prioridad = GetInt("Ingrese la prioridad para el dato (0-16): ");
    } while (prioridad < 0);

    Node* nuevoNodo = new Node();
    nuevoNodo->Data = GetInt("Ingrese el dato que quiere introducir a la Queue: ");
    nuevoNodo->Priority = prioridad;
    nuevoNodo->next = NULL;

    if (queue->Front == NULL)
    {
        queue->Front = queue->Back = nuevoNodo;
    }
    else if (prioridad < queue->Front->Priority)
    {
        nuevoNodo->next = queue->Front;
        queue->Front = nuevoNodo;
    }
    else
    {
        Node* actual = queue->Front;
        while (actual->next != NULL && actual->next->Priority <= prioridad)
        {
            actual = actual->next;
        }

        nuevoNodo->next = actual->next;
        actual->next = nuevoNodo;

        if (nuevoNodo->next == NULL)
        {
            queue->Back = nuevoNodo;
        }
    }
    nuevoNodo->Priority = prioridad;
    esperarEnter();
}

static void Dequeue(Queue*& queue)
{
    system("cls");
    Node* nodoAuxiliar = queue->Front;
    if (nodoAuxiliar != NULL)
    {
        cout << "El dato " << nodoAuxiliar->Data << " del elemento con mayor priorirdad fue eliminado de la Queue.\n";
        queue->Front = nodoAuxiliar->next;
        delete nodoAuxiliar;
    }
    else { cout << "\nLa Queue se encuentra vacia. No se puede eliminar nada."; }
    esperarEnter();
}

static void MostrarQueue(Queue*& queue)
{
    Node* nodoAuxiliar = queue->Front;
    if (nodoAuxiliar == NULL) {
        cout << "\nLa Queue se encuentra vacia.\n";
    }
    else
    {
        int i = 0;
        while (nodoAuxiliar != NULL)
        {
            cout << "\nEl valor numero " << i << " de la Queue es: " << nodoAuxiliar->Data << ".\n";
            nodoAuxiliar = nodoAuxiliar->next;
            i++;
        }
    }
    esperarEnter();
}

static void DesplegarQueue(Queue*& queue)
{
    Node* nodoAuxiliar = queue->Front;
    if (nodoAuxiliar == NULL) {
        cout << "\nLa Queue se encuentra vacia.\n";
    }
    else
    {
        while (nodoAuxiliar != NULL)
        {
            Node* temporal = nodoAuxiliar;
            nodoAuxiliar = nodoAuxiliar->next;
            delete temporal;
        }
        queue->Front = NULL;
        queue->Back = NULL;
        cout << "\nLa Queue fue desplegada exitosamente.\n";
    }
    esperarEnter();
}

static void esperarEnter()
{
    cout << "\nPresione enter para continuar.";
    cin.get();
}