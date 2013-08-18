//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1696
//#tag max sum

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>

#define MAX(a,b) (a<b)?b:a

using namespace std;

long long i, j , k, n , m,a,b,c,d, t, x, y;
long long in[30][30][30];
long long aux[30];
long long aux2[30][30];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	cin >> t;
	bool prim = true;
	while(t--){
		scanf("%d%d%d", &a, &b, &c);
		
		long long minv = 0, sum = 0;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				for( k=0;k<c;k++){
					cin >> d;
					// cout << d;
					in[i][j][k] = d;
					sum += d;
					if( d < 0) minv += d;
				}
			}
		}
		long long resp = minv, mai = minv;
		
		for(i=0;i<a;i++){
			memset( aux2, 0,sizeof(aux2));
			for(j=i;j<a;j++){
				for( k =0 ; k < b; k++){
					for( x = 0; x < c; x++){
						aux2[k][x] += in[j][k][x];
						// cout << aux2[k][x] << " ";
					}
					// cout << endl;
				}
				// cout << endl;
				//resolve problema 2d
				for( k=0;k<b;k++){
					memset( aux, 0, sizeof( aux));
					for( x = k; x < b; x++){
						for( y = 0; y < c; y++){
							aux[y] += aux2[x][y];
						}
						mai = minv;
						for( y = 0; y < c; y++){
							mai = MAX( aux[y] + mai, aux[y]);
							resp = MAX(resp , mai);
						}
					}
				}
			}
		}
		resp = MAX(sum, resp);
		if( !prim) cout <<endl;
else  prim = false;		
		cout << resp << endl ;
	}
	return 0;
}
