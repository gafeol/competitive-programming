#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<char, int, int> cii;
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

const int MAXN = 100005;

int n, m, k;
int s[MAXN];
int ss[MAXN];

int l[MAXN], r[MAXN];

vector<cii> ans;

void fail(){
    puts("-1");
    exit(0);
}

void paint(int i, int j, bool t){
    if(i >= j) return;
    ans.emplace_back((t ? 'M' : 'm'), i, j);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        l[a] = n;
        r[a] = 0;
    }
    for(int a=0;a<n;a++)
        scanf("%d", ss+a);

    int j = 0;
    vector<int> sp;
    for(int i=0;i<n;i++){
        while(j < n && s[i] == ss[j]){
            sp.pb(i);
            l[i] = min(l[i], j); 
            r[i] = max(r[i], j);
            j++;
        }
    }
    if(j < n)
        fail();

    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(), sp.end()), sp.end());

    for(int pos: sp){
        //solve left (if need be)
        if(l[pos] < pos){
            bool t = (s[pos-1] > s[pos]);
            paint(l[pos], pos-1, t);
            paint(l[pos], pos, 1-t);
        }
    }
    for(int i=sp.size()-1;i>=0;i--){
        int pos = sp[i];
        //solve right
        if(r[pos] > pos){
            bool t = (s[pos+1] > s[pos]);
            paint(pos+1, r[pos], t);
            paint(pos, r[pos], 1-t);
        }
    }
    printf("%d\n", ans.size());
    for(cii tp: ans){
        char t;
        int i, j;
        tie(t, i, j) = tp;
        printf("%c %d %d\n", t, i+1, j+1);
    }
}

