#include <stdio.h>
#include <windows.h>

HANDLE hEventOdd, hEventEven;

DWORD WINAPI print_odd(LPVOID lpParam) {
    for (int i = 1; i <= 9; i += 2) {
        WaitForSingleObject(hEventOdd, INFINITE);
        printf("th1: %d\n", i);
        SetEvent(hEventEven); 
    }
    return 0;
}

DWORD WINAPI print_even(LPVOID lpParam) {
    for (int i = 2; i <= 10; i += 2) {
        WaitForSingleObject(hEventEven, INFINITE); 
        printf("th2: %d\n", i);
        SetEvent(hEventOdd); 
    }
    return 0;
}

int main() {
    HANDLE th1, th2;

    hEventOdd = CreateEvent(NULL, FALSE, TRUE, NULL); 
    hEventEven = CreateEvent(NULL, FALSE, FALSE, NULL); 

    th1 = CreateThread(NULL, 0, print_odd, NULL, 0, NULL);
    th2 = CreateThread(NULL, 0, print_even, NULL, 0, NULL);

    WaitForSingleObject(th1, INFINITE);
    WaitForSingleObject(th2, INFINITE);

    CloseHandle(th1);
    CloseHandle(th2);
    CloseHandle(hEventOdd);
    CloseHandle(hEventEven);

    return 0;
}