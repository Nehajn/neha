#include<stdio.h>
#include<string.h>
enum days{
	
	Monday=0,
	Tuesday=1,
	Wednesday=2,
	Thursday=3,
	Friday=4,
	Saturday=5,
	Sunday=6,
};

typedef struct mydata{
	char myline[200];
}mydata;




const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ","))
    {
       // printf(tok);
		if (!--num)
            return tok;
    }
    return NULL;
}

void insertionsort(int arr[],mydata m[],int size);
//void read();
int main(){
	
	FILE *fp=fopen("F://Online11.csv","r");
	
	
	if(fp!=NULL){
		int t_size=150;
		char line[200];
		char *token=",";
		char *start;
		char strday[10];
		int x=0,si=0;
		int arr[150];
		enum days today;
		char day1[15];
		mydata *m=(mydata *)malloc(sizeof(mydata)*t_size);
		
		//fgets(line,sizeof line,fp);
		
		while(fgets(line,sizeof line,fp)!=NULL)
		{
		
		
		   strcpy(m[si].myline,line);
		   start=strtok(line,token);
		    x=0;
		
		    while(start!=NULL && x++!=6)
		   {
			start=strtok(NULL,token);	
		   }
		 	
			 if(!strcmp("Monday",start))
			{
			today=Monday;
			}
			else if(!strcmp("Tuesday",start))
			{
			today=Tuesday;
			}
			else if(!strcmp("Wednesday",start))
			{
			today=Wednesday;
			}
			else if(!strcmp("Thursday",start))
			{
			today=Thursday;
			}
			else if(!strcmp("Friday",start))
			{
			today=Friday;
			}
			else if(!strcmp("Saturday",start))
			{
			today=Saturday;
			}else{
			today=Sunday;
			}
		arr[si++]=today;					
		}
	
		insertionsort(arr,m,t_size);
		read();
		
		fclose(fp);
   		fp=fopen("F://Online1211.csv","w");
   		
   		int k=0,mn=0;
   		char test[200];
		for(k=0; k<=t_size; k++)
   		{
   			  printf("%s",m[k].myline);
   			  strcpy(test,m[k].myline);
   			  if(m[k].myline==',')
   			  {
   			  	printf("\n");
			  }
			  for(mn=0; mn<=sizeof (test); mn++)
			  {
				  if(test[mn]==NULL)
				  break;
			  }  
		   	   fwrite(m[k].myline,1,mn,fp);
		   
		}
		fclose(fp);

		fp=fopen("F://online1211.csv","r");
		char *line1;
		//char *line2;
		 while (fgets(line, 4096, fp))
        {
        char* tmp = strdup(line);
    	char* tmp1=strdup(line);
    	char tmp2[20];
    		
        printf("%s", getfield(tmp, 7));
        //snprintf(tmp,sizeof(10),getfield(tmp,7));
        //sprintf(tmp2,tmp,20);
        //printf(tmp2);
        printf(",");
        printf("%s\n",getfield(tmp1,3));
      // line1=getfield(tmp,7);
       //printf(line);
       /*I need to store this tmp1 and tmp to a new csv file*/
        // NOTE strtok clobbers tmp
       // free(tmp);
        //free(tmp1);
        
     //   	printf("enter the day\n");
   	//scanf("%s",&day1);
   //	if(strcmp(day1,getfield(tmp,7))==0)
   	//{
   	//	printf("yay");
	  // }
   	}
   
		   
		   
   		
   		
   		
	}else{
		printf("\n Error in opening file");
	}
	return 0;
}

void insertionsort(int arr[],mydata m[],int size)
{
	
   int i, key, j;
   int k=0;
   char s[200];
   for (i = 1; i < size; i++)
   {
   	   strcpy(s,m[i].myline);
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
   	   	   strcpy(m[j+1].myline,m[j].myline);
		   j--;
       }
       arr[j+1] = key;
   	   strcpy(m[j+1].myline,s); 
   }
 
   
   
   
}

