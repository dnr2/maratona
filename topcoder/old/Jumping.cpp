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
#define EPS 1e-5
#define INF 1e9

struct Jumping {
    string ableToGet(int x, int y, vector <int> jumpLengths) {
		
		int sz = jumpLengths.size();
		sort( jumpLengths.begin() , jumpLengths.end());		
		double dist = sqrt( pow( (double) x, 2) + pow( (double) y, 2));			
		if( sz == 1 ){
			if( fabs( dist - jumpLengths[0] ) < EPS ) return "Able";			 
		} else {	
			REP(j,0,sz-1){
				double sum1 = 0, sum2 = 0;	
				REP(i,0,j+1) sum1 += jumpLengths[i];
				REP(i,j+1,sz) sum2 += jumpLengths[i];
				// db( sum1 _ sum2 _ dist);
				double arr[3] = {sum1, sum2, dist};
				sort( arr, arr + 3);
				if( arr[0] + arr[1] > arr[2] ) return "Able";
			}
		}
		return "Not able";	
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x                     = 5;
			int y                     = 4;
			int jumpLengths[]         = {2, 5};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {4};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {6};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 0;
			int y                     = 1;
			int jumpLengths[]         = {100, 100};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 300;
			int y                     = 400;
			int jumpLengths[]         = {500};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,10};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,100};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
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
// Frog Suwako lives on a two-dimensional plane.
She likes to jump.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, y).
You are given the ints x and y.



Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths.
You are given these lengths in a vector <int> jumpLenghts.
For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.



Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths.
Otherwise, return "Not able".

DEFINITION
Class:Jumping
Method:ableToGet
Parameters:int, int, vector <int>
Returns:string
Method signature:string ableToGet(int x, int y, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000 and 1,000, inclusive.
-y will be between -1,000 and 1,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.


EXAMPLES

0)
5
4
{2, 5}

Returns: "Able"

One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).

1)
3
4
{4}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.

2)
3
4
{6}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.

3)
0
1
{100, 100}

Returns: "Able"

Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).

4)
300
400
{500}

Returns: "Able"



5)
11
12
{1,2,3,4,5,6,7,8,9,10}

Returns: "Able"



6)
11
12
{1,2,3,4,5,6,7,8,9,100}

Returns: "Not able"



**/
// END CUT HERE
