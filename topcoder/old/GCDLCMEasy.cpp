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

struct GCDLCMEasy {
    string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
        return ;
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
			int n                     = 4;
			int A[]                   = {0,1,2,3};
			int B[]                   = {1,2,3,0};
			int G[]                   = {6,6,6,6};
			int L[]                   = {12,12,12,12};
			string expected__         = "Solution exists";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 5;
			int A[]                   = {0,1,2,3,4};
			int B[]                   = {1,2,3,4,0};
			int G[]                   = {6,6,6,6,6};
			int L[]                   = {12,12,12,12,12};
			string expected__         = "Solution does not exist";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 2;
			int A[]                   = {0,0};
			int B[]                   = {1,1};
			int G[]                   = {123,123};
			int L[]                   = {456,789};
			string expected__         = "Solution does not exist";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 2;
			int A[]                   = {0};
			int B[]                   = {1};
			int G[]                   = {1234};
			int L[]                   = {5678};
			string expected__         = "Solution does not exist";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 6;
			int A[]                   = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
			int B[]                   = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
			int G[]                   = {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7};
			int L[]                   = {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105} ;
			string expected__         = "Solution exists";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 500;
			int A[]                   = {0};
			int B[]                   = {1};
			int G[]                   = {10000};
			int L[]                   = {10000};
			string expected__         = "Solution exists";

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int G[]                   = ;
			int L[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int G[]                   = ;
			int L[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int G[]                   = ;
			int L[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GCDLCMEasy().possible(n, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(G, G + (sizeof G / sizeof G[0])), vector <int>(L, L + (sizeof L / sizeof L[0])));
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
// Your task is to find n positive integers.
We will label them x[0] through x[n-1].



We will give you some information about these integers.
Namely, for some pairs of integers we will tell you both their greatest common divisor (GCD) and their least common multiple (LCM).



You are given the int n and four vector <int>s: A, B, G, and L.
These vector <int>s will all have the same number of elements.
Their meaning is as follows:
For each valid i, the integers x[ A[i] ] and x[ B[i] ] must have the greatest common divisor G[i] and the least common multiple L[i].



Return "Solution exists" (quotes for clarity) if there is at least one way to choose x[0] through x[n-1] so that all requirements are satisfied.
Otherwise, return "Solution does not exist".

DEFINITION
Class:GCDLCMEasy
Method:possible
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L)


NOTES
-The greatest common divisor (GCD) of two positive integers x and y is the largest positive integer z such that z divides x and at the same time z divides y.
-The least common multiple (LCM) of two positive integers x and y is the smallest positive integer z such that x divides z and at the same time y divides z.
-For example, the GCD of 10 and 15 is 5, and the LCM of 10 and 15 is 30.


CONSTRAINTS
-n will be between 1 and 500, inclusive.
-A will contain between 1 and 500 elements, inclusive.
-A and B will contain the same number of elements.
-A and G will contain the same number of elements.
-A and L will contain the same number of elements.
-Each element in A will be between 0 and n-1, inclusive.
-Each element in B will be between 0 and n-1, inclusive.
-For each i, A[i] and B[i] will be different.
-Each element in G will be between 1 and 10,000, inclusive.
-Each element in L will be between 1 and 10,000, inclusive.


EXAMPLES

0)
4
{0,1,2,3}
{1,2,3,0}
{6,6,6,6}
{12,12,12,12}

Returns: "Solution exists"

We have 4 unknown integers: x[0], x[1], x[2], and x[3].
The given A, B, G, and L encode the following information:

The GCD of x[0] and x[1] must be 6 and their LCM must be 12.
The GCD of x[1] and x[2] must be 6 and their LCM must be 12.
The GCD of x[2] and x[3] must be 6 and their LCM must be 12.
The GCD of x[3] and x[0] must be 6 and their LCM must be 12.

There are two valid solutions.
In one of them, x[0] = x[2] = 6 and x[1] = x[3] = 12.

1)
5
{0,1,2,3,4}
{1,2,3,4,0}
{6,6,6,6,6}
{12,12,12,12,12}

Returns: "Solution does not exist"



2)
2
{0,0}
{1,1}
{123,123}
{456,789}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] cannot be 456 and 789 at the same time.

3)
2
{0}
{1}
{1234}
{5678}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] must always be a multiple of their GCD.

4)
6
{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}
{1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}
{2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}
{30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}


Returns: "Solution exists"

There is one solution: {6, 10, 14, 15, 21, 35}.

5)
500
{0}
{1}
{10000}
{10000}

Returns: "Solution exists"



**/
// END CUT HERE
