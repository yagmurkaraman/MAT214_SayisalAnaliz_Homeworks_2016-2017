#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int degree;
int number;
int size;

void leastSquare(double *x, double *y, int degree);
int main()
{
    int number,degree,i,j;
    double *x, *y;
 
    printf("Enter the number of coordinates: ");        
    scanf("%d",&number);
    size=number;

    x=(double *)malloc(number*sizeof(double));
    y=(double *)malloc(number*sizeof(double));

    printf("Enter the values of x: ");
    for(i=0; i<number; i++){
        scanf("%lf",&x[i]);
    }

    printf("Enter the values of y: ");
    for(i=0; i<number; i++){
        scanf("%lf",&y[i]);
    }

    printf("Enter the degree of polynomial: ");
    scanf("%d",&degree);                                

    leastSquare(x,y,degree);

    
    return 0;
}
void leastSquare(double *x, double *y, int degree){

	int i,j;
	double *coefX;
	int number=size;
	char polynomial[1024]="";

    coefX=(double *)malloc((2*number+1)*sizeof(double));

    for(i=0; i<2*number+1; i++)
    {
        coefX[i]=0;
        for (j=0; j<number; j++){
            coefX[i]=coefX[i]+pow(x[j],i);      
        }
    }
    double matris[number+1][number+1];
    double *a;            
    a=(double *)malloc((number+1)*sizeof(double));

    for(i=0; i<=number; i++){

        for(j=0; j<=number; j++){
            matris[i][j]=coefX[i+j];            
        }
    }
    double *coefY;
    coefY=(double *)malloc((number+1)*sizeof(double));                    
    
    for(i=0; i<number+1; i++)
    {    
        coefY[i]=0;
        for(j=0; j<number; j++)
        	coefY[i]=coefY[i]+pow(x[j],i)*y[j];        
    }
    for(i=0; i<=number; i++){
        matris[i][number+1]=coefY[i];
    }

    number=number+1;               
        
    int k;
    for(i=0; i<number; i++){                   
        
        for(k=i+1; k<number; k++){
            
            if(matris[i][i] < matris[k][i]){
                
                for(j=0; j<=number; j++)
                {
                    double temp=matris[i][j];
                    matris[i][j]=matris[k][j];
                    matris[k][j]=temp;
                }
            }    
        }
    }
    for(i=0; i<number-1; i++){         
        
        for(k=i+1; k<number; k++)
        {
            double t=matris[k][i]/matris[i][i];
            for(j=0; j<=number; j++)
                matris[k][j]=matris[k][j]-t*matris[i][j];  
        }
    }        
    for(i=number-1; i>=0; i--){     

        a[i]=matris[i][number];               
        for(j=0; j<number; j++)
        {
            if(j!=i)                                             
                a[i]=a[i]-matris[i][j]*a[j];
        }
        a[i]=a[i]/matris[i][i];           
    }
    strcpy(polynomial,"x^0");

 	fprintf(stderr, "\nPolynomial: x^0 ");
    for(i=1; i<degree; i++)
    	fprintf(stderr, "+(%.3f)x^%d", a[i],i);
 
 	fprintf(stderr, "\n");
}