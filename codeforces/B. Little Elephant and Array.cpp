//http://codeforces.com/contest/221/problem/D
//#tag data structure
//#tag seg tree
//#sol a solução em n * log(n) se da usando a seg tree. Para isso devemos criar um array A tal que 
// A(j) + A(j+1) + .. + A(k-1) + A(k) seja a resposta para a query de j até k. montamos esse array 
// de forma "online". vamos interando x de 0 até n-1 (0 based array) e pegamos todas as queries que 
// terminam em x. Antes de executar as queries, atualizamos A, considerando o elemento do array de 
// entrada (in) na posição x: E. Sela L a lista de ocorrencias anterioes de E no array in verificamos
// se o tamalho dessa lista é maior uque E. caso positivo A( L(L.size() - E)) é incrementado em 1
// (ver código para os demais ifs)


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>

#define MAX 101000
#define MAXST 401000
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

struct query{
	int a,b,pos;
	query(int a =0,int b=0,int pos=0) : a(a), b(b), pos(pos) {}
};

int in[MAX];
query q[MAX];
vector<int> lista[MAX];
int pd[MAX * 10];
int resp[MAX];

bool cmp(query x, query y){
	if( x.b == y.b ) return x.a < y.a;
	return x.b < y.b;
}

void add(int val, int pos, int x, int y, int r){
	if( x == y) pd[r] += val;
	else {
		int m = (x+y)/2;
		if( pos <= m) add(val, pos, x, m, 2*r);
		else add(val, pos, m+1, y, (2*r)+1);		
		pd[r] = pd[2*r] + pd[(2*r)+1];
	}
}

int sum(int ini, int fim, int x, int y, int r){
	if( ini > y || fim < x ) return 0;
	if( ini <= x && y <= fim) return pd[r];
	int m = ( x + y) /2;
	return sum( ini,fim, x ,m,2 *r) + sum( ini,fim, m + 1,y, 2*r+1);
}


int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d%d", &n,&m);
	for( int i=0;i <n;i++){
		scanf("%d", &in[i]);
	}
	for( int i=0;i<m;i++){
		scanf("%d%d", &q[i].a, &q[i].b);
		q[i].pos = i;
	}
	sort(q,q+m,cmp);
	int cur =0;
	for( int i=0;i<n;i++){
		if( in[i] > 100000 ) continue;
		lista[in[i]].push_back(i);
		if( lista[in[i]].size() >= in[i])
			add( 1, (lista[in[i]][ lista[in[i]].size() - in[i]  ] + 1), 1, MAXST, 1);
		if( lista[in[i]].size() > in[i])  
			add(-2, lista[in[i]][ lista[in[i]].size() - in[i]-1] + 1, 1, MAXST, 1);
		if( lista[in[i]].size() > in[i]+1) 
			add( 1, lista[in[i]][ lista[in[i]].size() - in[i]-2] + 1, 1, MAXST, 1);
		while( q[cur].b == i + 1){
			resp[q[cur].pos] = sum( q[cur].a, q[cur].b, 1, MAXST, 1);			
			// cout << q[cur].pos << " " << resp[q[cur].pos] << endl;
			cur++;
		}
		if( cur == m) break;
	}
	for( int i =0;i<m;i++){
		printf("%d\n", resp[i]);
	}
	return 0;
}
