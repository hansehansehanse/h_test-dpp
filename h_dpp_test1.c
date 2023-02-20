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
// This method will be performed by each philosopher
void * Philosophize(void * id);

// Chopsticks: Shared resources
sem_t chopstick[N];


//----------------------------------------------------------------------------
int main()
{
	int i;
	srand(time(0));

	//---------------------------------------------------
	// Create 5 PHILOSOPHER
	pthread_t philo[N];
  	int *ids = (int *) malloc(sizeof(int) * N);

  	//---------------------------------------------------
	// Initialize Semaphores
	for(i=0; i<N; i++){
		sem_init(&chopstick[i], 0, 1);
	}

	//---------------------------------------------------
	// CREATE PHILOSOPHER threads
	for(i=0; i<N; i++){
    ids[i] = i;
		pthread_create(&philo[i], NULL, Philosophize, (void *) &ids[i]);
	}

	//---------------------------------------------------
	// JOIN PHILOSOPHER threads
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

		//----------------------------------------------------------------------------
		// 1. THINK for a while
		int thinking_duration = (rand() % (5-2)) + 1; 						
        printf("Philosopher %d is thinking...\n", ID);
        sleep(thinking_duration);
        printf("Philosopher %d is hungry.\n", ID);

		//----------------------------------------------------------------------------
		// 2. PICK-UP left chopstick
        sem_wait(&chopstick[ID]);
        printf("Philosopher %d PICKED-UP left chopstick.\n", ID);

		//----------------------------------------------------------------------------
		// 3. PICK-UP right chopstick
        sem_wait(&chopstick[(ID+1) % N]);
        printf("Philosopher %d PICKED-UP right chopstick.\n", ID);

		//----------------------------------------------------------------------------
		// 4. EAT for a while
        int eating_duration = (rand() % (3-2)) + 1;
        printf("Philosopher %d is eating...\n", ID);
        sleep(eating_duration);

		//----------------------------------------------------------------------------
		// 5. RELEASE left chopstick
        printf("Philosopher %d is done eating and returned the left chopstick...\n", ID);
        sem_post(&chopstick[ID]);

		//----------------------------------------------------------------------------
		// 6. RELEASE right choptick
        printf("Philosopher %d returned the right chopstick...\n", ID);
        sem_post(&chopstick[(ID+1) % N]);
	}

}
