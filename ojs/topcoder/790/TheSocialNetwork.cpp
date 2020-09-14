#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;


class TheSocialNetwork {
  public:
    vector<bool> mrk;
    vector<bool> usa;
    vector<vector<pii>> adj;
    vector<int> len;
    int N;


    int dfs(int u){
        mrk[u] = true;
        int sz = 1;
        for(pii ar: adj[u]){
            int nxt, id;
            nxt = ar.fst;
            id = ar.snd;
            if(mrk[nxt] || !usa[id]) continue;
            sz += dfs(nxt);
        }
        return sz;
    }

    bool conn(){
        mrk.clear();
        mrk.resize(N+1, false);
        return (dfs(1) == N);
    }

    const int MAXL = 100009;
    int minimumCut(int n, int m, vector <int> u, vector <int> v, vector <int> l) {
        vector<ll> pot(MAXL, 0);
        pot[0] = 1;
        for(int i=1;i<MAXL;i++)
            pot[i] = mod(pot[i-1]*2ll);
        N = n;
        len = l;
        adj.clear();
        adj.resize(n+1);
        usa.clear();
        usa.resize(m, false);
        vector<tuple<int, int, int>> ar;
        for(int a=0;a<m;a++){
            ar.pb(make_tuple(u[a], v[a], l[a]));
        }
        sort(ar.begin(), ar.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) { return get<2>(a) < get<2>(b); });
        for(int a=0;a<ar.size();a++){
            int u, v;
            tie(u, v, ignore) = ar[a];
            adj[u].pb({v, a}); 
            adj[v].pb({u, a});
        }
        for(int i=m-1;i>=0;i--){
            usa[i] = true;
            if(conn()){
                usa[i] = false; 
            }
        }
        ll ans = 0;
        for(int i=0;i<m;i++){
            if(!usa[i])
                ans = mod(ans + pot[get<2>(ar[i])]);
        }
        return ans;
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
			int n                     = 6;
			int m                     = 6;
			int u[]                   = {1, 2, 3, 4, 5, 6} ;
			int v[]                   = {2, 3, 4, 5, 6, 1};
			int l[]                   = {1, 7, 3, 4, 6, 12};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 5;
			int m                     = 7;
			int u[]                   = {1, 1, 1, 2, 2, 3, 3};
			int v[]                   = {5, 3, 2, 5, 3, 5, 4};
			int l[]                   = {1, 8, 2, 3, 4, 6, 9};
			int expected__            = 28;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int m                     = 6;
			int u[]                   = {1, 1, 2, 2, 3, 3};
			int v[]                   = {2, 3, 4, 5, 6, 7};
			int l[]                   = {7, 11, 6, 9, 20, 15};
			int expected__            = 64;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 8;
			int m                     = 11;
			int u[]                   = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 7};
			int v[]                   = {2, 8, 3, 5, 4, 6, 7, 5, 6, 8, 8};
			int l[]                   = {2, 3, 1, 6, 11, 8, 9, 10, 7, 4, 5};
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 13;
			int m                     = 56;
			int u[]                   = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};
			int v[]                   = {3, 4, 5, 7, 9, 12, 13, 3, 5, 8, 9, 10, 12, 13, 5, 6, 8, 9, 10, 11, 12, 5, 6, 7, 9, 11, 13, 7, 8, 9, 11, 12, 7, 8, 9, 10, 13, 8, 9, 10, 11, 12, 13, 9, 11, 12, 10, 11, 12, 13, 11, 12, 13, 12, 13, 13};
			int l[]                   = {82, 240, 395, 1041, 1165, 1274, 1540, 1650, 1904, 2306, 2508, 3162, 3380, 3637, 3778, 3913, 3971, 4101, 4148, 4218, 4394, 4434, 5107, 6147, 6280, 6337, 6461, 6490, 7056, 8024, 8373, 8924, 8961, 9058, 9304, 9359, 10899, 11049, 11090, 11174, 11269, 11356, 11547, 11808, 12566, 12591, 13322, 13447, 13667, 13672, 15013, 15319, 16153, 16447, 16454, 16470};
			int expected__            = 504663883;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int m                     = ;
			int u[]                   = ;
			int v[]                   = ;
			int l[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int u[]                   = ;
			int v[]                   = ;
			int l[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int m                     = ;
			int u[]                   = ;
			int v[]                   = ;
			int l[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheSocialNetwork().minimumCut(n, m, vector <int>(u, u + (sizeof u / sizeof u[0])), vector <int>(v, v + (sizeof v / sizeof v[0])), vector <int>(l, l + (sizeof l / sizeof l[0])));
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
