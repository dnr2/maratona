//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>

using namespace std;

int a, b, c,  d, i ,k, j, m , n, len;
char cmd1[10], cmd2[10];

int piles[30][30];
int tops[30];
	
struct pos{
	int x, y;
};
	
pos p1, p2;

void printPiles(){
	for( int x = 0; x < n; x++){
		printf("%d:", x);
		for( int y = 0; y <= tops[x]; y++){
			printf(" %d", piles[x][y]);
		}
        //printf("  -> %d", tops[x]);
        printf("\n");
	}
}

pos findPile(int block){
	pos aux;
	for( int x = 0; x < n; x++){		
		for( int y = tops[x]; y >= 0 ; y--){			
			if( piles[x][y] == block){
				aux.x = x;
				aux.y = y;
				return aux;
			}
		}
	}
	return aux;
}

void initial( int x, int bot){
	for( int y = bot + 1; (y < n) && (piles[x][y] != -1); y++){
        //printf(" puting %d %d on %d %d\n", x, y, piles[x][y] , 0);
		piles[piles[x][y]][0] = piles[x][y];
		tops[piles[x][y]] = 0;
		//printf(" removing %d from %d %d\n", piles[x][y], x, y);
		piles[x][y] = -1;		
	}
	tops[x] = bot;
}



int main(){
	
	freopen( "in.txt", "r", stdin);
	freopen( "out.txt", "w", stdout);
	
	scanf("%d", &n);	
	memset( piles, -1, sizeof(piles));
	memset( tops, 0, sizeof(tops));
	
	for( i = 0 ; i < n; i++){
		piles[i][0] = i;
	}
	
	while( scanf("%s %d %s %d", cmd1, &a, cmd2, &b) > 1 ){
		if( a != b ){
			p1 = findPile(a);
			p2 = findPile(b);
			//cout << p1.x << " " <<  p1.y << " " << p2.x << " " << p2.y << endl;
			if( p1.x != p2.x ){			
				if( strcmp(cmd1, "move") == 0){
					if( strcmp(cmd2	, "onto") == 0){									
						initial( p1.x, p1.y);
						initial( p2.x, p2.y);
						piles[p2.x][p2.y+1] = piles[p1.x][p1.y];
						piles[p1.x][p1.y] = -1;
						tops[p2.x]++;
						tops[p1.x]--;
					} else {
						initial( p1.x, p1.y);
						piles[p2.x][++tops[p2.x]] = piles[p1.x][p1.y];
						piles[p1.x][p1.y] = -1;					
						tops[p1.x]--;
					}
					
				} else { 
					if( strcmp(cmd2	, "onto") == 0){					
						initial( p2.x, p2.y);						
						for( int y = tops[p1.x]; y >= p1.y; y--){
							piles[p2.x][++tops[p2.x]] = piles[p1.x][y];
							piles[p1.x][y] = -1;
							tops[p1.x]--;							
						}
					} else {
						for( int y = p1.y; y < n && piles[p1.x][y] != -1; y++){
							piles[p2.x][++tops[p2.x]] = piles[p1.x][y];
							piles[p1.x][y] = -1;
                            tops[p1.x]--;
						}
					}
				}
				
				//cout << "\n";
			}
		}
		
	}
	printPiles();
	return 0;
}

