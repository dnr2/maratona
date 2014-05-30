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
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int main(){
	int i;
	while(scanf("%d", &i) > 0){
		if( i < 0) break;
		int sol = 0;
		REP(j,2,20){
			if( j >= i ) break;
			int tmp = i;
			REP(k,0,j){
				tmp -= 1;
				if( tmp < 0){
					tmp = 1; break;
				}
				if( tmp % j == 0){
					tmp /= j;
					tmp *= j-1;
				} else {
					tmp = 1; break;
				}
			}
			if( tmp % j == 0){
				sol = j;
			}
		}
		
		if( sol ) printf("%d coconuts, %d people and 1 monkey\n", i, sol);
		else printf("%d coconuts, no solution\n", i);
		
	}
	return 0;
}