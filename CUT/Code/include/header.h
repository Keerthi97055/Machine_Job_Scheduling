#include <stdio.h>  
// define success and failure macros
#define SUCC 1
#define FAIL 0

struct job_details 
{
    char *jno;     //Job Number
    char *jd;      // Job Description
    char *m;       //Machine Number - M1,M2,M3
    int time;      //Time required for job
    char *client;  //Client Name
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

int validAdd(job* st,int t1,int t2);

void displayList(machine *list);