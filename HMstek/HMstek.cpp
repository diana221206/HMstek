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
                std::cout << "Помилка: Зайва закриваюча дужка '" << ch << "' на позиції " << i + 1 << "n";
                return false;
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                std::cout << "Помилка: Закриваюча дужка '" << ch << "' не відповідає відкриваючій '" << top << "' на позиції " << i + 1 << "n";
                return false;
            }
        }
    }

    if (!s.empty()) {
        std::cout << "Помилка: Непарна відкриваюча дужка '" << s.top() << "' залишилася в стеки.n";
        return false;
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Введіть рядок з дужками (закінчується на ';'): ";
    std::getline(std::cin, input);

    if (!input.empty() && input.back() == ';') {
        input.pop_back();
    }

    if (isValid(input)) {
        std::cout << "Рядок коректний.n";
    }
    else {
        std::cout << "Рядок некоректний.n";
    }

    return 0;
}
