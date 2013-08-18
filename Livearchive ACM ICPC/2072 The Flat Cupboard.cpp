//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=73
//#tag: DAG


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int  i, j, k, m, n, a, b, c, d;
// int in[1010][1010];
struct no{
	int ya, yb, x1, x2;	
	no(int ya=0, int yb=0, int x1=0,int x2=0): ya(ya), yb(yb), x1(x1), x2(x2) {}
};
vector<int> dag[110];
no nos[110];
bool mark[110];
int dfs(int x){
	int r = 0;	
	mark[x] = true;
	// cout << "entering " << x << endl;
	for(vector<int>::iterator it = dag[x].begin(); it < dag[x].end(); it++){
		if( !mark[*it]){
			r += dfs(*it);
			r++;
		}
	}
	return r;
} 
int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while( scanf("%d", &n) > 0 && n != 0){		
		for(i=0;i<=100;i++){
			dag[i].clear();
		}
		memset(mark,false,sizeof(mark));
		// printf("n eh: %d\n" , n);
		for(i=0;i<n;i++){
			scanf("%d%d%d%d", &a, &b, &c, &d);			
			no aux(min(b,d), max(b,d)-1, min(a,c), max(a,c)-1);			
			nos[i] = aux;			
			// printf("%d -> %d %d %d %d\n", i ,nos[i].ya, nos[i].yb, nos[i].x1,  nos[i].x2);
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(j!=k){
					if( nos[j].yb < nos[k].ya && !( ( nos[k].x1 < min(nos[j].x1, nos[j].x2) && nos[k].x2 < min(nos[j].x1, nos[j].x2)  ) 
						|| ( nos[k].x1 > max(nos[j].x1, nos[j].x2) && nos[k].x2 > max(nos[j].x1, nos[j].x2)  ) ) ){
						dag[j].push_back(k);
						// printf("%d %d\n" , j, k);
					}
				}				
			}
		}
		// cout << endl;
		scanf("%d%d%d%d", &a, &b, &c, &d);	
		for(i=0;i<n;i++){
			// printf("%d -> %d %d %d %d\n", i ,nos[i].ya, nos[i].yb, nos[i].x1,  nos[i].x2);
			if( nos[i].ya ==  min(b,d) && nos[i].yb == max(b,d)-1 && 
					nos[i].x1 == min(a,c) && nos[i].x2 ==max(a,c)-1 ) {
				printf("%d\n", dfs(i) );
				break;
			}
		}
		
	}
	return 0;
}
