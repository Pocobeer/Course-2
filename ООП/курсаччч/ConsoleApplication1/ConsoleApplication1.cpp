﻿#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Базовый класс для всех лексем
class Lexeme {

    string name;

public:
    Lexeme(const string& name) : name(name) {}
    virtual string getClass() const = 0;
};

// Класс для идентификаторов
class Identifier : public Lexeme {
public:
    Identifier(const string& name) : Lexeme(name) {}
    string getClass() const override {
        return "Идентификатор";
    }
};

// Класс для ключевых слов
class Keyword : public Lexeme {
public:
    Keyword(const string& name) : Lexeme(name) {}
    string getClass() const {
        return "Ключевое слово";
    }
};

// Класс для знаков операций
class Operator : public Lexeme {
public:
    Operator(const string& name) : Lexeme(name) {}
    string getClass() const {
        return "Знак операции";
    }
};

// Класс для литералов
class Literal : public Lexeme {
public:
    Literal(const string& name) : Lexeme(name) {}
    string getClass() const {
        return "Литерал";
    }
};

// Класс для разделителей
class Delimiter : public Lexeme {
public:
    Delimiter(const string& name) : Lexeme(name) {}
    string getClass() const {
        return "Разделитель";
    }
};

// Класс для анализатора лексем
class LexicalAnalyzer {
private:
    unordered_map<string, Lexeme*> lexemes;

public:
    LexicalAnalyzer() {
        string identifiers[] = { "int", "float", "char", "string", "bool", "double",
    "long", "short", "unsigned", "signed", "void", "struct", "class", "enum",
    "typedef", "namespace", "const", "static", "extern", "auto" };//Идентификаторы
        string keywords[] = { "if", "else", "while", "for", "return", 
            "switch", "case", "break", "continue", "do", "class", "public", 
            "private", "protected", "virtual" };//Ключевые слова
        string operators[] = { "+", "-", "*", "/", "=", "==", "!=", "<", ">", 
            "<=", ">=", "&&", "||", "++", "--", "+=", "-=", "*=", "/=" };//Операторы
        string literals[] = { "123", "3.14", "'a'", "\"Hello\"", "true", "false", 
            "0xFF", "0b1010", "1.23e4", "0" };//Литералы(константные значения)
        string delimiters[] = { ";", ",", "(", ")", "{", "}", "[", "]", ":", 
            ".", "->", "::", "#", "//", "/*", "*/" };//Разделители
        for (const string& identifier : identifiers) {
            lexemes[identifier] = new Identifier(identifier);
        }
        for (const string& keyword : keywords) {
            lexemes[keyword] = new Keyword(keyword);
        }
        for (const string& operator_ : operators) {
            lexemes[operator_] = new Operator(operator_);
        }
        for (const string& literal : literals) {
            lexemes[literal] = new Literal(literal);
        }
        for (const string& delimiter : delimiters) {
			lexemes[delimiter] = new Delimiter(delimiter);
        }
    }

    ~LexicalAnalyzer() = default;

    void analyzeLexeme(const string& lexeme) {
        if (lexemes.find(lexeme) != lexemes.end()) {
            cout << "Лексема: " << lexeme << " - Класс: " << lexemes[lexeme]->getClass() << endl;
        }
        else {
            cout << "Лексема: " << lexeme << " - Класс: Неизвестный" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    LexicalAnalyzer analyzer;

    // Пример анализа лексем
    analyzer.analyzeLexeme("int");
    analyzer.analyzeLexeme("if");
    analyzer.analyzeLexeme("/");
    analyzer.analyzeLexeme("123");
    analyzer.analyzeLexeme("(");
    analyzer.analyzeLexeme("xyz"); // Неизвестная лексема

    return 0;
}
