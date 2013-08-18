//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=861
//#tag geometry geometria
//#sol primeiro ordenar a entrada pelo x, depois ir varrendo os pontos e calcular as partes vermelhas

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
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

#define pdd pair<double,double>

// #define umap unordered_map

using namespace std;

pdd in[100000];

bool cmp(pdd x, pdd y ){
	return x.F > y.F;
}

int main(){
	
	int t; cin >> t;
	while(t--){
		int n ; cin >> n;		
		fr(i,0,n) scanf("%lf%lf", &in[i].F, &in[i].S);
		sort(in,in+n,cmp);
		double resp = 0;  int ant = 0;
		fr(i,1,n) {
			// db( in[i].F _ in[i].S);
			if( in[i].S > in[ant].S  ) {
				double dist = hypot( in[i].F - in[i-1].F, in[i].S - in[i-1].S);
				resp += dist * ( fabs( in[i].S - in[ant].S) / fabs( in[i].S - in[i-1].S));
				ant = i;
			}
		}
		printf("%.2lf\n", resp);
	}
	return 0;
}