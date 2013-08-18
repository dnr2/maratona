//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1832

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;


int i,j,k,n,m,a,b,c;

struct mai{
	int num, p;
	mai(int x, int y) : num(x), p(y) {};
	
	bool operator < (const mai & n) const{
		return p < n.p;
	}
};

struct men{
	int num, p;
	men(int x, int y) : num(x), p(y) {};
	bool operator < (const men & n) const{
		return p >= n.p;
	}
};

int mark[1000010];

priority_queue<mai> qmax;
priority_queue<men> qmin;

int main(){	

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	memset(mark , -1 ,sizeof(mark));
	
	while(scanf("%d", &n) > 0 && n !=0){
		
		if( n == 1){
			scanf("%d%d",&a, &b);
			qmax.push(mai(a,b));
			qmin.push(men(a,b));
			mark[a] = b;
		} 
		if( n == 2){
			while( !qmax.empty() && mark[qmax.top().num] != qmax.top().p){
				qmax.pop();
			}
			if( qmax.empty()){
				puts("0");
			} else {
				printf("%d", qmax.top().num);
				puts("");
				mark[qmax.top().num] = -1;
				qmax.pop();
			}
		} 
		if( n == 3){
			while( !qmin.empty() && mark[qmin.top().num] != qmin.top().p){
				qmin.pop();
			}
			if( qmin.empty()){
				puts("0");
			} else {
				printf("%d", qmin.top().num);
				puts("");
				mark[qmin.top().num] = -1;
				qmin.pop();
			}
		} 
		
	}	
	
	return 0;
}

