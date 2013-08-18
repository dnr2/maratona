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

class st{	
	public :
		int cost;
		int	pos;
		string buf;	
		vector<string> hist;
	const bool operator < ( const st & in ) const {
		if( cost == in.cost && pos == in.pos ) return buf.size() < in.buf.size();
		if( cost == in.cost) return pos < in.pos;
		return cost > in.cost;
	}
};

class UndoHistory {
public:
   int minPresses( vector <string> lines ) {
		st ini; vector<string> temp; temp.pb("");
		ini.cost = 0; ini.pos =0; ini.buf = ""; ini.hist = temp;
		priority_queue<st> heap; heap.push(ini);
		int result = 0;
		for( int tt= 0; !heap.empty(); tt++){			
			// db(tt);
			ini = heap.top(); heap.pop();			
			result = ini.cost;
			db(ini.pos _ ini.buf);
			if( ini.pos >= lines.size()) {				
				break;
			}			
			if( lines[ini.pos].find(ini.buf) == 0 && lines[ini.pos].size() > ini.buf.size()) {
				st novo; novo.buf = ini.buf; novo.buf += lines[ini.pos][ini.buf.size()];
				vector<string> temp2; fr(i,0,ini.hist.size()) temp2.pb(ini.hist[i]); temp2.pb(novo.buf);
				novo.cost = ini.cost +1; novo.pos = ini.pos;  novo.hist = temp2;				
				heap.push(novo);
			}
			if( lines[ini.pos].compare(ini.buf) == 0){
				st novo; novo.buf = ini.buf;
				vector<string> temp2; fr(i,0,ini.hist.size()) temp2.pb(ini.hist[i]);
				novo.cost = ini.cost +1; novo.pos = ini.pos + 1;  ini.hist = temp2;				
				heap.push(novo);
			}
			// db(ini.hist.size());
			fr(i,0,ini.hist.size()){			
				if( lines[ini.pos].find(ini.hist[i]) == 0 && lines[ini.pos].size() >= ini.hist[i].size()) {
					st novo; novo.buf = ini.hist[i]; 
					vector<string> temp2; fr(i,0,ini.hist.size()) temp2.pb(ini.hist[i]);
					novo.cost = ini.cost + 2; novo.pos = ini.pos; novo.hist = temp2;
					
					heap.push(novo);
				}
			}			
		}
		return result;
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
			string lines[]            = {"tomorrow", "topcoder"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string lines[]            = {"a","b"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string lines[]            = {"a", "ab", "abac", "abacus" };
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string lines[]            = {"pyramid", "sphinx", "sphere", "python", "serpent"};
			int expected__            = 39;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string lines[]            = {"ba","a","a","b","ba"}
;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
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
