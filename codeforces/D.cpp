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
#define PII pair<int,int>
#define PDD pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int MAXN = 100;

int arr[2][4];
int in[4];

ll  poww( ll a, ll b){
	ll ret = 1;
	REP(i,0,b) ret *= a;
	return ret;
}

int main(){
	while(cin >> in[0]){
		FILL(arr,0);		
		REP(i,1,4) cin >> in[i];
		REP(i,0,4){
			while ((in[i] & 1) == 0){
				arr[0][i]++;
				in[i] /= 2; 
			}
		}
		REP(i,0,4){
			while (in[i] % 3 == 0){
				arr[1][i]++;
				in[i] /= 3; 
			}
		}
		int resp = 0;
		REP(j,0,2){
			REP(i,0,2){
				int x = i * 2;
				int y = (1-i) * 2;
				int z = (j==0)? 1 : 0;
				while( arr[z][x] + arr[z][x+1] < arr[z][y] + arr[z][y+1] ){
					resp++;
					if( arr[z][y] > 0){
						arr[z][y]--; 
						if( z > 0) arr[z-1][y]++;
					} else {
						arr[z][y+1]--; 
						if( z > 0) arr[z-1][y+1]++;
					}
				}
			}
		}
		if( in[0] * in[1] != in[2] * in[3]) cout << (-1) << endl;
		else {
			cout << resp << endl;
			REP(i,0,4){
				ll num = (1LL << arr[0][i]) * poww(3,arr[1][i]) * in[i];
				if( i & 1 ) cout << " " << num << endl;
				else cout << num;
			}
		}
	}
	return 0;
}