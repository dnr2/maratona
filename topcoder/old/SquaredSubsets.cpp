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

struct SquaredSubsets {
    long long countSubsets(int n, vector <int> x, vector <int> y) {
		ll ret = 0;
		ll one = 1;
		REP(i,0,x.size()){
			int p = 0;
			REP(j,0,x.size()){
				if( i == j ) continue;
				if( x[j]-x[i] <= n && y[j]-y[i] <= n) p++;
			}
			ret += one << (p-1);
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
			int n                     = 5;
			int x[]                   = {-5,0,5};
			int y[]                   = {0,0,0};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int x[]                   = {-5,0,5};
			int y[]                   = {0,0,0};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 100000000;
			int x[]                   = {-1,-1,-1,0,1,1,1};
			int y[]                   = {-1,0,1,1,-1,0,1};
			long long expected__      = 21;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5;
			int x[]                   = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0};
			int y[]                   = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5};
			long long expected__      = 66;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 1;
			int x[]                   = {-1,0};
			int y[]                   = {0,0};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
Given a set of points in the XY plane and an integer n, a subset P of those points is called n-squared if it is not empty and there exists a square of side n in the XY plane with its sides parallel to the axes such that a point from the given set of points is in P if and only if it is contained within the square. A point lying on a side or a vertex of the square is considered to be contained in it.

You will be given n as explained in the input. You will also be given two vector <int>s x and y such that the coordinates of point i are (x[i],y[i]). Return the number of n-squared subsets in the input set described by x and y.


DEFINITION
Class:SquaredSubsets
Method:countSubsets
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long countSubsets(int n, vector <int> x, vector <int> y)


CONSTRAINTS
-n will be between 1 and 100000000 (10^8), inclusive.
-x and y will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between -100000000 (-10^8) and 100000000 (10^8), inclusive.
-All described points will be different.


EXAMPLES

0)
5
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are squared: {(-5,0)}, {(0,0)}, {(5,0)}, {(-5,0),(0,0)}, {(0,0),(5,0)}.

1)
10
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are squared: {(-5,0)}, {(5,0)}, {(0,0),(5,0)}, {(-5,0),(0,0)}, {(-5,0),(0,0),(5,0)}.

2)
100000000
{-1,-1,-1,0,1,1,1}
{-1,0,1,1,-1,0,1}

Returns: 21



3)
5
{5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}
{0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}

Returns: 66



4)
1
{-1,0}
{0,0}

Returns: 3



**/
// END CUT HERE
