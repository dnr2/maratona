//http://acm.timus.ru/problem.aspx?space=1&num=1525

#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <map>
#include <list>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define MAXN 100
#define F first 
#define S second 
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;

const double PI = acos(-1.0);

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

char in[100010];
int dv[256];

int main() {
	ll n,m,k; cin >> n >> m>>k;
	scanf("%s", in); 
	pii mx = mp(0,0), my = mp(0,0), mz = mp(0,0); ll x=0, y=0, z= 0; 
	for(int i = 0; in[i]; i++){
		if( in[i] == 'u'){
			y += 1; my.F = max(my.F, y); 
		}
		if( in[i] == 'd'){
			y -= 1; my.S = min(my.S, y); 
		}
		if( in[i] == 'l'){
			x += 1; mx.F = max(mx.F, x);
		}
		if( in[i] == 'r'){
			x -= 1; mx.S = min(mx.S, x);
		}
		if( in[i] == 'f'){
			z += 1; mz.F = max(mz.F, z);
		}
		if( in[i] == 'b'){
			z -= 1; mz.S = min(mz.S, z);
		}
	}
	ll distx = mx.F - mx.S;
	ll disty = my.F - my.S;
	ll distz = mz.F - mz.S; ll um = 1;
	ll respx= max(um, n - distx);
	ll respy= max( um, m - disty);
	ll respz= max( um, k - distz);
	cout << (respx * respy * respz) << endl;
	return 0;
}