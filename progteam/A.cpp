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
#include <set>

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(ull (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

ull prim[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179};
ull arr[25];
ull fat[100], fatsz = 21;
map<ull,ull> mapa;
ull maxval = 1;

bool check(ull a, ull b){	
	return maxval / b <= a;
}

ull fn(int pos){
	ull div = 1, sum = 0;
	REP(i,0,pos+1){
		sum += arr[i];
		div *= fat[arr[i]];
	}
	if( sum >= fatsz) return 0;
	if( fat[sum] / div >= maxval) return 0;
	return fat[sum] / div;
}

void rec(ull num, ull pos){
	REP(i,1,65){
		if( pos > 0 && i > arr[pos-1] ) continue;		
		if( !check( num, prim[pos] )){
			num *= prim[pos];
			ull key = fn(pos);		
			if( key == 0 ) break;
			arr[pos] = i;
			db( key _ num );
			REP(j,0,pos+1) cerr << arr[j] << " ";
			cerr << endl;
			if( mapa[key] == 0) mapa[key] = num;
			else mapa[key] = min( mapa[key], num);
			rec( num, pos + 1);
		}
	}
}

int main(){
	maxval = maxval << 63;
	db( maxval );
	fat[0] = 1;
	fat[1] = 1;	
	REP(i,2,21){
		fat[i] = fat[i-1] * ((ull) i);
	}
	arr[0] = 1;
	rec(1, 0);
	for(map<ull,ull>::iterator it =mapa.begin(); it != mapa.end(); it++){
		cout << it->F << " " << it->S << endl;
	}
	return 0;
}