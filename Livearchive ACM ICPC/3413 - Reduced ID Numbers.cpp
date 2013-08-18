//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1414
//#tag number threory teoria dos números
//#tag math matematica

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

#define pii pair<int,int>
#define F first 
#define S second
#define MAP map<int,int>
#define FOR(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
#define MAXN 1000000
using namespace std;

bool mark[MAXN];
int in[310];

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int t,n,aux,cont;
	cin>>t;
	while(t--){
		scanf("%d", &n);
		FOR(i,0,n){
			scanf("%d", in+i);
		}
		memset(mark,0,sizeof(mark));
		FOR(i,0,n){
			FOR(j,0,n){
				if( i == j) continue;
				aux= abs(in[i]-in[j]);
				for( int k=1;k*k<=aux;k++){
					if( aux % k ==0) {
						mark[k] = mark[aux/k] = true;
					}
				}
			}
		}
		
		FOR(i,1,MAXN){
			if( !mark[i]) {
				cout << i << endl;
				break;
			}
		}
		
	}
	return 0;
}
