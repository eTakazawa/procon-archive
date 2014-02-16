#include<iostream>
#include<cstdio>
using namespace std;

int main(){
char c[5][5];
for(int i=0;i<4;i++)
scanf("%c %c %c %c\n",&c[i][0],&c[i][1],&c[i][2],&c[i][3]);

for(int i=3;i>=0;i--){
for(int j=3;j>=0;j--){
cout << c[i][j];if(j!=0)cout << ' ';
}
cout << endl;
}
}