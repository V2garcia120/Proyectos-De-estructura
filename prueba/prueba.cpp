
#include <iostream>
#include <vector>
#include <string>


using namespace std;

const int cantNumbers = 6;
const int cantBoxes = 4;

vector <bool> checked(cantNumbers + 1); //vector que indica si ya un numero esta en la secuencia misteriosa
vector <bool> used(cantNumbers + 1); //vector que indica si ya el user uso un numero en el mismo intento

vector <int> createNumbers() { //genera una permutacion aleatoria de numeros
    vector <int> aux(cantBoxes);

    cout << "Generando la combinacion de numeros secretos...\n";
    for (int i = 0; i < cantBoxes; i++) {
        while (true) {
            srand(time(nullptr));
            int num = rand() % cantNumbers + 1;
            if (!checked[num]) {
                checked[num] = true;
                aux[i] = num;
                break;
            }
        }
    }
    cout << "Listo! Bienvenido a Master Mind! El juego donde tendras que adivinar una combinacion secreta de numeros :)\n";
    cout << "El juego esta restringido a numeros del 1 al 6, la combinacion es de 4 numeros y esta garantizado de que estos no se repetiran.\n\n";

    return aux;
}

bool checkInput(string input) { //chequea si el input que ingreso el user es valido
    int aux = input[0] - '0';
    if (input.size() > 1 || (aux <= 0 || aux > 6)) {
        cout << "Valor ingresado invalido, intentelo de nuevo\n";
        return 0;
    }
    if (used[aux]) {
        cout << "Ya ha utilizado este numero.\n";
        return 0;
    }
    return 1;
}

int main() {
    vector <int> secretNumbers = createNumbers(); //vector que almacena los 4 numeros secretos

    for (auto x : secretNumbers)
        cout << x << " ";
    cout << "\n";

    int points = 10; //puntaje del participante
    while (points) { //mientras el participante tenga puntos seguirá participando
        vector <char> res(cantBoxes); //vector que almacenara la respuesta a cada juego
        vector <int> playerInput(cantBoxes); //vector que almacenara la combinacion ingresada por el user

        used = vector <bool>(cantNumbers + 1); //inicializamos used que nos indicara si el user ya ha utilizado el mismo numero

        cout << "Intento " << 10 - points + 1 << ". Ingrese la combinacion de numeros del 1 al 6 que desea probar:\n";
        for (int i = 0; i < 4; i++) {
            string input;
            do {
                cout << "Numero " << i + 1 << ": ";
                getline(cin, input); //dejamos que el user ingrese lo que quiera
            } while (!checkInput(input)); //se repetira hasta que el user ingrese un valor valido

            int num = input[0] - '0'; //transformamos el input del user a entero
            playerInput[i] = num; //guardamos la jugada del user
            used[num] = true; //marcamos la jugada del user para que no vuelva a repetir el mismo numero
            if (num == secretNumbers[i])
                res[i] = 'C';
            else if (checked[num])
                res[i] = 'F';
            else
                res[i] = 'X';
        }
        int cont = 0;
        cout << "\n";
        for (char x : res) {
            cout << x << " ";

            if (x == 'C')
                cont++;
        }
        cout << "\n";
        for (int x : playerInput)
            cout << x << " ";
        cout << "\n\n";

        if (cont == 4) { //gano si todos son C y termino el programa
            cout << "Ganaste!\nPuntaje: " << points << "\n";
            return 0;
        }
        points--; //si el programa sigue le resto puntos al jugador
    }

    cout << "Perdiste :(\nPuntaje: " << points << "\n";
    cout << "La combinacion secreta era: ";
    for (int x : secretNumbers)
        cout << x << " ";
    cout << "\n";

    return 0;
}