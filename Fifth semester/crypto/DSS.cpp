#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

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

// Function to generate DSA keys
void generateDSAKeys(long long p, long long q, long long &g, long long &x, long long &y) {
    // Generate a random x such that 1 < x < q
    x = rand() % (q - 1) + 1;

    // Calculate g = h^((p-1)/q) % p
    long long h = 2; // Example base, should be a primitive root modulo p
    g = modExp(h, (p - 1) / q, p);

    // Calculate y = g^x % p
    y = modExp(g, x, p);
}

// Function to sign a message
void signMessage(long long message, long long p, long long q, long long g, long long x, long long k, long long &r, long long &s) {
    if (k <= 0 || k >= q) {
        cout << "Invalid value for k." << endl;
        return;
    }
    long long r_temp = modExp(g, k, p) % q;
    long long k_inv = modInverse(k, q);
    s = (k_inv * ((message - x * r_temp) % q)) % q;
    r = r_temp;
}

// Function to verify a signature
bool verifySignature(long long message, long long r, long long s, long long p, long long q, long long g, long long y) {
    if (r <= 0 || r >= q || s <= 0 || s >= q) return false;

    long long w = modInverse(s, q);
    long long u1 = (message * w) % q;
    long long u2 = (r * w) % q;
    long long v = ((modExp(g, u1, p) * modExp(y, u2, p)) % p) % q;

    return v == r;
}

int main() {
    // Seed for random number generation
    srand(time(0));

    long long p, q, g, x, y, r, s, k;

    // Take prime numbers p and q as input
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter a prime number q (where q is a divisor of p-1): ";
    cin >> q;

    // Generate DSA keys
    generateDSAKeys(p, q, g, x, y);
    cout << "Public Key: (p = " << p << ", q = " << q << ", g = " << g << ", y = " << y << ")" << endl;
    cout << "Private Key: (x = " << x << ")" << endl;

    // Sign a message
    long long message;
    cout << "Enter a message (number) to sign: ";
    cin >> message;
    cout << "Enter a value for k (1 < k < " << q << "): ";
    cin >> k;
    signMessage(message, p, q, g, x, k, r, s);
    cout << "Signature: (r = " << r << ", s = " << s << ")" << endl;

    // Verify the signature
    long long receivedR, receivedS;
    cout << "Enter the signature values to verify (r and s): ";
    cin >> receivedR >> receivedS;

    if (verifySignature(message, receivedR, receivedS, p, q, g, y)) {
        cout << "Signature is valid." << endl;
    } else {
        cout << "Signature is invalid." << endl;
    }

    return 0;
}
