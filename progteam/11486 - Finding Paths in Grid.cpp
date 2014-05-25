//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2481
//#tag matrix multiplication
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

ll mod = 1000000007;

struct mat{
	ll ** m;
	int s;
	mat( int _s = 1) {
		s = _s;
		m = new ll*[s];
		REP(i,0,s) m[i] = new ll[s];
		REP(i,0,s) REP(j,0,s) m[i][j] = 0;
	}
	mat operator * ( mat & in ) {
		mat ret( s);
		if( s != in.s ) return ret;
		REP(k,0,s){
			REP(i,0,s){
				if( m[i][k] == 0) continue;
				REP(j,0,s){
					ret.m[i][j] += (m[i][k] * in.m[k][j]) % mod;
					ret.m[i][j] %= mod;
				}
			}
		}
		return ret;
	}
};

mat power( mat a, ll b){
	mat x(a.s); mat y = a;
	REP(i,0,x.s) x.m[i][i] = 1;
	while( b){
		if( b & 1) x = x * y; //todo y * x?
		y = y * y; b /= 2;
	}
	return x;
}

int inverse(int x){
	int ret = 0;
	REP(i,0,7){
		if( x & (1<<i)) ret |= (1<<(6-i));
	}
	return ret;
}

void printb( int x){
	REP(i,0,7){
		if( x & 1) cerr << 1;
		else cerr << 0;
		x >>= 1;
	}
}


bool transition(int i, int j){
	int a =0, b =0;
	bool ok = true;
	while( a < 7 && b < 7){			
		while( a < 7 && (((1<<a) & i) == 0) ) a++;
		while( b < 7 && (((1<<b) & j) == 0) ) b++;
		if( a >= 7 && b >= 7) break;
		if( abs(a-b) == 1){
			a++, b++;
		} else if( a < 6 && b < 6 && a == b && ((1<<(a+1)) & i) && ((1<<(b+1)) & j) ){ 
			a+=2; b+=2;
		} else{ ok = false; break; }				
	}
	return ok;
}

int main(){
	int T; cin >> T;
	map<int,int> mf;
	map<int,int> mb;
	int cont = 0;
	REP(a,0,7) REP(b,a+1,7) REP(c,b+1,7) REP(d,c+1,7){
		int state = (1<<a) + (1<<b) + (1<<c) + (1<<d);
		mf[state] = cont;
		mb[cont++] = state;
	}
	// db( cont);
	mat m(cont);
	REP(i,0,cont){
		REP(j,0,cont){
			if( transition(mb[i],mb[j]) ){
				m.m[j][i] = 1;
			}
		}		
	}
	while(T--){
		ll n; cin >> n;
		int state = 0;
		REP(i,0,7){
			int a; scanf("%d", &a);
			if( a > 0) state |= (1<<i);
		}
		if( n == 1) {
			cout << "1" << endl; continue;
		}
		mat ret= m;
		ret = power( ret, n-1);
		int idx = mf[state];
		ll resp = 0;
		REP(i,0,cont) resp = (resp + ret.m[i][idx]) % mod;
		cout << resp << endl;	
	}
	return 0;
}