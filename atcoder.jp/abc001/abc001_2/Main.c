#include <stdio.h>

int main(void)
{
	int m;
	double n;
	scanf("%d",&m);
	
	n = m/1000.0;
	
	if(n<0.1)
		printf("00\n");
	else if(0.1<=n&&n<=5){
		if(n<1)
			printf("0%.0f\n",n*10);
		else
			printf("%.0f\n",n*10);
	}
	else if(6<=n&&n<=30)
		printf("%.0f\n",n+50);
	else if(35<=n&&n<=70)
		printf("%.0f\n",(n-30)/5+80);
	else
		printf("89\n");
		
	return 0;
}