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
int s[MAXN];

int p[MAXN], c[MAXN], z[MAXN];


struct cam{
	int p, z, c;
	int id;

	bool const operator < (cam o) const {
		return (p < o.p);
	}
};

struct cmp {
	bool operator() (const cam& a, const cam& b) const {
		return (a.c < b.c || (a.c == b.c && a.id < b.id));
	}
};

set<cam> q;
set<cam, cmp> pr;

void add(int i){
	auto it = q.upper_bound({p[i], 0, 0, 0});	
	if(it != q.end()){
		if(it->z >= z[i]) return ;
	}
	if(it != q.begin()){
		it--;
		if(it->p == p[i] && (it->z > z[i] || (it->z == z[i] && it->c <= c[i]))) return ;
		while(1){
			if(it->z > z[i]) break;
			if(it == q.begin()){
				q.erase(it);
				pr.erase(pr.find(*it));
				break;
			}
			auto nxt = it;
			nxt--;
			q.erase(it);
			pr.erase(pr.find(*it));
			it = nxt;
		}
	}
	q.insert({p[i], z[i], c[i], i});
	pr.insert({p[i], z[i], c[i], i});
}

int qry(){
	if(pr.empty()) return -1;
	return pr.begin()->id+1;	
}

int main (){
	for_tests(t, tt){
		q.clear();
		pr.clear();
		scanf("%d", &n);
		int fst = 1;
		for(int a=0;a<n;a++){
			char ch;
			scanf(" %c", &ch);
			if(ch == 'P'){
				double zz;
				scanf("%d", p+a);
				scanf("%lf", &zz);
				scanf("%d", c+a);
				z[a] = (int)(zz*1000000. + 0.4);
				add(a);
			}
			else{
				if(!fst) putchar(' ');
				printf("%d", qry());
				fst = 0;
			}
		}
		puts("");
	}
}

