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

int n;

int main (){
    while(scanf("%d", &n) != EOF && n > 0){
        int points =0;
        for(int a=0;a<n;a++){
            char t;
            int h,hh,m, mm, s, ss;
            scanf(" %c:%d:%d:%d:%d:%d:%d", &t, &h, &m, &s, &hh, &mm, &ss);
            bool late = false;
            tuple<int, int, int> st = make_tuple(h, m, s);
            if(t == 'D' && make_tuple(h, m, s) > make_tuple(9, 30, 0)){
                late = true;
            }
            else if(t == 'E' && make_tuple(h, m, s) > make_tuple(12, 30, 0)){
                late = true;
            }
            st = max(st, make_tuple(8, 30, 0)); 
            tie(h, m, s) = st;
            int dur = (hh - h)*3600 + (mm - m)*60 + ss - s;

            bool lesswork = false;
            if(t == 'D' && dur < 8*3600)
                lesswork = true;
            if(t == 'E' && dur < 9*3600)
                lesswork = true;
            
            points += (lesswork || late);
        }
        if(points > 3)
            puts("Issue Show Cause Letter");
        else if(points > 0)
            printf("%d Point(s) Deducted\n", points);
        else
            puts("All OK");
    }
}

