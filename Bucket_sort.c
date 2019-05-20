#include <stdio.h>

int main() {
    FILE *input = fopen("\\input.txt", "r");
    FILE *output = fopen("\\output.txt", "w");
    int n = 0;
    fscanf(input, "%i", &n);
    char words[n][3];
    for (int i = 0; i < n; ++i) {
        fscanf(input, "%s", words[i]);
    }
    int index[n],index2[n];
    for (int i=0; i < n; ++i) {
        index[i] = i;
    }
    int dict[256] = {};
    int help = 0;
    for (int discharge = 2; discharge >= 0; --discharge){
        help = 0;
        for (int i = 0; i < 256; ++i){
            dict[i] = 0;
        }
        for (int i = 0; i < n; ++i){
            dict[words[index[i]][discharge]]++;
        }
        for (int i = 0; i < 256; ++i){
            help += dict[i];
            dict[i] = help - dict[i];
        }
        for (int i = 0; i < n; ++i){
            index2[dict[words[index[i]][discharge]]] = index[i];
            dict[words[index[i]][discharge]]++;
        }
        for (int i = 0; i < n; ++i){
            index[i] = index2[i];
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 3; ++j){
        fprintf(output, "%c", words[index[i]][j]);
    }
        fprintf(output, "\n");
    }
    return 0;
}
