#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

struct p{
	int i,j,n;
	p(int a = 0, int b = 0,int c = 0): i(a), j(b), n(c) {};
	bool operator < ( const p & in) const {
		return ((i != in.i)? i < in.i : n < in.n);
	}
};

int i, j , k, n , m, t, num, a, b,c;
p in[2501];
int fnum[51];
int resp;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	cin >> t;
	
	while(t--){
		resp =0 ;
		b = 0;
		num = 0;
		scanf("%d%d", &n, &m);
		memset(in, 0 , sizeof(in));
		memset(fnum, 0 , sizeof(fnum));
		for(i =0;i < n; i++){
			for(j=0;j< m;j++){
				scanf("%d", &a);
				num = max(num, a);
				if( a != -1) {
					p aux(i,j,a);
					fnum[i]++;
					in[b++] = aux;					
				}
			}
		}
		sort( in, in + num);
		c = 0;
		for( i=0;i < n; i++){
			int init = 0;
			for( j=0;j<fnum[i];j++){
				// printf("%d %d - %d %d -> %d\n" , in[c].i, in[c].n ,  abs(init - in[c].j), abs(m - abs( init - in[c].j)), init);
				resp += 5 * min( abs(init - in[c].j), abs( m -abs( init - in[c].j)));
				init = in[c++].j;
				// printf("%d\n", resp );
			}
			resp += i * 20 * fnum[i];
			// printf("%d\n", resp );
		}
		printf("%d", resp); puts("");
	}
	
	return 0;
	
}
