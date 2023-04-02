#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define THREADNUM 10


void* uneven_thread( void *args )
{
    printf( "\nIm uneven.\n" );
    
    pthread_exit( NULL );
}
void* even_thread( void *args )
{
    printf( "\nIm pair.\n" );
    
    pthread_exit( NULL );
}


int main()
{
    pthread_t threads[THREADNUM];
    
    int state, i;
    
    for(i=0; i < THREADNUM; i++) 
    {
        if (i % 2 == 0)
        {
        
        	state = pthread_create( &threads[i], NULL, even_thread, NULL );
        	
        printf( "Thread created by Main in the iteration: %d.\n", i );
        
        }
        
        else if (i % 2 != 0)
        {
        
        	state = pthread_create( &threads[i], NULL, uneven_thread, NULL );
        	
        printf( "Thread created by Main in the iteration: %d.\n", i );
        
        }
        
        if (state != 0) 
        {
        
            perror("pthread_create() error.");
            
            exit(-1);
            
        }
        
    }
    
    for (i = 0; i < THREADNUM; i++)
    {
    	state = pthread_join(threads[i], NULL);
    	
    	if (state != 0) 
        {
        
            perror("pthread_join() error.");
            
            exit(-1);
            
        }
        
    }
    
    exit(0);
}
