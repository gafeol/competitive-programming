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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN];

stack<int> ans;

int cnt[14], tot;

inline void add(int x){
	tot++;
	cnt[x]++;
	ans.push(x);
}

inline void rmv(int x){
	tot--;
	cnt[x]--;
	ans.pop();
}

int tam;

int go(int i, int lo){
	debug("i %d lo %d tam %d\n", i, lo, tam);
	if(i >= tam) return lo;	
	int ok = 0;
	debug("tam %d - i %d - tot %d\n", tam, i, tot);
	if(tam - i - tot > 0){
		if(lo){
			add(9);
			ok = go(i+1, lo);
			assert(ok);
		}
		else{
			if(cnt[s[i]] == 0){
				add(s[i]);
				debug("bota %d\n", s[i]);
				ok = go(i+1, 0);
				if(!ok){
					rmv(s[i]);
					if(s[i] == 0) return 0;
					if(s[i] == 1 && i == 0) return 0;
					add(s[i]-1);
					debug("bota %d\n", s[i]-1);
					ok = go(i+1, 1);
					assert(ok);
				}
			}
			else{
				tot--;
				cnt[s[i]]--;
				ans.push(s[i]);
				ok = go(i+1, 0);
				if(!ok){
					tot++;
					cnt[s[i]]++;
					ans.pop();
					if(s[i] == 0) return 0;
					if(s[i] == 1 && i == 0) return 0;
					add(s[i]-1);
					ok = go(i+1, 1);
					assert(ok);
				}
			}
		}
	}
	else{
		if(lo){
			int val = 0;
			for(int a=9;a>=0;a--){
				if(cnt[a] != 0){
					val = a;
					break;
				}
			}
			cnt[val]--;
			tot--;
			ans.push(val);
			ok = go(i+1, lo); 
			assert(ok);
		}
		else{
			int val = -1;
			for(int a=s[i];a>=0;a--){
				if(cnt[a] != 0){
					val = a;
					break;
				}
			}
			if(val == -1) return 0;
			cnt[val]--;
			tot--;
			ans.push(val);
			debug("5 ans push %d\n", val);
			debug("x %d\n", val);
			ok = go(i+1, (val < s[i]));
			if(!ok){
				ans.pop();
				cnt[val]++;
				tot++;
				val--;
				while(val >= 0 && cnt[val] == 0)
					val--;
				if(val < 0) return 0;
				cnt[val]--;
				tot--;
				ans.push(val);
				debug("x %d\n", val);
				ok = go(i+1, 1);
				assert(ok);
			}
		}
	}
	return ok;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s);
		tam = strlen(s);
		for(int a=0;a<tam;a++)
			s[a] = s[a]-'0';
		for(int a=0;a<10;a++)
			cnt[a] = 0;
		tot = 0;
		while(!ans.empty())
			ans.pop();
		if(go(0, 0)){
			vector<int> aux;
			while(!ans.empty()){
				aux.pb(ans.top());
				ans.pop();
			}
			for(int a=aux.size()-1;a>=0;a--)
				printf("%d", aux[a]);
			puts("");
			aux.clear();
		}
		else{
			for(int a=0;a<tam-2;a++)
				printf("9");
			printf("\n");
		}
	}
}

