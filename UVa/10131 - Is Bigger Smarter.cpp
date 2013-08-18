//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1072

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;

struct no{
	int w, i, n;
	no( int w=0, int i=0, int n=0) : w(w) , i(i), n(n) {}
	bool operator < (const no & a) const{
		if(a.w != w) return a.w < w;
		return a.i < i;
	}
};

int i,j,k,n,m,a,b,c,d;
no in[10010];
int indices[10010];
int pd[10010];
int g[10010];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	a = 0;
	while(scanf("%d %d", &n, &m) > 0){
		in[a++] = no(n,m,a+1);
	}
	stable_sort(in, in+a);
	// for(i=0;i<a;i++){	
		// printf("%d -> %d %d n: %d\n", i ,in[i].w, in[i].i, in[i].n);
	// }
	// cout <<endl;
	
	b = 1;
	pd[0] = in[0].i;
	indices[0] = 0;
	g[0] = 0;
	for(i=1;i<a;i++){	
		if(pd[b-1] < in[i].i){
			indices[b] = i;
			g[i] = indices[b-1];
			pd[b++] = in[i].i;
		} else {
			for(j=0;j<b;j++){
				if(pd[j] >= in[i].i) break;
			}
			pd[j] = in[i].i;
			indices[j] = i;
			if(j > 0) g[i] = indices[j-1];
			else g[i] = i;
		}
		// for(j=0;j<b;j++){
			// cout << pd[j] << " ";
		// }
		// cout << endl;
		// for(j=0;j<b;j++){
			// cout << indices[j] << " ";
		// }
		// cout << endl;
		// for(j=0;j<=i;j++){
			// cout << g[j] << " ";
		// }
		// cout << endl << endl;
	}
	c = indices[b-1];
	// cout << "c: " << c << " b-1 :" << (b-1) << endl;
	d = 1;
	// stack<int> s;
	// s.push(c);
	printf("%d\n", b);
	printf("%d\n", in[c].n);
	while(g[c] != c){
		// s.push(in[g[c]].n);
		// s.push(g[c]);
		printf("%d\n", in[g[c]].n);
		c = g[c];
		// d++;
	}
	// cout <<  "d = " << d << endl;
	// for(i=0;i<d;i++){
		// printf("%d\n", s.top());
		// s.pop();
	// }
	return 0;
	
}
