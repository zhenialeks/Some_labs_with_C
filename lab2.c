#include <stdio.h>

int main() {

    FILE *fin, *fout;
    int c;

    fin = fopen("input_lab2.txt", "r");
    fout = fopen("output.txt", "w");
    while ((c = getc(fin)) != EOF){
        if (c == 'a' || c == 'o' || c == 'e'||
            c == 'y' || c == 'u' || c == 'i'){
            putc(c, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}