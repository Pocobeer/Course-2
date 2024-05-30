#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <fstream>
//#include <Windows.h>
using namespace std;

enum State {
    S0, // Начальное состояние
    I,  // Идентификаторы и ключевые слова
    L,  // Литералы 
    O,  // Операторы
    S,  // Разделители
    C,  // Комментарий
    F,  // Конечное состояние
    E   // Ошибочное состояние
};

const map<wstring, wstring> keywords = {
    {L"int", L"KEYWORD"}, {L"float", L"KEYWORD"}, {L"if", L"KEYWORD"},
    {L"else", L"KEYWORD"}, {L"while", L"KEYWORD"}, {L"return", L"KEYWORD"},
    {L"char", L"KEYWORD"}, {L"double", L"KEYWORD"}, {L"for", L"KEYWORD"}, {L"void", L"KEYWORD"}
};

const map<wchar_t, wstring> operators = {
    {L'+', L"OPERATOR"}, {L'-', L"OPERATOR"}, {L'*', L"OPERATOR"},
    {L'/', L"OPERATOR"}, {L'=', L"OPERATOR"}, {L'<', L"OPERATOR"},
    {L'>', L"OPERATOR"}, {L'!', L"OPERATOR"}
};

const map<wchar_t, wstring> separators = {
    {L'\n', L"SEPARATOR"}, {L'\t', L"SEPARATOR"},
    {L'(', L"SEPARATOR"}, {L')', L"SEPARATOR"}, {L'{', L"SEPARATOR"},
    {L'}', L"SEPARATOR"}, {L';', L"SEPARATOR"}, {L',', L"SEPARATOR"}
};

const wstring invalidSymbols = L"@#$абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

class Token {
public:
    virtual wstring getType() const = 0;
    virtual wstring getValue() const = 0;
    virtual ~Token() = default;
};

class IdentifierToken : public Token {
private:
    wstring value;
public:
    IdentifierToken(const wstring& val) : value(val) {}
    wstring getType() const override {
        if (keywords.count(value)) {
            return L"Ключевое слово";
        }
        else {
            return L"Идентификатор";
        }
    }
    wstring getValue() const override {
        return value;
    }
};

class LiteralToken : public Token {
private:
    wstring value;
public:
    LiteralToken(const wstring& val) : value(val) {}
    wstring getType() const override {
        return L"Литерал";
    }
    wstring getValue() const override {
        return value;
    }
};

class OperatorToken : public Token {
private:
    wchar_t value;
public:
    OperatorToken(wchar_t val) : value(val) {}
    wstring getType() const override {
        return L"Оператор";
    }
    wstring getValue() const override {
        return wstring(1, value);
    }
};

class SeparatorToken : public Token {
private:
    wchar_t value;
public:
    SeparatorToken(wchar_t val) : value(val) {}
    wstring getType() const override {
        return L"Разделитель";
    }
    wstring getValue() const override {
        return wstring(1, value);
    }
};

// Функция переходов конечного автомата
State transition(State current, wchar_t input) {
    switch (current) {
    case S0:
        if (iswalpha(input) || input == L'_') return I;
        if (iswdigit(input)) return L;
        if (input == L'/') return C;
        if (operators.count(input)) return O;
        if (separators.count(input)) return S;
        return F;
    case I:
        if (iswalnum(input) || input == L'_') return I;
        return F;
    case L:
        if (iswdigit(input)) return L;
        if (iswalpha(input) || input == L'_') return E; // Если после цифр идут буквы или '_', переходим в ошибочное состояние
        return F;
    case O:
        if (input == L'/') return C; // Переход в состояние комментария
        return F;
    case C:
        if (input == L'\n') return S0; // Комментарий завершается новой строкой
        return C; // Оставаться в состоянии комментария
    case S:
        return F;
    default:
        return F;
    }
}

