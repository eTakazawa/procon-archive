#include <stdio.h>

int main(void)
{
	int i=0;
	char a[31]={'\0'};
	char b;
	
	while((b=getchar())!='\n'){
		if(b=='a'||b=='i'||b=='u'||b=='e'||b=='o'){
		}
		else{
			a[i]=b;
			i++;
		}
	}
	
	printf("%s\n",a);
	
	return 0;
}