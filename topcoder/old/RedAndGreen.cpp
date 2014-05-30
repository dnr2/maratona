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

struct RedAndGreen {
    int minPaints(string row) {
		int ret1=0,ret2=0;
		bool f = false;
		for(int i = ((int)row.size())-1; i >=0; i--){
			if( row[i] == 'R') f = true;
			if( f  && row[i] == 'G') ret1++;
		}
		f = false;
		for( int i =0; i < row.size(); i++){
			if( row[i] == 'G') f = true;
			if( f  && row[i] == 'R') ret2++;
		}
        return min( ret1, ret2);
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
			string row                = "RGRGR";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string row                = "RRRGGGGG";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string row                = "GGGGRRR";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string row                = "RGRGRGRGRGRGRGRGR";
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string row                = "RRRGGGRGGGRGGRRRGGRRRGR";
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string row                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string row                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string row                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RedAndGreen().minPaints(row);
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
You have several squares arranged in a single row. Each square is currently painted red or green. You can choose any of the squares and paint it over with either color. The goal is that, after painting, every red square is further to the left than any of the green squares. We want you to do it repainting the minimum possible number of squares.

Squares are numbered from left to right. You will be given the initial arrangement as a string row, such that character i is 'R' if square i is red or 'G' if square i is green. Return the minimum number of repaints needed to achieve the goal.


DEFINITION
Class:RedAndGreen
Method:minPaints
Parameters:string
Returns:int
Method signature:int minPaints(string row)


CONSTRAINTS
-row will contain between 1 and 50 characters, inclusive.
-Each character of row will be either 'R' or 'G'.


EXAMPLES

0)
"RGRGR"

Returns: 2

Paint the squares in the marked positions in the picture below with the opposite color. There are other ways with 2 total paints.

RGRGR
 |  |
RRRGG


1)
"RRRGGGGG"

Returns: 0

There is no need to paint anything.

2)
"GGGGRRR"

Returns: 3

Paint all the red squares green.

3)
"RGRGRGRGRGRGRGRGR"

Returns: 8



4)
"RRRGGGRGGGRGGRRRGGRRRGR"

Returns: 9



**/
// END CUT HERE
