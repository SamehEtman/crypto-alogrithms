#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
#define ll long long
string cypherTransEncrypt(string s, string key) {
	int x = s.size(), y = key.size();
	char arr[(x + y - 1) / y][y];
	x = (x + y - 1) / y;
	int ind = 0;

	// filling the table
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (ind < (int) s.size())
				arr[i][j] = s[ind++];
			else
				arr[i][j] = '?'; // if the word's length doesn't fit the table fill it with '?'
		}
	}
	vector<pair<char, int>> v(key.size()); // to associate the alphabets' order with the no. column
	string op; // final output variable

	for (int i = 0; i < y; i++) {
		v[i].first = key[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end()); // sorting alphabetically


	for (int i = 0; i < y; i++) {
		string temp = "";
		for (int j = 0; j < x; j++) {
			temp += arr[j][v[i].second];
		}
		op += temp;
	}
	// this commented section shows the table after rearranging it

	/*for (int i = 0; i < x; i++) {
	 for (int j = 0; j < y; j++) {
	 cout << arr[i][j] << ' ';
	 }
	 cout << endl;
	 }
	 */
	return op;
}

string cypherTransDecrypt(string s, string key) {
	int x = s.size(), y = key.size();
	char arr[(x + y - 1) / y][y];
	x = (x + y - 1) / y;
	int ind = 0;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			arr[j][i] = s[ind++];
		}
	}
	/*for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<pair<char, int>> v(key.size());
	for (int i = 0; i < y; i++) {
		v[i].first = key[i];
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	/*
	for (int i = 0; i < y; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}*/
	vector<vector<char>> op(x, vector<char>(y));
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			op[j][v[i].second] = arr[j][i];
		}
	}

	string ans;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			ans += op[i][j];
		}
	}
	return ans;
}
