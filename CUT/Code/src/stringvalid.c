#include "../include/header.h"
#define MAX 500
int stringValid(char str[MAX])
{
	int k=0;
	int c=0;
    if(str[0]=='J' || str[0]=='j')
    {
            	      
      while(str[k])
        {
            if(str[k]==':')
            {                    
               c++;
               if(c==2)
               {
            		if(!(str[k+1]=='M' || str[k+1]=='m' ))
            			break;
					else if(str[k+1]=='M' || str[k+1]=='m')
					{
					    if(!(str[k+2]>='1' && str[k+2]<='3'))
						{
							break;
						}	
				    }
            				
				}
			  if(c==3)
             {
            		if(!(str[k+1]>='0' && str[k+1]<='9' ))
            		  break;
					if(str[k+1]>='0' || str[k+1]<='9')
					{
						if(!(str[k+2]>='0' && str[k+2]<='9'))
						 { 
							break;
						 }	
				    }
               }    
           }
       k++;
	   }
       if(c>=3)
      {
	    return SUCC;
      }
      else
     {
	  return FAIL;
     }
			     
   }
			
}