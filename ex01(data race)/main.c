#include "../color.h"
#include <stdio.h>
#include <pthread.h>

#define TIME_COUNTER 20000

// -fsanitize=thread -g

void *thread_func(void *data)
{
	pthread_t tid;
	unsigned int *count;
	unsigned int i;

	tid = pthread_self(); // çalışan threadin idsini döndürür
	count = data;
	printf(TEXT_BRIGHT_YELLOW "\tThread [%ld]: count start->%u.\n" TEXT_RESET,(long)tid,*count);
	i = 0;
	while(i < TIME_COUNTER)
	{
		(*count)++;
		i++;
	}
	printf(TEXT_BRIGHT_YELLOW "\tThread [%ld]: final count start->%u.\n" TEXT_RESET,(long)tid,*count);
	return (NULL);
}

int main() {

	pthread_t tid1;
	pthread_t tid2;
	unsigned int count = 0;

	pthread_create(&tid1, NULL, thread_func ,&count);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_RED "Main : Creat first thread.\n" TEXT_RESET);

	pthread_create(&tid2, NULL, thread_func ,&count);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_RED "Main : Creat second thread.\n" TEXT_RESET);

	pthread_join(tid1, NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_MAGENTA "Main : Join first thread [%ld].\n" TEXT_RESET,(long)tid1);
	pthread_join(tid1, NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_MAGENTA "Main : Join second thread [%ld].\n" TEXT_RESET,(long)tid2);

	if (count != (2 * TIME_COUNTER)) 
		printf(TEXT_BRIGHT_RED "Main : Error! count :%u\n" TEXT_RESET,count);
	else
		printf(TEXT_BRIGHT_GREEN "Main : OK count :%u\n" TEXT_RESET,count);
    return 0;
 
}


