#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to compute (a^b) % m
long long modExp(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return result;
}

// Function to compute gcd of a and b
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse of a under modulo m
long long modInverse(long long a, long long m) {
    a = a % m;
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Should not happen if m is prime and a is coprime with m
}

// Function to generate RSA keys
void generateKeys(long long p, long long q, long long &n, long long &e, long long &d) {
    n = p * q;
    long long phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 17; // Example e
    while (gcd(e, phi) != 1) {
        e++;
    }

    // Compute d, the modular multiplicative inverse of e mod phi
    d = modInverse(e, phi);
}

// Function to sign a message
long long signMessage(long long message, long long d, long long n) {
    return modExp(message, d, n);
}

// Function to verify a signature
bool verifySignature(long long message, long long signature, long long e, long long n) {
    long long decryptedMessage = modExp(signature, e, n);
    return (message == decryptedMessage);
}

int main() {
    // Seed for random number generation
    srand(time(0));

    long long p, q, n, e, d;

    // Take prime numbers p and q as input
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter another prime number q: ";
    cin >> q;

    // Generate RSA keys
    generateKeys(p, q, n, e, d);
    cout << "Public Key: (n = " << n << ", e = " << e << ")" << endl;
    cout << "Private Key: (d = " << d << ")" << endl;

    // Sign a message
    long long message;
    cout << "Enter a message (number) to sign: ";
    cin >> message;
    long long signature = signMessage(message, d, n);
    cout << "Signature: " << signature << endl;

    // Verify the signature
    long long receivedSignature;
    cout << "Enter the signature to verify: ";
    cin >> receivedSignature;

    if (verifySignature(message, receivedSignature, e, n)) {
        cout << "Signature is valid." << endl;
    } else {
        cout << "Signature is invalid." << endl;
    }

    return 0;
}
