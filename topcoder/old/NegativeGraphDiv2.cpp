#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define EPS 1e-9
#define INF 1e9

ll w[52][1002];

struct NegativeGraphDiv2 {
    long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		ll inf = 1; inf = inf << 62; int E = s.size();
		REP(i,0,52) REP(j,0,1002) w[i][j] = inf;
		REP(i,0,1002) w[1][i] = 0;
		REP(i,0,charges+1){
			REP(j,0,N+1){
				REP(k,0,E){					
					if( w[s[k]][i] + weight[k] < w[t[k]][i]){	
						w[t[k]][i] = w[s[k]][i] + weight[k];						
					}
					if( w[s[k]][i] - weight[k] < w[t[k]][i+1]){
						w[t[k]][i+1] = w[s[k]][i] - weight[k];
					}
				}
			}
		}
		ll ret = inf;
		REP(i,0,charges+1){ ret = min( ret, w[N][i]); }
        return ret;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 3;
			int s[]                   = {1,1,2,2,3,3};
			int t[]                   = {2,3,1,3,1,2};
			int weight[]              = {1,5,1,10,1,1};
			int charges               = 1;
			long long expected__      = -9;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1;
			int s[]                   = {1};
			int t[]                   = {1};
			int weight[]              = {100};
			int charges               = 1000;
			long long expected__      = -100000;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int s[]                   = {1,1,2};
			int t[]                   = {2,2,1};
			int weight[]              = {6,1,4};
			int charges               = 2;
			long long expected__      = -9;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 2;
			int s[]                   = {1};
			int t[]                   = {2};
			int weight[]              = {98765};
			int charges               = 100;
			long long expected__      = -98765;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int N                     = 50;
			int s[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 35, 37, 38, 39, 40, 41, 42, 43, 42, 44, 45, 46, 45};
			int t[]                   = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 1, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 23, 37, 38, 39, 40, 41, 42, 43, 37, 44, 45, 46, 44, 50};
			int weight[]              = {99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 99998, 0, 99997, 99997, 99997, 99997, 99997, 99997, 99997, 0, 92734, 92734, 92734, 0};
			int charges               = 1000;
			long long expected__      = -99991587;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		} 
/*      case 5: {
			int N                     = ;
			int s[]                   = ;
			int t[]                   = ;
			int weight[]              = ;
			int charges               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int s[]                   = ;
			int t[]                   = ;
			int weight[]              = ;
			int charges               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NegativeGraphDiv2().findMin(N, vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])), charges);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Nancy has a directed graph with N vertices and E edges.
The vertices are numbered 1 through N.
Each edge of the graph has a positive integer weight.
This graph is described by three vector <int>s with E elements each: s, t, and weight.
For each valid i, the graph contains an edge from s[i] to t[i], and its weight is weight[i].
Note that Nancy's graph may contain multiple edges with the same start and end.
It may also contain self-loops.



Nancy is currently standing in the vertex 1.
She can reach other vertices by moving along the edges.
The cost of using an edge is equal to its weight.
Nancy's goal is to reach the vertex N and to minimize the total cost of doing so.



Nancy has a special power she can use to make her travels cheaper.
Whenever she traverses an edge, she can use that special power to make the weight of that edge temporarily negative.
You are given an int charges: the number of times Nancy can use her special power.
Each use of the special power only works for one traversal of an edge.
Nancy can traverse each edge arbitrarily many times.
Each time she traverses an edge, she may use her special power, if she still has some charges left.



Compute and return the minimal total cost of Nancy's journey.


DEFINITION
Class:NegativeGraphDiv2
Method:findMin
Parameters:int, vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-E will be between 1 and 2500, inclusive.
-s, t, weight will each contain exactly E elements.
-s and t will only contain numbers between 1 and N, inclusive.
-There will be a path from node 1 to node N.
-weight will contain numbers between 0 and 100,000, inclusive. 
-charges will be between 0 and 1,000, inclusive.


EXAMPLES

0)
3
{1,1,2,2,3,3}
{2,3,1,3,1,2}
{1,5,1,10,1,1}
1

Returns: -9

The optimal path for Nancy is 1->2->3, and using her single charge on the last edge.

1)
1
{1}
{1}
{100}
1000

Returns: -100000

The graph may contain self-loops. Here, the optimal solution is that Nancy uses the self-loop 1,000 times, each time using her special power to change its cost from 100 to -100.

2)
2
{1,1,2}
{2,2,1}
{6,1,4}
2

Returns: -9

There can be multiple edges between vertices.

3)
2
{1}
{2}
{98765}
100

Returns: -98765

Nancy may not be able to use all her charges.

**/
// END CUT HERE
