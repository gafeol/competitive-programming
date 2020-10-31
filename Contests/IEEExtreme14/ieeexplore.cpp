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


vector<string> prog;

vector<string> split(string s, vector<char> c, char rpl){
    sort(c.begin(), c.end());
    vector<string> aux;
    string p = "";
    for(int a=0;a<s.size();a++){
        if(binary_search(c.begin(), c.end(), s[a])){
            if(!p.empty())
                aux.pb(p);
            p = "";
        }
        else if(s[a] == rpl){
            if(!p.empty())
                aux.pb(p);
            p = "";
            p.push_back(rpl);
        }
        else
            p.pb(s[a]);
    }
    if(!p.empty())
        aux.pb(p);
    return aux;
}

vector<string> split(string s, char c){
    vector<string> aux;
    string p = "";
    for(int a=0;a<s.size();a++){
        if(s[a] == c){
            if(!p.empty())
                aux.pb(p);
            p = "";
        }
        else
            p.pb(s[a]);
    }
    if(!p.empty())
        aux.pb(p);
    return aux;
}

vector<string> stopWords;
vector<string> specWords;

stack<string> tags;

int score;


bool isTag(string s){
    return (s[0] == '<');
}

bool isSpec(string s){
    return binary_search(specWords.begin(), specWords.end(), s);
}

bool isStop(string s){
    return binary_search(stopWords.begin(), stopWords.end(), s);
}

void openTag(string s){
    tags.push(s);
    if(s == "<title")
        score = 5;
    else if(s == "<abstract")
        score = 3;
    else if(s == "<body")
        score = 1;
}

void closeTag(string s){
    tags.pop();
    if(s == "</title"){
        //cout << "fecha title" << endl;
        score = 0;
    }
    else if(s == "</abstract"){
        //cout << "fecha abs" << endl;
        score = 0;
    }
    else if(s == "</body"){
        //cout << "fecha body" << endl;
        score = 0;
    }
}

void tag(string s){
    if(s.size() > 1 && s[1] == '/')
        closeTag(s);
    else
        openTag(s);
}

vector<string> code;

void clean(string &s){
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i]))
            s[i] = tolower(s[i]);
    }
}


map<string, int> pont;
int L;

//vector<string> aux = split(line, {'>', ';', '!', '.', ',', '?', ' '}, '<');
bool isPont(char c){
    if(c == ';')
        return true;
    if(c == '!')
        return true;
    if(c == '.')
        return true;
    if(c == ',')
        return true;
    if(c == '?')
        return true;
    if(c == ' ')
        return true;

    return false;
}

void cleanPont(string &s){
    string ns = "";
    for(char c: s){
        if(!isPont(c))
            ns.pb(c);
    }
    s = ns;
}

void conta(string s){
    cleanPont(s);
    if(isStop(s))
        return ;
    if(isSpec(s)){
        //cout << "CONTA " << s << " com score " << score << endl;
        pont[s] += score;
    }
    if(s.size() >= 4 && score)
        L++;
}




int main (){
    IOS();
    string stop, spec;
    getline(cin, stop);
    stopWords = split(stop, ';');
    sort(stopWords.begin(), stopWords.end());
    getline(cin, spec);
    specWords = split(spec, ';');
    sort(specWords.begin(), specWords.end());
    
    string line;
    while(getline(cin, line)){
        clean(line);
        //vector<string> aux = split(line, {'>', ';', '!', '.', ',', '?', ' '}, '<');
        vector<string> aux = split(line, {'>', ' '}, '<');
        for(string s: aux)
            code.pb(s);
    }
    

    for(string word : code){
        //cout << (word) << endl;
        if(isTag(word))
            tag(word);
        else{
            conta(word);
        }
    }

    vector<pair<int, string>>  res;
    for(string s: specWords){
        res.emplace_back(-pont[s], s);
    }

    auto calc = [&](int p) { return (p * 100.)/((double)L); };

    sort(res.begin(), res.end());
    cout << setprecision(7) << fixed;

    /*
    for(string s: specWords){
        cout << s << " freq " <<  pont[s] << endl;
    }
    */
    if(res.size() <  3){
        for(auto [mp, s]: res){
            mp = -mp;
            if(mp == 0)
                continue;
            cout << s << ":" << calc(mp) << endl;
        }
    }

    else { 

        int thres = -res[2].fst;
        for(auto [mp, s]: res){
            mp = -mp;
            if(mp == 0 || mp < thres)
                continue;
            cout << s << ": " << calc(mp) << endl;
        }


    }
    return 0;
}

