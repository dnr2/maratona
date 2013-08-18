//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1636
//#tag: Binary search
//#tip: pi = cos(-1) /* use isso sempre! */
//#tip: essa busca deve ser feita com double e não com long long ( bichado )

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

#define DIF 1e-6

using namespace std;

int i,j,k,n,m,c,d,caso,t,num;
double in[100100];
double aux[100100];

bool check(double x){
	for(i=0;i<n;i++) aux[i] = in[i];
	int cont = 0;
	for(i=0;i<n;i++) {
		while( aux[i] >= x) {
			aux[i] -= x;
			cont++;
		}
	}
	return cont >= m;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	cin>>t;
	double pi = acos(-1);	
	while(t--){
		scanf("%d%d", &n, &m);
		m++;
		double mai = 0.0;
		for(i=0;i<n;i++){
			scanf("%lf", &in[i]);
			in[i] = in[i] * in[i] * pi;
			if( mai < in[i]) mai = in[i];
		}
		double s=0.0, e = mai, mid = e/2.0;		
		while( e - s > DIF ){			
			mid = (e+s)/2.0;
			if( check(mid) ) {
				s = mid;
			} else {
				e = mid;
			}
		}		
		printf("%.4lf\n", s);
	}
	return 0;
}

