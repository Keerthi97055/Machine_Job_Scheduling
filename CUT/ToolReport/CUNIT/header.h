#include <stdio.h>       

struct job_details 
{
    char *jno;
    char *jd;
    char *m;
    int time;
    char *client;
    struct job_details *next;
};

typedef struct job_details job;

struct linkedlist {
   job *head;
   job *tail;
};

typedef struct linkedlist machine;

void addtoList(machine *list, char *str);
void invalidFile(char str[100]);
void validAdd(job* st,int t1,int t2);
void displayList(machine *list);