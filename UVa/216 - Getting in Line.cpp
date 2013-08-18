//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=152
//#tag brute force força bruta
//#tag travelling salesman problem tsp caixeiro viajante
//#sol testar todas as permutações possíveis dos pontos e ver qual delas tem nenor custo

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

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

struct st{
	int x, y;
	int z;
	st(int x=0,int y=0, int z =0) : x(x), y(y), z(z) {}
	const bool operator < (const st & in) const{
		return z < in.z;
	}
};


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int n, caso = 1;
	while(scanf("%d", &n) > 0 && n){
		vector<st> in;
		vector<st> resp; int a, b;
		fr(i,0,n) { 
			scanf("%d %d", &a , &b); 
			in.pb( st(a, b , i));
		}
		double best = 1e10;
		do{
			// db(best);
			double cont =0;
			fr(i,1,n) {
				cont += hypot(((double)(in[i].x - in[i-1].x)), ((double)(in[i].y - in[i-1].y))) + 16.0;
			}
			if( cont < best){
				best = cont; 
				resp.clear();
				fr(i,0,n) resp.pb(in[i]);
			}
		} while( next_permutation( in.begin(), in.end()) ); 
		puts("**********************************************************");
		printf("Network #%d\n", caso++);
		fr(i,1,n){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
			resp[i-1].x, resp[i-1].y, resp[i].x, resp[i].y , (16.0 + hypot( ((double)(resp[i].x - resp[i-1].x)), ((double)resp[i].y - resp[i-1].y))));
		}
		printf("Number of feet of cable required is %.2lf.\n", best);
	}
	return 0;
}