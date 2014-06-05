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

int getNext(int a){
	REP(i,0,32){
		if( a <= (1<<i)) return (1<<i);
	}
	return 1;
}

struct BoxesDiv2 {
    int findSize(vector <int> candyCounts) {
		sort( candyCounts.begin(), candyCounts.end());
		priority_queue<int> q;
		REP(i,0,candyCounts.size()){
			q.push( -1 * getNext( candyCounts[i]) );
		}
		while(q.size() > 1){
			int a = -q.top(); q.pop();
			int b = -q.top(); q.pop();
			q.push( -1 * getNext( a + b) );
		}
        return -q.top();
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
			int candyCounts[]         = {8,8};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int candyCounts[]         = {5,6};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int candyCounts[]         = {1,7};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int candyCounts[]         = {1,1,13,1,1};
			int expected__            = 32;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int candyCounts[]         = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
			int expected__            = 1024;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int candyCounts[]         = {1,1,1,1,1};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int candyCounts[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int candyCounts[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
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
// Today is Fox Ciel's birthday.
You want to give her a box of candies as a present.

You have candies of several different types.
You are given a vector <int> candyCounts.
Each element of candyCounts is the number of candies of one particular type.

For each non-negative integer i, you have an unlimited supply of boxes with volume 2^i.
That is, you have boxes with volume 1, 2, 4, 8, and so on.

You are going to pack the candies into boxes.
Each type of candies has to be packed into a single box, and you have to use different boxes for different types of candy.
The volume of a box must be greater than or equal to the number of candies it contains.

Once you have each type of candies in a box, you want to pack those boxes into larger boxes, until only one box remains.
You can only pack two boxes at a time.
That is, you can take any two boxes you currently have, get a new box, and put the two old boxes into the new box.
This is possible if and only if the volume of the new box is greater than or equal to the sum of volumes of the two old boxes.
You always get to choose which two boxes you want to pack together, and how large the new box should be.

To summarize:

First, you will pack all the candies into boxes.
Then, you will pack all those boxes into larger boxes, until you are left with a single box that contains everything.


Compute and return the smallest possible volume of the box obtained at the end of packing.


DEFINITION
Class:BoxesDiv2
Method:findSize
Parameters:vector <int>
Returns:int
Method signature:int findSize(vector <int> candyCounts)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-candyCounts will contain between 1 and 100 elements, inclusive.
-Each element of candyCounts will be between 1 and 1000, inclusive.


EXAMPLES

0)
{8,8}

Returns: 16

First, you pack each type of candies into a box with volume 8. Then, you pack the two boxes into a single box with volume 16.

1)
{5,6}

Returns: 16

Even though you have fewer candies than in Example 0, you still have to use boxes with volume 8 (or more) to store them.

2)
{1,7}

Returns: 16

Now you could pack the 1 candy into a smaller box, but it will not help: you still have to use a box with volume 16 to store the two boxes with candies.

3)
{1,1,13,1,1}

Returns: 32



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}

Returns: 1024



**/
// END CUT HERE
