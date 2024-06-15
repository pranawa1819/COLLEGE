#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int mod(int a, int m) {
    return (a % m + m) % m;
}

int gcdExtended(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        throw runtime_error("Modular inverse does not exist");
    else {
        int res = (x % m + m) % m;
        return res;
    }
}

void getCofactor(const vector<vector<int>>& a, vector<vector<int>>& temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = a[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(const vector<vector<int>>& a, int n) {
    if (n == 1)
        return a[0][0];

    int det = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(a, temp, 0, f, n);
        det = mod(det + sign * a[0][f] * determinant(temp, n - 1), 26);
        sign = -sign;
    }

    return det;
}

void adjoint(const vector<vector<int>>& a, vector<vector<int>>& adj) {
    int n = a.size();
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    vector<vector<int>> temp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(a, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = mod(sign * determinant(temp, n - 1), 26);
        }
    }
}

bool inverse(const vector<vector<int>>& a, vector<vector<int>>& inv) {
    int n = a.size();
    int det = determinant(a, n);
    if (det == 0) {
        cout << "Inverse does not exist";
        return false;
    }

    vector<vector<int>> adj(n, vector<int>(n));
    adjoint(a, adj);

    int invDet = modInverse(det, 26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = mod(adj[i][j] * invDet, 26);
        }
    }
    return true;
}

void encrypt(const vector<vector<int>>& keyMatrix, const string& message, string& result) {
    int n = keyMatrix.size();
    string paddedMessage = message;
    int temp = (n - paddedMessage.size() % n) % n;
    for (int i = 0; i < temp; i++) {
        paddedMessage += 'x';
    }

    int k = 0;
    while (k < paddedMessage.size()) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (int j = 0; j < n; j++) {
                sum += (keyMatrix[i][j] * (paddedMessage[temp++] - 'a')) % 26;
                sum = mod(sum, 26);
            }
            result += (sum + 'a');
        }
        k += n;
    }
}

void decrypt(const vector<vector<int>>& inverseMatrix, const string& message, string& result) {
    int n = inverseMatrix.size();
    int k = 0;
    while (k < message.size()) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (int j = 0; j < n; j++) {
                sum += (inverseMatrix[i][j] * (message[temp++] - 'a')) % 26;
                sum = mod(sum, 26);
            }
            result += (sum + 'a');
        }
        k += n;
    }
}

int main() {
    int n;
    cout << "Enter the size of key matrix: ";
    cin >> n;
    cout << "Enter the key matrix: \n";
    vector<vector<int>> keyMatrix(n, vector<int>(n));
    vector<vector<int>> inverseMatrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> keyMatrix[i][j];
        }
    }

    if (!inverse(keyMatrix, inverseMatrix)) {
        return 1;
    }

    string message;
    cout << "Enter the message to encrypt: ";
    cin >> message;

    string encryptedMessage = "";
    encrypt(keyMatrix, message, encryptedMessage);
    cout << "Encrypted message: " << encryptedMessage << '\n';

    string decryptedMessage = "";
    decrypt(inverseMatrix, encryptedMessage, decryptedMessage);
    cout << "Decrypted message: " << decryptedMessage << '\n';

    return 0;
}
