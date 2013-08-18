//http://br.spoj.pl/problems/CADEIR09/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;

int in[204][204];
int resp[1001][3];
int n,m;

void swap(int & a, int & b){
	int c = a;
	a = b;
	b = c;
}

void swaplines( int l, int i, int k, int bounds){
	for( int x = 0; x < bounds;x++){
		if(l) {
			swap( in[i][x], in[k][x]);
		} else {
			swap( in[x][i], in[x][k]);
		}
	}
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%d%d", &n,&m);
	int i,j;
	for( i=0;i<n;i++){
		for( j=0;j<m;j++){
			scanf("%d", &in[i][j]);
		}
	}
	int cont = 0;
	for( int k =0;k<2;k++){
		for( int i =0;i< (k? n : m);i++){
			for( int j=i +1; j < (k? n : m);j++){
				if( (!k && in[0][j] % m == (i + 1)) || 
				(k && ( in[j][0] >= (i *  m) + 1 && in[j][0] <= (i *  m) + m) ) ) {
					swaplines( k,i,j, (k? m : n));
					resp[cont][0] = (k? 'L' :'C'); resp[cont][1] = i+1; resp[cont++][2] = j+1;
					break;
				}
			}
		}
	}
	
	cout << cont << endl;
	for( int i =0;i<cont;i++){
		printf("%c %d %d\n", resp[i][0], resp[i][1], resp[i][2]);
	}
	return 0;
}