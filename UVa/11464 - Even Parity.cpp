//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2459
//#tag ad hoc
//#tag brute force
//#sol por brute force você testa todas as possibilidades de mudar de 0 para 1 ou continuar com 0,
//mas apenas para a primeira linha, depois disso você checa se essa configuração é válida, e caso
//positivo calcula o custo total de tal configuração.

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
// #define umap unordered_map

using namespace std;

int arr[17][17];
int f[17][17];

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int t,n,caso = 1; cin >> t;
	
	while(t--){
		scanf("%d", &n);
		cl(arr);
		fr(i,0,n) fr(j,0,n) scanf("%d", &arr[i][j] );
		int cont = 0, resp = 100000, aux;
		fr(i,0,n) if( !arr[0][i] ) cont++;
		if( n > 1){
			fr(i,0,(1<<cont)+1){
				cl(f); bool bug = false; int val = 0;
				aux = i; 
				fr(j,0,n){
					if( arr[0][j] == 1) f[0][j] = 1;
					else {
						f[0][j] = aux & 1;
						if( aux & 1) val++; 
						aux >>= 1;
					}
				}
				fr(j,1,n){
					fr(k,0,n){
						int sum = (( k > 0)? f[j-1][k-1] : 0) 
							+ ((j>1)?f[j-2][k]:0) + ((k<n-1) ? f[j-1][k+1]:0);
						if( (sum & 1) == 0 && arr[j][k] ){
							bug = true; goto fim;
						}
						else if( (sum & 1) == 1 && arr[j][k] == 0) f[j][k] = 1, val++;
						else if( arr[j][k] == 1) f[j][k] = 1;
					}
				}
				fr(k,0,n) {
					int sum = (( k > 0)? f[n-1][k-1] : 0) + f[n-2][k] + ((k<n-1)?f[n-1][k+1]:0);
					if( sum & 1) bug = true;
				}
				fim: if( bug) continue;
				resp = min( val , resp);
			}
		} else {
			resp = 0;
		}
		if( resp == 100000) resp = -1;
		printf("Case %d: %d\n", caso++, resp);
	}
	
	
	
	return 0;
}