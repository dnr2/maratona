#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a), __ = (b); i < __; ++i)
#define frr(i,a,b)  for(int i = (a), __ = (b); i >= __; --i)
#define cl(a, b) memset(a, b, sizeof a)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double DINF = 1e15;

 
int cmp(double a, double b=0.0) {
    if(fabs(a-b)<eps) return 0;
    if(a<b) return -1;
    return 1;
}
 
struct pt {
    double x, y;
 
    pt() {}
    pt(double x, double y) : x(x), y(y) {}
 
    pt operator + (const pt &rhs) const {
        return pt(x+rhs.x, y+rhs.y);
    }
 
    pt operator - (const pt &rhs) const {
        return pt(x-rhs.x, y-rhs.y);
    }
 
    pt operator * (const double &k) const {
        return pt(x*k, y*k);
    }
 
    pt operator / (const double &k) const {
        return pt(x/k, y/k);
    }
 
    double operator * (const pt &rhs) const {
        return x*rhs.x+y*rhs.y;
    }
 
    double operator % (const pt &rhs) const {
        return x*rhs.y-y*rhs.x;
    }
} pivot;
 
bool parallel(pt a, pt b, pt c, pt d) {
    return !cmp(fabs((b-a)%(c-d)));
}
 
pt lineInter(pt a, pt b, pt c, pt d) {
    b=b-a; d=c-d; c=c-a;
    return a+b*(c%d)/(b%d);
}
 
struct chimney {
    pt p;
    char t;
 
    chimney() {}
    chimney(pt p, char t) : p(p), t(t) {}
 
    bool operator < (const chimney &rhs) const {
        return cmp((p-pivot)%(rhs.p-pivot)) < 0;
    }
} in[110];
 
typedef pair<pt,pt> seg;
 
bool cmpDouble(double a, double b) {
    return !cmp(a,b);
}
 
char line[110];
 
bool valid(int m) {
    sort(in,in+m);
    fr(i,0,m) if(line[i]!=in[i].t) return 0;
    return 1;
}
 
vector<double> keyPts;
vector< pair<double,double> > ans;
 
void printChar(double d){
    if(cmp(d, -DINF) < 0 || cmp(d, DINF) > 0) printf("*");
    else printf("%.6lf", d);
}
 
void printPair(int idx) {
    printChar(ans[idx].st);
    printf(" ");
    printChar(ans[idx].nd);
}
 
char straux[10];
 
int main(){
    int m;
    while(scanf("%d", &m) == 1) {
        keyPts.clear();
        ans.clear();
        scanf("%s", line);
        fr(i,0,m) {
            char t; double x, y; 
            scanf("%s %lf %lf", straux, &x, &y);
			t = straux[0];
            in[i] = chimney(pt(x,y), t);
        }
        seg Ox = mp(pt(0,0), pt(1,0));
        //cout << parallel(pt(1,1), pt(2,1), pt(0,0), pt(1,0)) << endl;
        fr(i,0,m)
            fr(j,i+1,m)
                if(!parallel(in[i].p, in[j].p, Ox.st, Ox.nd))
                    keyPts.pb(lineInter(in[i].p, in[j].p, Ox.st, Ox.nd).x);
        if((int)keyPts.size() == 0) {
            pivot = pt(0,0);
            if(valid(m)) printf("1\n* *\n\n");
            else printf("0\n\n\n");
            continue;
        }
        sort(keyPts.begin(), keyPts.end());
        int tam = unique(keyPts.begin(), keyPts.end(), cmpDouble)-keyPts.begin();
        keyPts.resize(tam);
        fr(i,0,tam+1) {
            if(!i) {
                pivot = pt(keyPts[0]-10.0, 0);
                if(valid(m)) ans.pb(mp(-DINF - 10, keyPts[0]));
            } else if(i==tam) {
                pivot = pt(keyPts[i-1]+10.0, 0);
                if(valid(m)) ans.pb(mp(keyPts[i-1], DINF + 10));
            } else {
                pivot = pt((keyPts[i-1]+keyPts[i])/2.0, 0);
                if(valid(m)) ans.pb(mp(keyPts[i-1], keyPts[i]));
            }
        }
        printf("%d\n", (int)ans.size());
        if((int)ans.size() == 0) printf("\n");
        else {
            fr(i,0,(int)ans.size()-1) {
                printPair(i);
                printf(" ");
            }
            printPair((int)ans.size()-1);
            printf("\n");
        }
		puts("");
    }
    return 0;
}