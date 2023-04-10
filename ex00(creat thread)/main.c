#include "../color.h"
#include <stdio.h>
#include <pthread.h>

void *thread_func(void *data)
{
	pthread_t tid;

	tid = pthread_self(); // çalışan threadin idsini döndürür
	printf(TEXT_BRIGHT_YELLOW "Thread [%ld] : herkez öldürür sevdiğini.\n" TEXT_RESET,(long)tid);
	return (NULL);
}

int main() {

	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, NULL, thread_func ,NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_RED "Main : Creat first thread.\n" TEXT_RESET);

	pthread_create(&tid2, NULL, thread_func ,NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_RED "Main : Creat second thread.\n" TEXT_RESET);

	pthread_join(tid1, NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_MAGENTA "Main : Join first thread [%ld].\n" TEXT_RESET,(long)tid1);
	pthread_join(tid1, NULL);
	printf(TEXT_UNDERLINE TEXT_BOLD TEXT_MAGENTA "Main : Join second thread [%ld].\n" TEXT_RESET,(long)tid2);
 


    return 0;
}
