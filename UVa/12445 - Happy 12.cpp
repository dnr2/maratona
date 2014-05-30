//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3876
//#tag hash map
//#tag bfs two level breadth first search busca de dois niveis
//#sol

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(ll (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

using namespace std;

unordered_map<ll, int> mapa[2];
ll off= 1;
ll target = 0;

ll mov[] = { 2,3,4,5,6,12,7,8,9,10,11,1, 
			 12,1,2,3,4,5,7,8,9,10,11,6, 
			 1,2,3,4,5,7,8,9,10,11,12,6, 
			 1,2,3,4,5,12,6,7,8,9,10,11, 
			 2,3,4,5,6,7,8,9,10,11,12,1, 
			 12,1,2,3,4,5,6,7,8,9,10,11 };

ll mask = ((1<<4)-1);
			 
int bfs(ll init, int sec){
	queue< ll > q;
	q.push( init );
	
	if( sec  && mapa[0][init] >= 1) return (mapa[0][init] -1);		
	mapa[sec][init] = off;
	while(!q.empty()){
		ll cur = q.front(); q.pop();
		for(int i=0; i < 6;i++){
			ll aux = cur, next = 0;
			for(int j=0; j < 12; j++){
				next += ( aux & mask ) << mov[(i*12)+j];
				aux >>= 4;
			}
			if( mapa[sec][next] >= off) continue;
			mapa[sec][next] = mapa[sec][cur] + 1;
			if( sec && mapa[0][next] >= 1 ) return (mapa[0][next]-1) + (mapa[1][next]-off);							
			if( !sec && mapa[sec][next] >= 11) continue;			
			q.push( next );
		}
	}
	return 0;
}

int main(){
	int T;
	cin >> T;
	ll cur,a;
	fr(i,0,6) fr(j,0,12) mov[(i*12)+j] = ((mov[(i*12)+j]-1)<<2);
	fr(i,0,12){
		target += i<<(i<<2);
	}
	bfs( target, 0);
	while(T--){
		cur = 0;
		fr(i,0,12){
			cin >> a;
			cur += (a-1) << (i<<2);
		}		
		printf("%d\n", bfs(cur, 1));
		off+=30;
	}
	return 0;
}