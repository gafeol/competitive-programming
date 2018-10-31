#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int ans[MAXN];
int cnt[3];

vector<int> x, y;

int ask(int i=-1, int j=-1, int k=-1){
	printf("Q");
	for(int a=0;a<n;a++){
		printf(" %d", (a == i || a== j || a==k));
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int ind[MAXN];

void solve(int t1, int t2){
	while(!x.empty()){
		ans[x.back()] = t1;
		cnt[t1]++;
		x.pop_back();
	}
	while(!y.empty()){
		ans[y.back()] = t2;
		cnt[t2]++;
		y.pop_back();
	}
}

int ask(int i, int vi, int j, int vj){
	printf("Q");
	for(int a=0;a<n;a++){
		if(a == i)
			printf(" %d", vi);
		else if(a == j)
			printf(" %d", vj);
		else
			printf(" 0");
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
	
}

int tot[2];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		int val = ask();
		cnt[0] = cnt[1] = 0;
		tot[0] = val;
		tot[1] = n - val;

		for(int a=0;a<n;a++){
			ind[a] = a;
		}
		srand(time(0));
		random_shuffle(ind, ind+n);
		memset(ans, -1, sizeof(ans));
		for(int ii=0;ii+1<n;ii+=2){
			if(tot[0] == cnt[0] || tot[1] == cnt[1]) break;
			bool tri = (ii + 2 < n && max(tot[1] - cnt[1], tot[0] - cnt[0]) >= 2*min(tot[1] - cnt[1], tot[0] - cnt[0]));
			int nv;
			if(tri){
				nv = ask(ind[ii], ind[ii+1], ind[ii+2]);
				if(abs(nv - val) == 3){
					ans[ind[ii]] = ans[ind[ii+1]]  = ans[ind[ii+2]] = (nv > val);
					cnt[(nv > val)] += 3;
					ii++;
					continue;
				}
				else{
					int nnv = ask(ind[ii], ind[ii+1]);
					if(abs(nnv - val) == 2){
						ans[ind[ii]] = ans[ind[ii+1]] = (nnv > val);
						ans[ind[ii+2]] = (nnv < val);
						cnt[(nnv>val)] += 2;
						cnt[(nnv<val)]++;
						ii++;
						continue;
					}
					else{
						if(x.empty()){
							x.pb(ind[ii]);
							y.pb(ind[ii+1]);
						}
						else{
							nv = ask(x.back(), ind[ii]);
							if(abs(nv - val) == 2){
								x.pb(ind[ii]);
								y.pb(ind[ii+1]);
								solve((nv > val), (nv < val));
							}
							else{
								x.pb(ind[ii+1]);
								y.pb(ind[ii]);
							}
						}
					}
				}
			}
			else{
				nv = ask(ind[ii], ind[ii+1]);
				if(abs(nv - val) == 2){
					ans[ind[ii]] = ans[ind[ii+1]] = (nv > val);
					cnt[(nv>val)] += 2;
				}
				else{
					if(x.empty()){
						x.pb(ind[ii]);
						y.pb(ind[ii+1]);
					}
					else{
						nv = ask(x.back(), ind[ii]);
						if(abs(nv - val) == 2){
							x.pb(ind[ii]);
							y.pb(ind[ii+1]);
							solve((nv > val), (nv < val));
						}
						else{
							x.pb(ind[ii+1]);
							y.pb(ind[ii]);
						}
					}
				}
			}
		}
		if(!x.empty() && !(tot[0] == cnt[0] || tot[1] == cnt[1])){
			int nv = ask(x.back(), 0, y.back(), 1);
			solve((nv < val), (nv > val));
		}
		if((n&1) && !(tot[0] == cnt[0] || tot[1] == cnt[1])){
			int nv = ask(ind[n-1]);
			ans[ind[n-1]] = (nv > val);
		}
		printf("A");
		for(int a=0;a<n;a++){
			if(ans[a] == -1)
				ans[a] = (cnt[1] < tot[1]);	
			printf(" %d", ans[a]);
		}
		puts("");
		fflush(stdout);
	}
}

