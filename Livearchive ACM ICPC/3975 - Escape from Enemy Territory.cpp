//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=1976&mosmsg=Submission+received+with+ID+1016907
//#tag graph
/*
Devemos achar um caminho de tamanho N minimo tal que todos os pontos estejam o mais distantes
das bases inimigas do que um certo limiar M, onde M eh o maior dos menores valores 
de distância possíveis em qualquer caminho de START para END
M eh a primeira saída, enquanto o N e a segunda saída.
Rodamos primeiro um A* para procurar o M, depois rodamos um djkstra
para achar N
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>

#define MIN(a,b) (a<b)?a:b
#define DIST(a,b,c,d) abs(a-c) + abs(b-d)

using namespace std;

int i, j , k, n , m, t, by, bx, a,b,c,d, ex,ey , respmindist;

struct p{
	int x, y, d;
	p( int a = 0, int b = 0, int c = 0): x(a), y(b), d(c) {};
};

struct no{
	int d, e, c, x, y;
	no( int in1 = 0, int in2 = 0, int in3 = 0, int in4 = 0, int in5 = 0) : d(in1), e(in2), c(in3), x(in4), y(in5) {};
	bool operator < ( const no & in ) const{
		bool ret;
		if( e >= respmindist && in.e >= respmindist){
			ret = (c + d > in.c + in.d)? true: false; 
		} else if( e >= respmindist && in.e < respmindist){
			ret = false;
		} else if( e < respmindist && in.e >= respmindist){
			ret = true;
		} else {
			ret = ( c + d > in.c + in.d )? true: false; 
		}
		return ret;
	}

};

p enem[10010];
int dists[1001][1001];
bool mark[1001][1001];

int achar(){	
	priority_queue<no> q;
	int dist  = DIST(a,b,c,d);
	no aux( dist, dists[b][a], 0 , a, b);
	q.push(aux);
	while(!q.empty()){
		aux = q.top();
		q.pop();
		if( mark[aux.y][aux.x]) continue;
		// printf("d = %d e = %d c = %d x = %d y = %d\n", aux.d, aux.e, aux.c, aux.x, aux.y); 
		mark[aux.y][aux.x] = true;
		respmindist = MIN(respmindist, aux.e);
		if( aux.x == c && aux.y == d) return aux.c;
		
		for(  int i = -1; i <= 1; i++){
			for( int j = -1; j <=1; j++){
				
				if(  aux.x + i < bx && aux.x + i >= 0 &&  aux.y + j < by 
						&& aux.y + j >=0 && abs(i + j) == 1 ){
					
					dist = DIST( aux.x+i,aux.y+j,c,d);
					no auxf( dist, dists[aux.y+j][aux.x+i], aux.c + 1, aux.x+i,aux.y+j);				
					q.push(auxf);
				}
			}
		}
	}
	return 0;
}

class comparison{
public:
	bool operator () ( const p & p1, const p & p2) const {
		return p1.d > p2.d;
	}
};

int denovo(){
	priority_queue<p, vector<p>, comparison> q;
	p aux( a, b, 0 );
	q.push(aux);
	while(!q.empty()){
		aux = q.top();
		q.pop();
		if( aux.x == c && aux.y == d) return aux.d;
		if( mark[aux.y][aux.x] ) continue;
		// printf("d = %d x = %d y = %d\n", aux.d, aux.x, aux.y); 
		mark[aux.y][aux.x] = true;		
		for(  int i = -1; i <= 1; i++){
			for( int j = -1; j <=1; j++){				
				if(  aux.x + i < bx && aux.x + i >= 0 &&  aux.y + j < by 
						&& aux.y + j >=0 && abs(i + j) == 1 && dists[aux.y+j][aux.x+i] >= respmindist ){
										
					p auxf( aux.x+i,aux.y+j, aux.d + 1);					
					q.push(auxf);
				}
			}
		}
	}
	return 1;
}

//calcular a distância mínima de cada ponto a alguma base inimiga
void bfs(){
	queue<p> q;
	for(int i = 0 ; i < n; i++){
		q.push( p(enem[i].x, enem[i].y, 0)); 
	}
	p aux;
	while(!q.empty()){
		aux = q.front();
		q.pop();
		if(aux.x < 0 || aux.y < 0   || aux.x >= bx || aux.y >= by || aux.d >= dists[aux.y][aux.x] ) continue;
		dists[aux.y][aux.x] = aux.d;
		// printf("%d %d\n", aux.x, aux.y);
		q.push(p(aux.x+1, aux.y, aux.d+1));
		q.push(p(aux.x, aux.y+1, aux.d+1));
		q.push(p(aux.x-1, aux.y, aux.d+1));
		q.push(p(aux.x, aux.y-1, aux.d+1));
	}
}

void print(){

	for( int i = 0; i < by; i++){
		for( int j = 0; j < bx; j++){
			printf("%d ", mark[i][j]);
		}
		printf("\n");
	}
}

int main(){	

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin >> t;
	while(t--){
		memset(mark, false, sizeof(mark));
		scanf("%d%d%d", &n, &bx, &by);
		respmindist = 1000000;
		for( i = 0; i < by; i++){
			for(  j = 0; j < bx; j++){
				dists[i][j] = 10000000;
			}
		}
		scanf("%d%d%d%d", &a, &b, &c,&d);

		// mark[b][a] = true;
		for( i=0 ;i < n ; i++){
			scanf("%d%d", &ex, &ey);		
			enem[i].x = ex;
			enem[i].y = ey;
			// mark[ey][ex] = true;
		}
		bfs();
		// respmindist = MIN( dists[b][a], dists[d][c]);		
		int resp2 = achar();
		// memset(mark, false, sizeof(mark));
		// int resp2 = denovo();
		// print();
		printf("%d %d\n",  respmindist, resp2);
	}
	
	return 0;
	
}
