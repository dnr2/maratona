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

struct TwoNumberGroupsEasy {
    int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
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
			int A[]                   = {1,2,3,4};
			int numA[]                = {2,1,1,1};
			int B[]                   = {5,6,7,8};
			int numB[]                = {1,1,1,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {5,7};
			int numA[]                = {1,1};
			int B[]                   = {12,14};
			int numB[]                = {1,1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {100};
			int numA[]                = {2};
			int B[]                   = {1};
			int numB[]                = {1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1};
			int numA[]                = {1};
			int B[]                   = {1};
			int numB[]                = {1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {5};
			int numA[]                = {1};
			int B[]                   = {6};
			int numB[]                = {1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160};
			int numA[]                = {8941,4607,1967,2401,495,7654,7078,4213,5485,1026};
			int B[]                   = {878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799};
			int numB[]                = {242,6538,7921,2658,1595,3049,655,6945,7350,6915};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int numA[]                = ;
			int B[]                   = ;
			int numB[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoNumberGroupsEasy().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(numA, numA + (sizeof numA / sizeof numA[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(numB, numB + (sizeof numB / sizeof numB[0])));
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
A multiset is the same thing as a set, with the difference that a multiset can contain multiple copies of the same element.
For example, {1,1,1,2,3} is a multiset that contains three 1s, one 2, and one 3.



The distance between two multisets is the smallest total number of elements we need to erase from them in order to make them equal.
For example, the distance between {1,1,2,2,3} and {1,2,2,4} is 3.
Note that we can compute distance as follows:
For each value, we count its occurrences in the first multiset, we count its occurrences in the second multiset, and we write down the difference between those two counts.
The distance is then equal to the sum of all values we wrote down.



If S is a multiset, then (S modulo M) is the multiset of all values (x modulo M) where x belongs to S.
For example, if S = {11,12,13,21,22} and M = 10, then (S modulo M) = {1,2,3,1,2} = {1,1,2,2,3}.



You have two multisets called A and B.
The first multiset is described by the vector <int>s A and numA.
For each valid i, the multiset contains numA[i] copies of the value A[i].
The second multiset is described by the vector <int>s B and numB in the same way.



We are now looking for a positive integer M with the following properties:
M must be greater than 1, and the distance between (A modulo M) and (B modulo M) must be as small as possible.
Compute and return the smallest possible distance.


DEFINITION
Class:TwoNumberGroupsEasy
Method:solve
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB)


CONSTRAINTS
-A and B will each contain between 1 and 10 elements, inclusive.
-All elements of A will be distinct.
-All elements of B will be distinct.
-The number of elements in numA will be the same as the number of elements in A.
-The number of elements in numB will be the same as the number of elements in B.
-All elements of A and B will be between 1 and 1,000,000,000, inclusive.
-All elements of numA and numB will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{1,2,3,4}
{2,1,1,1}
{5,6,7,8}
{1,1,1,2}

Returns: 2

This input describes the multisets A = {1,1,2,3,4} and B = {5,6,7,8,8}.
For M=2, we have (A modulo M) = {0,0,1,1,1} and (B modulo M) = {0,0,0,1,1}.
The distance between these two multisets is 2, and that is the best we can get.

1)
{5,7}
{1,1}
{12,14}
{1,1}

Returns: 0

The optimal solution is obtained for M = 7.

2)
{100}
{2}
{1}
{1}

Returns: 1



3)
{1}
{1}
{1}
{1}

Returns: 0



4)
{5}
{1}
{6}
{1}

Returns: 2



5)
{733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160}
{8941,4607,1967,2401,495,7654,7078,4213,5485,1026}
{878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799}
{242,6538,7921,2658,1595,3049,655,6945,7350,6915}

Returns: 7



**/
// END CUT HERE
