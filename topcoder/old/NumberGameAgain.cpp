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

struct NumberGameAgain {
    long long solve(int k, vector<long long> table) {
		ll ret = 0, sz = table.size();
		vector<ll> out(sz), len(sz);
		sort(table.begin(),table.end());
		REP(i,0,sz){
			ll aux = table[i];
			ll tmp = 0;
			while( aux > 0 ){
				tmp++;
				aux >>= 1;
			}
			len[i] = tmp;
			// db( i _ table[i] _ len[i]);
		}
		REP(i,0,sz){
			if( out[i] ) continue;
			REP(j,i+1,sz){
				if( table[i] == (table[j] >> (len[j] - len[i]) ) ) out[j] = 1;
			}
		}
		ll resp = 0, um = 1;
		REP(i,0,sz){
			// db( i _ table[i] _ out[i]);
			if( !out[i]) {
				ll sum = 0;
				REP(j,0,k-len[i]+1){
					sum += um << (j);
				}
				// db( table[i] _  len[i] _ sum );
				resp += sum;
			}
		}
		// db( resp );
        return (um << k) - 2 - resp;
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
			int k                     = 3;
			long long table[]         = {2, 4, 6};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int k                     = 5;
			long long table[]         = {2, 3};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int k                     = 5;
			long long table[]         = {};
			long long expected__      = 30;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int k                     = 40;
			long long table[]         = {2, 4, 8, 16, 32141531, 2324577, 1099511627775LL, 2222222222LL, 33333333333LL, 4444444444LL, 2135};
			long long expected__      = 549755748288LL;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int k                     = 40;
			long long table[]         = {};
			long long expected__      = 1099511627774LL;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
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
In this problem, you are going to play a simple number game.
The rules of the game are as follows:

You have a single variable called x. Initially, x is set to 1.
In each step, you can change the value of x either to 2x or to 2x+1.
You are given a list of forbidden values. If at any moment your x is on the list, you lose the game.
You are also given a target value y. If at any moment your x is equal to y, you win the game. (Note that the previous item applies sooner: if y is forbidden, you lose the game when you reach it.)
If at any moment winning the game becomes impossible, you lose the game.




For example, assume that the forbidden values are 4 and 7, and the goal is 12.
You can win the game as follows: change x from 1 to 2*1+1=3, then from 3 to 2*3=6, and then from 6 to 2*6=12.



You are given a vector<long long> table.
The elements of table are the forbidden values.



You are also given a int k.
Consider all possible goals y between 2 and (2^k)-1, inclusive.
For how many of these goals is it possible to win the game?
Compute and return the answer to that question.


DEFINITION
Class:NumberGameAgain
Method:solve
Parameters:int, vector<long long>
Returns:long long
Method signature:long long solve(int k, vector<long long> table)


CONSTRAINTS
-k will be between 2 and 40, inclusive.
-The number of elements in table will be between 0 and 20, inclusive.
-all numbers in table will be between 2 and 2^k - 1, inclusive.
-all numbers in table will be distinct.


EXAMPLES

0)
3
{2,4,6}

Returns: 2

There are three forbidden values: 2, 4, and 6.
As k=3, we are considering y between 2 and (2^3)-1 = 7.
This is how the game would end for each of these y's:

For y=2 we cannot win the game because 2 is forbidden.
For y=3 we can win the game: we change x from 1 to 3.
For y=4 we cannot win the game because 4 is forbidden.
For y=5 we cannot win the game. We would need to change x from 1 to 2 and then from 2 to 5, but we cannot do that because 2 is forbidden.
For y=6 we cannot win the game because 6 is forbidden.
For y=7 we can win the game: we change x from 1 to 3, and then from 3 to 7.

Thus, within the specified range there are two values of y for which we can win the game.


1)
5
{2,3}

Returns: 0

In this case, we will always reach a forbidden value after the very first step of the game. Therefore, there is no y for which we can win the game.

2)
5
{}

Returns: 30

With no forbidden values we can win this game for any y between 2 and 31, inclusive.

3)
40
{2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}

Returns: 549755748288



4)
40
{}

Returns: 1099511627774



**/
// END CUT HERE
