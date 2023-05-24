#include "../color.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

pthread_t tid[2];
int counter;

// -fsanitize=thread -g

// data race in oluştuğu kısın counter sayacı yanlış çalışıyor.

void* trythis(void* arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
	while(i < 999999999)
		i++;
    printf("\n Job %d has finished\n", counter);
  
    return NULL;
}
  

int main()
{
	int i = 0;
	int error;

	error = pthread_create(&(tid[0]), NULL, &trythis, NULL);

	error = pthread_create(&(tid[1]), NULL, &trythis, NULL);

	if(error != 0)
		printf("\nThread can't be created :[%s]", strerror(error));

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
}