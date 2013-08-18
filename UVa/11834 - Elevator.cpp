//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2934
//#tag math matematica
//#tag geometry geometria

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

#define FOR(i,j,k) for(int (i)=(j);(i) <(k);++(i))
#define MAXN 101000
#define ll long long
#define MAP map<int,int>
#define pii pair<int,int>
#define F first
#define S second
#define PI acos(-1)
#define db(x) cout << x << endl;

using namespace std;

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	double n,m,resp, aux,a,b,c,d,e;
	while(scanf("%lf%lf%lf%lf", &n,&m,&a,&b)>0 && (n > 0.0 || m > 0.0 || a > 0.0 || b > 0.0)){
		if( min(n,m) < 2*a || min(n,m) < 2*b ){ 
			puts("N"); continue;
		}
		n -= (a+b); m -= (a+b);
		if( n < 0 || m < 0 ) puts("N");
		else if( sqrt(pow(n,2) + pow(m,2)) >= a + b) puts("S");
		else puts("N");		
	}
	
	return 0;
}