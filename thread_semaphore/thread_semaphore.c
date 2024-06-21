// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
  
void* thread(void* arg) 
{ 
    pthread_t my_id = pthread_self();  // Get the ID of the current thread
    printf("\nThread %lu Entered..\n", (unsigned long)my_id);
    //wait 
    sem_wait(&mutex); 
    printf("\nEntered..\n"); 
  
    //critical section 
    sleep(4); 
      
    //signal 
    printf("\nJust Exiting...\n"); 
    sem_post(&mutex); 
} 

int main() 
{ 
    sem_init(&mutex, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread,NULL); 
    printf("\npthread_join t1...\n"); 
    pthread_join(t1,NULL); 
    printf("\npthread_join t2...\n"); 
    pthread_join(t2,NULL); 
    printf("\ngoing to destroy mutex...\n"); 
    sem_destroy(&mutex); 
    printf("\ndestrtoy matex done...\n"); 
    return 0; 
} 