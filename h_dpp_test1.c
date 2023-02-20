#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// time()
#include <math.h>		// srand() and ran()
#include <pthread.h>	// PTHREADS
//#include <semaphore.h>	// SEMAPHORES
#include <unistd.h>
#define N 5


//----------------------------------------------------------------------------
//---------------------------------------------------
void * Philosophize(void * id);

sem_t chopstick[N];


//----------------------------------------------------------------------------
int main()
{
	int i;
	srand(time(0));

	//---------------------------------------------------
	pthread_t philo[N];
  	int *ids = (int *) malloc(sizeof(int) * N);

  	//---------------------------------------------------
	for(i=0; i<N; i++){
		sem_init(&chopstick[i], 0, 1);
	}

	

	return 0;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void * Philosophize(void * id){
	int ID = *((int *) id);

	while(1){

		
	}

}
