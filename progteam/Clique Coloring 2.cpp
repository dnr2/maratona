#include <bits/stdc++.h>
#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define st first
#define nd second

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

ll arr[5];

int main() {
    int n; 
    while (scanf("%d", &n) == 1) {
    ll sum = 0;
    int numDois = 0;
    int qnt3 = 0;
    fr(i,0,n) {
        scanf("%lld", &arr[i]);
        numDois += (arr[i]==2);
        qnt3 += arr[i] == 3;
        sum += arr[i];
    }
    if(numDois==5) puts("4");
    else if(numDois==4) {
        if(n==4) puts("4");
        else printf("%lld\n", sum-7);
    } else if(numDois==3) {
        if(n==3) puts("3");
        else if(n==4) printf("%lld\n", sum-5);
        else printf("%lld\n", sum-7);
    } else {
        if(n==2) sum -= 1;
        else if(n==3) sum -= 3;
        else if(n==4) sum -= 5;
        else if(n==5) sum -= 8;        
        if(n==5 && numDois==2) sum++;
        if (qnt3 == 5) --sum;
        printf("%lld\n", sum);
    }    
    }
    return 0;
}
