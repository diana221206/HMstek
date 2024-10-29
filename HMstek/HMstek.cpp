#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& str) {
    std::stack<char> s;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                std::cout << "�������: ����� ���������� ����� '" << ch << "' �� ������� " << i + 1 << "n";
                return false;
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                std::cout << "�������: ���������� ����� '" << ch << "' �� ������� ����������� '" << top << "' �� ������� " << i + 1 << "n";
                return false;
            }
        }
    }

    if (!s.empty()) {
        std::cout << "�������: ������� ���������� ����� '" << s.top() << "' ���������� � �����.n";
        return false;
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "������ ����� � ������� (���������� �� ';'): ";
    std::getline(std::cin, input);

    if (!input.empty() && input.back() == ';') {
        input.pop_back();
    }

    if (isValid(input)) {
        std::cout << "����� ���������.n";
    }
    else {
        std::cout << "����� �����������.n";
    }

    return 0;
}
