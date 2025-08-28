#include <iostream>

using namespace std;
//estructura de nodo
struct Nodo
{
    int val;
    Nodo* next;
    Nodo(int valor) {
        val = valor;
        next = nullptr;
    }
};
//declariacion de funciones
int getint();
void push(Nodo*& pila, int val);
void pop(Nodo *&stack);
void mostrar(Nodo *&stack, bool vaciar);
void pause();
int main()
{
    Nodo* stack = NULL;
    bool salir = false;
    int val = 0;
    int tope = 0;
    while(!salir)
    {
        cout << "\033[2J\033[1;1H";
        cout << "Opciones de la pila\n";
        cout << "1.push\n2.pop\n3.deplegar todos los elementos\n4.salir"<<endl;
        cout << "\nCantidad de elementos en la pila: " << tope << endl;
        mostrar(stack, false);
        cout << right;
        cout << "\nSeleccione la accion que quiere realizar\n";
        
        int opcion = getint();
        if (opcion < 1 || opcion > 4)
        {
            cout << "El numero debe estar entre el rango de opciones.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcion)
        {
        case 1:
            cout << "\nQue numero quieres insertar a la pila?\n ";
            val = getint();
            push(stack, val);
            tope++;
            pause();
            break;
        case 2:
            if (tope == 0)
            {
                cout << "La cola esta vacia\n";
                pause();
                break;
            }
            cout << endl;
            pop(stack);
            tope--;
            pause();
            break;

        case 3:
            if (tope == 0)
            {
                cout << "La cola esta vacia\n";
                pause();
                break;
            }
            cout << endl;
            mostrar(stack, true);
            tope = 0;
            pause();
            break;

        case 4:
            cout << "Gracias por usar!\n";
            pause();
            salir = true;
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
        return numero;
    }
    return numero;
}
void push(Nodo*& stack, int val)
{
    Nodo* nuevo_nodo = new Nodo(val);
    nuevo_nodo->next = stack;
    stack = nuevo_nodo;
    cout << "\nNodo isnertado correctamente.\n";
}
void pop(Nodo *&stack)
{
    Nodo *temp = stack;
    stack = temp->next;
    cout << temp->val<<" \n";
    delete temp;
}

void mostrar(Nodo*& stack, bool vaciar)
{
    int i = 1;
    if (stack == nullptr) return;
    Nodo* temp = stack;
    if (vaciar) {
        while (stack != nullptr)
        {
            cout << i << "- ";
            pop(stack);
            i++;
        }

    }
    else
    {
        while (temp != nullptr) {
            cout << i << "- " << temp->val << endl;
            temp = temp->next;
            i++;
        }
        delete temp;
    }

}
void pause()
{
    cout << "Presiona enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}