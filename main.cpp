#include <iostream>
#include <vector>
using namespace std;

class HangGame {
private:
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string key;
	string answer;
public:
	void Alphabet() {
		for (int i = 0; i < alphabet.size(); i++)
		{
			cout << alphabet[i] << " ";
		}
		cout << endl;
	}
	void Alphabet(char choice) {
		for (int i = 0; i < alphabet.size(); i++)
		{
			if (choice == alphabet[i]) {
				alphabet.erase(alphabet.begin() + i);
			}
		}
		cout << endl;
	}
	bool isIncluded(char selectedChar) {
		for (int i = 0; i < key.size(); i++) {
			if (selectedChar == key[i]) {
				return true;
			}
		}
		return false;
	}
	void addLetter(char select) {
		for (int i = 0; i < key.size(); i++) {
			if (key[i] == select) {
				answer[i] = select;
			}
		}
	}
	bool isFilled() {
		for (int i = 0; i < key.size(); i++) {
			if (answer[i] == '-') return true;
		}
		return false;
	}

	void run(string k) {
		key = k;
		answer.resize(key.size());
		for (int i = 0; i < key.size(); i++) {
			answer[i] = '-';
		}
		cout << " This answer has " << key.size() << " letters ";
		cout << " Here are unchosen letters " << endl;
		Alphabet();
		cout << " Please enter the letter that you choose: ";
		while (isFilled()) {
			char select;
			cin >> select;
			Alphabet(select);
			Alphabet();
			if (isIncluded(select)) {
				cout << " Good ";
				addLetter(select);
				for (auto i : answer) {
					cout << i << "  ";
				}
				cout << endl;
			}
			else {
				for (auto i : answer) {
					cout << i << "  ";
				}
				cout << endl;
			}
		}
		cout << " Wonderful !! You are the first person who completes this game, which means that you must be Alice!";
		cout << endl;
	}
};


int main() {
	HangGame game1;
	cout << " Enter the keyword ";
	string key;
	cin >> key;
	game1.run(key);
	return 0;
}
