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

int dp[2][1<<15];
int n;
string c;

int rec( int p, int mask){
	if( dp[p][mask] != -1) return dp[p][mask];
	int cont = 0, last = 0;
	REP(i,0,n){
		if( mask & (1 << i)) cont++;	
		else last = i;
	}
	if( cont == n) return -1;
	if(cont == n-1) return dp[p][mask] = (c[last]=='B');	
	REP(i,0,n){
		if( (mask & (1<<i)) == 0){
			int tmp = mask;
			REP(j,i,n){
				if( (mask & (1<<j)) == 1 ) break;
				tmp |= (1 << j);
				int ret = rec( p ^ 1, tmp);				
				if( p == ret){
					return dp[p][mask] = p;
				}
			}
		}
	}	
	return dp[p][mask] = (p ^ 1);
}

struct RowAndCoins {
    string getWinner(string cells) {
		c = cells; n = c.size();
		memset(dp,-1,sizeof(dp));		
        return (rec( 0, 0)==0?"Alice":"Bob");
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
			string cells              = "ABBB";
			string expected__         = "Alice";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cells              = "BBBB";
			string expected__         = "Bob";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cells              = "BA";
			string expected__         = "Alice";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cells              = "BABBABBB";
			string expected__         = "Bob";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cells              = "ABABBBABAABBAA";
			string expected__         = "Alice";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string cells              = "BBBAAABBAAABBB";
			string expected__         = "Bob";

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string cells              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cells              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string cells              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RowAndCoins().getWinner(cells);
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
// Alice and Bob play the following game. 
The game board consists of some cells in a row. 
Each cell is marked either 'A' or 'B'. 
At the beginning, there are no coins placed on the board – all the cells are empty. 
Alice and Bob take alternating turns. 
Alice plays first. 
In each turn, the current player chooses some contiguous empty cells and places a coin onto each of the chosen cells. 
The player must always choose at least one cell. 
The player must never choose all empty cells. 
In other words, after each turn there must be at least one empty cell. 

The following picture shows two examples of placing coins: 



The game ends when there is only one cell left without a coin. 
If that cell is marked 'A', Alice wins. 
Otherwise, Bob wins. 
You are given a string cells representing the row of cells. 
Assuming that both players aim to win and play optimally, return a string containing the name of the winner. 


DEFINITION
Class:RowAndCoins
Method:getWinner
Parameters:string
Returns:string
Method signature:string getWinner(string cells)


CONSTRAINTS
-cells will contain between 2 and 14 characters, inclusive. 
-Each character in cells will be either 'A' or 'B'. 


EXAMPLES

0)
"ABBB"

Returns: "Alice"

Alice can win by placing coins on three cells marked 'B' in her first turn. 


1)
"BBBB"

Returns: "Bob"

2)
"BA"

Returns: "Alice"



3)
"BABBABBB"

Returns: "Bob"

4)
"ABABBBABAABBAA"

Returns: "Alice"



5)
"BBBAAABBAAABBB"

Returns: "Bob"



**/
// END CUT HERE
