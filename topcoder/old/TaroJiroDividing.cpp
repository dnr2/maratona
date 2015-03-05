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

struct TaroJiroDividing {
    int getNumber(int A, int B) {
		set<int> a, b;
		a.insert( A );
		while( (A & 1) == 0){
			A /=2;
			a.insert( A );
		}
		b.insert( B );
		while( (B & 1) == 0){
			B /=2;
			b.insert( B );
		}
		int resp = 0;
		for( set<int>::iterator it = a.begin(); it != a.end(); it++){
			if( b.count(*it) > 0){
				resp++;
			}
		}
        return resp;
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
			int A                     = 8;
			int B                     = 4;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 4;
			int B                     = 7;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 12;
			int B                     = 12;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 24;
			int B                     = 96;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 1000000000;
			int B                     = 999999999;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int A                     = 1;
			int B                     = 1;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int A                     = 10;
			int B                     = 20;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroJiroDividing().getNumber(A, B);
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
The dividing game is played as follows:
You start by taking a clean sheet of paper and writing down some positive integer.
Then you repeat the following process:
Let X be the last integer you wrote.
If X is odd, the game ends.
Otherwise, divide X by 2 and write down the result.




For example, if you start the game by writing 12 you will then write 12/2 = 6, followed by 6/2 = 3, and as 3 is odd, the game ends there.
Your paper now contains the numbers 12, 6, and 3.




Cat Taro has just played the game starting with the integer A.
Jiro has also played the game but he started with the integer B.
You are given the ints A and B.
Return the number of integers that were written both by Taro and by Jiro.


DEFINITION
Class:TaroJiroDividing
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int A, int B)


CONSTRAINTS
-A and B will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
8
4

Returns: 3

Taro will write the integers {8,4,2,1}. Jiro will write {4,2,1}. The three integers written by both of them are 4, 2, and 1.

1)
4
7

Returns: 0



2)
12
12

Returns: 3



3)
24
96

Returns: 4



4)
1000000000
999999999

Returns: 0



**/
// END CUT HERE
