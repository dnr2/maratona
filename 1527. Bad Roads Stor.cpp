#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define add(a,b,c,t,h) ant[z] = adj[a], to[z] = b, cost[z] = c, time[z] = t, height[z] = h, adj[a] = z++
#define MAXN 110
#define MAXM 100100
int ant[MAXM], to[MAXM], cost[MAXM], time[MAXM], height[MAXM], adj[MAXM], z;
int C[MAXN][MAXN], back[MAXN][MAXN][3];

struct abc {
	int no, money, cost;
	abc() {}
	abc(int no, int money, int cost) : no(no), money(money), cost(cost) {}
	bool operator<(const abc &lhs) const {
		return cost > lhs.cost;
	}
} aux;

int n, m, s, t, money, maxtime, u, v, c, ti, h;
int maxc =0;

priority_queue<abc> fila;
bool teste(int k, bool fim = 0) {
	memset(C, 0x3f, sizeof C);
	C[s][0] = 0;
	back[s][0][0] = back[s][0][1] = back[s][0][2] = -1;
	while (!fila.empty()) fila.pop();
	fila.push(abc(s,0,0));
	while (!fila.empty()) {
		aux = fila.top(); fila.pop();
		maxc++;
		if (aux.no == t && aux.money <= money) {
			if (fim) {
				int n0 = aux.no, n1 = aux.money, _n0;
				stack<int> st;
				while (back[n0][n1][0] != -1) {
					st.push(back[n0][n1][0]);
					_n0 = back[n0][n1][1];
					n1 = back[n0][n1][2];
					n0 = _n0;
				}
				printf("%d\n", st.size());
				while (!st.empty()) printf("%d\n", st.top()), st.pop();
			}
			return aux.cost <= maxtime;
		}
		if (aux.money > n) continue;
		for (int i = adj[aux.no]; i != -1; i = ant[i]) {
			if (height[i] <= k && aux.cost+time[i] < C[to[i]][aux.money+cost[i]]) {
				C[to[i]][aux.money+cost[i]] = aux.cost+time[i];
				back[to[i]][aux.money+cost[i]][0] = i+1;
				back[to[i]][aux.money+cost[i]][1] = aux.no;
				back[to[i]][aux.money+cost[i]][2] = aux.money;
				fila.push(abc(to[i], aux.money+cost[i], aux.cost+time[i]));
			}
		}
	}
	return 0;
}

int main() {
	memset(adj,-1,sizeof adj); z = 0;

	scanf("%d%d%d%d", &n, &m, &s, &t);
	scanf("%d%d", &money, &maxtime);
	rp(i,m) {
		scanf("%d%d%d%d%d", &u, &v, &c, &ti, &h);
		add(u,v,c,ti,h);
	}
	int ini = 0, fim = 1000001, meio;
	while (ini < fim) {
		meio = (ini+fim)/2;
		if (teste(meio)) fim = meio;
		else ini = meio+1;
	}
	if (ini == 1000001) printf("-1\n");
	else {
		printf("%d\n", ini);
		teste(ini,1);
	}
	cout << "\n" << "maxc = " << maxc << endl;
	return 0;
}