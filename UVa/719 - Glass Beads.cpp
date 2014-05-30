//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660
//#tag suffix tree
//#tag string
//#sol create the string xx, where x is the input string, generate a suffix tree and get the first substring in xx that has size |x|

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
// #include <unordered_map>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
// #define umap unordered_map

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str();}

int my_length;

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
		SuffixTree* tree;
		Node(SuffixTree* tree) : tree(tree) {}
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

	int resp(){
		return rec( getRoot());
	}
	int rec(Node * node){	
		if( node->b - node->a >= my_length && node->a < my_length) return node->a;
		if( node->edges.size() == 0){
			return -1;
		} else {
			int ret = -1;
			for( map<char,Edge*>::iterator it = node->edges.begin(); it != node->edges.end(); it++){
				int aux = rec( it->S->end );
				if( aux >= 0 && ret == -1) ret = aux;
			}
			return ret;
		}
	}
};

ostream& operator<<(ostream& out, SuffixTree::Edge& e) { return out << e.tree->str.substr(e.a,e.size()); }
ostream& operator<<(ostream& out, SuffixTree::Node& n) { return out << n.tree->str.substr(n.a,min(n.b,n.tree->last)-n.a+1); }	
ostream& operator<<(ostream& out, SuffixTree& t) { return t.prettyFormat(out, t.root, 0); }


const int MAXN = 30000;
char str[MAXN];

int main(){
	int T; cin >> T;
	while( T--){
		scanf("%s", str);
		
		my_length = strlen( str);
		REP(i,0,my_length){
			str[my_length+i] = str[i];
		}		
		//str[my_length*2] = '$';
		//str[my_length*2+1] = 0;
		str[my_length*2] = 0;
		SuffixTree t(str);
		// cout << str << endl;
		// cout << t << endl;
		printf("%d\n", (t.resp() + 1));;
	}
	return 0;
}