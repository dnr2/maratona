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

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int t;
	cin >> t;
	string a, b, resp;
	int x, y;
	map<string, int> mapa;
	while(t--){
		mapa.clear();
		for(int i=0;i<16;i++) {
			cin >> a>>b;
			scanf("%d%d", &x,&y);
			mapa[a]; mapa[b];
			if( x > y ) mapa[b]++;
			else mapa[a]++;
		}
		for(map<string,int>::iterator it= mapa.begin();it != mapa.end(); it++){
			if( it->S == 0) cout << it->F << endl;
		}
	}
	return 0;
}