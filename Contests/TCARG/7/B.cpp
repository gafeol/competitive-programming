#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

typedef ll tp;
bool op(char c){ return (c== '+' || c=='*' || c=='='); }

void join(vector<tp> &A, char o, vector<tp> &B){
    if(o == '+'){
        if(A.size() < B.size())
            A.resize(B.size(), 0);
        for(int i=0;i<B.size();i++)
            A[i] += B[i]; 
    }
    else{
        vector<tp> cA = A;
        A.clear();
        A.resize(cA.size() + B.size() - 1, 0);
        for(int i=0;i<cA.size();i++){
            for(int j=0;j<B.size();j++){
                //check(cA[i], B[j]);
                A[i+j] += cA[i]*B[j]; 
            }
        }
    }
}

vector<tp> getn(string &s, int ini){
    vector<tp> ans;
    while(ini < s.size() && !op(s[ini])){
        ans.pb(s[ini]-'0');
        ini++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<tp> rep(string s){
    int i = 0;
    stack<vector<tp>> q;
    q.push(getn(s, 0));
    while(i < s.size()){
        while(i < s.size() && !op(s[i]))
            i++;
        if(i == s.size())
            break;
        char o = s[i];
        i++;
        vector<tp> num = getn(s, i);
        if(o == '*'){
            vector<tp> aux = q.top();
            q.pop();
            join(aux, o, num);
            q.push(aux);
        }
        else
            q.push(num);
    }
    vector<tp> ans = q.top();
    q.pop();
    while(!q.empty()){
        join(ans, '+', q.top());
        q.pop();
    }
    return ans;
}

inline bool eval(vector<tp> &p, tp b){
    tp exp = 1;
    tp ans = 0;
    for(int a=0;a<p.size();a++){
        ans = ans +  exp*p[a];
        exp = exp*b;
    }
    return (ans != (tp)0);
}

int mnBase = 2;

vector<ll> solve(vector<tp> p){
    vector<tp> P, Q;
    int ini = 0;
    while(p[ini] == 0)
        ini++;
    for(tp a=1;a<=sqrt((long double)abs(p[ini]))+3 && a<=abs(p[ini]);a++){
        if(p[ini]%a == 0){
            if(a >= mnBase)
                P.pb(a);
            if(abs(p[ini]/a) >= mnBase)
                P.pb(abs(p[ini]/a));
        }
    }
    for(tp a=1;a<=sqrt((long double)abs(p.back()))+3 && a<=abs(p.back());a++){
        if(p.back()%a == 0){
            Q.pb(a);
            Q.pb(abs(p.back()/a));
        }
    }

    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    sort(Q.begin(), Q.end());
    Q.erase(unique(Q.begin(), Q.end()), Q.end());

    vector<ll> ans; 
    for(tp x: P){
        for(tp y: Q){
            if(x%y == 0 && x/y >= mnBase && eval(p, x/y) == 0){
                assert(log((long double)x/y) <= log(LLONG_MAX));
                ans.pb(x/y);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans; 
} 

int32_t main (){
    IOS();
    while(1){
        mnBase = 2;
        string s;
        cin >> s;
        if(s == "=") break;
        for(char c: s){
            if(op(c)) continue;
            mnBase = max(mnBase, c-'0'+1);
        }
        int ig = s.find('=');
        vector<tp> A = rep(s.substr(0, ig));
        vector<tp> B = rep(s.substr(ig+1, s.size() - ig -1));
        if(B.size() > A.size())
            swap(A, B);
        for(int a=0;a<B.size();a++)
            A[a] -= B[a];
        while(!A.empty() && !A.back())
            A.pop_back();
        if(A.empty()){
            cout << mnBase << "+" << endl;
            continue;
        }
        vector<ll> ans = solve(A);
        if(ans.empty()){
            cout << "*" << endl;
            continue;
        }
        for(ll x: ans)
            cout << x << " ";
        cout << endl;
    }
}
