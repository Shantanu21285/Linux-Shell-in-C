#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argv[1][0]=='\0')
	{
		//printf("1");
		int i=0;
		int j=0;
		while(argv[2][i]!='\0')
		{
			char filename[50]="";
			while(argv[2][i]!='\0')
			{
				if(argv[2][i]==' ')
				{
					int exec=mkdir(filename,0755);
					if(exec!=0)
					{
						printf("%s: cannot create directory\n",filename);
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
				int exec=mkdir(filename,0755);
				if(exec!=0)
				{
					printf("%s: cannot create directory\n",filename);
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
			//printf("2");
			int i=0;
			int j=0;
			while(argv[2][i]!='\0')
			{
				char filename[50]="";
				while(argv[2][i]!='\0')
				{
					if(argv[2][i]==' ')
					{
						int exec=mkdir(filename,0755);
						if(exec!=0)
						{
							printf("%s: cannot create directory\n",filename);
						}
						else
						{
							printf("%s: directory successfully created\n",filename);
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
					int exec=mkdir(filename,0755);
					if(exec!=0)
					{
						printf("%s: cannot create directory\n",filename);
					}
					else
					{
						printf("%s: directory successfully created\n",filename);
						j=0;
					}
				}
			}
		}
		else if(!strcmp(argv[1],"-p\0"))
		{
			//printf("3");
			char cwd[100];
			int j=0;
			int i=0;
			while(argv[2][i]!='\0')
			{
				char filename[50]="";
				while(argv[2][i]!='\0')
				{
					if(argv[2][i]=='/')
					{
						int exec=mkdir(filename,0755);
						getcwd(cwd,sizeof(cwd));
						strcat(cwd,"/");
						strcat(cwd,filename);
						chdir(cwd);
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
					int exec=mkdir(filename,0755);
					getcwd(cwd,sizeof(cwd));
					strcat(cwd,"/");
					strcat(cwd,filename);
					chdir(cwd);
					j=0;
				}
			}
		}
		else
		{
			printf("INVALID COMMAND\n");
		}
	}
	return 0;

}