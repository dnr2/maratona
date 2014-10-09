//http://acm.timus.ru/problem.aspx?num=1995

// #include <bits/stdc++.h> // not sure if this works on the judge machine
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FILL(x,v) memset(x,v,sizeof(x))

int v[100100];

int main(){
	int n, k, p;
	scanf("%d %d",&n,&k);
	scanf("%d",&p);
	
	for(int i=0; i<=n; i++) v[i]=1;
	ll soma=n-k;
	int qatual=n-k;
	int qantigo=0;
	int menores=0;
	int atual=1;
	for(int i=n-k; i<n; i++)
	{
		if(menores*100>=p*i)
		{
			v[i]=atual;
			qatual++;
			soma=soma+atual;
		}
		else{
			atual++;
			v[i]=atual;
			soma=soma+atual;
			menores=menores+qatual;
			qantigo=qatual;
			qatual=1;
		}
	}
	
	cout << soma << endl;
	printf("%d",v[0]);
	for(int i=1; i<n; i++) printf(" %d",v[i]);
	printf("\n");
	return 0;
}