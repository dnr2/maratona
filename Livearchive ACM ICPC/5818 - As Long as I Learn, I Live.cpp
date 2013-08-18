#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

int i,j,k,n,m,a,b,c,d, t, resp;
vector<int> g[110];
int in[110];

int rec(int x){
	if(g[x].empty()){
		resp = x;
		return 0;
	}
	int ind = 0, m = -1;
	for(vector<int>::iterator it = g[x].begin(); it <g[x].end(); it++){
		if(m<in[*it]){
			ind =  *it;
			m = in[*it];
		}
	}
	return m + rec(ind);
}

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	cin >> t;
	int caso = 1;
	while(t--){
		
		scanf("%d%d", &n ,&m);
		for(i=0;i<n;i++){
			scanf("%d", &in[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
		}
		int num = rec(0);
		printf("Case %d: %d %d", caso++, num, resp );
		puts("");
		for(i=0;i<n;i++){
			g[i].clear();
		}
		memset(in,0,sizeof(in));
	}
	
	
	return 0;
}

