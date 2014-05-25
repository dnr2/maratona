//
//#tag dinic
//#tag maxflow 
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
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int maxflow() {
int inc, res = 0;
/* constroi lista de adjacencias */
memset(nadj, 0, sizeof(nadj));
memset(x, 0, sizeof(x));
memcpy(r, cap, sizeof(r));
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
if (cap[i][j] || cap[j][i]) adj[i][nadj[i]++] = j;
while ((inc = aumenta()) > 0)
res += inc;
return res;
}


/**** Exemplo simples de uso ****/
int main() {
int i, j;
int u, v, c;
for (;;) {
scanf("%d", &n);
if (!n) break;
memset(cap, 0, sizeof(cap));
scanf("%d%d%d", &s, &t, &m); s--; t--;
for (i = 0; i < m; i++) {
scanf("%d%d%d", &u, &v, &c); u--; v--;
cap[u][v] += c;
cap[v][u] += c;
}
printf("Fluxo maximo %d.\n\n", maxflow());
printf("Fluxo:\n");
for (i = 0; i < n; i++)
for (j = 0; j < nadj[i]; j++)
if (x[i][adj[i][j]] > 0)
printf("(%d %d) %d\n", i, adj[i][j], x[i][adj[i][j]]);
printf("Arestas do corte:\n");
mincut(); /* ver mincut() no algoritmo de preflow */
printf("\n");
}
return 0;
}