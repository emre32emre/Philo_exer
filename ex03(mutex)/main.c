#include "../color.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

// -fsanitize=thread -g

// data race in oluştuğu kısın counter sayacı yanlış çalışıyor.

void* trythis(void* arg)
{
	pthread_mutex_lock(&lock);
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
	while(i < 999999999)
		i++;
    printf("\n Job %d has finished\n", counter);
	pthread_mutex_unlock(&lock);
    return NULL;
}
  

int main()
{
	int i = 0;
	

	pthread_mutex_init(&lock, NULL);

	

	pthread_create(&(tid[0]), NULL, &trythis, NULL);

	pthread_create(&(tid[1]), NULL, &trythis, NULL);


	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
}