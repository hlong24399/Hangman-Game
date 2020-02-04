#include <iostream>
#include <iomanip>
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

	void hanging(int num) {
		cout << endl;
		switch (num) {
		case 0:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           " << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\			" << endl;
			break;
		case 1:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\			" << endl;
			break;
		case 2:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |          /|" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\			" << endl;
			break;
		case 3:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |          /|\\" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\			" << endl;
			break;
		case 4:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |          /|\\" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\		" << endl;
			break;
		case 5:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |          /|\\" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |          /" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\			" << endl;
			break;
		case 6:
			cout << setw(10) << "" << "  ____________" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |           |" << endl;;
			cout << setw(10) << "" << " |           O" << endl;
			cout << setw(10) << "" << " |          /|\\" << endl;
			cout << setw(10) << "" << " |           |" << endl;
			cout << setw(10) << "" << " |          / \\" << endl;
			cout << setw(10) << "" << " |			" << endl;
			cout << setw(10) << "" << "/ \\         " << endl;
			break;
		}


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
		int losingCount = 0;
		hanging(0);
		int winningCount = 0;
		while (isFilled() && losingCount != 6) {
			char select;
			cin >> select;
			Alphabet(select);
			Alphabet();
			
			if (isIncluded(select)) {
				cout << endl;
				addLetter(select);
				for (auto i : answer) {
					cout << i << "  ";
				}
				cout << endl;
				switch (winningCount) {
				case 0:
					cout << " Good " << endl;
					break;
				case 1:
					cout << " Eh, not bad. " << endl;
					break;
				case 2:
					cout << " Yo! That's brilliant!" << endl;
					break;
				case 3:
					cout << " No kidding, y'all!!! " << endl;
					break;
				case 4:
					cout << " God damn! I can't imagine! *passed out* " << endl;
					break;

				}
				winningCount++;

			}

			else {
				///Something here as hangman
				losingCount++;
				hanging(losingCount);
				for (auto i : answer) {
					cout << i << "  ";
				}
				cout << endl;
			}
		}
		cout << setw(10) << "" << " Well, the game is done. HOWEVER!!! Wanna try again? Kiss that guy twice  " << endl;
	}
};


int main() {
	HangGame game1;
	cout << " Enter the key word ";
	string key;
	cin >> key;
	game1.run(key);
	return 0;
}
