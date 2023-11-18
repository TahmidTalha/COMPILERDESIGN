#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> keywords = {"int", "float", "char", "if", "else", "while", "for"};
unordered_set<string> operators = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "!="};

bool isKeyword(const string& word) {
    return keywords.count(word) > 0;
}

bool isOperator(const string& word) {
    return operators.count(word) > 0;
}

bool isIdentifier(const string& word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }
    for (char c : word) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

bool isConstant(const string& word) {
    for (char c : word) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream file("myfile.txt");
    string word;
    string keywordsOutput, identifiersOutput, constantsOutput, operatorsOutput;

    while (file >> word) {
        if (isKeyword(word)) {
            keywordsOutput += (keywordsOutput.empty() ? "" : ", ") + word;
        } else if (isOperator(word) && !isIdentifier(word)) {
            operatorsOutput += (operatorsOutput.empty() ? "" : ", ") + word;
        } else if (isIdentifier(word)) {
            identifiersOutput += (identifiersOutput.empty() ? "" : ", ") + word;
        } else if (isConstant(word)) {
            constantsOutput += (constantsOutput.empty() ? "" : ", ") + word;
        }
    }

    cout << "Keywords: " << keywordsOutput << endl;
    cout << "Identifiers: " << identifiersOutput << endl;
    cout << "Operators: " << operatorsOutput << endl;
    cout << "Constants: " << constantsOutput << endl;

    file.close();
    return 0;
}
