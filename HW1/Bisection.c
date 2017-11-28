/******************************************************************************/
/* Sayisal Analiz-Homework1                                                   */
/* --------------------------                                                 */
/* Yagmur Karaman - 141044016                                                 */
#define ITR_MAX 100 /* max iterations */
#define PI 3.141592 /* value of pi */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *file;
	double startPoint,endPoint,epsilon;
	double x,result,myFunc,fa,errorDis,errorAbs,errorRel;
	char stop[20];
	int i=1;

	/* her bir fonksiyonun ciktisi icin dosya olusturulur */
	/*file=fopen("exercise6A.txt","a");
	file=fopen("exercise6B.txt","a");
	file=fopen("exercise6C_1.txt","a");
	file=fopen("exercise6C_2.txt","a");
	file=fopen("exercise6D_1.txt","a");*/
	file=fopen("exercise6D_2.txt","a");

	/* kullanici tarafindan inputlar girilir */
	printf("start of the root: ");
	scanf("%lf",&startPoint);

	printf("end of the root: ");
	scanf("%lf",&endPoint);

	printf("type of stopping criterion: ");
	scanf("%s",stop);

	printf("epsilon value: ");
	scanf("%lf",&epsilon);
	/* dosyaya basliklar yazilir */
	fprintf(file,"        a          b         p       ABSOLUTE ERROR     RELATIVE_ERROR  \n" );
	fprintf(file,"****************************************************************************\n");


	/* asagidaki kodun algoritmasini kitabin 49. sayfasindaki 
		algorithm 2.1 den aldim */
	x=startPoint;
	
	/*myFunc=3*x-exp(x);
	myFunc=2*x+3*cos(x)-exp(x);
	myFunc=pow(x,2)-4*x+4-log(x);*/
	myFunc=x+1-2*sin(PI*x);

	fa=myFunc;
	while(i<=ITR_MAX)
	{
		errorDis=fabs(myFunc);
		x=startPoint+(endPoint-startPoint)/2;
		errorAbs=fabs(x-startPoint);
		errorRel=fabs(x-startPoint)/x;
		
		/*myFunc=3*x-exp(x);
		myFunc=2*x+3*cos(x)-exp(x);
		myFunc=pow(x,2)-4*x+4-log(x);*/
		myFunc=x+1-2*sin(PI*x);
		result=myFunc;
		
		if(result==0 || ((endPoint-startPoint)/2)<epsilon)
		{	
			/* root bulunur, son veriler dosyaya yazilir ve program sonlanir. */
			fprintf(file, "%2d. ",i);
			fprintf(file, "%.6lf   ",startPoint);
			fprintf(file, "%.6lf   ",endPoint);
			fprintf(file, "%.6lf       ",x);
			fprintf(file, "%.6lf        ",errorAbs);
			fprintf(file, "%.6lf   \n",errorRel);

            fprintf(file,"\nTOTAL ITERATION IS :  %d",i);
            fprintf(file,"\nTHE APPROXIMATE ROOT :  %f",x); 

			return 0;
		}
		/* bulunan degerler dosyaya yazilir, -"nice" formatting.- */
		fprintf(file, "%2d. ",i);
		fprintf(file, "%.6lf   ",startPoint);
		fprintf(file, "%.6lf   ",endPoint);
		fprintf(file, "%.6lf       ",x);
		fprintf(file, "%.6lf        ",errorAbs);
		fprintf(file, "%.6lf   \n",errorRel);		
		if(fa*result>0)
		{
			startPoint=x;
			fa=result;
		}
		else
			endPoint=x;		
	
		++i;
	}
	/* eger root 100 iterationla bulunamazsa hata mesaji verilir ve 
				program biter */
	if(i>ITR_MAX)
		printf("ERROR! ROOT COULDN'T FOUND IN 100 ITERATIONS!\n");

	return 0;
}