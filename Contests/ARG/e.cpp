
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

const int MAXN = 212345;
const int N = 1e5 + 5;

int a, n;
int erdos[N];
bool seen[N];
vector<int> adjA[N], adjP[N];

void bfs() {
	queue<int> q;
	q.push(0);
	erdos[0] = 0;

	while (!q.empty()) {
		int x = q.front(); 
		q.pop();

		for (int i = 0; i < adjP[x].size(); i++) {
			int art = adjP[x][i];
			if (!seen[art]) {
				seen[art] = true;
				for (int j = 0; j < adjA[art].size(); j++) {
					int person = adjA[art][j];
					if (erdos[person] == -1) {
						erdos[person] = erdos[x] + 1;
						q.push(person);
					}
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		adjA[i].clear();
		adjP[i].clear();
		seen[i] = 0;
	}
	memset(erdos, -1, sizeof erdos);
}

int main (){
	while (scanf(" %d %d", &a, &n) != EOF) {
		init();
		for (int i = 0; i < a; i++) {
			int c;
			scanf(" %d", &c);
			while (c--) {
				int pi;
				scanf(" %d", &pi);
				pi--;
				adjA[i].pb(pi);
				adjP[pi].pb(i);
			}
		}

		bfs();
		int d = 0, m = 0, s = 0;
		for (int i = 0; i < n; i++) {
			//printf("erdos[%d] %d\n", i, erdos[i]);
			if (erdos[i] == -1) continue;
			d++;
			m = max(m, erdos[i]);
			s += erdos[i];
		}

		
		printf("%d %d %d\n", d, m, s);
	}
}
