#include "programming_operations.h"

int P_get_prior(char element) {
    if (element == '~') {
        return 4;
    }
    if (element == '+' || element == '-') {
        return 2;
    }
    if (element == '*') {
        return 3;
    }
    if (element == '^' || element == '<' || element == '>' || element == '|') {
        return 1;
    } else {
        return 0;
    }
}

string hex(int x) {
    string ans = "";
    int n = x;
    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 16;
        if (rem < 10) {
            ch = rem + 48;
        } else {
            ch = rem + 55;
        }
        ans += ch;
        n = n / 16;
    }
    int i = 0, j = ans.size() - 1;
    while (i <= j) {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}

string bin(int x) {
    string ans;
    int n = x;
    while (n != 0) {
        ans = (n % 2 == 0 ? "0" : "1") + ans;
        n /= 2;
    }
    return ans;
}

string oct(double x) {
    int octalNum = 0, placeValue = 1;
    int n = (int) x;
    while (n != 0) {
        octalNum += (n % 8) * placeValue;
        n /= 8;
        placeValue *= 10;
    }
    return to_string(octalNum);
}

void P_add_number(stack<int_identifier> &numbers_list, int_identifier &item1, bool &flag1) {
    int value;
    cin >> value;
    item1.ch = '0';
    item1.value = value;
    numbers_list.push(item1);
    flag1 = false;
}

void P_add_el(stack<int_identifier> &operators_list, int_identifier &item1, char element) {
    if (element == '<') {
        char ch = cin.peek();
        if (ch != '<') {
            cerr << "Wrong expression";
            exit(0);
        }
        cin.ignore();
    }
    if (element == '>') {
        char ch = cin.peek();
        if (ch != '>') {
            cerr << "Wrong expression";
            exit(0);
        }
        cin.ignore();
    }
    item1.ch = element;
    item1.value = 0;
    operators_list.push(item1);
    cin.ignore();
}

void add_not(stack<int_identifier> &operators_list, int_identifier &item1) {
    item1.ch = '~';
    item1.value = 0;
    operators_list.push(item1);
    cin.ignore();
}

void P_sum(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
           stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 + num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_difference(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
                  stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 - num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_prod(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
            stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 * num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_xor(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
           stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 ^ num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_and(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
           stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 & num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_or(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
          stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 | num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_right(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
             stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 << num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_left(int num1, int num2, stack<int_identifier> &numbers_list, int_identifier &item1,
            stack<int_identifier> &operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 >> num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_not(int num1, stack<int_identifier> &numbers_list, int_identifier &item1, stack<int_identifier> &operators_list,
           int c) {
    c = ~num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

bool P_maths(stack<int_identifier> &numbers_list, stack<int_identifier> &operators_list, int_identifier &item1) {
    int a, b, c;
    b = 0;
    c = 0;
    a = numbers_list.top().value;
    numbers_list.pop();
    switch (operators_list.top().ch) {
        case '+':
            P_sum(a, b, numbers_list, item1, operators_list, c);
            break;
        case '-':
            P_difference(a, b, numbers_list, item1, operators_list, c);
            break;
        case '*':
            P_prod(a, b, numbers_list, item1, operators_list, c);
            break;
        case '^':
            P_xor(a, b, numbers_list, item1, operators_list, c);
            break;
        case '|':
            P_or(a, b, numbers_list, item1, operators_list, c);
            break;
        case '&':
            P_and(a, b, numbers_list, item1, operators_list, c);
            break;
        case '>':
            P_left(a, b, numbers_list, item1, operators_list, c);
            break;
        case '<':
            P_right(a, b, numbers_list, item1, operators_list, c);
            break;
        case '~':
            P_not(a, numbers_list, item1, operators_list, c);
            break;
        default:
            cerr << "Error, sth went wrong\n";
            return false;
    }
    return true;
}

bool
P_mathsExceptions(stack<int_identifier> &numbers_list, stack<int_identifier> &operators_list, int_identifier &item1) {
    if (!P_maths(numbers_list, operators_list, item1)) {
        return false;
    }
    return true;
}

void P_calculate() {
    stack<int_identifier> numbers;
    stack<int_identifier> operators;
    int_identifier item;
    char element;
    bool flag = true;
    while (true) {
        element = cin.peek();
        if (element == '\n') {
            break;
        }
        if (element == ' ') {
            cin.ignore();
            continue;
        }
        if (element == '~') {
            add_not(operators, item);
            continue;
        }
        if (element >= '0' && element <= '9' || element == '-' && flag == 1) {
            P_add_number(numbers, item, flag);
            continue;
        }
        if (element == '+' || element == '*' || element == '-' && flag == 0 || element == '^' ||
            element == '&' || element == '|' || element == '<' || element == '>') {
            if (operators.empty()) {
                P_add_el(operators, item, element);
                continue;
            }
            if (!operators.empty() && P_get_prior(element) > P_get_prior(operators.top().ch)) {
                P_add_el(operators, item, element);
                continue;
            }
            if (!operators.empty() && P_get_prior(element) <= P_get_prior(operators.top().ch)) {
                P_mathsExceptions(numbers, operators, item);
                continue;
            }
        }
        if (element == '(') {
            flag = true;
            P_add_el(operators, item, element);
            continue;
        }
        if (element == ')') {
            while (operators.top().ch != '(') {
                P_mathsExceptions(numbers, operators, item);
                continue;
            }
            operators.pop();
            cin.ignore();
            continue;
        } else {
            cout << "Inappropriate expression\n";
            system("pause");
            return;
        }
    }
    while (!operators.empty()) {
        if (!P_mathsExceptions(numbers, operators, item)) {
            return;
        } else {
            continue;
        }
    }
    cout << "The answer is: " << numbers.top().value << endl;
    cout << "Hex - " << hex(numbers.top().value) << endl;
    cout << "Oct - " << oct(numbers.top().value) << endl;
    cout << "Bin - " << bin(numbers.top().value) << endl;
    return;
}

