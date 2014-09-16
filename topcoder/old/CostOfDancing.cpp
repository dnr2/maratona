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

struct CostOfDancing {
    int minimum(int K, vector <int> danceCost) {
		int ret = 0;
		sort( danceCost.begin(), danceCost.end());
		REP(i,0,K){
			ret += danceCost[i];			
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
			int K                     = 2;
			int danceCost[]           = {1, 5, 3, 4};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int K                     = 3;
			int danceCost[]           = {1, 5, 4};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int K                     = 1;
			int danceCost[]           = {2, 2, 4, 5, 3};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int K                     = 39;
			int danceCost[]           = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932, 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
			int expected__            = 20431;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int K                     = ;
			int danceCost[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int K                     = ;
			int danceCost[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int K                     = ;
			int danceCost[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CostOfDancing().minimum(K, vector <int>(danceCost, danceCost + (sizeof danceCost / sizeof danceCost[0])));
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
// Gustavo studies at the Byteversity (one of the best universities in Byteland). He's also very keen on dancing, so he decided to enroll at a dance school.

The school offers many different courses, each teaching one dance. Different courses may have different costs. You are given a vector <int> danceCost. The elements of danceCost are the costs of all courses offered at the dance school.

Gustavo would like to learn exactly K of those dances. He is a poor student, so his only priority is to pay as little as possible for the courses.

You are given the int K and the vector <int> danceCost. Compute and return the smallest possible total cost of learning K dances.

DEFINITION
Class:CostOfDancing
Method:minimum
Parameters:int, vector <int>
Returns:int
Method signature:int minimum(int K, vector <int> danceCost)


CONSTRAINTS
-danceCost will contain between 1 and 1,000 elements, inclusive.
-Each element of danceCost will be between 1 and 1,000, inclusive.
-K will be between 1 and the number of elements in danceCost, inclusive.


EXAMPLES

0)
2
{1, 5, 3, 4}

Returns: 4

Gustavo must pay for exactly two out of the four given courses. The cheapest possibility is to pay 1 for one course and then 3 for another course. The total cost is 1+3 = 4.

1)
3
{1, 5, 4}

Returns: 10

Gustavo has no choice here. He has to pay for all three courses, which costs 1+5+4 = 10.

2)
1
{2, 2, 4, 5, 3}

Returns: 2

Among all 5 possible courses he can take, the cheapest one is either the course #0 or course #1 (0-based).

3)
39
{973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801}

Returns: 20431



**/
// END CUT HERE
