#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Функцията, която всяка нишка ще изпълнява
void* print_thread_id(void* thread_arg) {
    int id = *((int*)thread_arg);
    printf("Нишка номер: %d\n", id);

    // Важно: Освобождаваме паметта, заделена за аргумента
    free(thread_arg);

    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        // Заделяме памет за номера на нишката, за да избегнем "race condition"
        int* thread_id = malloc(sizeof(int));
        *thread_id = i + 1;

        printf("Main: създаване на нишка %d\n", i + 1);

        rc = pthread_create(&threads[i], NULL, print_thread_id, (void*)thread_id);

        if (rc) {
            printf("ГРЕШКА: код от pthread_create() е %d\n", rc);
            exit(-1);
        }
    }

    // Изчакваме всички нишки да приключат (pthread_join)
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main: Всички нишки приключиха.\n");

    return 0;
}