#include <stdio.h>
#include <windows.h> // Библиотеката за нишки под Windows

// Функция за първата нишка (нечетни числа)
DWORD WINAPI print_odd(LPVOID lpParam) {
    for (int i = 1; i <= 9; i += 2) {
        printf("th1: %d\n", i);
        Sleep(10); // Малка пауза, за да се смесят нишките визуално
    }
    return 0;
}

// Функция за втората нишка (четни числа)
DWORD WINAPI print_even(LPVOID lpParam) {
    for (int i = 2; i <= 10; i += 2) {
        printf("th2: %d\n", i);
        Sleep(10);
    }
    return 0;
}

int main() {
    HANDLE th1, th2;

    // 1. Създаваме th1
    th1 = CreateThread(NULL, 0, print_odd, NULL, 0, NULL);
    if (th1 == NULL) return 1;

    // 2. Създаваме th2
    th2 = CreateThread(NULL, 0, print_even, NULL, 0, NULL);
    if (th2 == NULL) return 1;

    WaitForSingleObject(th1, INFINITE);
    WaitForSingleObject(th2, INFINITE);

    CloseHandle(th1);
    CloseHandle(th2);

    return 0;
}