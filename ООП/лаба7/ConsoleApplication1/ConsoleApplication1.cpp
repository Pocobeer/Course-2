#include<iostream>
#include<string>
using namespace std;
class Word {
	string word;
public:
	Word(string w) :word(w) {};
	void inputWord() {
		cout << "Enter word: ";
		cin >> word;
	}
	static int count;
	static int Get_Count() {
		return count;
	}
	void showWord() {
	cout << word << endl;
	}
};
int Word::count = 0;
class WordCount : public Word {
	int wordCount;
public:
	WordCount(string w) :Word(w) {
		wordCount = 1;
		for (int i = 0; i < w.length(); i++) {
			if (w[i] == ' ') {
				wordCount++;
			}
		}
	}
	void showWordCount() {
		showWord();
		cout << wordCount << endl;
	}
	static void Set_Count() {
		count = 0;
	}
};

int main() {
	Word w_1("Pupupu");
	w_1.showWord();
	cout << "type of class:" << typeid(w_1).name() << endl;
	WordCount w_2("Pupupupu pupupu");
	cout << "type of class:" << typeid(w_1).name() << endl;
	w_2.showWordCount();
	cout << "type of class:" << typeid(w_2).name() << endl;
	

}