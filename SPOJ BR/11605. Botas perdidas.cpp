//http://br.spoj.pl/problems/BOTAS/
//sorting sort

#include<cstdio>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>

#define F first
#define S second


using namespace std;

pair<int,char> arr[10100];
bool mark[10100];

bool cmp(pair<int,char> x, pair<int,char> y){
	if( x.F == y.F ) return x.S < y.S;
	return x.F < y.F;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int n, a, b, resp;
	char c;
	while(scanf("%d", &n) > 0 && n){
		memset(mark,false,sizeof(mark));
		memset(arr,0,sizeof(arr));
		resp =0;
		for(int i=0;i<n;i++){
			scanf("%d %c", &arr[i].F, &arr[i].S);
		}
		sort( arr, arr + n, cmp);
		for(int i=0;i<n;i++){
			int k = upper_bound( arr + i + 1, arr+n, arr[i]) - arr;
			while( (mark[k] || arr[k].S == arr[i].S ) && arr[k].F == arr[i].F ) k++;
			if( arr[k].F == arr[i].F) mark[k] = true, resp++; 
		}
		printf("%d\n" ,resp);
	}
}