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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}


int main(){
	
	int x, y; cin >> x >> y;
	int a, b ,c, d;
	if(x >0 && y > 0){
		a = 0; b = x + y;
		c = b; d = 0;
	} else if(x <0 && y > 0){
		a = x - y; b = 0;
		c = 0; d = -a;
	}  else if(x <0 && y < 0){
		a = x + y; b = 0;
		c = 0; d = a;
	} else {
		a = 0; b = y - x;
		c = -1 * b; d = 0;
	}
	printf("%d %d %d %d\n", a, b , c, d);
	return 0;
}