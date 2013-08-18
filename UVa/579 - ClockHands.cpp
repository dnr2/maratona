//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=101&page=show_problem&problem=520
//#tag math matematica
//#tag geometry geometria
//#tag angulo angle

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
	double n,m,resp, aux;
	pair<double,double> a, b;
	while( scanf("%lf:%lf",&n,&m)>0 && (n != 0.0 || m != 0.0)){
		b.F = cos( PI/2 - (2*PI)*m/60);
		b.S = sin( PI/2 - (2*PI)*m/60);
		a.F = cos( PI/2 - (2*PI)*n/12 - (2*PI*m)/(60*12) );
		a.S = sin( PI/2 - (2*PI)*n/12 - (2*PI*m)/(60*12) );
		aux = a.F * b.F +  a.S * b.S;
		// printf("%lf %lf %lf %lf\n", a.F , a.S, b.F, b.S);
		resp = 360 / (2 *PI) *  acos(aux /( sqrt(pow(a.F,2) + pow(a.S,2)) * sqrt(pow(b.F,2) + pow(b.S,2)) )) ;
		printf("%.3lf\n" , resp);
	}
	return 0;
}