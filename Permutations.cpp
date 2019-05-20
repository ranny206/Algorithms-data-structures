#include <iostream>
#include <string>

using namespace std;

string perm(int num, int pos);

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int pos = 0;
    string as = string(to_string(a).length(), '1');
    string bs = string(to_string(b).length(), '1');
    as = perm(a, pos);
    bs = perm(b, pos);
    if ((stoi(as) + stoi(bs) == c) && (as[0] != '0') && (bs[0] != '0')){
        cout << "YES"<< "\n";
        cout << stoi(as) << stoi(bs);
    }
    else{
        cout << "NO";
    }
    return 0;
}

string perm(int num, int pos){
    string s = to_string(num);
    if (pos > s.length()){
        return(s);
    }
    else{
        for(int i = pos; i < s.length(); i++){
            char buf = s[i];
            s[i] = s[pos];
            s[pos] = buf;
            perm(num, pos++);
            buf = s[i];
            s[i] = s[pos];
            s[pos] = buf;
        }
    }
}