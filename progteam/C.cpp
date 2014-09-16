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

const int MAXN = 110;

int in[MAXN][2];
int sz = 0;

string bits(int mask){
	string str = "";
	while( mask > 0){
		if( mask & 1) str.PB('1');
		else str.PB('0');
		mask >>= 1;
	}
	return str;
}

int main(){
	int n; 
	map<char,int> f; f['R'] = 0; f['G'] = 1; f['B'] = 2; f['Y'] = 3; f['W'] = 4;
	while(cin >> n){
		set<PII> s;
		string str;
		REP(i,0,n){
			cin >> str;
			s.insert( PII( f[str[0]], str[1]-'1'));		
		}
		sz = 0;
		for(PII p : s){
			in[sz][0] = p.F;
			in[sz++][1] = p.S;
		}
		int resp = INF;
		REP(mask,0,1<<10){
			vector<int> v;
			v.PB((1<<sz)-1);
			int cont = 0;
			REP(i,0,10) if( mask & (1<<i)) cont++;
			if( cont > resp) continue;
			REP(i,0,10){
				if( mask & (1<<i)){
					int len = v.size();
					REP(j,0,len){
						int m1 = 0, m2 = 0;
						REP(k,0,sz){
							if( ( v[j] & (1<<k)) ){
								if( in[k][(i<5)?0:1] == i%5 ){
									m1 |= 1 << k;
								} else {
									m2 |= 1 << k;
								}
							}				
						}
						if( m1 == 0 || m2 == 0) continue;
						v[j] = m1;
						v.PB(m2);
					}
				}
			}
			if( (int)v.size() == sz && cont < resp ) resp = cont;
		}
		cout << resp << endl;
	}
	return 0;
}