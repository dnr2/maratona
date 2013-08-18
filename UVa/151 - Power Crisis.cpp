//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=87
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

int arr[110];
int bit[110], n = 10;
int resp[] = {
1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22, 54, 52, 113, 15
};

int update( int x, int v){ while( x <= n){ bit[x] += v ; x += (x & -x);}} 
int sum(int x){int ret = 0; while(x>0){ ret+= bit[x]; x -= (x & -x); } return ret;}

int cmp(int x, int y){
	return sum(x) < y;
}

int josephus( int N , int k) {
	n = N;
	cl(bit); int pos = 1, pont = 0;
	fr(i,1,n+1){
		update( i, 1);		
	}
	update( 1, -1);
	fr(i,2,n){
		pos = (( pos + k - 2 ) % (n+1-i)) + 1;						
		pont = lower_bound(arr+1, arr+n+1, pos, cmp) - arr;			
		update( pont, -1);
		
	}
	pont = lower_bound(arr+1, arr+n+1, 1, cmp) - arr;
	return pont;
}

int main(){
	// freopen("out.txt", "w", stdout);
	fr(i,0,110) arr[i] = i;
	int in;
	while(scanf("%d", &in)>0 && in){
		printf("%d\n", resp[in-13]);
		// fr(in,13,100){
		// fr(i,1,100000){
			// ll ret = josephus(in,i);
			// if( ret == 13){ printf("%d, ", i); break; }
		// }
	}
	// }
	return 0;
}