#include "bits/stdc++.h"
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

int n, m, k;
int s[MAXN];

char op[MAXN];
int p[MAXN];

int main (){
	scanf("%d", &n);
    stack<int> st;
	for(int a=0;a<2*n;a++){
        scanf(" %c", op+a);
        if(op[a] == '-'){
            scanf("%d", p+a);
            if(st.empty()){
                puts("NO");
                debug(" 1\n");
                return 0;
            }
            p[st.top()] = p[a];
            st.pop();
        }
        else{
            st.push(a);
        }
	}
    multiset<int> q;
    for(int a=0;a<2*n;a++){
        if(op[a] == '-'){
            if(q.empty() || *q.begin() != p[a]){
                puts("NO");
                return 0;
            }
            q.erase(q.begin());
        }
        else
            q.insert(p[a]);
    }
    puts("YES");
    for(int a=0;a<2*n;a++){
        if(op[a] == '-') continue;
        printf("%d ", p[a]);
    }
    puts("");
    return 0;
}

