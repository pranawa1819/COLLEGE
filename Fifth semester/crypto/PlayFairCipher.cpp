#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char grid[5][5]; // 5x5  matrix to encipher or decipher
char keyword[26]; // cipher key
char msg[100]; // message
int mark[130], len, r, c; // necessary variables

void createGrid();
void showGrid();
void encipher();
void decipher();
void initialize();
void menu();

void initialize() {
    memset(mark, 0, sizeof(mark));
}

void menu() {
    initialize();
    int n;
    cout << "-----------Menu-------------\n";
    string op[] = {"1. Encrypt", "2. Decrypt", "3. Exit"};
    cout << op[0] << endl << op[1] << endl << op[2] << endl << "Enter choice: ";
    cin >> n;
    if (n == 1) encipher();
    else if (n == 2) decipher();
    else exit(1);
}

int main() {
    menu();
    return 0;
}

void decipher() {
    initialize();
    createGrid();
    cout << "Cypher text: ";
    char cypText[150]; // cypher text
    cin >> cypText;
    int l = strlen(cypText); //take length

    cout << "Decipher text: ";
    int P, Q, R, S;
    char x, y;
    for (int i = 0; i < l; i += 2) {
        x = toupper(cypText[i]);
        y = toupper(cypText[i+1]);
        int f1 = 0, f2 = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (x == grid[j][k]) {
                    P = j;
                    Q = k;
                    f1 = 1;
                }
                if (y == grid[j][k]) {
                    R = j;
                    S = k;
                    f2 = 1;
                }
                if (f1 && f2) break;
            }
            if (f1 && f2) break;
        }
        if (P == R) { // same row
            cout << grid[P][(Q + 4) % 5] << grid[R][(S + 4) % 5];
        } else if (Q == S) { // same column
            cout << grid[(P + 4) % 5][Q] << grid[(R + 4) % 5][S];
        } else { // opposite corner
            cout << grid[P][S] << grid[R][Q];
        }
    }
    cout << endl << endl;
    menu();
}

void encipher() {
    initialize();
    createGrid();
    cout << "Message to cipher: ";
    cin.ignore();
    cin.getline(msg, 100);
    int l = strlen(msg); // msg length
    char reqText[150]; // generate required text to encipher
    int in = 0;

    for (int i = 0; i < l; i++) {
        if (msg[i] == ' ') continue; // ignore all space from string
        if (toupper(msg[i]) == 'J') msg[i] = 'I'; // ignore J
        reqText[in++] = toupper(msg[i]);
        if (in % 2 == 1 && i < l - 1 && toupper(msg[i]) == toupper(msg[i+1])) { // if duplicate add 'X' after the first letter
            reqText[in++] = 'X';
        }
    }
    if (in % 2 != 0) reqText[in++] = 'X'; // if one character left, add 'X' after it

    cout << "Cipher text: ";
    int P, Q, R, S;
    char x, y;
    for (int i = 0; i < in; i += 2) {
        x = reqText[i];
        y = reqText[i+1];
        int f1 = 0, f2 = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (x == grid[j][k]) {
                    P = j;
                    Q = k;
                    f1 = 1;
                }
                if (y == grid[j][k]) {
                    R = j;
                    S = k;
                    f2 = 1;
                }
                if (f1 && f2) break;
            }
            if (f1 && f2) break;
        }
        if (P == R) { // same row
            cout << grid[P][(Q + 1) % 5] << grid[R][(S + 1) % 5];
        } else if (Q == S) { // same column
            cout << grid[(P + 1) % 5][Q] << grid[(R + 1) % 5][S];
        } else { // opposite corner
            cout << grid[P][S] << grid[R][Q];
        }
    }
    cout << endl << endl;
    menu();
}

void createGrid() {
    cout << "Keyword: ";
    cin >> keyword; // key of the cipher
    len = strlen(keyword); // size of input string
    mark['J'] = 1; // ignore J
    r = 0, c = 0; // initialize row and column

    // first populate the keyword
    for (int i = 0; i < len; i++) {
        if (!mark[toupper(keyword[i])]) { // ignore duplicates
            mark[toupper(keyword[i])] = 1;
            grid[r][c++] = toupper(keyword[i]);
            if (c % 5 == 0) { // increase row column
                c = 0;
                r++;
            }
        }
    }

    // complete rest of the matrix from unused characters starting from A
    for (int i = 'A'; i <= 'Z'; i++) {
        if (mark[i] == 0 && i != 'J') { // taking values that are not in the matrix already
            grid[r][c++] = i;
            mark[i] = 1;
            if (c % 5 == 0) {
                r++;
                c = 0;
            }
        }
    }
}

void showGrid() {
    cout << "5x5 Matrix" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
