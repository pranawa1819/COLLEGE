//3.	WAP to simulate a Turing Machine that accepts language L= {WcW^R|n>=1} over alphabet {a,b} using c++.
#include <iostream>
#include <cstring>

#define MAX_LENGTH 100

using namespace std;

char tape[MAX_LENGTH];
int tapehead = 1;
int state = 0;

int action(char input_char, char replace_with, char move, int new_state) {
    if (tape[tapehead] == input_char) {
        tape[tapehead] = replace_with;
        state = new_state;
        if (move == 'L') {
            tapehead -= 1;
        } else {
            tapehead += 1;
        }
        return 1;
    }
    return 0;
}

int main() {
    char string[MAX_LENGTH];
    cout << "Enter String: ";
    cin >> string;
    int length = strlen(string) + 2;
    memset(tape, 'B', length);
    int i = 1;
    for (int j = 0; j < strlen(string); j++) {
        tape[i] = string[j];
        i++;
    }

    int oldtapehead = -1;
    int accept = 0;
    while (oldtapehead != tapehead) {
        oldtapehead = tapehead;
        if (state == 0) {
            if (action('a', 'B', 'R', 1) || action('c', 'B', 'R', 6) || action('b', 'B', 'R', 4)) {
                continue;
            }
        } else if (state == 1) {
            if (action('a', 'a', 'R', 1) || action('b', 'b', 'R', 1) || action('c', 'c', 'R', 1) || action('B', 'B', 'L', 2)) {
                continue;
            }
        } else if (state == 2) {
            if (action('a', 'B', 'L', 3)) {
                continue;
            }
        } else if (state == 3) {
            if (action('a', 'a', 'L', 3) || action('b', 'b', 'L', 3) || action('c', 'c', 'L', 3) || action('B', 'B', 'R', 0)) {
                continue;
            }
        } else if (state == 4) {
            if (action('a', 'a', 'R', 4) || action('b', 'b', 'R', 4) || action('c', 'c', 'R', 4) || action('B', 'B', 'L', 5)) {
                continue;
            }
        } else if (state == 5) {
            if (action('b', 'B', 'L', 3)) {
                continue;
            }
        } else if (state == 6) {
            if (action('B', 'B', 'R', 7)) {
                continue;
            }
        } else {
            accept = 1;
        }
    }

    if (accept) {
        cout << "accept" << endl;
    } else {
        cout << "reject" << endl;
    }

    return 0;
}