void createToken(const wstring& token, size_t position, size_t tokenNumber, vector<pair<Token*, wstring>>& tokens) {
    bool hasInvalid = false;
    for (wchar_t ch : token) {
        if (invalidSymbols.find(ch) != wstring::npos) {
            hasInvalid = true;
            break;
        }
    }

    if (hasInvalid) {
        wcout << L"Токен: " << token << L", ошибка: наличие недопустимых символов (Токен №" << tokenNumber << L")" << endl;
        return; // Пропускаем токен с недопустимыми символами
    }

    wstring tokenType;

    auto it_kw = keywords.find(token);
    if (it_kw != keywords.end()) {
        tokenType = it_kw->second;
        tokens.push_back(make_pair(new IdentifierToken(token), tokenType));
        return;
    }

    auto it_op = operators.find(token[0]);
    if (it_op != operators.end()) {
        tokenType = it_op->second;
        tokens.push_back(make_pair(new OperatorToken(token[0]), tokenType));
        return;
    }

    auto it_sep = separators.find(token[0]);
    if (it_sep != separators.end()) {
        tokenType = it_sep->second;
        tokens.push_back(make_pair(new SeparatorToken(token[0]), tokenType));
        return;
    }

    if (token.find_first_not_of(L"0123456789") == wstring::npos) {
        tokenType = L"Литерал";
        tokens.push_back(make_pair(new LiteralToken(token), tokenType));
        return;
    }

    tokenType = L"Идентификатор"; // Если не обнаружено недопустимых символов, считаем токен идентификатором
    tokens.push_back(make_pair(new IdentifierToken(token), tokenType));
}

void lexicalAnalysis(const wstring& input) {
    State currentState = S0;
    wstring token;
    vector<pair<Token*, wstring>> tokens;

    size_t position = 0;
    size_t tokenNumber = 1;

    for (size_t i = 0; i < input.length(); ++i) {
        wchar_t ch = input[i];
        State nextState = transition(currentState, ch);

        if (nextState == F || nextState == E) {
            if (!token.empty()) {
                if (nextState == E) {
                    wcout << L"Токен: " << token + ch << L", ошибка: требуется идентификатор (Токен №" << tokenNumber++ << L")" << endl;
                    token.clear();
                    while (i < input.length() && !iswspace(input[i]) && separators.find(input[i]) == separators.end() && operators.find(input[i]) == operators.end()) {
                        ++i;
                        //token += input[i];
                    }
                    currentState = S0;
                    continue;
                }
                else {
                    createToken(token, position, tokenNumber++, tokens);
                }
            }
            token.clear();
            currentState = transition(S0, ch);
            position = i;
            if (currentState != F && currentState != C && !iswspace(ch)) {
                token += ch;
            }

        }
        else if (nextState == C) {
            currentState = C;
            while (i < input.length() && input[i] != L'\n') {
                ++i;
            }
        }
        else {
            token += ch;
            currentState = nextState;
        }

        if (invalidSymbols.find(ch) != wstring::npos) {
            if (!token.empty()) {
                wcout << L"Токен: " << token << L", ошибка: наличие недопустимых символов (Токен №" << tokenNumber++ << L")" << endl;
                token.clear();
            }
            while (i + 1 < input.length() && separators.find(input[i + 1]) == separators.end() && operators.find(input[i + 1]) == operators.end()) {
                ++i;
            }
            currentState = S0;
        }
    }

    if (!token.empty()) {
        createToken(token, position, tokenNumber++, tokens);
    }

    for (const auto& t : tokens) {
        wcout << L"Токен: " << t.first->getValue() << L", тип: " << t.first->getType() << endl;
        delete t.first;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    wstring input = L"int maiававn() Pnt_22 22pytr { int x = 42; if (x > 0) returШn x; } // Это комментарий\n if (x > 0) return x; // Еще один комментарий\n }";
    wcout << L"Строка для показа работы программы: " << input << endl;
    cout << "Итоги анализа: " << endl;
    lexicalAnalysis(input);
    return 0;
}
