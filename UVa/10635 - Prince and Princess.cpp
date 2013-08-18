//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576
//#tag lis longest increasing subsequence

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<map>


using namespace std;

int in[2][92500];
int pd[92500];

bool cmp(int x, int y){
	return in[0][x] < in[0][y];
}

int main(){
	int t, n, p ,q ,a, k, caso=1;
	cin >> t;
	while( t--){
		scanf("%d%d%d", &n, &p, &q );
		memset(in, 0, sizeof( in));
		memset(pd, 0, sizeof( pd));
		for( int i =0; i <= p; i++){
			scanf("%d", &a );
			in[0][a] = i+1;
		}
		int cont = 0;
		for( int i =0; i<= q; i++){
			scanf("%d", &a );
			if( in[0][a] ) in[1][cont++] = a; 
		}
		int tan = 0;
		for( int i =0; i< cont; i++){
			k = lower_bound(pd, pd + tan, in[1][i], cmp) - pd;
			if( tan == k) tan++;
			pd[k] = in[1][i];
			
		}
		
		printf("Case %d: %d\n", caso++ , tan);
	}
	return 0;
}
