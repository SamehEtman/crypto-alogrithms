#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
#define dl double long

/*
 1. Choose two prime numbers p and q.
 2. Compute n = p*q.
 3. Calculate phi = (p-1) * (q-1).
 4. Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
 5. Calculate d as d ≡ e−1 (mod phi(n)); here, d is the modular multiplicative inverse of e modulo phi(n).
 6. For encryption, c = me mod n, where m = original message.
 7. For decryption, m = c d mod n.
 * */
int gcd(int a, int h) {
	int temp;
	while (1) {
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}
dl RSAEncrypt(dl message) {

	dl p = 3; // we assume the prime numbers are 3 , 7
	dl q = 7;
	dl n = p * q; //calculate n
	dl phi = (p - 1) * (q - 1); //calculate phi
	dl track;
	//public key
	//e stands for encrypt
	dl e = 2;
	//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
	while (e < phi) {
		track = gcd((int) e, (int) phi);
		if (track == 1)
			break;
		else
			e++;
	}

	dl c = pow(message, e); //encrypt the message
	c = fmod(c, n);

	return c;
}

dl RSADecrypt(dl message) {

	dl p = 3; // we assume the prime numbers are 3 , 7
	dl q = 7;
	dl n = p * q; //calculate n = 21
	dl phi = (p - 1) * (q - 1); //calculate phi wich will equal 12
	dl track;
	//public key
	//e stands for encrypt
	dl e = 2;
	//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
	while (e < phi) {
		track = gcd((int) e, (int) phi);
		if (track == 1)
			break;
		else
			e++;
	}
	// Private key (d stands for decrypt)
	// choosing d such that it satisfies
	// d*e = 1 + k * totient
	int k = 2;  // A constant value
	double d = (1 + (k * phi)) / e;
	dl m = pow(message, d);
	m = fmod(m, n);
	return m;
}
