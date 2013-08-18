//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=497
//#tag ad hoc
//#tag simulação simulation

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

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
char in[2000][2000];
int arr[2000][2000];
int resp[10];

int ar(int x){
	return ((((x-1)%4)+4)%4);
}

int main(){
	
	// freopen("out.txt", "w", stdout);
	int n , m;
	while(scanf("%d%d", &n, &m) > 0 && (m||n) ){
		int x = 1, y = n, dir = 1;
		cl(resp);
		fr(i,1,n+1){
			scanf("%s", in[i]+1);
			in[i][0] = in[i][m+1] =1;
			fr(j,1,m+1) arr[i][j] = 0, in[i][j] -= '0';
		}
		fr(j,0,m+2) in[0][j] = in[n+1][j] = 1;		
		// fr(i,0,n+2){
			// fr(j,0,m+2){
				// cout << ((int)in[i][j]) ;
			// }
			// cout << endl;
		// }
		do{
			arr[y][x]++;
			if( in[y+dy[(dir+1)%4]][x+dx[(dir+1)%4]]==0  ){
				x+=dx[(dir+1)%4]; y+=dy[(dir+1)%4]; dir = (dir+1)%4;
				// cout << "a" << endl;
			} else if( in[y+dy[dir]][x+dx[dir]]==0 ){
				x+=dx[dir];y+=dy[dir];
				// cout << "b" << endl;
			} else if(in[y+dy[ar(dir)]][x+dx[ar(dir)]]==0 ){
				x+=dx[ar(dir)];y+=dy[ar(dir)]; dir = ar(dir);
				// cout << "c" << endl;
			} else {
				dir = ar(ar(dir));
				x+= dx[dir];y+=dy[dir];
				// cout << "d" << endl;
			}
		} while( x != 1 || y != n);
		fr(i,1,n+1){
			fr(j,1,m+1){
				if( !in[i][j]) resp[arr[i][j]]++;
			}
		}
		fr(i,0,5){
			printf("%3d", resp[i]);
		}
		puts("");
	}
	return 0;
}