#include <stdio.h>
#include <math.h>

int main(void)
{
	int xa,ya,xb,yb,xc,yc;
	double ans,a,b,c,s;
	scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
	
	a = sqrt(pow(xa-xb,2)+pow(ya-yb,2));
	b = sqrt(pow(xb-xc,2)+pow(yb-yc,2));
	c = sqrt(pow(xa-xc,2)+pow(ya-yc,2));
	
	s=0.5*(a+b+c);
	
	ans = sqrt(s*(s-a)*(s-b)*(s-c));
	
	printf("%f\n",ans);
	
	return 0;
}