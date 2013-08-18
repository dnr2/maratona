//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3961
//#tag ad hoc
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

int r, c, p, z;
bool mark[280][1050];
vector<int> adj[30];

bool can(int x) {
	fr(i,0,adj[x].size()) {
		if (!mark[x][adj[x][i]-1]) mark[x][adj[x][i]-1] = true;
		else if (!mark[x][adj[x][i]]) mark[x][adj[x][i]] = true;
		else return false;
	}
	return true;
}

int main() {
	while(scanf("%d%d\n", &r, &c) != EOF && (r||c)) {
		scanf("%d\n", &p);
		char t1[100],t2[100], t;
		int tmp;
		fr(i,0,p) {
			scanf("%c%d%s\n", &t, &tmp, t2);
			if (t2[0] == '-') mark[(t-'A')][(tmp)-1] = true;
			else mark[(t-'A')][(tmp)] = true;
		}
		
		scanf("%d\n", &z);
		fr(i,0,z) scanf("%c%d\n", &t, &tmp), adj[t-'A'].pb(tmp);
		
		fr(i,0,30) {
			sort(adj[i].begin(), adj[i].end());
			if (!can(i)) {
				puts("NO");
				goto end;
			}
		}
		puts("YES");
		end: ;
		ms(mark,0);
		fr(i,0,30) adj[i].clear();
	}
	return 0;
}
