#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define pair<int,int> pii
#define FOR(i,j,k) for(int (i) =(j);(i)<(k);++(i))
#define EPS 1e-9

using namespace std;

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int m,n,a,b,c;
	priority_queue< int,vector<int>, greater<int> > heap; 
	while(scanf("%d%d", &m,&n) >0 && (n || m)){
		while(!heap.empty())heap.pop();
		FOR(i,0,m){
			scanf("%d",&a);
			heap.push(a);
		}
		int sum =0;
		while(heap.size() >= 2){
			a = heap.top();heap.pop();
			b = heap.top();heap.pop();
			sum += a + b;
			heap.push(a+b);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}