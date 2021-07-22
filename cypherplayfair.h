#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

string removeSpaceAndLower(string key) {
	string op = "";
	for (int i = 0; i < (int) key.size(); i++) {
		if (isalpha(key[i])) // check if it's a character
			op += tolower(key[i]);
	}
	return op;
}


// this function implements the table and return it as a 2-d vector
vector<vector<char>> makeTable(string key) {
	int n = 5;		// the table dimension
	vector<vector<char>> arr(n, vector<char>(n));
	int ind1 = 0, ind2 = 0;
	string alpha = "abcdefghiklmnopqrstuvwxyz"; // removed j

	// removing the key letters from "alpha" to prevent duplication
	for (int i = 0; i < (int) key.size(); i++) {
		for (int j = 0; j < (int) alpha.size(); j++) {
			if (key[i] == alpha[j]) {
				alpha.erase(alpha.begin() + j);
			}
		}
	}

	//filling the table
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ind1 < (int) key.size()) {	// checking if the key string is done
				arr[i][j] = key[ind1++];
			} else {						// to start filling with "alpha"
				arr[i][j] = alpha[ind2++];

			}
		}
	}

	return arr;
}


// this function splits the message as pairs of characters
// and return these pairs as a vector of pairs
vector<pair<char, char>> split(string msg) {

	vector<pair<char, char>> pairs;

	for (int i = 0; i < (int) msg.size(); i += 2) {
		if ((int) msg.size() - i > 1) {
			pairs.push_back(make_pair(msg[i], msg[i + 1]));
			if (msg[i] == msg[i + 1]) {			// if two charcters are the same replace the second with 'x'
				if (msg[i] != 'x') {
					pairs[(int) pairs.size() - 1].second = 'x';
					i--;
				} else {
					pairs[(int) pairs.size() - 1].second = 'o'; // very edge case at which both
					i--;										// characters are 'x's
				}
			}
		} else {
			pairs.push_back(make_pair(msg[i], 'z'));	//append 'z' if the msg has odd number of characters
		}
	}
	return pairs;
}

// this function return the coordinates of the character in the table
// as a pair of intergers
pair<int, int> getCord(char c, vector<vector<char>> table) {
	pair<int, int> cord = make_pair(-1, -1);
	for (int i = 0; i < (int) table.size(); i++) {
		for (int j = 0; j < (int) table[i].size(); j++) {
			if (c == table[i][j]) {
				cord.first = i;
				cord.second = j;
				return cord;
			}
		}
	}
	return cord;
}


// This function does the encrypthion part
string playFairEncrypt(string key, string msg) {
	key = removeSpaceAndLower(key);			// removing spaces and lowering all the characters

	msg = removeSpaceAndLower(msg);

	vector<vector<char>> table = makeTable(key);

	vector<pair<char, char>> pairs = split(msg);	// splitting the msg into pairs of characters
	string op = "";
	for (int i = 0; i < (int) pairs.size(); i++) {
		pair<int, int> a = getCord(pairs[i].first, table); // cordinates of the first letter
		pair<int, int> b = getCord(pairs[i].second, table);// cordinates of the second letter

		if (a.second == b.second) {						// if they have the same coloumn
			op += table[(a.first + 1) % 5][a.second]; 	// we increment it by one coloumn down
			op += table[(b.first + 1) % 5][a.second];
		} else if (a.first == b.first) {				// if they have the same row
			op += table[a.first][(a.second + 1) % 5];	// we increment it by one row to the right
			op += table[b.first][(b.second + 1) % 5];
		} else {										// neither same row nor same coloumn
			op += table[a.first][b.second];
			op += table[b.first][a.second];
		}

	}
	return op;
}

string playFairDecrypt(string key, string msg) {
	key = removeSpaceAndLower(key);

	msg = removeSpaceAndLower(msg);

	vector<vector<char>> table = makeTable(key); // filling the table

	vector<pair<char, char>> pairs = split(msg);

	string op = "";

	for (int i = 0; i < (int) pairs.size(); i++) {
		pair<int, int> a = getCord(pairs[i].first, table);
		pair<int, int> b = getCord(pairs[i].second, table);

		if (a.second == b.second) {
			op += table[(a.first - 1) % 5][a.second];
			op += table[(b.first - 1) % 5][a.second];
		} else if (a.first == b.first) {
			op += table[a.first][(a.second - 1 + 5) % 5];// +5 is to prevent negative mod
			op += table[b.first][(b.second - 1 + 5) % 5];
		} else {
			op += table[a.first][b.second];
			op += table[b.first][a.second];
		}

	}
	return op;
}
