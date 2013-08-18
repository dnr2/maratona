//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3909
//#tag math matematica
//#sol considerar que a==b(mod m) é o mesmo que a-b==0(mod m), ou seja, m divide (a-b)
//desta forma basta pegarmos o número de divisores de (a-b)

#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>
 
#include <iostream>
#include<algorithm>
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
 
#define MAXN 100
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
 
int main() {
	//cin.sync_with_stdio(false);
	/* int T; scanf("%d", &T); while(T--) { } */
	int a, b,c ,aux, root;
	while(scanf("%d%d", &a,&b) != EOF && (a || b)) { 
		c = abs( a-b);
		aux = 0;
		for(int i=1;i*i <= c;i++){
			if( c % i == 0 && i*i == c) aux+=1;
			else if( c % i == 0)  aux += 2;
		}
		cout << aux << endl;
	}
	return 0;
}