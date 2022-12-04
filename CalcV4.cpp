#include "functions.h"

int main() {
    string str1;
    stack<identifier> numbers;
    stack<identifier> operators;
    identifier item;
    char element;
    bool flag = true;
    int logBasis = 0;
    while (true) {
        element = cin.peek();
        if (element == '\n') {
            break;
        }
        if (element == ' ') {
            cin.ignore();
            continue;
        }
        if (element == 's' || element == 'c' || element == 't' || element == 'e' || element == 'l' ||
            element == 'n' || element == 'o' || element == 'g' || element == 'a') {
            char func[4];
            for (int i = 0; i < 4; i++) {
                func[i] = cin.peek();
                if (isdigit(func[i]) || func[i] == '(') {
                    break;
                }
                cin.ignore();
            }
            if (func[0] == 'l' && func[1] == 'n') {
                add_ln(operators, item);
                continue;
            }
            if (func[0] == 'a' && func[1] == 's' && func[2] == 'i' && func[3] == 'n') {
                add_asin(operators, item);
                continue;
            }
            if (func[0] == 'a' && func[1] == 'c' && func[2] == 'o' && func[3] == 's') {
                add_acos(operators, item);
                continue;
            }
            if (func[0] == 'l' && func[1] == 'g') {
                add_lg(operators, item);
                continue;
            }
            if (func[0] == 'l' && func[1] == 'o' && func[2] == 'g' && func[3] >= '0' && func[3] <= '9') {
                logBasis = func[3] - '0';
                add_log(operators, item);
                continue;
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') {
                add_sin(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 's') {
                add_cos(operators, item);
                continue;
            }
            if (func[0] == 't' && func[1] == 'a' && func[2] == 'n') {
                add_tg(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 't' && func[2] == 'g') {
                add_ctg(operators, item);
                continue;
            }
            if (func[0] == 'e' && func[1] == 'x' && func[2] == 'p') {
                add_exp(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 'h') {
                add_cosh(operators, item);
                continue;
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'h') {
                add_sinh(operators, item);
                continue;
            }
        }
        if (element == 'p') {
            add_pi(numbers, item, flag);
            cin.ignore();
            continue;
        }
        if (element >= '0' && element <= '9' || element == '-' && flag == 1) {
            add_number(numbers, item, flag);
            continue;
        }
        if (element == '+' || element == '*' || element == '-' && flag == 0 || element == '/' || element == '^' ||
            element == '&' || element == '|') {
            if (operators.empty()) {
                add_el(operators, item, element);
                continue;
            }
            if (!operators.empty() && getRank(element) > getRank(operators.top().type)) {
                add_el(operators, item, element);
                continue;
            }
            if (!operators.empty() && getRank(element) <= getRank(operators.top().type)) {
                mathsExceptions(numbers, operators, item, logBasis);
                continue;
            }
        }
        if (element == '(') {
            flag = true;
            add_el(operators, item, element);
            continue;
        }
        if (element == ')') {
            while (operators.top().type != '(') {
                mathsExceptions(numbers, operators, item, logBasis);
                continue;
            }
            operators.pop();
            cin.ignore();
            continue;
        }
        else {
            cout << "Inappropriate expression\n";
            system("pause");
            return 0;
        }
    }
    while (!operators.empty()) {
        if (!mathsExceptions(numbers, operators, item, logBasis)) {
            return 0;
        }
        else {
            continue;
        }
    }
    cout << "The answer is: " << numbers.top().value << endl;
    return 0;
}