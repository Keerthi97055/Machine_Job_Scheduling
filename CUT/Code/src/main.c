#include <stdio.h>
#include <pthread.h>     
#include <stdlib.h>  
#include<string.h>
#include "../include/assignJob.h"

#define MAX 500

pthread_mutex_t  M1 , M2, M3,invalidLock;
int timeT1=1,timeT2=1,timeT3=1;

int main(int argc, char* argv[])
{
    int        rc;                                        
    pthread_t  thread_id[argc-1];
     
    printf("\n\n----------------Machine Job Scheduling----------------\n\n");
    //checking argc 
    if(argc<2){
        printf("\n\tInvalid usage: Enter the file name");
        printf("\n\tMust enter atleast one file name\n");
        exit(1);
    } 
    //Displaying file names entered by user
    printf("\n     File names entered by user are : ");
    for(int i =0;i<argc-1;i++)
    {
    printf("\n\tThe file %d : %s " , i+1,argv[i+1]); 
    }
    printf("\n");
    //initialization of mutex M1
    if (pthread_mutex_init(&M1, NULL) != 0)
    {
        printf("\nMutex M1 initialization failed\n");
        return 1;
    }

    //initialization of mutex M2
    if (pthread_mutex_init(&M2, NULL) != 0)
    {
        printf("\nMutex M2 initialization failed\n");
        return 1;
    }

    //initialization of mutex M3
    if (pthread_mutex_init(&M3, NULL) != 0)
    {
        printf("\nMutex M3 initialization failed\n");
        return 1;
    }
    if (pthread_mutex_init(&invalidLock, NULL) != 0)
    {
        printf("\nMutex which is present on invalid file is failed\n");
        return 1;
    }
    //Creating threads
    for(int i=0;i<argc-1;i++){
        rc = pthread_create(&thread_id[i], NULL, assignJob, (void *)argv[i+1]);
        if(rc)                      
        {
                printf("\n\tThread %d is not created properly on %s\n", i+1,argv[i+1]);
                exit(1);
        }
        //printf("\n CREATED THREAD SUCCESSFULLY (%lu) ... \n", thread_id);
    }

    //distroy mutex
    pthread_mutex_destroy(&M1);
    pthread_mutex_destroy(&M2);
    pthread_mutex_destroy(&M3);
    pthread_mutex_destroy(&invalidLock);

    for(int i=0;i<argc-1;i++){
        pthread_join(thread_id[i],NULL);        
    }
   
    for(int i=0;i<argc-1;i++){
        pthread_exit(NULL);       
    }    
}
