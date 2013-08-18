//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3772

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
#define ler(a) scanf("%d", &a)
#define ler2(a,b) scanf("%d%d", &a, &b)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

int main() {
	//cin.sync_with_stdio(false);
	long long t, a, b, c;
	long long faca, mao;
	cin >> t;
	int caso = 1;
	while(t--){
		cin >> a >> b >> c;
		faca = (a-1)+(b-1)+(c-1);
		mao = (a-1) + a*(b-1 +b*(c-1));
		faca = (int)(ceil(log2(a)) + ceil(log2(b)) + ceil(log2(c)));
		
		// r = log2(a);
		cout << "Case #" << caso++ << ": " << mao << " " << faca << endl;
	}
	
	return 0;
}
