#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;


void *Farmer(void *far)
{   
   /*
   1.Farmer harvest crops and put them in particular room. For example, room 0 for Rice(R).
   2.use mutex and semaphore for critical section.
   3.print which farmer is keeping which crops in which room inside the critical section.
   4.print the whole warehouse buffer outside of the critical section
   */
   
   int i,j=0; 
   int *farmid = (int *)far;

   while(i<MaxCrops) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[(*farmid + i) % MaxCrops]; //cyclic order 
        printf("Farmer %d: Insert crops %c at %d\n", *farmid, warehouse[in], in);
        in = (in + 1) % warehouseSize; //increasing in to next position,end->first (%)
        i++;
        
        
        pthread_mutex_unlock(&mutex);
        sleep(1);
        sem_post(&full);
        

        
    }
    printf("Farmer%d: ", *farmid);
    while (j < warehouseSize){
            printf("%c", warehouse[j]);
            j++;
    }
    printf("\n");

    return NULL;
    
}
void *ShopOwner(void *sho)
{   
/*
   1.Shop owner takes crops and makes that particular room empty.
   2.use mutex and semaphore for critical section.
   3.print which shop owner is taking which crops from which room inside the critical section.
   4.print the whole warehouse buffer outside of the critical section
   */
   int i,j=0;
   int *shop_id = (int *)sho;
   
 
   while(i<MaxCrops){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Shop owner %d: Remove crops %c from %d\n", *shop_id, warehouse[out], out);
        warehouse[out] = 'N'; //warehouse is empty
        out = (out + 1) % warehouseSize;
        i++;
       
        sleep(1);
        pthread_mutex_unlock(&mutex);
        
        sem_post(&empty);
        
      
        
    }
    printf("ShopOwner%d: ", *shop_id);
    while (j < warehouseSize){
            printf("%c", warehouse[j]);
            j++;
    }
    printf("\n");

    return NULL;
}
int main()
{   
    /*initializing thread,mutex,semaphore
    */
    pthread_t Far[5],Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,warehouseSize);//when the warehouse is full thread will wait
    sem_init(&full,0,0);//when the warehouse is empty thread will wait


    int a[5] = {1,2,3,4,5}; //Just used for numbering the Farmer and ShopOwner


    /*create 5 thread for Farmer 5 thread for ShopOwner
    -------------------------------------------------
    -------------------------------------------------
    */
    pthread_create(&Far[0], NULL, Farmer, (void *)&a[0]);
    pthread_create(&Far[1], NULL, Farmer, (void *)&a[1]);
    pthread_create(&Far[2], NULL, Farmer, (void *)&a[2]);
    pthread_create(&Far[3], NULL, Farmer, (void *)&a[3]);
    pthread_create(&Far[4], NULL, Farmer, (void *)&a[4]);
    
    pthread_create(&Sho[0], NULL, ShopOwner, (void *)&a[0]);
    pthread_create(&Sho[1], NULL, ShopOwner, (void *)&a[1]);
    pthread_create(&Sho[2], NULL, ShopOwner, (void *)&a[2]);
    pthread_create(&Sho[3], NULL, ShopOwner, (void *)&a[3]);
    pthread_create(&Sho[4], NULL, ShopOwner, (void *)&a[4]);
    
    pthread_join(Far[0], NULL);
    pthread_join(Far[1], NULL);
    pthread_join(Far[2], NULL);
    pthread_join(Far[3], NULL);
    pthread_join(Far[4], NULL);
    
    pthread_join(Sho[0], NULL);
    pthread_join(Sho[1], NULL);
    pthread_join(Sho[2], NULL);
    pthread_join(Sho[3], NULL);
    pthread_join(Sho[4], NULL);
    
    
    
    //  Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    


    return 0;
    
}

