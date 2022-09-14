#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "../include/header.h"
#include "../include/test.h"

#define MAX 500

extern pthread_mutex_t  M1 ;
extern pthread_mutex_t  M2 ; 
extern pthread_mutex_t  M3 ;
extern int timeT1;
extern int timeT2;
extern int timeT3;

void* assignJob(void* data)
{
    char *my_data = (char *)data;         
    FILE *fpr;
    fpr= fopen(my_data,"r");
    int i=0;
    job *temp=NULL;
    int add=0;
    machine *job1=(machine*)calloc(1,sizeof(machine));
    if (fpr == NULL)
    {
        printf("\n----------------File %s is not present in input data folder----------------\n", my_data);
        pthread_exit(NULL);
    }
    char str[MAX];
    char *m1="M1";
    char *m2="M2";
    char *m3="M3";
    int cnt=0;
    while (1)
    {
        if (fgets(str, 100, fpr) == NULL)
        {
            if(cnt==0){
                printf("\n----------------File %s is empty----------------\n",my_data);
                pthread_exit(NULL);
            }
            break;
        }
        else
        {
            cnt=cnt+1;
            int st = stringValid(str);
            
        	if(st==1)
        	{
        	    addtoList(job1,str);
                
			}
			else
			{
				invalidFile(str);
			}			
        }                
    }
    for(temp=job1->head;temp!=job1->tail->next;temp=temp->next)
                {
                     if(strcmp((*temp).m,m1)==0)
                     {
                          
                          pthread_mutex_lock(&M1);
                          int t=timeT1;
                          timeT1+= temp->time;
                          validAdd(temp,t,timeT1);
                          /*if(validAdd(temp,t,timeT1))
                                printf("\n Mutex Successfully applied on machine 1\n");
                           else
                                printf("\n Mutex is not Successfully applied on machine 1\n");
                          */
                          pthread_mutex_unlock(&M1);
                     }
                      if(strcmp((*temp).m,m2)==0)
                     {
                          pthread_mutex_lock(&M2);
                          int t=timeT2;
                          timeT2+= temp->time;
                          validAdd(temp,t,timeT2);
                          //check return value unable to enter schedule
                          /*if(validAdd(temp,t,timeT2))
                                printf("\n Mutex Successfully applied on machine 2\n");
                          else
                                printf("\n Mutex is not Successfully applied on machine 2\n");
                          */
                         pthread_mutex_unlock(&M2);
                     }
                      if(strcmp((*temp).m,m3)==0)
                     {
                          pthread_mutex_lock(&M3);                          
                          int t=timeT3;
                          timeT3+= temp->time; 
                          validAdd(temp,t,timeT3); 
                          /*if(validAdd(temp,t,timeT3))
                                printf("\n Mutex Successfully applied on machine 3\n");
                            else
                                printf("\n Mutex is not Successfully applied on machine 3\n");
                          */
                          pthread_mutex_unlock(&M3);
                     }
                }
			    
    //displayList(job1);
    fclose(fpr);
    pthread_exit(NULL); 
}
