#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iostream>

#define pair<int,int> pii

using namespace std;

int i,j,k,a,b,c,d, n,m;
int caso =1;

int in[100010];
int aux[100010];
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	for( i=0;i<n;i++){
		scanf("%d", in+i);
		aux[i] = in[i];
	}
	sort( in, in+n);
	int cont = 0;
	for( i=0;i<n;i++){
		if( aux[i] != in[i]) cont++;
	}
	if( cont < 3){
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}