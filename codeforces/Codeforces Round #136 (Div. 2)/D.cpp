#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

#define F first
#define S second

using namespace std;

map<int,int> val[500001];

void at( int p , int x, int r, int i, int j){
    if( i == j) val[r][x] = 1;
    else {
        int m = (i + j) /2;
        if( p <= m) at( p, x, 2 * r, i , m);
        else at(p, x, (2 * r)  + 1, m+1, j);
        val[r][x] += val[2 * r][x] + val[ (2*r)  +1][x];
    }
}

map<int,int> query( int ini, int fim, int n, int i, int j ){
	map<int,int> ret1, ret2;
    if( ini > j || fim < i) return ret1;
    if( ini <= i && j <= fim) return val[n];
    int m = (i+j) /2;
	ret1 = query( ini, fim, 2*n, i , m);
	ret2 = query(ini, fim , 2*n + 1, m +1 , j);
	for(map<int,int>::iterator it = ret1.begin(); it != ret1.end(); ++it){
		ret2[it->F] += it->S;
	}
    return  ret2;
}


int i,j,k,n,m, a, b;
int main(){
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);	
	for( i =1; i<=n;i++){
		scanf("%d", &a);
		// cout << a << endl;
		at(a, i, 1 ,1 , n<<2);
	}
	for( i = 1; i<=m;i++){
		scanf("%d%d", &a, &b);
		map<int,int> ret = query( a, b, 1, 1 , n << 2);
		int resp = 0;
		for(map<int,int>::iterator it = ret.begin(); it != ret.end(); ++it){
			printf("%d %d\n", it->F , it->S);
			if (it->F == it->S) resp++;
		}
		printf("%d\n", resp);
	}
	return 0;
}
