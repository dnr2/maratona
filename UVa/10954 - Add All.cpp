//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1895
//#tag priority queue heap 
//#sol usar heap para pegar os dois menores números do conjunto, 
//sempre que somar dois números, colocálos de volta como soma

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
#include <sstream>
#include <climits>

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

struct Num{
	long long  val;
	Num(){}
	Num(long long a):val(a){}
	const bool operator < (const Num & ele) const{
		return val > ele.val;
	}
};

int main(){

	//freopen("a.txt","r",stdin);
	int qtd;
	long long temp;
	while(scanf("%d",&qtd) == 1 && qtd){
		
		priority_queue<Num> heap;
		for(int i=0;i<qtd;i++){
			scanf("%lld", &temp);
			heap.push(Num(temp));
		}
		long long a, b;
		long long soma = 0;
		while(heap.size()>1){
			a = heap.top().val , heap.pop();
			b = heap.top().val , heap.pop();
			soma += (a+b);
			heap.push(Num(a+b));
		}
		cout << soma << endl;
		heap.pop();
	}
	return 0;
}
