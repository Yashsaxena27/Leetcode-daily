#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();
    int length = 0;

    int i = n - 1;

    // Step 1: Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Step 2: Count characters of last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);   // important: takes full line including spaces

    int result = lengthOfLastWord(s);

    cout << "Length of last word: " << result << endl;

    return 0;
}