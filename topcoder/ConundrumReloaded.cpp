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

int ans[100], tmp[100], sz;

int solve( int b){
	int resp = 100;
	int e = b;
	while( (e+1)%sz != b && ans[(e+1)%sz] != -1) e = (e+1)%sz;
	REP(ini,0,2){
		memset( tmp , -1, sizeof(tmp));
		tmp[b] = ini; int sum = ini, cur = b;
		while(true){			
			tmp[(cur+1)%sz] = tmp[cur] ^ ans[cur];
			if( (cur+1)%sz != b ) sum += tmp[cur] ^ ans[cur];
			if( cur == e ) break;
			cur = (cur+1)%sz;
		}
		if( tmp[b] == ini) resp = min(resp,sum);
	}
	return resp;
}

struct ConundrumReloaded {
    int minimumLiars(string answers) {
		sz =answers.size();
		bool qmark = false;
		REP(i,0,sz){
			if( answers[i] == '?') ans[i] = -1, qmark = true;
			else ans[i] = answers[i] == 'H'?0:1;
		}
		int resp = 100;
		if( qmark ){
			resp = 0;
			REP(i,0,sz){
				if( ans[i] == -1 && ans[(i+1)%sz] != -1) resp += solve( (i+1)%sz ) ;
			}
		} else {
			resp = solve(0);
		}
        return resp == 100?-1:resp;
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
			string answers            = "LLH";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string answers            = "?????";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string answers            = "LHLH?";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string answers            = "??LLLLLL??";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string answers            = "LLL";
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string answers            = "?L?L?H?H?HH?LH??HL?LL?HH?L?L?H?H?HH?LH??HL?L";
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string answers            = "?L?H?L";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string answers            = "L?LL?L";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 8: {
			string answers            = "LHL";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ConundrumReloaded().minimumLiars(answers);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
// Once upon a time, N people sat around a circle. They were numbered 0 through N-1 in counter-clockwise order. Each person was either a honest person or a liar. A honest person always tells the truth, a liar always lies. You asked some of them (possibly all or none) whether the person sitting to the right of them is a liar. You are given their answers in a string answers with N characters. For each i, character i of answers is one of the following:


'L' if person i said that person (i+1) is a liar,
'H' if person i said that person (i+1) is a honest person,
'?' if you didn't ask person i.

(Above, (i+1) is considered modulo N. That is, person N-1 is talking about person 0.)

You are given the string answers. If there is at least one possible combination of honest people and liars that is consistent with answers, return the smallest possible number of liars. Else return -1.

DEFINITION
Class:ConundrumReloaded
Method:minimumLiars
Parameters:string
Returns:int
Method signature:int minimumLiars(string answers)


CONSTRAINTS
-answers will contain between 2 and 50 characters, inclusive.
-Each character in answers will be 'L', 'H' or '?'.


EXAMPLES

0)
"LLH"

Returns: 1

According to the input:

Person 0 says that person 1 is a liar.
Person 1 says that person 2 is a liar.
Person 2 says that person 0 is a honest person.

Clearly, they cannot all be honest, so there is at least one liar. It is possible that person 1 is liar and the other two are honest. Hence, the smallest possible number of liars is one.

(Note that it is also possible that person 1 is honest and the other two are liars.)

1)
"?????"

Returns: 0

Nobody told us anything. It is possible that everybody is honest.

2)
"LHLH?"

Returns: 2

If person #1 and person #2 are liars, then the answers would be "LHLHH". This is consistent with the answers we received.

3)
"??LLLLLL??"

Returns: 3



4)
"LLL"

Returns: -1

Each of the 8 possible combinations of (liar / honest person) will lead to a contradiction.

**/
// END CUT HERE
