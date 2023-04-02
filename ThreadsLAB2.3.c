#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ARRAYS 5

int a[ARRAYS] = {0};

void *CONSUMER(){

    int i = 0;
    
    while (1) {
    
        if (a[i] != 0) {
        
            printf("\nThe value has been found!: %d\n", a[i]);
            
            a[i] = 0;
            
            if (i == ARRAYS - 1){
            
                pthread_exit(NULL);
                
            }
            
        }
        
        i = (i + 1) % ARRAYS;
        
    }
    
}

int main() {

    int i;
    
    
    pthread_t threads;

   
    printf("\nPlease enter %d values: ", ARRAYS);
    
    
    for (i = 0; i < ARRAYS; i++) {
    
        scanf("%d", &a[i]);
        
    }

    
    pthread_create(&threads, NULL, CONSUMER, NULL);
    
    
    pthread_join(threads, NULL);
    

    printf("\nAaaaand we done :D\n\n");
    

    return 0;
}
