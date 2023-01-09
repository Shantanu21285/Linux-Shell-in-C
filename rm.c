#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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
					int exec=remove(filename);
					if(exec!=0)
					{
						printf("%s: cannot remove directory",filename);
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
				int exec=remove(filename);
				if(exec!=0)
				{
					printf("%s: cannot remove directory",filename);
				}
				else
				{
					j=0;
				}
			}
		}
	}
	else
	{
		if(!strcmp(argv[1],"-v\0"))
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
						int exec=remove(filename);
						if(exec!=0)
						{
							printf("%s: cannot remove directory",filename);
						}
						else
						{
							printf("%s: directory successfully remove\n",filename);
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
					int exec=remove(filename);
					if(exec!=0)
					{
						printf("%s: cannot remove directory",filename);
					}
					else
					{
						printf("%s: directory successfully removed\n",filename);
						j=0;
					}
				}
			}
		}
		else if(!strcmp(argv[1],"-r\0"))
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
						int exec=rmdir(filename);
						if(exec!=0)
						{
							printf("%s: cannot remove directory",filename);
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
					int exec=rmdir(filename);
					if(exec!=0)
					{
						printf("%s: cannot remove directory",filename);
					}
					else
					{
						j=0;
					}
				}
			}
		}
		else
		{
			printf("INVALID COMMAND!");
		}
	}
	return 0;
}