//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=241
//#tag josephus
//#sol simulação e preprocessamento

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

int arr[30] ;
int out[] = {
2, 
7, 
5, 
30, 
169, 
441, 
1872, 
7632, 
1740, 
93313, 
459901, 
1358657, 
2504881, 
13482720, 
};

int main(){
	// freopen("out.txt", "w", stdout);
	int k;
	while(scanf("%d", &k) >0 && k){
		cout << out[k-1] << endl;
	}
	return 0;
}