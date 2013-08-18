//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3877
//#tag pd dinamic programming

#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>
 
#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
 
//#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define ms(ar,a) memset(ar, a, sizeof(ar))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

ll arr[1001011];
ll mod = 1000000007;
int main() {
	//cin.sync_with_stdio(false);
	ll a, b ,c,d,e=0,f=0,  x=2,y=5,z=4;
	ms(arr,0);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 9;
	arr[3] = 32;
	c = 4;
	fr(i,4,1000011) {
		a = ((arr[i-1] * x)%mod);
		b = ((arr[i-2] * y)%mod);
		c += ((arr[i-3] * z)%mod);
		arr[i] = (a + b + c ) % mod;
		arr[i] =  arr[i]%=mod;
	}
	int t; cin >> t;
	ll in;
	while(t--){
		scanf("%lld", &in);
		cout << arr[in] << endl;
	}
	
	return 0;
}
