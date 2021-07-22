#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
#define ll long long

string cypherSubEncrypt(string s, int offset = 5) {
	string alphapetSmall = "abcdefghijklmnopqrstuvwxyz", alphapetCap =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < (int) s.size(); i++) {
		if (isalpha(s[i])) {
			if (islower(s[i]))
				s[i] = alphapetSmall[(s[i] + offset - 'a') % 26];
			else
				s[i] = alphapetCap[(s[i] + offset - 'A') % 26];
		}
	}
	return s;
}

string cypherSubDecrypt(string s, int offset = 5) {
	string alphapetSmall = "abcdefghijklmnopqrstuvwxyz", alphapetCap =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < (int) s.size(); i++) {
		if (isalpha(s[i])) {
			if (islower(s[i])) {
				s[i] = alphapetSmall[(s[i] - offset - 'a' +26) % 26];
			} else {
				s[i] = alphapetCap[(s[i] - offset - 'A' + 26) % 26];
			}
		}
	}
	return s;
}
