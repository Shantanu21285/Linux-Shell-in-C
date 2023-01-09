#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void merge(char *arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;

	char* arr1[n1];
	char* arr2[n2];
	for(int i=0; i<n1; i++)
	{
		arr1[i]=arr[l+i];
	}
	for(int i=0; i<n2; i++)
	{
		arr2[i]=arr[m+1+i];
	}

	int i=0, j=0, k=l;
	while(i<n1 && j<n2)
	{
		if(strcmp(arr1[i],arr2[j])<=0)
		{
			arr[k]=arr1[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=arr2[j];
			j++;
			k++;
		}
	}

	while(i<n1)
	{
		arr[k]=arr1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=arr2[j];
		j++;
		k++;
	}
}

void mergesort(char* arr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}


int main(int argc, char* argv[])
{
	char* files[1024];
	if(argv[1][0]=='\0')
	{
		DIR *dir;
		struct dirent *folder;
		dir= opendir(".");
		int i=0;
		if(dir==NULL)
		{
			printf("EMPTY DIRECTORY!");
		}
		else
		{
			while((folder=readdir(dir)))
			{
				//printf("1");
				//printf("%s",folder->d_name);
				if(folder->d_name[0]!='.')
				{
					files[i]=folder->d_name;
					//printf("%s %s",files[i],folder->d_name);
					i++;
				}
			}
			mergesort(files,0,i-1);
			
			for(int j=0; j<=i; j++)
			{
				printf("%s\n",files[j]);
			}
		}
		closedir(dir);
	}
	else if(!strcmp(argv[1],"-a\0"))
	{
		DIR *dir;
		struct dirent *folder;
		dir= opendir(".");
		int i=0;
		if(dir==NULL)
		{
			printf("EMPTY DIRECTORY!");
		}
		else
		{
			while((folder=readdir(dir)))
			{
				files[i]=folder->d_name;
				i++;
			}
			mergesort(files,0,i-1);
			
			for(int j=0; j<=i; j++)
			{
				printf("%s\n",files[j]);
			}
		}
		closedir(dir);
	}
	else if(!strcmp(argv[1],"-r\0"))
	{
		DIR *dir;
		struct dirent *folder;
		dir= opendir(".");
		int i=0;
		if(dir==NULL)
		{
			printf("EMPTY DIRECTORY!");
		}
		else
		{
			while((folder=readdir(dir)))
			{
				if(folder->d_name[0]!='.')
				{
					files[i]=folder->d_name;
					i++;
				}
			}
			mergesort(files,0,i-1);
			
			for(int j=i-1; j>=0; j--)
			{
				printf("%s\n",files[j]);
			}
		}
		closedir(dir);
	}
	else
	{
		printf("INVALID COMMAND!");
	}
	return 0;

}