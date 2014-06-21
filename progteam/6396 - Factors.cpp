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

ull primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179};
ull arr[20];
ull fat[100], fatsz;
map<ull,ull> mapa;
ull maxval = 1;

bool check(ull a, ull b){
	return maxval / b <= a;
}

void rec(ull num, ull sum, ull sz){		
	db( num );
	ull fnum = 1;
	// if( sum >= fatsz) return; //TODO can be bigger!! D=
	fnum = fat[sum];	
	db( fnum );
	REP(i,0,sz){
		fnum /= fat[arr[i]];
	}
	if( check(fnum, 1) ) return; //TODO
	if( mapa[fnum] == 0 ) mapa[fnum] = num;
	else mapa[fnum] = min(mapa[fnum],num);
	db( fnum _ mapa[fnum] _ num _ sz _ sum);
	REP(i,0,sz) cerr << arr[i] << " ";
	cerr << endl;
	
	REP(i,0,sz){
		if( i > 0 && arr[i] >= arr[i-1]) continue;		
		ull aux = num, nsum = sum;
		if( !check( aux, primes[i] )){
			aux *= primes[i];
			arr[i]++; nsum++;
			rec( aux, nsum, sz );
			arr[i]--;
		}
	}	
	if( !check( num, primes[sz])){
		num *= primes[sz];
		arr[sz]++;
		rec( num, sum+1, sz+1);
		arr[sz]--;
	}
}

int main(){
	maxval = maxval << 7;
	fat[0] = 1;
	fat[1] = 1;
	fatsz = 2;
	REP(i,2,20){		
		fat[fatsz] = fat[fatsz-1] * fatsz;		
		fatsz++;
	}
	arr[0] = 1;
	rec(2, 1, 1);
	for(map<ull,ull>::iterator it =mapa.begin(); it != mapa.end(); it++){
		cout << it->F << " " << it->S << endl;
	}
	return 0;
}