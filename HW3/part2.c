#include <stdio.h>
#include <stdlib.h>

double *x,*y;
double value;
int number;

double dividedDifference(double F[number+1][number+1]);
int main(){

	int xValue , yValue;
	int i,j;
	
	printf("Number of elements: ");
	scanf("%d",&number);

	x=(double *)malloc(number*sizeof(double));
	y=(double *)malloc(number*sizeof(double));

	printf("Enter values of coordinate x: ");
	for(i=0; i<number; ++i)
	{
		scanf("%lf",&x[i]);
	}
	printf("Enter values of coordinate y-(f(x)): ");
	for(i=0; i<number; ++i)
	{
		scanf("%lf",&y[i]);
	}
	printf("Value for evaluate: ");
	scanf("%lf",&value); 
	
	double F[number+1][number+1];

	for(i=0; i<number; ++i)
	{
		for(j=0; j<=i; ++j)
		{
			if(j==0)
				F[i][j]=y[i];
				
		}	
	}
	for(i=1; i<number; ++i)
	{
		for(j=1; j<=i; ++j)
			F[i][j]=(F[i][j-1]-F[i-1][j-1])/(x[i]-x[i-j]);
			
	}
	fprintf(stderr,"P(%.2lf): %.3lf\n", value,dividedDifference(F));
	return 0;
}
double dividedDifference(double F[number+1][number+1]){

	double total=0;
	double result=1;
	int i,j;

	for(i=1; i<=number; ++i){
	
		result=1;
		for(j=0; j<=i-1; ++j){
			result=result*(value-x[j]);
		}
		total=total+F[i][i]*result;
	}
	total=total+F[0][0];
	for(i=0; i<number; ++i){
		fprintf(stderr, "F[%d][%d]: %.3lf\n",i,i,(double)F[i][i]);

	}
	//printf("P(%f): %.3f\n", value,total);
	return total;
}