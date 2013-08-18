//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=951
//#tag ad hoc
//#tag strings
//#sol fazer simulação para encontrar palavras

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

char str[52][52];
char aux[100];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};


int main(){
	
	int t,n,m,w; scanf("%d\n", &t);	
	while(t--){
		bool primeiro = true;
		cin >> n >> m;
		fr(i,0,n) {
			scanf("%s" , str[i]);
			fr(j,0,m) str[i][j] = tolower(str[i][j]);
		}
		
		cin >> w;
		fr(a,0,w){
			scanf("%s", aux);
			int len = strlen(aux);
			fr(i,0,len) aux[i] = tolower(aux[i]);
			fr(i,0,n) {
				fr(j,0,m){
					fr(d,0,8){					
						int y = i, x = j;
						bool ok = false;
						fr(k,0,len){
							if( aux[k] != str[y][x]) break;
							if( k == len-1) ok = true;
							y += dy[d]; x += dx[d];
							if( y < 0 || x < 0 || y > n || x > m) break;
						}
						if( ok ) {
							printf("%d %d\n", i + 1, j +1);
							goto fim;
						}
					}
				}
			}
			fim :
			a =a ;
		}
		if( t != 0) puts("");
	}
	return 0;
}