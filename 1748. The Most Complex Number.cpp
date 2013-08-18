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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};

ll nums[1000]; // menor nums[i] é o menor número com i divisores

ull bound, nummin, divmin;

ll fast( ll x, ll y){
	if( y == 0) return 1;
	if( y & 1) return x * fast(x,y-1);
	ll ret = fast( x, y/2);
	return ret*ret;
}

ll rec( ull x , ull y){
	ull num = 1, int ndiv = 1; int cont = 0;
	while(x > 0) {
		num *= fast(primes[cont++], x&7); ndiv *= (x&7)+1;
	}
	while(y > 0) {
		num *= fast(primes[cont++], x&7); ndiv *= (x&7)+1;
	}
	if( num > bound) return;
	if( nums[ndiv] > num ) nums[ndiv] = num;
	ull aux = x;
	fr(i,0,20){
		rec( 
	}
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	
	
	return 0;
}