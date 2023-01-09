#include <stdio.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	if(argv[1][0]=='\0')
	{
	    int i=0;
		int j=0;
		while(argv[2][i]!='\0')
		{
			char filename[50]="";
			while(argv[2][i]!='\0')
			{
				if(argv[2][i]==' ')
				{
					FILE* ptr;
				    char txt[2048];
				    ptr = fopen(filename, "r");
				 
				    if (ptr==NULL) 
				    {
				        printf("file can't be opened \n");
				    }
				    else
				    {
				    	while (fgets(txt, 2048, ptr) != NULL)
					    {
					        printf("%s",txt);
					    }
					    fclose(ptr);
				    }
				    j=0;
				    i++;
					break;
				}
				else
				{
					filename[j]=argv[2][i];
					i++;
					j++;
				}
			}
			if(argv[2][i]=='\0')
			{
				FILE* ptr;
			    char txt[2048];
			    ptr = fopen(filename, "r");
			 
			    if (ptr==NULL) 
			    {
			        printf("file can't be opened \n");
			    }
			    else
			    {
			    	while (fgets(txt, 2048, ptr) != NULL)
				    {
				        printf("%s",txt);
				    }
				    fclose(ptr);
			    }
			    j=0;
			}
		}
	}
	if(!strcmp(argv[1],"-n\0"))
	{
	    int i=0;
		int j=0;
		int k=1;
		while(argv[2][i]!='\0')
		{
			char filename[50]="";
			while(argv[2][i]!='\0')
			{
				if(argv[2][i]==' ')
				{
					FILE* ptr;
				    char txt[2048];
				    ptr = fopen(filename, "r");
				 
				    if (ptr==NULL) 
				    {
				        printf("file can't be opened \n");
				    }
				    else
				    {
				    	while (fgets(txt, 2048, ptr) != NULL)
					    {
					        printf("%d  %s",k,txt);
					        k++;
					    }
					    fclose(ptr);
				    }
				    j=0;
				    i++;
					break;
				}
				else
				{
					filename[j]=argv[2][i];
					i++;
					j++;
				}
			}
			if(argv[2][i]=='\0')
			{
				FILE* ptr;
			    char txt[2048];
			    ptr = fopen(filename, "r");
			 
			    if (ptr==NULL) 
			    {
			        printf("file can't be opened \n");
			    }
			    else
			    {
			    	while (fgets(txt, 50, ptr) != NULL)
				    {
				        printf("%d  %s",k,txt);
				        k++;
				    }
				    fclose(ptr);
			    }
			    j=0;
			}
		}
	}
	if(!strcmp(argv[1],"-E\0"))
	{
		int i=0;
		int j=0;
		while(argv[2][i]!='\0')
		{
			char filename[50]="";
			while(argv[2][i]!='\0')
			{
				if(argv[2][i]==' ')
				{
					FILE* ptr;
				    char ch;
				    ptr = fopen(filename, "r");
				 
				    if (ptr==NULL) 
				    {
				        printf("file can't be opened \n");
				    }
				    else
				    {
				    	do 
				    	{
        					ch=fgetc(ptr);
        					if(ch=='\n')
        					{
        						printf("$");
        					}
					        printf("%c", ch);
					    } while (ch != EOF);
				    }
				    j=0;
				    i++;
					break;
				}
				else
				{
					filename[j]=argv[2][i];
					i++;
					j++;
				}
			}
			if(argv[2][i]=='\0')
			{
				FILE* ptr;
			    char ch;
			    ptr = fopen(filename, "r");
			 
			    if (ptr==NULL) 
			    {
			        printf("file can't be opened \n");
			    }
			    else
			    {
			    	do {
    					ch=fgetc(ptr);
    					if(ch=='\n')
    					{
    						printf("$");
    					}
				        printf("%c", ch);
				    } while (ch != EOF);			    
			    	j=0;
				}
			}
		}
	}


	return 0;
}