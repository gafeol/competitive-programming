#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
string s;

int main (){
    IOS();
    cin >> s;
    n = s.size();
    int turn = 0;
    int games[2];
    games[0] = games[1] = 0;
    int points[2];
    points[0] = points[1] = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'Q'){
            if(games[0] >= 2){
                cout << games[0] << " (winner)" << " - " << games[1] << endl;
            }
            else if(games[1] >= 2){
                cout << games[0] << " - " << games[1] << " (winner)" << endl;
            }
            else{
                cout << games[0] << " (" << points[0] << (turn == 0 ? "*" : "") << ")";
                cout << " - ";
                cout << games[1] << " (" << points[1] << (turn == 1 ? "*" : "") << ")";
                cout << endl;
            }
        }
        else if(s[i] == 'S'){
            points[turn]++;
        }
        else{
            turn ^= 1;
            points[turn]++;
        }
        for(int t=0;t<2;t++){
            if(points[t] == 10 || (points[t] >= 5 && points[t] - points[1-t] >= 2)){
                games[t]++;
                turn = t;
                points[0] = points[1] = 0;
            }
        }

    }
    return 0;
}

