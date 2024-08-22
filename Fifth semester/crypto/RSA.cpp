#include <iostream>
#include <math.h>
using namespace std;

// Function to find gcd
int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main() {
    // Variables for user input
    double p, q;
    
    // Take prime numbers as input from the user
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter another prime number q: ";
    cin >> q;

    // Calculate n
    double n = p * q;
    double track;
    double phi = (p - 1) * (q - 1); // Calculate phi

    // Public key
    // e stands for encrypt
    double e = 7;

    // Ensure that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while (e < phi) {
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }

    // Private key
    // d stands for decrypt
    // Choosing d such that it satisfies d*e = 1 mod phi
    double d1 = 1 / e;
    double d = fmod(d1, phi);

    // Take message as input from the user
    double message;
    cout << "Enter a message to encrypt: ";
    cin >> message;

    // Encrypt the message
    double c = pow(message, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);

    // Output the results
    cout << "Original Message = " << message;
    cout << "\n p = " << p;
    cout << "\n q = " << q;
    cout << "\n n = pq = " << n;
    cout << "\n phi = " << phi;
    cout << "\n e = " << e;
    cout << "\n d = " << d;
    cout << "\n Encrypted message = " << c;
    cout << "\n Decrypted message = " << m << endl;

    return 0;
}
