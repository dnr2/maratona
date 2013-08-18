//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1834

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>


using namespace std;

struct par{
	int d, p;
	par ( int x = 0,  int y = 0) : d(x) , p(y) {};
	bool operator < ( const par & a) const{
		return p < a.p; 
	}
};

int i, j , k, n , m, l, a,b;
int in[100100];
priority_queue<par> heap;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%d%d", &n , &l) > 0){
		memset( in, 0, sizeof( in));
		int maior = 0;
		long long resp = 0;
		for( i =0; i< n;i++){
			scanf("%d%d", &a , &b);
			par x(b,a);
			heap.push(x);			
		}
		while( !heap.empty()){
			par x = heap.top();
			for( i = x.d; i >=0 ;i--){
				if( in[i] < l){
					in[i]++;
					resp += x.p;
					break;
				}
			}
			heap.pop();
		}
		printf("%lld", resp ); puts("");
	}
	return 0;
	
}
