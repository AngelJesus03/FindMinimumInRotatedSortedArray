#include <cassert>
#include <iostream>
#include <string>
#include "../src/solution.hpp"

using namespace std;

void ejecutar_test_Encontrar_Min(int arr[], int n, int esperado, const string& nombre) {
    int resultado = encontrarMin(arr, n);
    assert(arr[resultado] == esperado);
    cout << nombre << " pasó" << endl;
}

void ejecutar_test_Encontrar_Min_Ingenua(int arr[], int n, int esperado, const string& nombre) {
    int resultado = encontrarMinIngenua(arr, n);
    assert(arr[resultado] == esperado);
    cout << nombre << " pasó" << endl;
}

int main() {
    int arr1[] = {3, 4, 5, 1, 2};
    int arr2[] = {7, 8, 9, 10, 11, 1, 2, 3, 4, 5, 6};
    int arr3[] = {1, 2};
    int arr4[] = {2, 1};
    int arr5[] = {1};
    int arr6[] = {1, 2, 3, 4, 5};
    int arr7[] = {22, 23, 24, 25, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int arr8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    cout << "Ejecutando tests con la funcion 'EncontrarMin'\n" << endl;

    ejecutar_test_Encontrar_Min(arr1, 5, 1, "Caso normal 1");
    ejecutar_test_Encontrar_Min(arr2, 11, 1, "Caso normal 2");
    ejecutar_test_Encontrar_Min(arr3, 2, 1, "Caso pequeño 1");
    ejecutar_test_Encontrar_Min(arr4, 2, 1, "Caso pequeño 2");
    ejecutar_test_Encontrar_Min(arr5, 1, 1, "Caso borde 1");
    ejecutar_test_Encontrar_Min(arr6, 5, 1, "Caso borde 2");
    ejecutar_test_Encontrar_Min(arr7, 25, 1, "Caso propuesto 1");
    ejecutar_test_Encontrar_Min(arr8, 25, 1, "Caso propuesto 2");

    cout << "\nEjecutando tests con la funcion 'EncontrarMinIngenua'\n" << endl;

    ejecutar_test_Encontrar_Min_Ingenua(arr1, 5, 1, "Caso normal 1");
    ejecutar_test_Encontrar_Min_Ingenua(arr2, 11, 1, "Caso normal 2");
    ejecutar_test_Encontrar_Min_Ingenua(arr3, 2, 1, "Caso pequeño 1");
    ejecutar_test_Encontrar_Min_Ingenua(arr4, 2, 1, "Caso pequeño 2");
    ejecutar_test_Encontrar_Min_Ingenua(arr5, 1, 1, "Caso borde 1");
    ejecutar_test_Encontrar_Min_Ingenua(arr6, 5, 1, "Caso borde 2");
    ejecutar_test_Encontrar_Min_Ingenua(arr7, 25, 1, "Caso propuesto 1");
    ejecutar_test_Encontrar_Min_Ingenua(arr8, 25, 1, "Caso propuesto 2");

    cout << "\nTodos los test pasaron" << endl;

    return 0;
}