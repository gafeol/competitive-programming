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

const int MAXN = 10;

int n, m, k, deg;
ll s[MAXN][3];
vector<ll> ds;

map<ll, int> cnt;

ll sq(ll x, ll y){
	return (x-y)*(x-y);
}

ll dist(int i, int j){
	ll ans = 0;
	for(int a=0;a<3;a++){
		ans += sq(s[i][a], s[j][a]);
	}
	return ans;
}

int main (){
	for(int a=0;a<8;a++){
		scanf("%lld%lld%lld", &s[a][0], &s[a][1], &s[a][2]);
	}
	int res = 0;
	do{
		do{
			do{
				do{
					do{
						do{
							do{
								do{
									deg++;
									ds.clear();
									cnt.clear();
									for(int a=0;a<8;a++){
										for(int b=0;b<8;b++){
											if(b == a) continue;
											ll d = dist(a, b);
											if(cnt.find(d) == cnt.end()){
												ds.pb(d);
												cnt[d] = 0;
												if(ds.size() > 3)
													break;
											}
											cnt[d]++;
										}
										if(ds.size() > 3)
											break;
									}
									sort(ds.begin(), ds.end());
									if(ds.size() == 3 && cnt[ds[0]] == 24 && cnt[ds[1]] == 24 && cnt[ds[2]] == 8 && ds[1] == 2ll*ds[0] && ds[2] == 3ll*ds[0]){
										puts("YES");
										debug("deg %d\n", deg);
										for(int a=0;a<8;a++){
											for(int b=0;b<3;b++){
												printf("%lld ", s[a][b]);
											}
											printf("\n");
										}
										return 0;
									}
									debug("passed\n");

								}while(next_permutation(s[0], s[0]+3));
							}while(next_permutation(s[1], s[1]+3));
						}while(next_permutation(s[2], s[2]+3));
					}while(next_permutation(s[3], s[3]+3));
				}while(next_permutation(s[4], s[4]+3));
			}while(next_permutation(s[5], s[5]+3));
		}while(next_permutation(s[6], s[6]+3));
	}while(next_permutation(s[7], s[7]+3));
	debug("deg %d\n", deg);
	puts("NO");
}
