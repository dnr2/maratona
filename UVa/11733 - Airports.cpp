//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct edge{
	int e1, e2, peso;
};

bool cmp(edge e1, edge e2){
	return e1.peso < e2.peso;
}

int i , j , k , n , m , a, b, c, d;

vector<edge> g;
int pai[10100];

int findPai(int x){
	if( pai[x] == x ) return x;
	return pai[x] = findPai(pai[x]);
}

int add(int x, int y){
	pai[findPai(y)] = findPai(x);
}


int main(){	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t = 1, caso;
	cin >> caso;
	while(caso--){
		
		scanf("%d%d%d", &n, &m, &a);
		for( i = 0 ; i <= n ; i++) {
			pai[i] = i;		
		}
		g.clear();
		
		for( i = 0 ; i < m ; i++){
			scanf("%d%d%d", &b, &c, &d);
			edge e; 
			e.e1 = b;
			e.e2 = c;
			e.peso =  d;
			if( d < a) g.push_back(e);
		}
		sort( g.begin(), g.end(), cmp);
		vector<edge>::iterator it;
		
		int menor = n * a;
		int resp = n;
		for( it = g.begin(); it < g.end(); it++){
			// cout << it->e1 << "->" << it->e2 << " " << it->peso << endl;
			if( findPai(it->e1) != findPai(it->e2) ){
				add(it->e1 , it->e2);
				menor = menor - a + it->peso;
				resp--;
			}
		}
		printf("Case #%d: %d %d\n", t++, menor, resp);
	}
	
    return 0;
}

