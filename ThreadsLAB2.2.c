#include <stdio.h>
#include <pthread.h>
#define ARRAYS 12
#define THREADNUM 3

int a[ARRAYS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int findnum = 5;

int fflag = 0;

void *findarray(void *arg){

    int i;
    
    
    int *subarray = (int *) arg;

    
    
    
    for(i = 0; i < ARRAYS/THREADNUM; i++) {
    
        if (subarray[i] == findnum) {
        
            fflag = 1;
            
            pthread_exit(NULL);
            
        }
        
    }
    
    pthread_exit(NULL);
    
}

void create_threads(){

    int i;
    
    pthread_t threads[THREADNUM];

    for(i = 0; i < THREADNUM; i++){
    
        pthread_create(&threads[i], NULL, findarray, &i);
        
    }

    for(i = 0; i < THREADNUM; i++){
    
        pthread_join(threads[i], NULL);
        
    }
}

int main(){

    int i;
    
    pthread_t threads[THREADNUM];
    
    int subarrays[THREADNUM][ARRAYS/THREADNUM];

    
    
    for(i = 0; i < THREADNUM; i++){
    
        int j, k;
        
        k = i * (ARRAYS/THREADNUM);
        
        for(j = 0; j < ARRAYS/THREADNUM; j++){
        
            subarrays[i][j] = a[k];
            
            k++;
            
        }
        
    }

    
    for(i = 0; i < THREADNUM; i++){
   
        pthread_create(&threads[i], NULL, findarray, (void *) subarrays[i]);
        
    }

    
    for(i = 0; i < THREADNUM; i++){
    
        pthread_join(threads[i], NULL);
        
    }

    
    if (fflag){
    
        printf("\nThe number '%d' is in the array\n\n", findnum);
        
    }else{
    
        printf("\nThe number %d is in the array\n\n", findnum);
        
    }

    return 0;
    
}
