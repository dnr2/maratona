//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1847

#include<bits/stdc++.h>
#define REP(i,j,k) for(int (i)=(j); (i) < (k); (i)++)
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define FILL(a,b) memset(a,b,sizeof a)
#define INF 0x3f3f3f3f
#define DB(x) if(0) cerr << #x << " " << x << endl
#define _ << " " <<

using namespace std;

const int maxn = 100;

vector< vector<string> > in;
char out[50][20*30*10];
int mpos[maxn];
int off[maxn];

bool empty(vector<string> a){
	REP(i,0,(int)a.size()){
		REP(j,0,(int)a[i].size()){
			if( a[i][j] == '#') return false;
		}	
	}
	return true;
}

void print( vector<string> vec, int off){
	REP(i,0,(int)vec.size()){
		REP(j,0,(int)vec[i].size()){
			if( vec[i][j] == '#')
				out[i][j+off] = vec[i][j];
		}
	}
}

int main(){
	
	int n; int cn = 1; 
	while(cin >> n ){
		if(n == 0) break;
		in.clear();
		cout << cn << endl;
		cn++;
		string str; getline( cin, str);
		REP(i,0,n){
			getline( cin, str);
			stringstream ss(str);
			string tok; int j = 0;
			while( ss >> tok ){
				if( (int)in.size() <= j ){
					vector<string> nada;
					in.PB( nada );
				}
				in[j].PB(tok);
				j++;
				
			}
		}
		
		FILL(out,'.');
		while( empty(in[0]) ){
			in.erase(in.begin());
		}
		
		while( empty( in[ ((int)in.size())-1 ] )){
			in.erase(in.begin()+(((int)in.size())-1));
		}
		
		//DB( "aqui" _ in.size() );
		int sz  = in.size();
		FILL(mpos,0);
		FILL(off,0); //TODO
		
		int minoff = INF; 
		int maxoff = 0;
		
		REP(i,0,sz){
			if( i == 0 ){
				off[0] = 20*30;
			} else {
				REP(r,0,n){
					REP(c,0,(int)in[i][r].size()){
						if( in[i][r][c] == '#' || in[i][r][c] == '0'){
							off[i] = max( off[i], mpos[r] - c + 2);
							break;
						}
					}
				}
			}
			DB( i _ off[i] );
			REP(r,0,n){
				REP(c,0,(int)in[i][r].size()){
					if( in[i][r][c] == '#' || in[i][r][c] == '0'){
						mpos[r] = max( mpos[r], off[i] + c); 
					}
				}
				//DB( r _ mpos[r] );
			}
			minoff = min( minoff, off[i] );
			maxoff = max( maxoff, off[i] + (int)in[i][0].size() );
		}
		
		DB( minoff _ maxoff);
		
		REP(i,0,sz){
			print( in[i], off[i] - minoff );
		}
		
		int ini = 0, end = maxoff-minoff;
		while( ini < end){
			int cont = 0;
			REP(r,0,n){
				if( out[r][ini] != '.') cont++;
			}	
			if( cont == 0) ini++;
			else break;
		}
		while( ini < end){
			int cont = 0;
			REP(r,0,n){
				if( out[r][end] != '.') cont++;
			}	
			if( cont == 0) end--;
			else break;
		}
		
		REP(r,0,n){
			REP(c,ini,end+1){
				printf("%c", out[r][c]);
			}
			puts("");
		}
		
	}		
	return 0;
}	