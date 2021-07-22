#include "cypherSub.h"
#include "cypherplayfair.h"
#include "RAS.h"
#include "cypherTrans.h"

int main() {
	while (true) {
		cout << "Enter 'E' for Encryption or 'D' for Decryption\n";
		char c;
		cin >> c;
		if (c == 'E') {
			cout
					<< "Enter 1 for cypher sub method \n      2 for cypher trans method  \n      3 for cipher play fair method\n      4 for RAS method\n";
			int in;
			while (cin >> in) {
				if (in < 1 || in > 4)
					cout << "invalid input!\n";
				else
					break;
			}

			if (in == 1) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the offset : ";
				int offset;
				cin >> offset;
				string op = cypherSubEncrypt(s, offset);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 2) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the key : ";
				string key;
				cin >> key;
				string op = cypherTransEncrypt(s, key);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 3) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the key : ";
				string key;
				cin >> key;
				string op = playFairEncrypt(key, s);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 4) {
				cout << "Enter the message(number) : ";
				double long s;
				cin >> s;
				double long op = RSAEncrypt(s);
				cout << "Encrypted message : " << op << endl;
			}

		}

		else if (c == 'D') {

			cout
					<< "Enter 1 for cypher sub method \n      2 for cypher trans method  \n      3 for cipher play fair method\n      4 for RAS method\n";
			int in;
			while (cin >> in) {
				if (in < 1 || in > 4)
					cout << "invalid input!\n";
				else
					break;
			}
			if (in == 1) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the offset : ";
				int offset;
				cin >> offset;
				string op = cypherSubDecrypt(s, offset);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 2) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the key : ";
				string key;
				cin >> key;
				string op = cypherTransDecrypt(s, key);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 3) {
				cout << "Enter the message : ";
				string s;
				cin.ignore();
				getline(cin, s);
				cout << "Enter the key : ";
				string key;
				cin >> key;
				string op = playFairDecrypt(key, s);
				cout << "Encrypted message : " << op << endl;
			} else if (in == 4) {
				cout << "Enter the message(number) : ";
				double long s;
				cin >> s;
				double long op = RSADecrypt(s);
				cout << "Encrypted message : " << op << endl;
			}

		} else {
			cout << "invalid input\n";
		}
		cout << endl;
	}
	return 0;
}
