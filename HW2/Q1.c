#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	FILE *file=fopen(argv[2],"r");
	char myC;
	int size=0;
	int num;
	int **arr;
	
	myC=getc(file);
	while(myC!=EOF)
	{
		if(myC!=',' && myC!='\n')
		{
			++size;	
			if(myC=='-')
			{	
				myC=getc(file);	
				num=-(myC-'0');
			}
			else
				num=myC-'0';
			
			printf("%d ", num);
		}
		if(myC=='\n')
			printf("\n");

		myC=getc(file);
	}
	printf("\n");	
	printf("size of augmented matrix: %d\n", size);
}