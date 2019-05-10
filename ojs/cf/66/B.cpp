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


class Solution{
    int n;
    vector<int> s;

    public:

    Solution(){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            int x;
            scanf("%d", &x);
            s.push_back(x);
        }
    }


    int solve(){
        int i = 0, j = 0;
        int a = 0;
        int ans = 0;
        while(a < n){
            j = max(j, a);
            while(j + 1 < n && s[j+1] <= s[j])
                j++;
            ans = max(ans, j - i + 1); 
            a++;
            if(a < n && s[a] < s[a-1])
                i = a;
        }
        printf("%d\n", ans);
    }
};

int main (){
    Solution problem;
    problem.solve();
}

