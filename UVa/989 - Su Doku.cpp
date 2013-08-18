//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=930
//#tag: Backtraking

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int i,j,k,n,m,c,d,topo,n2;
bool used[3][10][10]; // first dimension used as block, line or column
int in[10][10];

void print(){
	for( int x=0;x<n2;x++){
		for(int y=0;y<n2;y++){
			printf("%d", in[x][y]);
			if( y < n2-1) printf(" ");
		}
		printf("\n");
	}
}

bool sudoku(int x, int y){
	if( y == n2) return true;	
	if(in[y][x]) {
		if( x < n2 -1) return sudoku(x+1,y);
		else return sudoku(0,y+1);
	}
	for(int z =1; z <= n2;z++){
		if( !used[0][z][x/n + n* (y/n)] && !used[1][z][y] && !used[2][z][x] ) {
			in[y][x] = z;
			used[0][z][ x/n + n * (y/n) ] = used[1][z][y] = used[2][z][x] = true;
			// printf("x = %d y = %d z = %d\n", x, y, z); print(); puts("");
			if( sudoku(x,y) ) return true;
			in[y][x] = 0;
			used[0][z][ x/n + n * (y/n) ] = used[1][z][y] = used[2][z][x] = false;
		}
	}
	return false;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	bool first = true;
	while(scanf("%d", &n) >0 ){
		memset(used, false ,sizeof(used));
		memset(in, 0 ,sizeof(in));
		n2 = n * n;
		for(i=0;i<n2;i++){
			for(j=0;j<n2;j++){
				scanf("%d", &in[i][j]);
				if(in[i][j] != 0){
					used[0][in[i][j]][ j/n + n * (i/n) ] = used[1][in[i][j]][i] = used[2][in[i][j]][j] = true;
				}
			}
		}
		
		if( first ) first = false;
		else printf("\n");
		
		if( sudoku(0,0)){
			print();
		} else {
			printf("NO SOLUTION\n");
		}
	}
	return 0;
}

