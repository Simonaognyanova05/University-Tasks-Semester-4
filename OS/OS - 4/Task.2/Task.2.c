#include <stdio.h>
#include <windows.h>

HANDLE sem1, sem2, sem3;

DWORD WINAPI thread1(LPVOID lpParam) {
    for (int i = 1; i <= 3; i++) {
        WaitForSingleObject(sem1, INFINITE); 
        printf("th1: loop %d\n", i);
        ReleaseSemaphore(sem2, 1, NULL);    
    }
    return 0;
}

DWORD WINAPI thread2(LPVOID lpParam) {
    for (int i = 1; i <= 3; i++) {
        WaitForSingleObject(sem2, INFINITE); 
        printf("th2: loop %d\n", i);
        ReleaseSemaphore(sem3, 1, NULL);    
    }
    return 0;
}

DWORD WINAPI thread3(LPVOID lpParam) {
    for (int i = 1; i <= 3; i++) {
        WaitForSingleObject(sem3, INFINITE);
        printf("th3: loop %d\n", i);
        ReleaseSemaphore(sem1, 1, NULL);    
    }
    return 0;
}

int main() {
    sem1 = CreateSemaphore(NULL, 1, 1, NULL);
    sem2 = CreateSemaphore(NULL, 0, 1, NULL);
    sem3 = CreateSemaphore(NULL, 0, 1, NULL);

    HANDLE threads[3];
    threads[0] = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
    threads[1] = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
    threads[2] = CreateThread(NULL, 0, thread3, NULL, 0, NULL);

    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    for (int i = 0; i < 3; i++) CloseHandle(threads[i]);
    CloseHandle(sem1); CloseHandle(sem2); CloseHandle(sem3);

    return 0;
}