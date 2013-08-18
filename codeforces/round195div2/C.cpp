//
//#tag
//#sol

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
#define EPS 1e-9
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int arr[100010];
int p[35][100010];
int pos[35];

int most(int x){
	int cont = 0;
	while(x > 0){
		cont++; x = x >> 1;
	}	
	return --cont;	
}

int main(){
	
	int t; cin >> t;	
	fr(i,0,t){
		scanf("%d", arr + i);
		fr(j,0,30){
			if( (arr[i] & (1 << j)) > 0){
				p[j][pos[j]++] = arr[i];
				// db(j _ arr[i]);
			}
		}
	}
	for(int x = 30; x >0; x--){
		if( pos[x] == 0) continue;
		int aux = -1;
		fr(i,0,pos[x]){
			aux = aux & p[x][i];
		}
		// db(x _ aux _ pos[x] _ (aux & ( (1<<x) -1)) );
		if( (aux & ( (1<<x) -1)) == 0) {
			cout << pos[x] << endl;
			fr(i,0,pos[x]){
				if( i > 0) printf(" ");
				printf("%d", p[x][i]);
			}
			return 0;
		}		
	}
	cout<< t << endl;
	fr(i,0,t) {
		if( i > 0) printf(" ");
		printf("%d", arr[i]);
	}	
	return 0;
}