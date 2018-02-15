#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define pf push_front
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100010, SQRT = 320;

vector<deque<int> > bck;

int cnt[SQRT][MAXN];

int s[MAXN];

int n, m;

int main (){
	scanf("%d", &n);
	int szb = (int)ceil(sqrt(n));
	deque<int> aux;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(a > 0 && (a-1)/szb != a/szb){
			bck.pb(aux);
			aux.clear();
		}
		aux.pb(s[a]);
		cnt[a/szb][s[a]]++;
	}
	if(!aux.empty())
		bck.pb(aux);
	

	scanf("%d", &m);
	int last_ans = 0;
	for(int a=0;a<m;a++){
		int t, i, j, k;
		scanf("%d%d%d", &t, &i, &j);
		i = (i + last_ans - 1)%n;
		j = (j + last_ans - 1)%n;
		if(i > j) swap(i, j);
		if(t == 1){
			int fb = i/szb, lb = j/szb;
			int fs = i%szb, ls = j%szb;
			debug("fb %d fs %d\nlb %d ls %d\n", fb, fs, lb, ls);
			for(int a=ls;a < bck[lb].size()-1;a++)
				swap(bck[lb][a], bck[lb][a+1]);
			int ult = bck[lb].back();
			bck[lb].pop_back();
			debug("ok!\n");
			cnt[lb][ult]--;
			bck[fb].pf(ult);
			for(int a=0;a<fs;a++)
				swap(bck[fb][a], bck[fb][a+1]);
			cnt[fb][ult]++;
			for(int a=fb;a<lb;a++){
				debug("ok! %d\n", a);
				int lst = bck[a].back();
				bck[a].pop_back();
				int aa = a+1;
				cnt[a][lst]--;
				cnt[aa][lst]++;
				bck[aa].pf(lst);
			}
		}
		else{
			scanf("%d", &k);
			k = (k + last_ans - 1)%n+1;
			int ans = 0;
			int fb = i/szb, lb = j/szb;
			for(int a = fb + 1;a < lb;a++)
				ans += cnt[a][k];	
			int fs = i%szb, ls = j%szb;
			//debug("fb %d fs %d\nlb %d ls %d\n", fb, fs, lb, ls);
			if(fb == lb){
				for(int a=fs;a<=ls;a++)
					ans += (bck[fb][a] == k);	
			}
			else{
				assert(fs < bck[fb].size());
				for(int a=fs;a<bck[fb].size();a++){
					ans += (bck[fb][a] == k);	
				}
				assert(ls < bck[lb].size());
				for(int a=0;a<=ls;a++){
					ans += (bck[lb][a] == k);
				}
			}
			printf("%d\n", ans);
			last_ans = ans;
		}
	}
}
