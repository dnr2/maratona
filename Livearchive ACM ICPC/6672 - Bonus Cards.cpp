//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4684

#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
#define EPS 1e-9


const int maxn = 4000;
int n, a, b;

double dp[maxn][maxn];
double card;
int mark[maxn][maxn], passo = 1;

double rec( int c1, int c2 ){
    if( c1 + c2 == n) return 0;
    if( mark[c1][c2] == passo ) return dp[c1][c2];
    int aa = a - c1;
    int bb = b - c2;
    double tot = card + (aa * 2) + bb;
    double ret = card / tot;
    
    if( c1 < a) ret += rec( c1+1, c2) * (aa * 2 / tot);
    if( c2 < b) ret += rec( c1, c2+1) * (bb / tot);
    mark[c1][c2] = passo;
    return dp[c1][c2] = ret;
}

int main() {

    
    while( scanf("%d%d%d", &n, &a, &b) > 0){
        
        for(int i = 2; i >=1; i--){
            card = i;			
			passo++;
            printf("%.16lf\n", rec( 0 , 0 ));
        }
    }
    return 0;
}
