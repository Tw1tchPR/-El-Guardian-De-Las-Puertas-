#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; 

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

// Función principal del juego
int main() {
    // Semilla para números aleatorios
    srand(time(0));
    int nivel = 1;
    int vidas = 3;
    int puntuacion = 0;

    cout << "¡Bienvenido a 'El guardián de las puertas'!" << endl;
    cout << "Tu tarea es aceptar o rechazar criaturas según las reglas mágicas.\n" << endl;

    while (vidas > 0) {
        cout << "=== Nivel " << nivel << " ===" << endl;
        // Define regla del nivel
        if (nivel == 1) {
            cout << "Regla: El número debe ser múltiplo de 3." << endl;
        } else if (nivel == 2) {
            cout << "Regla: El número debe ser primo." << endl;
        } else {
            cout << "Regla: El número debe ser múltiplo de 5 y no contener el dígito 7." << endl;
        }
        
        // Generar número aleatorio para la criatura
        int codigo = rand() % 100 + 1; // Número entre 1 y 100
        cout << "La criatura tiene el código: " << codigo << endl;
        
        // Entrada del jugador
        string decision;
        cout << "¿Aceptar o Rechazar? (escribe 'aceptar' o 'rechazar'): ";
        cin >> decision;

        // Verifica si la decisión es correcta
        bool esValido = false;
        if (nivel == 1) {
            esValido = (codigo % 3 == 0);
        } else if (nivel == 2) {
            esValido = esPrimo(codigo);
        } else {
            esValido = (codigo % 5 == 0 && to_string(codigo).find('7') == string::npos);
        }

        // Validar respuesta
        if ((decision == "aceptar" && esValido) || (decision == "rechazar" && !esValido)) {
            cout << "¡Correcto! +10 puntos." << endl;
            puntuacion += 10;
        } else { 
            cout << "¡Incorrecto! Pierdes una vida." << endl;
            vidas--;
        }

        // Mostrar estado actual
        cout << "Puntuación: " << puntuacion << " | Vidas Restantes: " << vidas << "\n" << endl;

        // Avanzar al siguiente nivel si el jugador tiene éxito
        if (vidas > 0) nivel++;
    }

    // Fin del juego
    cout << "¡Juego terminado! Tu puntuación final es: " << puntuacion << endl;
    return 0;
}
