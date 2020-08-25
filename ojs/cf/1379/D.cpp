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

int n, m, k;
int h;
int s[MAXN];

int main (){
	scanf("%d%d%d%d", &n, &h, &m, &k);
    vector<pii> t;
	for(int a=0;a<n;a++){
        int hh, mm;
        scanf("%d%d", &hh, &mm);
        t.pb({mm%(m/2), a});
        t.pb({(mm%(m/2)) + m/2, a});
        //printf("ev em %d e %d id %d\n", (mm%(m/2)), (mm%(m/2)) + m/2, a);
	}
    sort(t.begin(), t.end());
    int j = 0;
    int ans = INT_MAX, anst;
    for(int i=0;i<t.size();i++){
        while(j < t.size() && t[j].fst < t[i].fst + k){
            //printf("i %d t[i]%d + k %d > t[j] %d\n", i, t[i].fst, k, t[j].fst);
            j++;
        }
        int res = j - i - 1;
        if(res < ans){
            ans = res;
            anst = t[i].fst+k;
            //printf("com i %d ans %d anst %d\n", i, ans, anst);
        }
        if(j == t.size()) break;
    }
    printf("%d %d\n", ans, anst%(m/2));
    for(int i=0;i<t.size();i++){
        if(t[i].fst > anst-k && t[i].fst < anst)
            printf("%d ", t[i].snd+1);
    }
    puts("");
}
