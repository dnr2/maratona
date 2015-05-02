//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3246
//#tag geometry
//#sol By Mateus Moury

/* 
Considere que as retas de todas as queries estão ordenadas pelo seu angulo em relação à reta 0x, de forma que a reta
que chamei de A em certa query é a reta com o menor ângulo, e a C é a reta com o maior angulo. No caso acima, a 
gente pode perceber que se a gente pegar todos os soldados (tudo que eu falar pra soldado é a mesma coisa pra tanque) 
que estão à esquerda da reta C, nós vamos ter x = A1 + A3 + A4 + A5 soldados. Se a gente pegar todos os soldados que 
estão à esquerda da reta que tem o segundo menor ângulo (que é a reta B), nós vamos ter y = A2 + A3 + A4 soldados. 
Finalmente, se a gente pegar todos os soldados que estão à direita da reta A, teremos z = A4 + A5 + A6 soldados.

Podemos perceber que x - y - z = A1 + A3 + A4 + A5 - A2 - A3 - A4 - A4 - A5 - A6 = A1 - A2 - A4 - A6.

E A1 - A2 - A4 - A6 é justamente a diferença que a questão pede em cada query.

Mas esse não é o único caso. Existe o caso em que o ponto oposto à reta C (que é a reta de maior ângulo) está à direita
dessa reta:

Nesse caso, para fazermos nossos cálculos, agora a gente vai ter que pegar os soldados que estão à direita da reta 
C (chamamos de x), à direita da reta B (chamamos de y) e à esquerda da reta A (chamamos de b).  Podem checar que x-y-z 
também dá exatamente a diferença cobrada na questão. Tudo se resume agora a saber quantos soldados estão à direita 
e à esquerda de cada reta.

Calculando quantos pontos estão à esquerda da reta em O(log(n))

Nós sabemos que todas as retas C', C''… são paralelas à reta C, como ele diz na questão. Isso quer dizer que, para 
um conjunto de pontos, existe uma forma de ordená-los. Intuitivamente, imagina que uma reta vem lá da extrema 
esquerda, vem descendo e vai pra o infinito da direita. A gente quer saber então quais pontos vão sendo tocados pela
reta a medida que ela desliza pelo plano cartesiano.
Pegamos, por exemplo, a reta C da primeira query. Calculamos a distância de todos os pontos a essa reta. Se um ponto
qualquer tiver à esquerda da reta, multiplicamos essa distância por -1. Se tiver a direita, por 1 (ou não multiplica). 
Assim, os pontos que vem antes terão as menores distâncias. Pra ver a questão de esquerda/direita, vocês podem usar 
vetores e cross product (eu fiz assim, e tem uns casos chatos, vão descobrindo ai) ou acho que só jogar na 
equação Ax + By + C e ver se é > ou < a 0 deve ser suficiente também. 
Agora que esses pontos estão ordenados de acordo com a reta C, toda vez que você receber uma reta C', é so pegar 
qualquer ponto que está nessa reta, e fazer um lower_bound no array ordenado de pontos que você tem. Todos os pontos
que vierem antes desse estão à esquerda da reta. E o resto, à direita.

*/

#include <bits/stdc++.h>


// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 70010;

struct pt{
	double x, y ;
	pt( double x = 0, double y = 0 ) : x(x), y(y) {}
	pt operator - (pt in ) { return pt ( x - in.x, y - in.y); }
	pt operator + (pt in ) { return pt ( x + in.x, y + in.y); }
	double operator ! () { return  sqrt( x*x+y*y); }
};

pt operator * (double a, pt b) {
	return pt(a*b.x, a*b.y);
}

double dot( pt a, pt b){
	return a.x * b.x + a.y * b.y;
}

///orientation
double kr(pt a, pt b) { // z component of the cross product $a\times b$
	return a.x*b.y-b.x*a.y;
}
double kr( pt a, pt b, pt c) { // z component of the cross product $(b-a)\times (c-a)$
	return kr(b-a,c-a);
}

pt interLine(pt a1, pt a2, pt b1, pt b2) {
	return (1.0/kr(a1-a2,b1-b2))*(kr(a1,a2)*(b1-b2) - kr(b1,b2)*(a1-a2));
}

int n[2];
int q; 
pt in[2][maxn];
pt que[maxn][3][2];
double dist[2][3][maxn];
double sline[3];

double signLine(pt a, pt b, pt c ){
	pt ac = c - a;
	pt ab = b - a;
	// DB( ac.x _ ac.y _ ab.x _ ab.y );
	return kr( ab, ac );
}

double distLP( int l , pt c){
	pt a = que[0][l][0];
	pt b = que[0][l][1];
	pt ac = c - a;
	pt ab = b - a;
	double fac = (dot(ac,ab) / dot(ab,ab));
	pt proj =  a + (fac * ab);	
	return !(c-proj);
}


int main(){
	int cn = 1;
	while( scanf("%d%d%d", n, n +1, &q ) > 0 ){
		if( !(n[0]||n[1]||q) ) break;
		REP(kk,0,2) REP(i,0,n[kk]){
			double x, y;
			scanf("%lf%lf", &x, &y);
			in[kk][i] = pt(x, y );
		}
		REP(i,0,q) REP(j,0,3){
			double A, B, C;
			scanf("%lf%lf%lf", &A, &B, &C);
			if( fabs( B ) > EPS ){
				que[i][j][0] = pt( 0, -C / B);
				que[i][j][1] = pt( 1, - (C + A) / B);
			} else {
				que[i][j][0] = pt( -C / A, 0 );
				que[i][j][1] = pt( - (C + B) / A , 1 );
			}		
		}
		
		REP(l,0,3){
			int l2 = (l+1) %3, l3 = (l+2) %3;
			pt inter = interLine( que[0][l2][0], que[0][l2][1], que[0][l3][0], que[0][l3][1] );
			sline[l] = signLine( que[0][l][0], que[0][l][1], inter);
		}
		REP(kk,0,2){
			REP(l,0,3){
				REP(i,0,n[kk]){				
					dist[kk][l][i] = distLP( l, in[kk][i]);	
					double spoint = signLine( que[0][l][0], que[0][l][1], in[kk][i] );
					if( spoint * sline[l] < 0 ) dist[kk][l][i] *= -1;					
				}
				sort( dist[kk][l] , dist[kk][l] + n[kk] );				
			}
		}
		printf("Battle Field %d:\n", cn++);
		REP(qn,0,q){
			printf("Query %d:",qn+1 );
			REP(kk,0,2){
				
				int resp = 0; int lol = 0;				
				REP(l,0,3){		
					double d = distLP( l ,  que[qn][l][0] );
					double spoint = signLine( que[0][l][0], que[0][l][1], que[qn][l][0] );
					if( spoint * sline[l] < 0 ) d *= -1;
					
					
					int sizel = lower_bound( dist[kk][l] , dist[kk][l] + n[kk], d - EPS ) - dist[kk][l];				
					
					int l2 = (l+1) %3, l3 = (l+2) %3;
					pt inter = interLine( que[qn][l2][0], que[qn][l2][1], que[qn][l3][0], que[qn][l3][1] );					
					double nslineVal = signLine( que[qn][l][0], que[qn][l][1], inter);
					bool changed = (sline[l] * nslineVal < 0);
					if( (l ==0 && !changed) || ( l > 0 && changed) ) sizel = n[kk] - sizel;																
					if( l == 0) resp += sizel;
					else resp -= sizel;					
					
				}				
				printf(" %d", resp);
			}
			puts("");
		}
	}
	
	return 0;
}