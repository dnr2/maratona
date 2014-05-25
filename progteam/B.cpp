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
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int maxn = 200;
int arr[maxn];
int main(){
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		map<int,int> mapa;
		REP(i,0,n){
			int a; cin >> a;
			mapa[a]++;
		}
		int sz = 0;
		for( map<int,int>::iterator it= mapa.begin(); it != mapa.end(); it++){
			arr[sz] = it->S;
			sz++;
		}
		sort( arr, arr + sz);
		int resp = unique( arr, arr+sz) - arr;
		cout << resp << endl;
	}
	return 0;
}