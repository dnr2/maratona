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

struct WinterAndPresents {
    long long getNumber(vector <int> apple, vector <int> orange) {
        return long long(0);
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
			int apple[]               = {1};
			int orange[]              = {1};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int apple[]               = {1, 2, 0, 3};
			int orange[]              = {4, 5, 0, 6};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int apple[]               = {2, 2, 2};
			int orange[]              = {2, 2, 2};
			long long expected__      = 16;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int apple[]               = {7, 4, 5};
			int orange[]              = {1, 10, 2};
			long long expected__      = 46;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int apple[]               = {1000000};
			int orange[]              = {1000000};
			long long expected__      = 1000002000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
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
It's winter time!
You need to prepare a Christmas gift for your friend.




You have several bags arranged in a row.
The bags only contain apples and oranges.
You are given an vector <int> apple and an vector <int> orange.
For each i, the i-th element of apple represents the number of apples in the i-th bag, and the i-th element of orange represents the number of oranges in the i-th bag.




You will choose the gift using the following procedure:
First, you will choose any positive integer X such that there are at least X pieces of fruit in each bag.
Then, you will take exactly X pieces of fruit out of each bag, and combine all the fruit into one present.
Return the number of different gifts that may be produced by following the given procedure.
(Two gifts are considered different if they contain a different number of apples or a different number of oranges.)


DEFINITION
Class:WinterAndPresents
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long getNumber(vector <int> apple, vector <int> orange)


CONSTRAINTS
-apple will contain between 1 and 50 elements, inclusive.
-orange will contain between 1 and 50 elements, inclusive.
-apple and orange will contain the same number of elements.
-Each element of apple and orange will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{1}
{1}

Returns: 3

Three different presents are possible in this case: 


0 apples and 1 orange


1 apple and 0 oranges


1 apple and 1 orange



1)
{1, 2, 0, 3}
{4, 5, 0, 6}

Returns: 0

As there is an empty bag, there is no way to choose the present.

2)
{2, 2, 2}
{2, 2, 2}

Returns: 16



3)
{7, 4, 5}
{1, 10, 2}

Returns: 46



4)
{1000000}
{1000000}

Returns: 1000002000000



**/
// END CUT HERE
