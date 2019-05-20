#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> shush;
vector<int> score;
string perm;
int p;
int q;
int counter = 0;
int k = 0;
bool f = false;

ifstream fin("input.txt");
ofstream fout("output.txt");

void gen(int pos);

int main() {
    fin >> p >> q;
    shush.resize(p);
    score.resize(p);
    for (int i = 0; i < p; i++) {
        fin >> shush[i];
        fin >> score[i];
    }
    int pos = 0;
    perm = string(q, '-');
    gen(pos);
    return 0;
}

void gen(int pos) {
    if (pos == q) {
        perm = perm;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                  if (perm[j] == shush[i][j]) {
                    counter++;
                }
            }
            int c = counter;
            if (counter == score[i]) {
                k++;
            }
            counter = 0;
            if (c != score[i]) {
                break;
            }

        }
        if (!f){
            if (k == p) {
                fout << perm;
                f = true;
                k = 0;
                return;
            }
        }
    }
    else {
        k = 0;
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                perm[pos] = '+';
            }
            else {
                perm[pos] = '-';
            }
            gen(pos + 1);
        }
    }
}