//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3483
//#tag geometry geometria
//#sol calcular o angulo entre os prédios para ver o tempo inicial e final que ele recebe sol
//cuidado com precisão


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

struct st{
	int m;
	int ini, fim;
	st(int m = 0, double ini = 0, double fim = 0): m(m), ini(ini), fim(fim) {};
};

st in[110];

int main(){
	int n, caso = 1;
	while(scanf("%d", &n) > 0 && n) {
		printf("Apartment Complex: %d\n\n", caso++);
		int w, h;
		scanf("%d%d", &w, &h);
		int a; int b;
		scanf("%d", &b);  
		in[0].m = b; in[0].ini = 0; in[0].fim = w;
		fr(i,1,n) { 
			scanf("%d%d", &a, &b); in[i].m = b; 
			in[i].ini = in[i-1].fim + a; 
			in[i].fim = in[i].ini + w;
		}
		int temp;
		while( scanf("%d", &temp ) > 0 && temp ){
			// testar caso d(i) = 0
			int build = temp % 100, ap= temp/100;			
			if( build < 1 || build > n || ap < 1 || ap > in[build-1].m ) { printf("Apartment %d: Does not exist\n\n", temp); continue; }
			ap--; build--; // zero based
			double la = PI, ra = 0, t;
			fr(i,build+1,n){
				if( (in[i].m - ap ) <= 0) continue;
				t = atan2( h * (in[i].m - ap ), in[i].ini - in[build].fim );
				ra = max( ra , t );
			}
			for(int i = build-1; i >=0; i--){
				if( in[i].m - ap <= 0 ) continue;
				t = atan2( h * ( in[i].m - ap) , in[i].fim - in[build].ini);
				la = min( la, t); 
			}
			la = PI -la; ra = PI - ra; 
			double hi = (5 * 60 * 60) + (37 * 60), hf =  (18 * 60 * 60) + (17  * 60); 
			la = hi + ((hf - hi) * la / PI); ra = hi + ((hf - hi) * ra / PI);
			int lh = (int) (la+EPS), rh = (int) (ra+EPS);
			printf("Apartment %d%02d: %02d:%02d:%02d - %02d:%02d:%02d\n\n", 
				(ap+1), (build+1), lh/(60*60), (lh/(60))%60 , (lh)%60, 
					rh/(60*60), (rh/(60))%60 , (rh)%60 );
		}
	}
	return 0;
}
