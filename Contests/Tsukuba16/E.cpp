#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt)                                             \
    int t;                                                           \
    scanf("%d", &t);                                                 \
    for (int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
    out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
    out << t << ' ';
    write(out, args...);
}

template <typename... Args> void debug(Args... args) {
#ifdef LOCAL
    write(cerr, args...);
#endif
}

template <typename T> inline T abs(T t) { return t < 0 ? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char sb[] = {'0', '1', '(', ')', '-', '+', '*', '='};

void prep_cin() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

struct Calc {
    bool bad;
    int i, ans;
    string s;

    Calc(string in) : bad(false), i(0), s(in) {
        ans = E();
        bad = (bad || (i != s.size()));
    }

    operator int() { return ans; }

    int E() {
        int loc = T();
        while (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i++] == '+')
                loc += T();
            else
                loc -= T();
        }
        return loc;
    }

    int T() {
        int loc = F();
        while (i < s.size() && s[i] == '*') {
            i++;
            loc *= F();
        }
        return loc;
    }

    int F() {
        int loc = 0;
        if (i == s.size()){ 
            bad = true;
            return 0;
        }
        if (s[i] == '0' || s[i] == '1') {
            if (s[i] == '0') {
                i++;
                if (i < s.size() && (s[i] == '0' || s[i] == '1')){
                    bad = true;
                    i++;
                }
                return 0;
            }
            while (s[i] == '0' || s[i] == '1')
                loc = 2 * loc + (s[i++] - '0');
            return loc;
        }
        if (s[i] == '-') {
            i++;
            return (-1) * F();
        }
        if (s[i] == '(') {
            i++;
            loc = E();
            if (i == s.size()){
                bad = true;
                return loc;
            }
            if (s[i] != ')')
                bad = true;
            i++;
            return loc;
        }
        else{
            bad = true;
        }
        return loc;
    }
};

string s;

vector<char> ch;

map<char, char> chg, inv;
set<string> foi;

int fat[10];

int main() {
    fat[0] = 1;
    for(int a=1;a<=8;a++)
        fat[a] = fat[a-1]*a;
    prep_cin();
    cin >> ws >> s;
    n = s.size();
    for (int a = 0; a < n; a++) {
        if ((s[a] >= 'a' && s[a] <= 'z') ||
            (s[a] >= 'A' && s[a] <= 'Z')) {
            ch.pb(s[a]);
        }
    }
    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());
    if (ch.size() > 8) {
        puts("0");
        return 0;
    }
    sort(sb, sb + 8);
    int res = 0;
    do {
        /*for(int a=0;a<8;a++){
            cout << sb[a]  << " ";
        }
        cout << endl;*/
        chg.clear();
        inv.clear();
        for (int i = 0; i < ch.size(); i++) {
            chg[ch[i]] = sb[i];
            inv[sb[i]] = ch[i];
        }
        vector<int> mrk(n, 0);
        for (int a = 0; a < n; a++) {
            if ((s[a] >= 'a' && s[a] <= 'z') ||
                (s[a] >= 'A' && s[a] <= 'Z')) {
                s[a]   = chg[s[a]];
                mrk[a] = 1;
            }
        }

        string A, B;
        bool ig = 0;
        bool cago = false;
        for (int a = 0; a < n; a++) {
            if (s[a] == '=') {
                if(ig == true) 
                    cago = true;
                ig = true;
                continue;
            }
            if (ig)
                B += s[a];
            else
                A += s[a];
        }
        if(!cago){
            if (ig && s[0] != '=' && s[n - 1] != '=') {
                auto ca = Calc(A);
                auto cb = Calc(B);

                if(!ca.bad && !cb.bad){
                    if(int(ca) == int(cb)){
           //             if(foi.find(A+"="+B) == foi.end())
            //                cout << A+"="+B << endl;
                        foi.insert(A+"="+B);
                    }
                }
            }
        }

        for (int a = 0; a < n; a++)
            if (mrk[a]) 
                s[a] = inv[s[a]];

    } while (next_permutation(sb, sb + 8));
    printf("%d\n", (int)foi.size());
}
