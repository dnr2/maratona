//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4693

#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair

#define REP(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
#define FT first
#define SD second
#define DB( x ) cerr << #x << " " << x << endl
#define _ << " " <<

using namespace std;

typedef pair<int,int> PII;
typedef long long ll;

const int maxn = 2000000;

int n, p, ncor, targ;
int board[maxn];
int hand[maxn];

int main() {    
    //TODO voce pode ser o unico jogador mas acabar perdendo por so ter uma peca de outro tipo
    //TODO long long?
    while( scanf("%d%d%d%d", &n, &p, &ncor, &targ) > 0){
        
        map<int,int> m1,m2, cmb;
		set<PII> maxx;
        REP(i,0,n) scanf("%d", board + i);
        REP(i,0,p) scanf("%d", hand + i);
        
        REP(i,0,n){
            m1[board[i]]++;
            cmb[board[i]]++;    
        }
            
        REP(i,0,p){
            m2[hand[i]]++;
            cmb[hand[i]]++; 
        } 
		for(map<int,int>::iterator it = cmb.begin(); it != cmb.end(); it++){
			maxx.insert( PII(-it->SD , it->FT));
		}
        vector<int> resp;
        // DB( targ _ hand[0] _ m2[targ] _ m2[hand[0]] );
        REP(index,0,n){
			// DB("");
            //update
            m1[board[index]]--;
            m1[hand[0]]++;
            
            m2[hand[0]]--;
            maxx.erase(PII(-cmb[board[index]], board[index] ));
            cmb[board[index]]--;
            maxx.insert(PII(-cmb[board[index]], board[index] ));			
			
            //cmb[hand[0]]++;
            //cmb[hand[0]]--;
            
            //end-update
            
            //TODO correto? pode ser outro alem desse?
            PII cor_max = *maxx.begin();
            
            if( cor_max.SD == targ) {
                set<PII>::iterator it = maxx.begin();
                it++; 
                if( it == maxx.end() ){					
                    resp.push_back( index);
                    //roll back
                    m1[board[index]]++;
                    m1[hand[0]]--;
                    m2[hand[0]]++;
                    maxx.erase(PII(-cmb[board[index]], board[index] ));            
					cmb[board[index]]++;
					maxx.insert(PII(-cmb[board[index]], board[index] ));
                    //end-roll back
                    continue;
                }
                cor_max = *it;
            }
                        
            int ncor_max = min( -cor_max.FT, n );
			
            // DB( index _ ncor_max _ cor_max.SD );
			// DB( cmb[board[index]] _ board[index] );
            //TODO -m2[targ] if no targ on board to put form hand to board and dont count?
            int ncor_targ = max( 0 , m1[targ] - ((p-1) - m2[targ] )); 
            
            if( m1[targ] == 0 && m2[targ] > 0 && ((p-1) - m2[targ]) == 0){
                ncor_targ++;
                if( m1[cor_max.SD] == n ) {
                    ncor_max--;
                }
            }
            
            
            // DB( ncor_targ _ m1[targ] _ (p-1) _ m2[targ] );
            
            if( ncor_max < ncor_targ ){
                resp.push_back( index );
            }
               
            //roll back
            m1[board[index]]++;
            m1[hand[0]]--;
            m2[hand[0]]++;
			maxx.erase(PII(-cmb[board[index]], board[index] ));            
            cmb[board[index]]++;
            maxx.insert(PII(-cmb[board[index]], board[index] ));
            //end-roll back
        }
        
        printf("%d\n", (int) resp.size());
        REP(i,0,(int)resp.size()){
            if( i > 0) printf(" ");
            printf("%d", resp[i] + 1);
        }
        if( (int) resp.size() > 0) puts("");
    }    
}
