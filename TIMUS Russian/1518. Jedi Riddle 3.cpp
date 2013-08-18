//http://acm.timus.ru/problem.aspx?space=1&num=1518
//#tag fast

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<queue>

#define F first 
#define S second
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define PI acos(-1)
#define pb push_back
#define fr(i,j,k) for(int i=j;i<k;++i)
#define cl(x) memset(x,0,sizeof(x))
#define ll long long

using namespace std;

ll mod;

struct mat{
	int len;
	ll m[100][100];
	mat(int len = 100): len(len){
		// cout<< "aqui----------"<< endl;
		fr(i,0,len ) fr(j,0,len) m[i][j] = 0;
		// cout<< "lol"<< endl;
	}
	const mat operator * (const mat & in){
		// cout<< "aqui2"<< endl;
		mat ret(len);
		fr(i,0,len){
			fr(j,0,len){
				fr(k,0,len){
					ret.m[i][j] += m[i][k] * in.m[k][j];
					ret.m[i][j] %= mod;
				}
			}
		}
		return ret;
	}
	~mat(){
		free(m);
	}
};
int n, x;

mat fast( mat a, int b){
	mat x(n); fr(i,0,n) x.m[i][i] = 1;
	mat y = a;
	while( b){
		if( b & 1) x = x * y; 
		y = y * y; b /= 2;
	}
	return x;
}

ll ink[101];
ll inc[101];

int main(){
	
	cin >> n >> x >> mod;
	mat matrix(n);
	fr(i,0,n) cin >> ink[n-i-1];
	fr(i,0,n) cin >> inc[n-i-1];
	fr(i,1,n) matrix.m[i][i-1] = 1;
	fr(i,0,n) matrix.m[0][i] = inc[i];
	mat aux(n);
	aux = fast( matrix, x - n);
	ll resp = 0;
	fr(i,0,n) resp += aux.m[0][i] * ink[i], resp %= mod;
	cout << resp << endl;
	return 0;
}
