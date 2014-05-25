//http://poj.org/problem?id=3756
//#tag
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
#include <set>

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

const int maxn = 111; 
double prob[3][maxn];
pii stat[maxn];
int N;

int walk(int a, int b){	
	while( b != 0){
		if( a == 0) b = abs(b);
		if( a == N-1) b = -abs(b);
		if( b > 0){ a++; b--; }
		else{ a--; b++; }
	}	
	return a;
}


int main(){
	while(scanf("%d", &N) > 0){
		REP(j,0,maxn){
			stat[j] = mp(0,0);
			REP(i,0,3) prob[i][j] = 0; 
		}
		N++;
		int Nf; scanf("%d", &Nf);
		REP(i,0,Nf){
			int a,b; scanf("%d%d", &a, &b);
			stat[a] = mp( 1, b);
		}
		int Nb; scanf("%d", &Nb);
		REP(i,0,Nb){
			int a,b; scanf("%d%d", &a, &b);
			stat[a] = mp( 2, -b);
		}
		int Ns; scanf("%d", &Ns);
		REP(i,0,Ns){
			int a; scanf("%d", &a);
			stat[a] = mp( 3, 0);
		}	
		double resp = 0;
		prob[0][0] = 1.0;
		REP(i,0,1000){
			resp += prob[i%3][N-1] * i;
			REP(j,0,N) prob[(i+2)%3][j] = 0;
			REP(j,0,N-1){
				REP(k,1,7){
					if( fabs(prob[i%3][j]) < EPS) continue;
					int aux = walk( j, k);
					if( stat[aux].F == 3){
						prob[(i+2)%3][aux] += prob[i%3][j] / 6.0;
						continue;
					}		
					aux = walk(aux, stat[aux].S);
					prob[(i+1)%3][aux] += prob[i%3][j] / 6.0;
				}
			}		
		}
		if( fabs( resp ) < EPS) puts("Impossible");
		else printf("%.2lf\n", resp );
	}
	return 0;
}