#include<bits/stdc++.h>

using namespace std;

#define REP(i,j,k) for(int (i)=(j); (i)<(k);++(i))
#define ll long long
#define FT first
#define SD second
#define PII pair<int,int>
#define FILL(i,j) memset(i,j,sizeof(i))
#define DB(x) cerr << #x << "=" << x << endl
#define _ << " " <<

int n,m;
const int MAXN = 100;
const int MAXNODES = 100;
char in[2][MAXN][MAXN];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


int mat[MAXNODES][MAXNODES];
int color[MAXNODES];

vector<int> adj[MAXNODES];
int pai[MAXNODES];


int findp(int x){
	if( pai[x] == x) return x;
	return pai[x] = findp( pai[x]);
}

int dfs( int node, int p){
	
}


void printMap(int pos){
	REP(i,0,n){
		REP(j,0,m){
			cerr << in[pos][i][j];
		}
		cerr << endl;
	}	
	cerr << endl;
}

void fill(int y, int x, int avoid, int cor , int pos){
	if( in[pos][y][x] == avoid ) return;	
	queue<PII> q;
	q.push(PII(y,x));	
	in[pos][y][x] = cor;
	while( !q.empty()){
		int i = q.front().FT, j = q.front().SD; q.pop();
		REP(k,0,4){
			int ni = i + dy[k];
			int nj = j + dx[k];
			if( ni < 0 || nj < 0 || ni >= n || nj >= m) continue;	
			if( in[pos][ni][nj] != avoid && in[pos][ni][nj] != cor){
				in[pos][ni][nj] = cor;
				q.push( PII( ni , nj));
			}
		}
	}
}



int main(){
	int T; scanf("%d", &T);
	REP(cn,1,T+1){
		scanf("%d%d", &n, &m);		
		
		
		REP(i,1,n+1) scanf("%s", in[0][i]+1);
		n+=2; m+=2;
		
		REP(i,0,n) in[0][i][0] = in[0][i][m-1] = '.';
		REP(j,0,m) in[0][0][j] = in[0][n-1][j] = '.';				
			
		
		map<char,int> ma; int sz = 0;
		REP(i,0,n ) REP(j,0,m){
			if(in[0][i][j] != '.' && ma.count(in[0][i][j]) == 0) ma[in[0][i][j]] = sz++;
		}
		
		for(map<char,int>::iterator it = ma.begin(); it != ma.end(); it++){
			REP(i,0,n) REP(j,0,m){
				in[1][i][j] = (it->FT == in[0][i][j] )? it->FT : 0;			
			}
			fill(0,0,it->FT,1,1);
			REP(i,0,n) REP(j,0,m){
				if( in[1][i][j] == 0){
					fill(i,j,it->FT,it->FT,0);
				}
			}
		}
		
		ma.clear(); sz = 0;
		REP(i,0,n ) REP(j,0,m){
			if(in[0][i][j] != '.' && ma.count(in[0][i][j]) == 0) ma[in[0][i][j]] = sz++;
		}
		
		FILL(mat,0);
		
		REP(i,0,n) REP(j,0,m){
			if( in[0][i][j] != '.' ){
				REP(k,0,4){
					int ni = i + dy[k];
					int nj = j + dx[k];
					if( ni < 0 || nj < 0 || ni >= n || nj >= m ) continue;
					if( in[0][i][j] != in[0][ni][nj] && in[0][ni][nj] != '.' ){
						int u = ma[in[0][i][j]], w = ma[in[0][ni][nj]];
						mat[u][w] = 1;
						mat[w][u] = 1;						
					}
				}
			}
		}
		
		
		
		//test one color;
		int numcoloring = 1;

		REP(i,0,sz){
			int cont = 0;
			REP(j,0,sz){
				cont += mat[i][j];
			}
			if( cont > 0){
				numcoloring = 2; break;
			}
		}
		if( numcoloring > 1){
		
			//test two colors
			FILL( color, -1);
			REP(i,0,sz){
				bool ok = true;
				if( color[i] == -1){
					queue<int> q;
					q.push( i);
					color[i] = 0;
					while(!q.empty()){
						int cur = q.front(); q.pop();						
						REP(next,0,sz){
							if( mat[cur][next] == 0 ) continue;				
							if( color[cur] == color[next]){
								ok = false; goto end;
							}
							if( color[next] == -1){
								color[next] = (color[cur]+1) % 2;
								q.push( next );
							}
						}
					}
				}		
				end :
				if(!ok){
					numcoloring = 3; break;
				}
			}

			if( numcoloring > 2){
			
				//four clique
				REP(i,0,sz) REP(j,i+1,sz) REP(k,j+1,sz) REP(l,k+1,sz){
					if( mat[i][j] > 0 && mat[i][k] > 0 && mat[i][l] > 0 && 
						mat[j][k] > 0 && mat[j][l] > 0 && mat[k][l] > 0){
						numcoloring = 4; goto printans;
					}
				}
			
				REP(i,0,sz+1) adj[i].clear();
				REP(i,0,sz) pai[i] = i;
				
				
				int count3 = 0;				
				REP(i,0,sz) REP(j,i+1,sz) REP(k,j+1,sz){
					if( mat[i][j] > 0 && mat[j][k] > 0 && mat[k][i] > 0 ){
						// if( count == 0) {
							// adj[i].push_back(j);
							// adj[j].push_back(i);
							// adj[i].push_back(k);
							// adj[k].push_back(i);
							// pai[j] = i;
							// pai[k] = i;
						// }
						count3++; k = j = i = sz;
					}
				}								
				
				//Grotzsch's theorem
				if( count3 == 0){
					numcoloring = 3; goto printans;
				}
				
				
				assert(sz < 20);
				
				REP(i,0,sz){
					REP(j,i+1,sz){
						if( mat[i][j] ){
							if( find(i) != find(j)){
								pai[find(i)] = find(j);
								adj[i].push_back( j);
								adj[j].push_back( i);
							}
						}
					}
				}
				
				FILL(color,-1);
				REP(i,0,n){
					if( color[i] == -1){
						color[i] = 0;
						if( dfs( i , -1) == -1 ){
							numcoloring = 4; goto printans;
						}
					}
				}
				
				numcoloring = 3; goto printans;
			}
			
		} 
		
		printans :
		printf("Case %d: %d\n", cn, numcoloring);
		REP(i,1,n-1){
			REP(j,1,m-1){
				printf("%c", in[0][i][j]);
			}
			puts("");
		}
		
	}
	return 0;
}