//3436. Histogram
//#tag pd dinamic programming 
//#tag memoization

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

#define fr(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

int in[16];
pii pd[1<<16][111];
int mark[1<<16][111];
int n,m,t,num,resp=0, resp2, turn = 1;

pii rec(int mask, int ant){
	if( mark[mask][ant] == turn ) return pd[mask][ant];
	mark[mask][ant] = turn;
	
	pii ret(-1,0), aux;
	bool ok = 0;
	fr(i,0,n){
		if( !((mask >> i) & 1) ){
			ok = true;
			aux = rec( (mask | (1<<i)) , in[i]);
			aux.F += abs(in[i] - ant);
			if( ret.F < aux.F){	
				ret.F = aux.F; ret.S = aux.S;
			} else if( ret.F == aux.F) {
				ret.S += aux.S;
			}
		}
	}
	if(!ok){
		return pd[mask][ant] = pii(ant,1);
	}
	return pd[mask][ant] = ret;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while(scanf("%d", &n) >0 && n ){
		fr(i,0,n) scanf("%d", in+i);
		pii ret = rec(0,0);
		turn++;
		printf("%d %d\n", ret.F + 2 * n, ret.S);
	}
	return 0;
}