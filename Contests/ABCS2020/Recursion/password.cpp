#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'passwordCracker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY passwords
 *  2. STRING loginAttempt
 */

vector<int> canBuildFrom;

bool match(int from, string &a, string &b){
    if(from + b.size() > a.size()) return false;
    for(int i=0;i<b.size();i++){
        if(a[from+i] != b[i])
            return false;
    }
    return true;
}

bool canBuild(int i, vector<string> &pass, string &s){
    if(canBuildFrom[i] != -1)
        return canBuildFrom[i];
    canBuildFrom[i] = false;
    if(i == s.size())
        return canBuildFrom[i] = true;
    for(string p: pass){
        if(match(i, s, p))
            canBuildFrom[i] |= canBuild(i+p.size(), pass, s);
    }
    return canBuildFrom[i];
}

string build(int i, vector<string> &pass, string &s){
    if(i == s.size())
        return "";

    string space = (i == 0 ? "" : " ");
    for(string p: pass)
        if(match(i, s, p) && canBuildFrom[i + p.size()])
            return space + p + build(i+p.size(), pass, s);
    return "";
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
    canBuildFrom.clear();
    canBuildFrom.resize(loginAttempt.size()+1, -1);
    if(canBuild(0, passwords, loginAttempt)){
        return build(0, passwords, loginAttempt);
    }
    return "WRONG PASSWORD";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string passwords_temp_temp;
        getline(cin, passwords_temp_temp);

        vector<string> passwords_temp = split(rtrim(passwords_temp_temp));

        vector<string> passwords(n);

        for (int i = 0; i < n; i++) {
            string passwords_item = passwords_temp[i];

            passwords[i] = passwords_item;
        }

        string loginAttempt;
        getline(cin, loginAttempt);

        string result = passwordCracker(passwords, loginAttempt);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
