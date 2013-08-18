//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1572

#include <bits/stdc++.h>

using namespace std;

map<int, int> fact(int x) {
    map<int, int> res;
    while(x%2==0) { x/=2; res[2]++; }
    int c = 3;
    while (c <= sqrt(double(x))+1) {
        if (x%c == 0) x/=c, res[c]++;
        else c+=2;
    }
    if (x>1) res[x]++;
    return res;
}

int phi(int x0) {
    int v = x0;
    map<int,int> m = fact(x0); map<int,int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) v/=(it->first), v*=(it->first-1);
    return v;
}

int n, p[1002];

int main() {
	
	p[2] = 1;
	for (int i = 3; i <= 1000; i++) p[i] = p[i-1] + phi(i);

	int T; scanf("%d", &T); for (int caso = 1; caso <= T; caso++) {
		scanf("%d", &n);
		printf("%d %d %d", caso, n, p[n]*2 + 3);	puts("");
	}
	return 0;
}
