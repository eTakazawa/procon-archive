#include<iostream>
#include<string> 

using namespace std;
 
int main(void)
{
int r=0,g=0,b=0;
int n;
string ball;
cin >> n;
cin >> ball;
for(int i=0;i<ball.size();i++){
if(ball[i] == 'R') r++;
else if(ball[i] == 'G') g++;
else if(ball[i] == 'B') b++;
}
cout << (r%2)+(g%2)+(b%2) << endl;
 
 
}