//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
//#tag segment tree seg tree arvore de segmentos 
//#tag lazy propagation
//#sol use seg tree with lazy propagation, there are potentially too many parates, but a few queries, use
//coordinate compression to reduce the number of nodes in the tree

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

#define DOTS 30000
#define MAXM 310

int NSEG; // Number of fields (with indices $0,\dots,NSEG-1$)
int sum[DOTS];
int off[DOTS]; 

char str[MAXM][300];
char straux[300];
int rep[MAXM];

int que[3100][3];
int cords[DOTS];
map<int,int> trans;
map<int,int> untrans;

int apply( int i, int s, int e){ //new value considering the op
	if( off[i] == 1) return untrans[e]-untrans[s];
	if( off[i] == 2) return 0;
	if( off[i] == 3) return (untrans[e]-untrans[s])-sum[i];
	else return sum[i];
}

int join(int i, int j){
	if( i == 0) return j;
	if( i == 3) {
		if( j == 0) return 3;
		if( j == 1) return 2;
		if( j == 2) return 1;		
		if( j == 3) return 0;
	}
	return i;
}

void relax(int i, int s, int e) {	
	sum[i] = apply(i,s,e);
	off[2*i+1] = join( off[i], off[2*i+1] );
	off[2*i+2] = join( off[i], off[2*i+2] );
	off[i] = 0;
}

void modify(int a, int b, int op, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a)
		return;
	if (a <= s && e <= b){
		off[i] = join(op , off[i]);
		return;
	}
	relax(i, s, e);
	modify(a, b, op, 2*i+1, s, (s+e)/2);
	modify(a, b, op, 2*i+2, (s+e)/2, e);
	sum[i] = 
		apply(2*i+1 , s, (s+e)/2)+ 
		apply(2*i+2 , (s+e)/2, e);
}

void sett(int a, int b, int val, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a)
		return;
	if (a <= s && e <= b){
		sum[i] = val;		
		return;
	}	
	sett(a, b, val, 2*i+1, s, (s+e)/2);
	sett(a, b, val, 2*i+2, (s+e)/2, e);
	
	sum[i] = sum[2*i+1] + sum[2*i+2];	
}

int query(int a, int b, int i=0, int s=0, int e=NSEG) {
	if (b <= s || e <= a)
		return 0;
	if (a <= s && e <= b){
		return apply( i, s, e);		
	}
	relax(i, s, e);
	return 
		query(a, b, 2*i+1, s, (s+e)/2) +
		query(a, b, 2*i+2, (s+e)/2, e);
}

int main(){
	
	int T; cin >> T;
	REP(cn,1,T+1){		
		trans.clear(); untrans.clear();
		memset(cords,0,sizeof(cords));
		int M; scanf("%d", &M);		
		REP(i,0,M){
			scanf("%d%s", rep+i, str[i] );			
		}
		int Q = 0; scanf("%d", &Q);
		int sz = 0;
		cords[sz++] = 0;
		REP(i,0,Q){
			int a, b;
			scanf("%s%d%d", straux, &a, &b );
			que[i][0] = (straux[0] == 'F')? 1 : (straux[0] == 'E')? 2 : (straux[0] == 'I')? 3 : 0;
			que[i][1] = a;
			que[i][2] = b;
			cords[sz++] = a;
			cords[sz++] = b+1;			
		}
		sort( cords, cords + sz);
		sz = unique( cords, cords + sz) - cords;
		REP(i,0,sz){
			trans[cords[i]] = i;
			untrans[i] = cords[i];			
		}
		NSEG = sz;
		REP(i,0,NSEG*4){
			sum[i] = off[i] = 0;
		}
		sz = 0; int p = 1, cont = 0 ;
		REP(i,0,M){
			REP(r,0,rep[i]){
				int len = strlen( str[i] );
				REP(j,0,len){
					if( str[i][j] == '1') cont++;
					sz++;					
					if( cords[p] <= sz ){
						sett( p-1, p, cont);						
						cont = 0;
						p++;
					}
				}
			}
		}
		
		printf("Case %d:\n", cn);
		int qcount = 1;
		REP(i,0,Q){
			if( que[i][0] > 0 ){
				modify( trans[que[i][1]] , trans[que[i][2]+1], que[i][0]);						
			}
			if( que[i][0] == 0){ 
				printf("Q%d: %d\n", qcount++, 
					query(trans[que[i][1]], trans[que[i][2]+1] ));							
			}
		}
	}	
	return 0;
}