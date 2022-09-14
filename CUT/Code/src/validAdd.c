#include <string.h>
#include "../include/header.h"

int validAdd(job* st,int t1,int t2)
{
	FILE *fp1,*fp2,*fp3;
	char* M1="m1";
	char* M2="m2";
	char* M3="m3";
    char* m1="M1";
	char* m2="M2";
	char* m3="M3";

    if(strcmp(M1,st->m)==0 || strcmp(m1,st->m)==0  )
    {
    	fp1 = fopen ("data/Schedule1.txt", "a+");
		//check file opening
		if(fp1==NULL)
		{
           printf("\n----------------Error in opening output file for Machine 1----------------\n");
		   return FAIL;
		}
		if(t1==1)
		{
        		fprintf(fp1,"%s:%d:%d\n",st->jno,t1,t2);
		}
		else
		{
				fprintf(fp1,"%s:%d:%d\n",st->jno,t1+1,t2);
		}
        fclose(fp1);
		return SUCC;
	}
	if(strcmp(M2,st->m)==0|| strcmp(m2,st->m)==0)
    {
    	fp2 = fopen ("data/Schedule2.txt", "a+");
		//check file opening
		if(fp2==NULL)
		{
           printf("\n----------------Error in opening output file for Machine 2----------------\n");
		   return FAIL;
		}
		if(t1==1)
		{
        		fprintf(fp2,"%s:%d:%d\n",st->jno,t1,t2);
		}
		else
		{
				fprintf(fp2,"%s:%d:%d\n",st->jno,t1+1,t2);
		}
        fclose(fp2);
		return SUCC;
	}
	if(strcmp(M3,st->m)==0 || strcmp(m3,st->m)==0 )
    {
    	fp3 = fopen ("data/Schedule3.txt", "a+");
		//check file opening return the failuer
		if(fp3==NULL)
		{
           printf("\n----------------Error in opening output file for Machine 3----------------\n");
		   return FAIL;
		}
		if(t1==1)
		{
        		fprintf(fp3,"%s:%d:%d\n",st->jno,t1,t2);
		}
		else
		{
				fprintf(fp3,"%s:%d:%d\n",st->jno,t1+1,t2);
		}
        fclose(fp3);
		return SUCC;
	}
}