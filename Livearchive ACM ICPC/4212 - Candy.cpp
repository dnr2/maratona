//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2213&mosmsg=Submission+received+with+ID+1150265
//#tag pd dinamic programing
//#sol usar a pd com os seguintes estados que resolve o problema para uma única linha:
// pd[j][1] é o melhor caso considerand não usar o elemento j;
// pd[j][0] é o melhor caso considerando que se PODE usar o elemento j;
// depois de resolver para cada linha tratar as colunas como se fossem ima linha considerando cada 
// resultado obtido anteriormente

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

int m ,n,p;
int pd[100001][2];
int in[100001][2];

int rec(int dep, int used){	
	if(p == 0 && dep >= n) return 0;
	if( p && dep >= m) return 0;
	if( pd[dep][used] >= 0) return pd[dep][used];
	if( used ) return pd[dep][used] = rec( dep+1 , 0);	
	return pd[dep][used] = max( rec( dep+1 , 0), in[dep][p] + rec(dep+1,1));	
}

int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while( cin >> m >> n ){
		if( (n||m) == 0) break;
		cl(pd);
		cl(in);
		p = 0;
		fr(i,0,m) {
			fr(j,0,n)  cin >> in[j][p];
			fr(j,0,n) pd[j][0] = pd[j][1] = -1;
			int ret  = max( rec( 0,0), rec( 0,1));
			in[i][1] = ret;
		}
		fr(i,0,m) pd[i][0] = pd[i][1] = -1;
		p = 1;
		int ret = max( rec( 0,0), rec( 0,1));
		cout << ret << endl;
	}
	return 0;
}