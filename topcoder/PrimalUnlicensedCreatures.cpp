#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <sstream>
#include <ctime>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,j,k) for(int (i)=(j);(i)<(k);++(i))
#define pb push_back
#define PI acos(-1)
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
#define mp make_pair
#define cl(x) memset(x,0,sizeof(x))
#define EPS 1e-9

using namespace std;
class PrimalUnlicensedCreatures {
public:
   int maxWins( int initialLevel, vector <int> grezPower ) {
		sort(grezPower.begin(), grezPower.end());
		int val = initialLevel;
		int cont = 0;
		fr(i,0,grezPower.size()){
			if( val > grezPower[i] ){
				val += grezPower[i] /2; cont++;
			}
		}
		return cont;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
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
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int initialLevel          = 31;
			int grezPower[]           = {10, 20, 30};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int initialLevel          = 20;
			int grezPower[]           = {24, 5, 6, 38};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int initialLevel          = 20;
			int grezPower[]           = {3, 3, 3, 3, 3, 1, 25 };
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int initialLevel          = 4;
			int grezPower[]           = {3, 13, 6, 4, 9};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int initialLevel          = 7;
			int grezPower[]           = {7, 8, 9, 10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int initialLevel          = ;
			int grezPower[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int initialLevel          = ;
			int grezPower[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int initialLevel          = ;
			int grezPower[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimalUnlicensedCreatures().maxWins(initialLevel, vector <int>(grezPower, grezPower + (sizeof grezPower / sizeof grezPower[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
