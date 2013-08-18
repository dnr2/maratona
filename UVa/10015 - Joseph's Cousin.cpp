//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=956
//#tag josephs joseph josephus
//#tag binary indexed tree bit
//#sol usar bit para solucionar joseph

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
#include <sstream>
#include <climits>

// #include <unordered_map>

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
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

int crivo[101000];
int prim[3512];
int arr[3512];
int bit[4512], n = 10;

int update( int x, int v){ while( x <= n){ bit[x] += v ; x += (x & -x);}} 
int sum(int x){int ret = 0; while(x>0){ ret+= bit[x]; x -= (x & -x); } return ret;}
int val(int x){ int ret = sum(x); return ret - sum(x-1);}

int cmp(int x, int y){
	return sum(x) < y;
}

int main(){
	
	int cont = 1;
	for(int i=2; i < 100000; i++) {
		if(crivo[i]==0) { 
			prim[cont++] = i; 
			if(cont > 3503) break; 
			for(int j=i;j<100000;j+=i) crivo[j] = i;
		}
	}
	fr(i,0,3503) arr[i] = i;
	while(scanf("%d", &n)>0 && n){
		cl(bit); int pos = 1, pont = 0;
		fr(i,1,n+1) update( i, 1);		
		fr(i,1,n){			
			pos = (( pos + prim[i] - 2 ) % (n+1-i)) + 1;						
			pont = lower_bound(arr+1, arr+n+1, pos, cmp) - arr;			
			update( pont, -1);
		}
		pont = lower_bound(arr+1, arr+n+1, 1, cmp) - arr;
		printf("%d\n", pont);
	}
	return 0;
}