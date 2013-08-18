//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3131
//#tag: flood algorithm

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <utility>
#include <string>

using namespace std;

int i,j,k,a,b,c,d,t,n,m, caso =1;
int arr[1000][300];
int resp[10], cor[300];
char in[60];

void print(){
	for( int y =0; y <= n; y++){
		for(int x =0; x <=m;x++){
			printf("%d" , arr[y][x]);
		}
		puts("");
	}
	puts("");
}

void wflood(int y, int x){	
	if( arr[y][x] == 0) arr[y][x] = t;	 
	else return;
	if( y > 0 ){
		wflood(y-1, x);
	}
	if( x > 0){
		wflood(y, x-1);	
	}
	if( y <=n ){
		wflood(y+1, x);
	}
	if( x <=m){
		wflood(y, x+1);
	}
}


void bflood(int y, int x){
	// print();
	if( arr[y][x] == 0  || arr[y][x] == 1) {
		if( arr[y][x] == 0){
			wflood(y, x);
			cor[t]++;
		}
		if( arr[y][x] == 1) arr[y][x] = -1;	 
		if( y > 0 ){
			bflood(y-1, x);
		}
		if( x > 0){
			bflood(y, x-1);
		}
		if( y <=n ){
			bflood(y+1, x);
		}
		if( x <=m ){
			bflood(y, x+1);
		}		
	}
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while(scanf("%d%d", &n, &m) > 0 && n != 0){
		memset( resp, 0, sizeof(resp));
		memset( arr, 0, sizeof(arr));
		memset( cor, 0, sizeof(cor));
		t = 2;
		
		for(i = 0; i< n; i++){
			scanf("%s", &in);
			for(j=0;j<m;j++){				
				a = ( in[j] >= 'a')? (in[j] - 'a' + 10) : (in[j] - '0');
				for( k=3; k>=0;k--){
					arr[i+1][j*4 + k + 1] = a & 1;
					a = a >> 1;
				}				
			}
		}		
		m *= 4;
		// print();
		wflood(0,0);
		t++;
		for(i = 1; i<= n; i++){
			for(j=1;j<=m;j++){
				if( arr[i][j] == 1){
					bflood(i,j);					
					t++;
				}
			}
		}
		for( i = 3; i< t; i++){
			// printf("cor %d -> %d\n", i , cor[i]);
			switch(cor[i]){
				case 1: resp[0]++; //A
				break;
				case 5: resp[1]++; //D
				break;
				case 3: resp[2]++; // J
				break;
				case 2: resp[3]++; //K
				break;
				case 4: resp[4]++; // S
				break;
				case 0: resp[5]++; // W
				break;
			}
		}
		printf("Case %d: ", caso++); 
		for(i=0;i<=5;i++){
			for(j =0; j< resp[i]; j++){
				switch(i){
					case 0: printf("A"); //A
					break;
					case 1: printf("D"); //D
					break;
					case 2: printf("J"); // J
					break;
					case 3: printf("K"); //K
					break;
					case 4: printf("S"); // S
					break;
					case 5: printf("W"); // W
					break;
				}
						
			}
		}
		puts("");
	}
	return 0;
}
