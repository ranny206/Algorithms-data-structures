#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int a, b, c;
vector<bool> is_used;
map<int, int> all_a;

void gen_a(int pos, string s, string perm);
void gen_b(int pos, string s, string perm);

int main() {
    fin >> a >> b >> c;
    string a_str = to_string(a);
    string b_str = to_string(b);
    int pos = 0;
    string a_perm = string(a_str.length(), '1');
    string b_perm = string(b_str.length(), '1');
    if (a_str.length() > b_str.length()){
        is_used.resize(a_str.length());
    }
    else{
        is_used.resize(b_str.length());
    }
    gen_a(pos, a_str, a_perm);
    gen_b(pos, b_str, b_perm);
    fout << "NO";
    fin.close();
    fout.close();
    return 0;

}

void gen_a(int pos, string s, string perm){
    if (pos == s.length()) {
        if (perm[0] != '0'){
            all_a.insert({c - stoi(perm), stoi(perm)});
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (!is_used[i]) {
            is_used[i] = true;
            perm[pos] = s[i];
            gen_a(pos + 1, s, perm);
            is_used[i] = false;
        }
    }
}
void gen_b(int pos, string s, string perm){
    if (pos == s.length()) {
        if (all_a.find(stoi(perm)) != all_a.end()){
            if (perm[0] != '0'){
                fout << "YES" << "\n";
                fout << c - stoi(perm) << ' ' << stoi(perm);
                exit(0);
            }
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (!is_used[i]) {
            is_used[i] = true;
            perm[pos] = s[i];
            gen_b(pos + 1, s, perm);
            is_used[i] = false;
        }
    }
}