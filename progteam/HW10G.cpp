//
//#tag
//#sol

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
#include <set>
#include <limits>
#include <bitset> 
// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define EPS 1e-9
#define IOFAST ios_base::sync_with_stdio(0);cin.tie(0)
#define mask bitset<200> 

// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

const int MAXN = 200000;
string str;
char buff[MAXN];
int off = 130;
int longest;
int N;


struct SuffixTree
{
    static const int INF = 1<<30;
    int last;
    string str;

    struct Node;
    struct Edge
    {
		int a,b;
		Node *end;
		SuffixTree* tree;
		Edge(int a, int b, Node *end, SuffixTree* tree) : a(a), b(b), end(end), tree(tree) {}
		char getFirst() const { return tree->str[a]; }
		int size() const { return min(tree->last,b)-a+1; }
		friend ostream & operator << (ostream & out, Edge & e);
    };
    struct Node
    {
		map<char,Edge*> edges;
		Node* suffix;
		int a,b;
		bool goodnode;
		SuffixTree* tree;
		Node(SuffixTree* tree) : tree(tree) { goodnode = false; }
		Node() { goodnode = false; }
		void add(Edge* e) { edges[e->getFirst()] = e; }
		Edge* operator[](char c) { return edges[c]; }
		int numChildren() { return edges.size(); }
		friend ostream& operator<<(ostream& out, Node&);
    };
    
    Node *root, *sentinel;

    Node* getRoot() { return root; }
    const string& getStr() const { return str; }
    
    void setPrefix(Node* n, Edge* e, int len)
    {
	map<char,Edge*>::iterator it = n->edges.begin();
	for (; it != n->edges.end(); ++it) 
	{
	    Edge *edge = it->second;
	    setPrefix(edge->end,edge,len+min(edge->b,last)-edge->a+1);
	}
	if (e) { n->b = min(e->b,last); n->a = n->b - len + 1; }
	else { n->a = 0; n->b = -1; }
    }

    Node* testAndSplit(Node* s, int k, int p, char c)
    {
	if (k > p) return s == sentinel ? NULL : (*s)[c] == NULL ? s : NULL;
	Edge* e = (*s)[str[k]];
	if (c == str[e->a+p-k+1]) return NULL;
	Node* r = new Node(this);
	Edge* re = new Edge(e->a+p-k+1,e->b,e->end,this);
	r->add(re);
	Edge* se = new Edge(e->a,e->a+p-k,r,this);
	s->add(se);
	return r;
    }
    Node* canonize(Node* s, int& k, int p)
    {
	if (p < k) return s;
	if (s == sentinel) { s = root; ++k; if (p < k) return s; }
	Edge* e = (*s)[str[k]];
	while (e->b - e->a <= p - k)
	{
	    k = k + e->b - e->a + 1;
	    s = e->end;
	    if (k <= p) e = (*s)[str[k]];
	}
	return s;
    }
    Node* update(Node* s, int& k, int i)
    {
	Node *oldr = root, *r = testAndSplit(s,k,i-1,str[i]);
	while (r)
	{
	    Node* rp = new Node(this);
	    Edge* e = new Edge(i,INF,rp,this);
	    r->add(e);
	    if (oldr != root) oldr->suffix = r;
	    oldr = r;
	    s = canonize(s->suffix,k,i-1);
	    r = testAndSplit(s,k,i-1,str[i]);	    
	}
	if (oldr != root) oldr->suffix = s;
	return s;
    }
    void buildTree()
    {
	root = new Node(this);
	sentinel  = new Node(this);
	root->suffix = sentinel;
	Node* s = root;
	int k = 0;
	last = -1;
	for (int i = 0; i < (int)str.size(); ++i)
	{
	    ++last;
	    s = update(s,k,i);
	    s = canonize(s,k,i);
	}
    }
    int fix(int x) const { return x == INF ? last : x; }
    friend ostream& operator<<(ostream& out, SuffixTree& t);
    ostream& prettyFormat(ostream& out, Node* n, int tab) const
    {
	out << string(tab,' ') << n->a << " " << n->b << " " << "\"" << *n << "\"" << endl;
	map<char,Edge*>::iterator it = n->edges.begin();
	for (; it != n->edges.end(); ++it)
	{
	    Edge* e = it->second;
	    cout << string(tab,' ') << it->first << " : " << *e << " = " << e->a << ',' << fix(e->b) << ',' << e->size() << endl;
	    prettyFormat(out,e->end,tab+2);
	}
	return out;
    }

    SuffixTree(const string& str) : str(str) 
    {
	buildTree();
	setPrefix(root,NULL,0);
    }

	bool resp(){
		rec( getRoot());
		// db( longest);
		return print( getRoot() );
	}
	
	mask rec(Node * node){
		// db( node->a _ node->b );
		if( node->edges.size() == 0){
			if( N == 1){
				longest = max( longest, node->b - node->a + 1);
				node->goodnode = true;
			}
			mask m;
			return m;
		} else {
			mask m;
			for( map<char,Edge*>::iterator it = node->edges.begin(); it != node->edges.end(); it++){						
				REP(i,it->S->a,it->S->b+1){
					if( i < 0 || i >= (int)str.size()) break;					
					int val = ((int) ((unsigned char)str[i]));	
					// db( val );
					if( val >= off){
						m.set(val - off);						
						break;
					}
				}
				mask ret = rec( it->S->end );				
				REP(i,0,N){
					if( ret[i] ) m.set(i);
				}
			}
			// db( m.count());
			if( (int) m.count() >= N/2 + 1){
				longest = max( longest, node->b - node->a + 1);
				node->goodnode = true;
			}
			return m;
		}
	}
	
	bool print(Node * node){	
		bool ret = false;
		if( node->b - node->a + 1 == longest && longest > 0 && node->goodnode){
			REP(i,node->a, node->b+1){
				if( i + 1 == ((int) str.size()) ) continue;
				printf("%c", str[i]);
			}
			puts("");
			ret = true;;
		}
		for( map<char,Edge*>::iterator it = node->edges.begin(); it != node->edges.end(); it++){				
			if( print( it->S->end )) ret = true;
		}
		return ret;
	}
	
};

ostream& operator<<(ostream& out, SuffixTree::Edge& e) { return out << e.tree->str.substr(e.a,e.size()); }
ostream& operator<<(ostream& out, SuffixTree::Node& n) { return out << n.tree->str.substr(n.a,min(n.b,n.tree->last)-n.a+1); }	
ostream& operator<<(ostream& out, SuffixTree& t) { return t.prettyFormat(out, t.root, 0); }

int main(){
	bool first = true;
	while(scanf("%d", &N) > 0 && N){
		longest = 0;
		str = "";
		int sign = off;
		REP(i,0,N){
			scanf("%s", buff);
			string tmp(buff);
			str += tmp;
			str += (char) sign;
			sign++;
		}
		SuffixTree t(str);		
		// cout << t << endl;
		if( first) first = false;
		else puts("");
		if( !t.resp() ) puts("?");
		
	}
	return 0;
}