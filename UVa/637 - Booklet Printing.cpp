//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=578
//#tag ad hoc
//#sol simular

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

int arr[110][2];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n; 
	while( scanf("%d", &n) > 0 && n){
		int f = (n + 3) / 4;
		int b = n % 4;
		int side = 1; int cont = 1;
		cl(arr);
		printf("Printing order for %d pages:\n", n);
		fr(i,0,f<<1){		
			arr[i][side] = cont++;
			side = ((side+1)%2);
			if( cont > n) break;
		}
		if( cont <= n) for(int i= (f<<1)-1; i >=0;i--){
			arr[i][side] = cont++;
			side = ((side+1)%2);
			if( cont > n) break;
		}
		fr(i,0,f<<1){
			if(  arr[i][0] == 0 && arr[i][1] == 0) continue;
			
			cout << "Sheet " << ((i/2)+1) << ", " << ((i&1)?"back ":"front" )
			<<": ";
			if( arr[i][0]==0) cout << "Blank"; else cout << arr[i][0] ;
			cout << ", " ;
			if( arr[i][1]==0) cout << "Blank"; else cout << arr[i][1] ;
			cout << endl;
		}
	}
	
	return 0;
}