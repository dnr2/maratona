//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1661
//#tag graph theory teoria dos grafos 
//#tag erdos - gallai theorem
//#sol testar as restrições do erdos-gallai nos números da entrada

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

// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))

// #define umap unordered_map

using namespace std;

int in[10010];
ll sum[10010];
bool cmp( ll x, ll y){
	return  x > y ;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int n;
	while(scanf("%d", &n) >0 && n){
		bool ok = true; ll cont = 0;
		n++;
		fr(i,1,n){  
			scanf("%d", in+i); 
			cont += in[i]; 
			if( in[i] >= n || in[i] < 0) ok = false; 
		}
		if( cont & 1) ok = false;
		else if( ok == true){
			sort( in+1, in+n ,cmp); ll aux = cont - in[1];
			// fr(i,0,n+1) db( "->" _ in[i]);
			fr(i,2,n) { sum[i] = aux; aux -= in[i]; }
			// fr(i,2,n) db( ">>>" _ sum[i]);
			aux = 0; ll k = n; sum[n] = 0;
			for( ll i=1;i<n-1;i++){
				aux += in[i];
				while( k < i+1) k++;
				while( k > i+1 && in[k-1] <= i) k--;
				ll value = (i*(i-1));
				value += sum[k]; value += ((k-i-1)*i);
				if( aux > value ){ ok = false; break;}
			}
		}
		if( !ok) puts("Not possible");
		else puts("Possible");
	}
	return 0;
}