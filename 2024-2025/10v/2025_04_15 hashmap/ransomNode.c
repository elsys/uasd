#include<stdio.h>
#include<stdlib.h>

int canMake(char* ransomNote, char* magazine) {
    int letterOcurrances[26] = {0};

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        letterOcurrances[ransomNote[i] - 'a']++;
    }

    for (int i = 0; magazine[i] != '\0'; i++) {
        if (--letterOcurrances[magazine[i] - 'a'] < 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

}