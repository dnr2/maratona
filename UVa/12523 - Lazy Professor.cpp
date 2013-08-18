//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3968
//#tag simulação 
//#tag ad hoc

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
 
//#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define ms(ar,a) memset(ar, a, sizeof(ar))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define ler(a) scanf("%d", &a)
#define ler2(a,b) scanf("%d%d", &a, &b)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define F first
#define S second
#define pdd pair<double,double>
#define pdi pair<double,int>
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100

pii in[101];
pii r[101];

bool cmp(pii x, pii y){
	return x.F > y.F;
}

int main() {
	//cin.sync_with_stdio(false);
	int s, n;
	int sum , aux, resp;
	while(scanf("%d%d",&s,&n) >0 && (s||n)){
		sum = 0;
		fr(i,0,101){
			in[i].F = r[i].F = r[i].S = 0;
			in[i].S = i;
		}
		fr(i,0,s){
			fr(j,0,n){
				scanf("%d", &aux);
				in[j].F += aux;
			}
		}
		//fr(i,0,n) in[i].F /= ((double) s);
		resp = 0;
		fr(i,0,n){
			scanf("%d%d", &r[i].F, &r[i].S);
			r[i].S -= r[i].F;
			resp +=  in[i].F * (r[i].F );
			sum += r[i].F;
		}
		sort(in,in+n,cmp);
		// fr(i,0,n) cout << in[i].F << " " << in[i].S << endl;
		fr(i,0,n){
			if( sum + r[in[i].S].S < 100){
				resp += (in[i].F * r[in[i].S].S );
				sum +=  r[in[i].S].S;
			} else {
				resp += (100 - sum) * in[i].F;
				break;
			}
		}
		printf("%.2lf\n", (((double) resp) / ((double) (s * 100)) + 0.0000001) );
		// printf("%.2lf\n", ret );
		
	}
	return 0;
}
