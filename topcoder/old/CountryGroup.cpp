#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PII pair<int,int>
#define FT first
#define SD second
#define REP(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define PB push_back
#define PI acos(-1)
#define DB(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define MP make_pair
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define IOFAST() ios_base::sync_with_stdio(0);cin.tie(0)
#define FILL(x,v) memset(x,v,sizeof(x))

struct CountryGroup {
    int solve(vector <int> a) {
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
			int a[]                   = {2,2,3,3,3};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1,1,1,1,1};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {3,3};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {4,4,4,4,1,1,2,2,3,3,3};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {2,1,2,2,1,2};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CountryGroup().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
Some people are sitting in a row.
Each person came here from some country.
You have a theory that people from the same country are all sitting together.
You decided to test this theory.
You asked each person the same question: "How many people from your country (including you) are here?"



You are given a vector <int> a containing their answers.
The answers are given in the order in which the people sit in the row.
(Note that some of the answers may be incorrect.
See the examples for clarification.)



If all the answers are consistent with your theory, return the number of different countries that are present.
(Given that all answers are consistent with the theory, the number of countries can always be uniquely determined.)
Otherwise, return -1.


DEFINITION
Class:CountryGroup
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All elements of a will be between 1 and 100, inclusive.


EXAMPLES

0)
{2,2,3,3,3}

Returns: 2

These answers are consistent with your theory. The first two people are from one country, the other three are from a different country. Thus, there are two countries and the correct return value is 2.

1)
{1,1,1,1,1}

Returns: 5

Here, each person comes from a different country.

2)
{3,3}

Returns: -1

These answers do not correspond to your theory. In particular, they are not even correct: there are only two people but each of them claims that there are three people from their country.

3)
{4,4,4,4,1,1,2,2,3,3,3}

Returns: 5



4)
{2,1,2,2,1,2}

Returns: -1

These answers do not correspond to your theory. It is possible that these are people from four different countries, but even if that were the case, we can tell that people from some countries are not sitting together. For example, consider the leftmost person. According to her answer, there are two people from her country. However, the person sitting next to her cannot be from the same country.

**/
// END CUT HERE
