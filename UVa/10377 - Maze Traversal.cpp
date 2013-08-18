//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1318

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, a, b, c, d ,m , t;
int p, q, k , n, e, x, y;
char arr[100][100];
char buf;

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);	
	
	cin >> t;	
	while(t--){	
		memset(arr, 0 , sizeof(arr));
		scanf("%d %d", &n, &m);
		// cout << n << " " <<m << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%c",&buf);
				if(buf == '\n'){
					scanf("%c",&buf);					
				}
				arr[i][j] = buf;				
			}
			// puts(arr[i]);
		}
		scanf("%d %d", &y , &x);
		x--; y--;
		d = 0;
		bool fim = false;
		// cout << y << " " << x << endl;
		while( scanf("%c", &buf) > 0){			
			
			switch(buf){
				case 'R': 
					d = (d + 1) % 4;
					break;
				case 'L': 
					d = (((d - 1) % 4 )+ 4 ) % 4;
					break;					
				case 'F': 
					switch(d){
						case 0:
							if( y -1 >= 0 && arr[y-1][x] == ' ' ) 
							y--;
							break;
						case 1:
							if(  x + 1 < m && arr[y][x+1] == ' ')
							x++;
							break;
						case 2:
							if( y + 1 < n && arr[y+1][x] == ' ' ) 
							y++;
							break;
						case 3:
							if( x -1 >= 0 && arr[y][x-1] == ' ' )
							x--;
							break;
					}
					break;
				case 'Q': 
					char out;
					switch(d){
						case 0: out = 'N';
							break;
						case 1: out = 'E';
							break;
						case 2: out = 'S';
							break;
						case 3: out = 'W';
							break;
					}
					fim = true;
					printf("%d %d %c\n", y+1, x+1, out );
					if( t > 0) printf("\n");
					break;
			}
			if(fim) break;
		}		
		
		// cout << n << " " << m << endl;
	}
	
	return 0;
}
