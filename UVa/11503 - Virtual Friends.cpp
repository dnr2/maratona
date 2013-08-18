//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, a, b, c, d, i, j, k;
int h, len, z, resp, t, p;

map<string, int> net;
char b1[200], b2[200];

string n1, n2;

int pa[400100];
int na[400100];

int rec(int x){
	if( pa[x] == x || pa[x] < 0) return x;
	return pa[x] = rec( pa[x] );
}

void insert(int x, int y){
	
    if( pa[x] < 0 && pa[y] < 0){
		pa[x] = x;
		pa[y] = x;
		na[x] = 2;
	} else if( pa[x] < 0 ){
		pa[x] = rec(y);
		na[pa[x]] += 1;
	} else if( pa[y] < 0 ){
		pa[y] = rec(x);
		na[pa[y]] += 1;
    } else if( rec(x) != rec(y)){
        int p1 = rec(x);
		int p2 = rec(y);
		pa[p2] = p1;
		na[p1] += na[p2];		
	} 
}


int main(){
    //freopen("in.txt", "r", stdin );  freopen("out.txt", "w", stdout );
    
    int t = 0;
	cin >> t;
	
	while( t--){
		memset(pa, -1, sizeof(pa));	
		memset(na, 1, sizeof(na));	
		len = 1;
		scanf("%d", &h);
        net.clear();		
		
		while( h--){		
			
			scanf("%s %s", &b1, &b2);		
			n1 = b1;
			n2 = b2;
			if( net[n1] == 0){
				net[n1] = len++;
			}
			if( net[n2] == 0){
				net[n2] = len++;			             
			}			
			insert(net[n1], net[n2]);            
			printf( "%d\n", na[rec(net[n1])]);
			
		}
	}
	
    return 0;

}

