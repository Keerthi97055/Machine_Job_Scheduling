#include <stdlib.h>
#include <string.h>
#include "../include/header.h"

void addtoList(machine *list, char *str)
{
    job *newnode = (job *)calloc(1, sizeof(job));
    job* temp = NULL;
    newnode->next = NULL;
    if (list->head == NULL)
    {
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        list->tail->next = newnode;
        list->tail = newnode;
    }
    int i=0;
    char *token = strtok(str,":");
    while(token != NULL){
	switch(i)
	{
	
         case 0:
		         newnode->jno = (char *)calloc(strlen(token), sizeof(char));
                 strcpy(newnode->jno, token);
                 break;
         case 1:        
                 newnode->jd = (char *)calloc(strlen(token), sizeof(char));
                 strcpy(newnode->jd, token);
                 break;
         case 2:
                  newnode->m = (char *)calloc(strlen(token), sizeof(char));
                  strcpy(newnode->m, token);
                  break;
         case 3:         
				  newnode->time = atoi(token);
		          break;
		 case 4:
                  newnode->client = (char *)calloc(strlen(token), sizeof(char));
                  strcpy(newnode->client, token);
                  break;
          default: printf("\n");
    		         break;
    }
    i++;
    
    token = strtok(NULL,":");
  }
 
}