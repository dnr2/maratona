#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define cl(i) memset(i,0,sizeof(i))
#define F first
#define S second
#define pii pair<int,int>
#define pid pair<int,double>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define ll long long
#define PI acos(-1)
#define EPS 1e-9

using namespace std;

map<int,double> grid[100][100];
bool used[100][100];
int off = 50;

void rec(int turn, int x, int y , double p, bool decima){
	if( p < EPS ) return;
	// db( turn _ x _ y _ p );
	if( !used[y][x+off]) {
		if( y <= 0 ) { grid[y][x+off][turn] = p; used[y][x+off] = true; }
		else rec( turn, x, y-2, p, true);
	} else {
		double sum = 0;
		// assumindo que chegou aqui com probabilidade p
		for (map<int,double>::iterator it =grid[y][x+off].begin(); it!=grid[y][x+off].end(); ++it){
			// assumindo que este bloco x y  está lá com problabilidade it->S
			if( decima){
				rec( turn, x + 2, y , 0.5 * p * it->S , false); 
				rec( turn, x - 2, y , 0.5 * p * it->S , false);
			}
			// assumindo que está lá e que há outro bloco adjacente...
			for (map<int,double>::iterator it2=grid[y][x+off-2].begin(); it2!=grid[y][x+off-2].end(); ++it2){
				grid[y+1][x+off-1][turn] += p * it->S * it2->S; 
				used[y+1][x+off-1] = true;
			}
			for (map<int,double>::iterator it2=grid[y][x+off+2].begin(); it2!=grid[y][x+off+2].end(); ++it2){
				grid[y+1][x+off+1][turn] += p * it->S * it2->S;
				used[y+1][x+off+1] = true;
			}			
			sum += it->S;
		}
		//assumindo que não esta lah
		if( (1 - sum) > EPS){
			if( y - 2 >= 0 ) rec( turn , x , y - 2, p * (1 - sum), true);
			else {
				grid[y][x+off][turn] += p * (1 - sum);			
				used[y][x+off] = true;
			}
		}
	}
}

int main(){
	
	int c, caso =1;
	scanf("%d",&c);
	fr(i,1,21){
		rec( i, 0, 20, 1.0, true);
		db( grid[0][off][i] _ grid[0][off - 2][i] _ grid[0][off + 2][i]);
	}
	while (c--){
		int n , x, y;
		scanf("%d%d%d", &n, &x, &y);
		// db(n _ x _ y);
		double resp =0;
		if( abs(x) > 50 || abs( y) > 50 ) { printf("Case #%d: %.8lf\n", caso++, 0.0); continue;}
		for (map<int,double>::iterator it =grid[y][x+off].begin(); it!=grid[y][x+off].end(); ++it){
			if( it->F <= n) resp += it->S;
		}
		printf("Case #%d: %.8lf\n", caso++, resp);
	}
	return 0;
}

