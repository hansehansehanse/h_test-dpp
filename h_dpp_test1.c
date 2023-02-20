#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// time()
#include <math.h>		// srand() and ran()
#include <pthread.h>	// PTHREADS
#include <semaphore.h>	// SEMAPHORES
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

	pthread_t philo[N];
  	int *ids = (int *) malloc(sizeof(int) * N);

	for(i=0; i<N; i++){
		sem_init(&chopstick[i], 0, 1);
	}

	for(i=0; i<N; i++){
    ids[i] = i;
		pthread_create(&philo[i], NULL, Philosophize, (void *) &ids[i]);
	}

	for(i=0; i<N; i++){
		pthread_join(philo[i], NULL);
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
