//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2678
//#tag mst agpm arvore geradore de peso minimo
//#tag graph grafos
//#sol usar alguma algorimto para resolver o problema de agpc, não esquecer que o desejado eh
//o custo a ser salvo, não o custo mínimo

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

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))


using namespace std;
struct edge{
	int x, y,z;
	edge(int x = 0, int y = 0, int z =0) : x(x), y(y), z(z) {}
};

edge arr[200010];
int p[200010];

int find(int x){
	if( p[x] == x) return x;
	return p[x] = find(p[x]);
}

int unir(int x, int y){
	int z = find(x), w = find(y);
	p[w] = z;
}

bool cmp(edge x, edge y){
	return x.z < y.z;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n , m, aux, resp;
	int a, b , c;
	
	while(scanf("%d%d", &m,&n) > 0 && (n || m)){
		fr(i,0,m) p[i] = i;
		int total = 0;
		fr(i,0,n){
			scanf("%d%d%d", &a,&b,&c);
			total += c;
			edge e(a,b,c);
			arr[i] = e;
		}
		sort( arr, arr+n, cmp);
		resp = 0;
		fr(i,0,n){
			if( find(arr[i].x) != find(arr[i].y)){
				resp += arr[i].z; 
				unir( arr[i].x ,arr[i].y);
			}
		}
		printf("%d\n" , total - resp);
	}
	
	return 0;
}
