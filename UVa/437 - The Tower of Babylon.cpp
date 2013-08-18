//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=378
// #tag: DAG

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    // x is supposed to be bigger than y
    int x, y, h, n;
    node (int x=0, int y=0,int h=0, int n= 0): x(x), y(y), h(h), n(n) {}
    bool operator < ( const node & a) const {
        return ( x < a.x ) && ( y < a.y);
    }
};

node nos[100];
vector<int> g[100];

int best[100];
int i,j,k,n,m,a,b,c,d;

int dag(int x){
    if( best[x] ) return best[x];
    if( g[x].empty()) return best[x] = nos[x].h;

    vector<int>::iterator it;
    int resp = 0;
    for( it = g[x].begin(); it<g[x].end();it++){
        resp = max(resp, dag(*it));
    }
    return best[x] = resp + nos[x].h;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int caso = 1;
	while(scanf("%d" , &n) > 0 && n != 0){
	    int num = 0;

        for(i=0;i<n;i++){
            scanf("%d%d%d", &a, &b, &c);
            nos[num++] = node(max(a,b), min(a,b) , c, num);
            nos[num++] = node(max(a,c), min(a,c) , b, num);
            nos[num++] = node(max(b,c), min(b,c) , a, num);
        }

        for(i=0;i<num;i++){
            for(j=0;j<num;j++){
                if(i!=j){
                    if(nos[i] < nos[j]) {
                        g[j].push_back(i);
                        //printf("%d %d h(%d) -> %d %d h(%d)\n", nos[j].x , nos[j].y, nos[j].h, nos[i].x, nos[i].y, nos[i].h );
                    }
                }
            }
        }
        m = 0;

        for(i=0;i<num;i++){
            memset(best , 0, sizeof(best));
            m = max(m, dag(i));
        }
        for(i=0;i<num;i++){
            g[i].clear();
        }
        printf("Case %d: maximum height = %d\n", caso++ , m );
	}
	return 0;
}
