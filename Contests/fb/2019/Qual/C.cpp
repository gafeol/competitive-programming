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

int n, m, k;
char s[MAXN];
int o[MAXN];
map<char, bool> val;

void setx(bool x){
    val['x'] = x;
    val['X'] = !x;
}

bool go(int i, int j){
    if(s[i] == '('){
        int mid =  o[i+1]+1;
        if(s[mid] == '&')
            return (go(i+1, mid-1)&go(mid+1, j-1));
        else if(s[mid] == '|')
            return (go(i+1, mid-1)|go(mid+1, j-1));
        else if(s[mid] == '^')
            return (go(i+1, mid-1)^go(mid+1, j-1));
        else
            assert(false);
    }
    else
        return val[s[i]];  
}

bool value(int x){
    setx(x);
    return go(0, n-1);
}

int main (){
    val['0'] = 0;
    val['1'] = 1;
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);
        stack<int> q;
        for(int a=0;a<n;a++){
            o[a] = a;
            if(s[a] == '(')
                q.push(a);
            else if (s[a] == ')'){
                int ot = q.top();
                q.pop();
                o[ot] = a;
                o[a] = ot;
            }
        }
        printf("Case #%d: ", tt);
        if(value(0) == value(1))
            puts("0");
        else
            puts("1");
    }
}

