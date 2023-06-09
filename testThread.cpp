#include <pthread.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/threading.h>

#ifdef __cplusplus
extern "C"
#endif
{
	pthread_t thread_id2[10];
	int stopFlag = 0;
	pthread_mutex_t g_pMutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *threadFunc(void* arg)
{
	printf("enter thread func\n");
	return arg;
}
void *threadFunc2(void* arg)
{
	printf("enter thread func\n");
	for(int i=0;i<10000000000;i++)
	{
		if(stopFlag)
		{
			//pthread_mutex_lock(&g_pMutex);
			//printf("thread2 release\n ");
			//pthread_exit(0);
			//pthread_cond_signal(&cond);
	        //pthread_mutex_unlock(&g_pMutex);
			break;
		}
		usleep(1000000);
		printf("thread Loop\n");
	}
	printf("thread return\n");
	return arg;
}

int testThread() {
  
    //pthread_t *thread_id;
    //int ret = pthread_create(thread_id, NULL, threadFunc, NULL);
	//if(ret)
	//{
	//	std::cout<<"create thread failed!"<<std::endl;
	//}
	//pthread_detach(*thread_id);//分离线程
	
	printf("play\n");
	for(int i=0;i<2;i++)
	{
		int ret2 = pthread_create(&thread_id2[i], NULL, threadFunc2, NULL);
		if(ret2!=0)
		{
			printf("create thread2 failed!\n");
		}
	}
    
	//pthread_detach(thread_id2);//分离线程
	
    return 0;
}
int stop(){
	printf("stop 1\n");
	stopFlag = 1;
	//usleep(2000000);
	for(int i=0;i<2;i++)
	{
		pthread_join(thread_id2[i],NULL);//销毁
	}
	
	//free(&thread_id2);
	//pthread_mutex_lock(&g_pMutex);
	//pthread_cond_wait(&cond,&g_pMutex);
	printf("stop 2\n");
	//pthread_mutex_unlock(&g_pMutex);
	
	//printf("thread_id2 destroy\n");
	return 1;
}
int main()
 {
	// testThread();
	// stop();
 }

#ifdef __cplusplus
}
#endif
