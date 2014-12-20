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

struct ChristmasTreeDecorationDiv2 {
    int solve(vector <int> col, vector <int> x, vector <int> y) {
		int n = col.size(); int m = x.size();
		int ret = 0;
		REP(i,0,m){
			ret += (col[x[i]-1] == col[y[i]-1])?0:1 ;
		}
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int col[]                 = {1,2,3,3};
			int x[]                   = {1,2,3};
			int y[]                   = {2,3,4};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int col[]                 = {1,3,5};
			int x[]                   = {1,3};
			int y[]                   = {2,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int col[]                 = {1,1,3,3};
			int x[]                   = {1,3,2};
			int y[]                   = {2,1,4};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int col[]                 = {5,5,5,5};
			int x[]                   = {1,2,3};
			int y[]                   = {2,3,4};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int col[]                 = {9,1,1};
			int x[]                   = {3,2};
			int y[]                   = {2,1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int col[]                 = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int col[]                 = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int col[]                 = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasTreeDecorationDiv2().solve(vector <int>(col, col + (sizeof col / sizeof col[0])), vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
Christmas is just around the corner, and Alice just decorated her Christmas tree.
There are N stars and N-1 ribbons on the tree.
Each ribbon connects two of the stars in such a way that all stars and ribbons hold together.
(In other words, the stars and ribbons are the vertices and edges of a tree.)



The stars are numbered 1 through N.
Additionally, each star has some color.
You are given the colors of stars as a vector <int> col with N elements.
For each i, col[i] is the color of star i+1.
(Different integers represent different colors.)



You are also given a description of the ribbons: two vector <int>s x and y with N-1 elements each.
For each i, there is a ribbon that connects the stars with numbers x[i] and y[i].



According to Alice, a ribbon that connects two stars with different colors is beautiful, while a ribbon that connects two same-colored stars is not.
Compute and return the number of beautiful ribbons in Alice's tree.


DEFINITION
Class:ChristmasTreeDecorationDiv2
Method:solve
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-The number of elements in col will be exactly N.
-The number of elements in x will be exactly N - 1.
-The number of elements in y will be the same as the number of elements in x.
-All elements of x and y will be between 1 and N, inclusive.
-For each i, the numbers x[i] and y[i] will be different.
-The graph formed by the N-1 ribbons will be connected.


EXAMPLES

0)
{1,2,3,3}
{1,2,3}
{2,3,4}

Returns: 2

There are two beautiful ribbons: the one that connects stars 1 and 2, and the one that connects stars 2 and 3.
The other ribbon is not beautiful because stars 3 and 4 have the same color.

1)
{1,3,5}
{1,3}
{2,2}

Returns: 2



2)
{1,1,3,3}
{1,3,2}
{2,1,4}

Returns: 2



3)
{5,5,5,5}
{1,2,3}
{2,3,4}

Returns: 0



4)
{9,1,1}
{3,2}
{2,1}

Returns: 1



**/
// END CUT HERE
