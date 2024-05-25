#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <fstream>
#include <tuple>

using namespace std;

enum State { START, IDENTIFIER, LITERAL, OPERATOR, DELIMITER, UNKNOWN };

class LexicalAnalyzer {
private:
    set<string> keywords = { "if", "else", "while", "for", "return", "switch", "case",
                            "break", "continue", "do", "class", "public", "private",
                            "protected", "virtual" };
    set<string> operators = { "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=",
                             "&&", "||", "++", "--", "+=", "-=", "*=", "/=" };
public:
    pair<string, State> transition(State current, char input, string lexeme) {
        switch (current) {
        case START:
            if (isalpha(input) || input == '_') return { "Идентификатор", IDENTIFIER };
            if (isdigit(input)) return { "Литерал", LITERAL };
            if (input == '+' || input == '-' || input == '*' || input == '/' ||
                input == '=' || input == '<' || input == '>' || input == '!' ||
                input == '&' || input == '|') return { "Знак операции", OPERATOR };
            if (input == ';' || input == ',' || input == '(' || input == ')' ||
                input == '{' || input == '}' || input == '[' || input == ']' ||
                input == ':' || input == '.' || input == '#') return { "Разделитель", DELIMITER };
            break;
        case IDENTIFIER:
            if (isalnum(input) || input == '_') return { "Идентификатор", IDENTIFIER };
            break;
        case LITERAL:
            if (isdigit(input)) return { "Литерал", LITERAL };
            break;
        case OPERATOR:
            return { "Знак операции", OPERATOR };
        case DELIMITER:
            return { "Разделитель", DELIMITER };
        default:
            return { "Неизвестный", UNKNOWN };
        }
        return { "Неизвестный", UNKNOWN };
    }

    string analyzeLexeme(const string& lexeme) {
        State currentState = START;
        string currentClass = "Неизвестный";
        for (char ch : lexeme) {
            tie(currentClass, currentState) = transition(currentState, ch, lexeme);
            if (currentState == UNKNOWN) return "Неизвестный";
        }

        if (currentState == IDENTIFIER && keywords.find(lexeme) != keywords.end()) {
            return "Ключевое слово";
        }

        return currentClass;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string inputFileName, outputFileName;
    cout << "Введите имя входного файла: ";
    cin >> inputFileName;
    cout << "Введите имя выходного файла: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cout << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    LexicalAnalyzer analyzer;
    string lexeme;
    while (inputFile >> lexeme) {
        string result = analyzer.analyzeLexeme(lexeme);
        cout << "Лексема: " << lexeme << " - Класс: " << result << endl;
    }
    while (inputFile >> lexeme) {
        string result = analyzer.analyzeLexeme(lexeme);
        outputFile << "Лексема: " << lexeme << " - Класс: " << result << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Анализ завершен. Результаты сохранены в " << outputFileName << endl;

    return 0;
}
