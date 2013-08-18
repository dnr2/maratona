//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3194
//#tag math matematica
//#tag probability probabilidade
//#tag pd programação dinâmica

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

#define FOR(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

string in[20];
double p[20][20];
double pd[20][20][20];

double rec( int win, int x, int y){
	if( pd[win][x][y] >= 0 ) return pd[win][x][y];
	if( abs(x-y) == 1 ){
		return pd[win][x][y] = p[win][(x==win)?y:x];
	}
	double ret = 0;
	if( win > (x+y) /2){
		for( int i=x;i<=(x+y) /2;i++){
			ret += p[win][i] * rec( i , x , (x+y) /2);
		}
		ret *= rec( win ,(x+y)/2 + 1, y);
	} else {
		for( int i=(x+y)/2 + 1;i<=y;i++){
			ret += p[win][i] * rec( i ,(x+y)/2 + 1, y);
		}
		ret *= rec( win , x , (x+y) /2);
	}
	pd[win][x][y] = ret;
	return ret;
}
int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	FOR(i,0,20) FOR(j,0,20) FOR(k,0,20) pd[i][j][k] = -1.0;
	FOR(i,1,17) cin>>in[i];
	FOR(i,1,17) FOR(j,1,17) { 
		cin>> p[i][j]; 
		p[i][j] /= 100.0; 
	} 
	FOR(i,1,17){ 
		printf("%-10s p=%.2lf", in[i].c_str(), (100.0 * rec( i, 1, 16)));
		puts("%");
	}
	return 0;
}