#include<iostream>
#include <stdio.h>
#include<string>
using namespace std;
 
int W,H;
char maze[501][501];
bool reached[501][501];
 
void search(int x, int y)
{
	if (x < 0 || W <= x || y < 0 || H <= y || maze[y][x] == '#' ) return;
	if (reached[y][x]) return;
 
	reached[y][x] = true;
 
	search(x+1, y);
	search(x-1, y);
	search(x, y+1);
	search(x, y-1);
}
 
int main()
{
	
	int s_x=0,s_y=0,g_x=0,g_y=0;
	cin >> H >> W;
	for (int i=0;i<H;i++)
	{
		scanf("%s",maze[i]);
		for(int j=0;j<W;j++)
		{
			
			if(maze[i][j]=='s') 
			{
				s_x=j;
				s_y=i;
			}
			else if(maze[i][j]=='g') 
			{
				g_x=j;
				g_y=i;
			}
		}
	}
	
	search(s_x, s_y);
	if(reached[g_y][g_x] == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}