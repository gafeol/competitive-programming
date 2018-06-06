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

int n, k;
int s[MAXN];

int d[MAXN], h;
int l[MAXN], r[MAXN];

map<int, map<int, char> > m;

void add(int i, int j){
    //printf("add %d %d\n", i, j);
	l[j] = min(l[j], i);
	r[j] = max(r[j], i);
	d[i] = j;
	h = max(h, 1+abs(i - j));
	s[j]--;
}

int main (){
	for_tests(t, tt){
		m.clear();
		h = INT_MIN;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
			l[a] = INT_MAX;
			r[a] = INT_MIN;
			d[a] = -1;
		}
		int nd = 0;

		deque<pii> q;
		queue<int> fila;
		for(int a=0;a<n;a++){
			if(!q.empty()){
				pii f = q.front();
				q.pop_front();
				f.snd--;
				add(a, f.fst);
				if(f.snd > 0)
					q.push_front(f);
			}
			else
				fila.push(a);

			if(s[a] > 0){
				while(!fila.empty() && s[a] > 0){
					int u = fila.front();
					fila.pop();
					add(u, a);
				}
				if(s[a] > 0)
					q.push_back(pii(a, s[a]));
			}
		}
		printf("Case #%d: ", tt);
		if(!q.empty() || !fila.empty()){
			puts("IMPOSSIBLE");
			while(!q.empty())
				q.pop_front();
			while(!fila.empty())
				fila.pop();
			continue;
		}
		int fodeu = 0;
		for(int a=0;a<n;a++){
			if(s[a] != 0)
				fodeu = 1;
		}
		if(fodeu){
			puts("IMPOSSIBLE");
			continue;
		}
		for(int a=0;a<n;a++){
			int alt = 0;
			char ab = '\\';
			for(int ll = a-1;ll>=l[a];ll--){
				if(m[alt][ll] == '/' || m[alt][ll+1] == '/') fodeu = 1;
				m[alt][ll] = '\\';
				//printf("seta %d %d = %c\n", alt, ll, m[alt][ll]);
				alt++;
				if(ll == 0 || ll == n-1){
					debug("aaaa");
                    fodeu = 1;
				}
			}
			alt = 0;
			for(int rr = a+1;rr<=r[a];rr++){
				if(m[alt][rr] == ab ||   m[alt][rr-1] == '\\') fodeu = 1;
				m[alt][rr] = '/';
				//printf("seta %d %d = %c\n", alt, rr, m[alt][rr]);
				if(rr == 0 || rr == n-1){
                    fodeu = 1;
					debug("nbbb");
				}
                    alt++;
			}
		}
		if(fodeu){
			puts("IMPOSSIBLE");
			continue;
		}
		printf("%d\n", h);
		for(int a=h-2;a>=0;a-- ){
			for(int b=0;b<n;b++){
				if(m[a][b] == '/' || m[a][b] == '\\')
					printf("%c", m[a][b]);
				else
					printf(".");
			}
			puts("");
		}
		for(int b=0;b<n;b++)
            printf(".");
        puts("");
	}
}
