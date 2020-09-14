#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
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

//            12345678901
string MAX = "99999999999";
string INF = "a";
string ZER = "";
int n, m, k;

string beg(string s){
    while(s.size() < 11)
        s.pb('0');
    return s;
}

string maisUm(string s){
    if(stoll(s) == stoll(MAX))
        return INF;
    ll val = stoll(s) + 1;
    for(int a=s.size()-1;a>=0;a--){
        s[a] = val%10 + '0';
        val /= 10;
    }
    if(val > 0)
        s = INF;
    return s;
}

string mais(string s, ll x){
    if(stoll(s) + x > stoll(MAX))
        return INF;
    ll val = stoll(s) + x;
    for(int a=s.size()-1;a>=0;a--){
        s[a] = val%10 + '0';
        val /= 10;
    }
    if(val > 0)
        s = INF;
    return s;
}

string menosUm(string s){
    if(stoll(s) == 0)
        return ZER;
    ll val = stoll(s) - 1;
    for(int a=s.size()-1;a>=0;a--){
        s[a] = val%10 + '0';
        val /= 10;
    }
    if(val > 0)
        s = ZER;
    return s;
}

string fim(string base, string suf){
    for(int i=0;i<suf.size();i++){
        int j = base.size() - suf.size() + i;
        base[j] = suf[i];
    }
    while(base.size() < 11)
        base.pb('9');
    return base;
}

vector<tuple<string, string, string>> ans;

set<pss> occ;

string nxtFree(string s){
    //printf("nxtFree de %s\n", s.c_str());
    auto it  = occ.upper_bound({s, INF});
    if(it == occ.begin()){
        return s;
    }
    --it;
    if(it->snd < s){
        return s;
    }
    else{
        return maisUm(it->snd);
    }
}

void add(string l, string r, string tag){
    string u = nxtFree(l);
    while(u <= r){
        auto nxt = occ.lower_bound({u, ZER});
        string ate = (nxt == occ.end() ? r : min(r, menosUm(nxt->fst)));
        ans.pb({u, ate, tag});
        u = nxtFree(maisUm(ate));
    }

    auto it = occ.upper_bound({l, INF});
    if(it != occ.begin()){
        it--;
        if(it->snd < menosUm(l))
            it++;
    }
    string rl = l, rr = r;
    string lim = maisUm(r);
    while(it != occ.end() && it->fst <= lim){
        rl = min(rl, it->fst);
        rr = max(rr, it->snd);
        auto bef = it;
        it++;
        occ.erase(bef);
    }
    occ.insert({rl, rr});
    //puts("OK ADD");
}

int main (){
    freopen("billing.in", "r", stdin);
    freopen("billing.out", "w", stdout);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        char L[15], R[15];
        char tag[30];
        scanf(" %s - %s %s", L, R, tag);
        add(beg(L), fim(L, R), tag);
	}
    sort(ans.begin(), ans.end());
    vector<tuple<string, string, string>> cleanAns;
    for(int i=0;i<ans.size();i++){
        if(i == ans.size()-1){
            cleanAns.pb(ans[i]);
        }
        else{
            if(get<2>(ans[i]) == get<2>(ans[i+1]) && maisUm(get<1>(ans[i])) == get<0>(ans[i+1]))
                ans[i+1] = {get<0>(ans[i]), get<1>(ans[i+1]), get<2>(ans[i+1])};
            else
                cleanAns.pb(ans[i]);
        }
    }


    ans = cleanAns;
    vector<pss> realAns;
    for(tuple<string, string, string> tp: ans){
        string L = get<0>(tp);
        string R = get<1>(tp);
        string tag = get<2>(tp);
        if(tag == "invalid")
            continue;
        //printf("BEF L %s R %s\n", L.c_str(),R.c_str());
        while(L.size() > 1 && L.back() == '0' && R.back() == '9'){
            L.pop_back();
            R.pop_back();
        }
        //printf("AFT L %s R %s\n", L.c_str(), R.c_str());
        while(L <= R){
            //printf("L %s R %s\n", L.c_str(),R.c_str());
            while(L.size() > 1 && L.back() == '0' && mais(L, 9) <= R){
                //printf("diminui L de %s para ", L.c_str());
                L.pop_back();
                //printf("%s\n", L.c_str());
            }
            string dif = ""; // colocar varios 9
            while(L.size() + dif.size() < R.size())
                dif.pb('9');
            while(L.size() < R.size() && L + dif > R){
                //printf("tem que aumentar L pq %s eh maior que %s\n", maisUm(L).c_str(), R.c_str());
                L.pb('0');
                dif.pop_back();
            }
            realAns.pb({L, tag});
            L = maisUm(L);
        }
    }
    printf("%d\n", (int)realAns.size());
    for(pss p: realAns){
        printf("%s %s\n", p.fst.c_str(), p.snd.c_str());
    }
}

