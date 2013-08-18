//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1361
//#tag string
//#tag adhoc
//#tag map
//#sol usar map para armazenar as strings e o número de suas aparições

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



int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t; scanf("%d\n", &t);
	map<string,int> mapa;
	string aux, p;
	while(t--){
		getline(cin,aux);
		istringstream ss(aux);
		getline(ss, p, ' ');
		mapa[p]++;
	}
	for(map<string,int>::iterator it = mapa.begin(); it != mapa.end(); it++){
		cout << it->F << " " << it->S << endl;
	}
	
	return 0;
}