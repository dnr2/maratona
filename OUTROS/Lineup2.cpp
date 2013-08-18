//
//#tag
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

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair

using namespace std;

int in[11][11];

int t,z = 11,a,b,c;

int rec(int dep, int mask){
	if(dep >= z) return 0;
	int ret =-10000;
	fr(i,0,z) if( (1<<i & mask )==0 && in[dep][i]){
		ret = max( ret , rec( dep+1, (mask | 1<<i)) + in[dep][i] );
	}
	return ret;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	cin >> t;
	while(t--){
		fr(i,0,z) fr(j,0,z) scanf("%d", &in[i][j]);
		cout <<rec( 0,0) << endl;
	}
	return 0;
}