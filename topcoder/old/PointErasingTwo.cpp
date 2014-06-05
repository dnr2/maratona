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

struct PointErasingTwo {
    int getMaximum(vector <int> y) {
        return int(0);
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
			int y[]                   = { 1, 2, 1, 1, 0, 4, 3 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int y[]                   = { 0, 1 };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int y[]                   = { 0, 1, 2, 3, 4 };
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int y[]                   = { 10, 19, 10, 19 };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int y[]                   = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PointErasingTwo().getMaximum(vector <int>(y, y + (sizeof y / sizeof y[0])));
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
// You are given a vector <int> y of length N. 
The values in y describe N points in the plane: 
for each x = 0, 1, ..., N - 1 there is a point at coordinates (x, y[x]). 

Krolik is going to perform the following operation: 

	Choose two of the given points, say A and B, with different y-coordinates. 
	Consider the rectangle with sides parallel to coordinate axes and points A and B in two opposite corners. 
	Erase all points strictly inside the rectangle. 

Return the maximum possible number of points Krolik can erase by a single operation. 


DEFINITION
Class:PointErasingTwo
Method:getMaximum
Parameters:vector <int>
Returns:int
Method signature:int getMaximum(vector <int> y)


NOTES
-A point is strictly inside a rectangle if it is inside the rectangle and does not lie on the border of the rectangle. 


CONSTRAINTS
-y will contain between 2 and 50 elements, inclusive. 
-Each element of y will be between 0 and 50, inclusive. 
-y will contain at least 2 distinct elements. 


EXAMPLES

0)
{ 1, 2, 1, 1, 0, 4, 3 }

Returns: 2

If Krolik chooses A = (1, 2) and B = (4, 0), Krolik can erase two points: (2, 1) and (3, 1).




1)
{ 0, 1 }

Returns: 0

2)
{ 0, 1, 2, 3, 4 }

Returns: 3

3)
{ 10, 19, 10, 19 }

Returns: 0



4)
{ 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }

Returns: 5

**/
// END CUT HERE
