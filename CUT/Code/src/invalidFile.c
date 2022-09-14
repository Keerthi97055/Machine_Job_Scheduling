#include <stdio.h>
#include <string.h>
#include<pthread.h>
#define MAX 500
extern pthread_mutex_t invalidLock;

void invalidFile(char str[MAX])
{
    // make a call to file mutex
    pthread_mutex_lock(&invalidLock);
	FILE *fp;
    fp = fopen ("data/invalidRecord.txt", "a+");
    char s[MAX];
    strcpy(s,str); 
    fputs(s, fp);
    fputs("\n",fp);
	fclose(fp); 
    pthread_mutex_unlock(&invalidLock);
    //make call to unlock file mutex
}