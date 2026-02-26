#include <iostream>
#include <string>
using namespace std;

int numSteps(string s) {
    int steps = 0;
    int carry = 0;

    // Traverse from right to left (ignore first bit)
    for (int i = s.length() - 1; i > 0; i--) {
        int bit = (s[i] - '0') + carry;

        if (bit % 2 == 0) {
            // Even → divide by 2
            steps += 1;
        } else {
            // Odd → add 1 then divide
            steps += 2;
            carry = 1;
        }
    }

    return steps + carry;
}

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    int result = numSteps(s);
    cout << "Number of steps: " << result << endl;

    return 0;
}