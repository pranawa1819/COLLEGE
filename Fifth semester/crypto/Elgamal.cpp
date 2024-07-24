#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to calculate (a^b) % p
long long modExp(long long a, long long b, long long p) {
    long long res = 1;
    a = a % p;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % p;
        b = b >> 1; // b = b/2
        a = (a * a) % p;
    }
    return res;
}

int main() {
    // Public key components
    long long p; // large prime number
    long long g; // primitive root modulo p
    long long y; // g^x % p

    // Private key
    long long x; // chosen such that 1 < x < p-1

    // Take prime number p and primitive root g as input
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter a primitive root g: ";
    cin >> g;

    // Take private key x as input
    cout << "Enter a private key x (1 < x < " << p - 1 << "): ";
    cin >> x;

    // Generate public key y
    y = modExp(g, x, p);

    cout << "Private key x = " << x << endl;
    cout << "Public key (p, g, y) = (" << p << ", " << g << ", " << y << ")" << endl;

    // Encryption
    long long message;
    cout << "Enter a message to encrypt (as a number): ";
    cin >> message;

    // Take random number k as input
    long long k;
    cout << "Enter a random number k (1 < k < " << p - 1 << "): ";
    cin >> k;

    // Calculate a = g^k % p
    long long a = modExp(g, k, p);

    // Calculate b = (message * y^k) % p
    long long b = (message * modExp(y, k, p)) % p;

    cout << "Encrypted message (a, b) = (" << a << ", " << b << ")" << endl;

    // Decryption
    long long decryptedMessage = (b * modExp(a, p - 1 - x, p)) % p;
    cout << "Decrypted message = " << decryptedMessage << endl;

    return 0;
}
