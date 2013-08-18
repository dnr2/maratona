#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

struct pt{
	int d, w, e, s;
	pt( int d = 0, int w = 0, int e = 0, int s = 0) : d(d) , w(w), e(e), s(s) {}
	const bool operator < ( const pt & in ) const {
		return d < in.d;
	}
};

#define maxn 1000100

int mur[maxn];
int aux[maxn];
int off = maxn/2;

pt att[1100];

int main(){
	
	int ca; int caso =1;
	scanf("%d",&ca);
	while( ca--){
		int N, d,n,w,e,s,dd,dp,ds;
		cl(mur);
		cl(aux);
		scanf("%d", &N);
		int cont= 0;
		fr(i,0,N){
			scanf("%d%d%d%d%d%d%d%d", &d,&n,&w,&e,&s,&dd,&dp,&ds);			
			fr(j,0,n){
				att[cont++] = pt(d+j*dd, w + j*dp, e + j *dp, s + j * ds);
			}
		}
		int resp =0;
		sort(att, att+cont);
		fr(i,0,cont){
			fr(j,0,maxn) aux[j] = mur[j];
			int dia = att[i].d;
			while(att[i].d == dia){
				bool done = false;
				fr(k,att[i].w + off , att[i].e + off + 1){
					if( att[k].s > mur[k]){
						aux[k] = att[k].s; done = true;
					}
				}
				if(done) resp++;
				i++;
			}
			i--;
			fr(j,0,maxn) mur[j] = aux[j];
		}
		printf("Case #%d: %d", caso++ , resp );
	}
	return 0;
}
