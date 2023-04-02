#include <stdio.h>
#include <pthread.h>
#define THREADNUM 3 

int result[THREADNUM]; 

int parts[THREADNUM][2] = {{1,3}, {4,6}, {7,9}}; 

void *factorial(void *parameter) {
    
    int idTHREAD = *(int *) parameter; 
    
    int start = parts[idTHREAD][0]; 
    
    int end = parts[idTHREAD][1]; 
    
    result[idTHREAD] = 1; 
    
    for (int i = start; i <= end; i++) {
       
        result[idTHREAD] *= i; 
        
    }
    
    pthread_exit(NULL); 
    
}

int main() {

    pthread_t threads[THREADNUM];
    
    int identifiers[THREADNUM]; 
    
    for (int i = 0; i < THREADNUM; i++) {
    
        identifiers[i] = i; 
        
        pthread_create(&threads[i], NULL, factorial, &identifiers[i]); 
        
    }
    
    for (int i = 0; i < THREADNUM; i++) {
    
        pthread_join(threads[i], NULL); 
        
    }
    
    int total = 1; // 
    
    for (int i = 0; i < THREADNUM; i++) {
    
        total *= result[i]; 
        
    }
    
    printf("\nThe factorial of 9 is: %d :D\n\n", total); 
    
    return 0;
}
