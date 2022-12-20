#include "programming_operations.h"
#include "functions.h"

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
    }
    else {
        return 0;
    }
}

string hex(double x) {
    string ans = ""; //stroke by default
    int n = x; //as we work only with ints we cast double to int
    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 16;
        if (rem < 10) {
            ch = rem + 48; //if remnanat <9 ew return the value(number)
        }
        else {
            ch = rem + 55; //if remnant >9 we return a letter(A,B,C,...)
        }
        ans += ch;
        n = n / 16;
    }
    int i = 0, j = ans.size() - 1;
    while (i <= j) { // as our stroke was mirrored we reverse all the elements
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}

string bin(double x) {
    string ans;
    int n = x;  //as we work only with ints we cast double to int
    while (n != 0) {
        ans = (n % 2 == 0 ? "0" : "1") + ans; //divide by 2 all the time and print every symbol, thats easy
        n /= 2;
    }
    return ans;
}

string oct(double x) {
    int octalNum = 0, placeValue = 1;
    int n = x; //as we work only with ints we cast double to int
    while (n != 0) {
        octalNum += (n % 8) * placeValue; //here i tried to find the remnant and thenadd it to octalnum
        n /= 8;
        placeValue *= 10;
    }
    return to_string(octalNum);
}

void P_add_number(stack<int_identifier>& numbers_list, int_identifier& item1, bool& flag1) { //here we add the number to the stack
    int value;
    cin >> value;
    item1.ch = '0'; //number isnt an operation so its charValue = '0', but numberValue = number
    item1.value = value;
    numbers_list.push(item1);
    flag1 = false;
}

void P_add_el(stack<int_identifier>& operators_list, int_identifier& item1, char element) { //here we add an element to the stack
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
    item1.ch = element; //
    item1.value = 0; //as element has no numberValue we write 0
    operators_list.push(item1);
    cin.ignore();
}

void add_not(stack<int_identifier>& operators_list, int_identifier& item1) { //other operations shown below follow the same logic as it was in the previous example
    item1.ch = '~';
    item1.value = 0;
    operators_list.push(item1);
    cin.ignore();
}

void P_sum(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 + num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_difference(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 - num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_prod(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 * num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_xor(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 ^ num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_and(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 & num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_or(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 | num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_right(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 << num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_left(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 >> num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void P_not(int num1, stack<int_identifier>& numbers_list, int_identifier& item1, stack<int_identifier>& operators_list,
    int c) {
    c = ~num1;
    item1.ch = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

//this method works to calculate all the operations

bool P_maths(stack<int_identifier>& numbers_list, stack<int_identifier>& operators_list, int_identifier& item1) {
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

//validation of exceptions

bool P_mathsExceptions(stack<int_identifier>& numbers_list, stack<int_identifier>& operators_list, int_identifier& item1) {
    if (!P_maths(numbers_list, operators_list, item1)) {
        return false;
    }
    return true;
}

//the method that works to call the calculator from 1 point

void P_calculatorStart() {
    cout << "To work with some functions use: sin(x), cos(x), tan(x), ctg(x), sinh(x), cosh(x), abs(x), tanh(x), ctgh(x) \n\t\t\t\t ln(x), lg(x), logA(x) (where A is basis( log(8) )), asin(x), acos(x), exp(x)" << endl;
    cout << " \t\t\t\t (x)! to use factorial, to see oct,bin and hex just input a number and press Enter.\n\n" << endl;
    while (1) {
        char mode;
    label1:
        std::cout << "Enter working mode: \n For engineer mode enter \"0\" \n For programming mode enter \"1\" \n To exit enter \"e\": ";
        cin >> mode;
        if (mode == '1') {
            cin.ignore();
            P_calculate();
        }
        else if (mode == '0') {
            cin.ignore();
            calculate();
        }
        else if (mode == 'e') {
            exit(0);
        }
        else {
            cout << "Wrong working mode! " << endl;
            goto label1;
        }
    }
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
        }
        else {
            cout << "Inappropriate expression\n";
            system("pause");
            return;
        }
    }
    while (!operators.empty()) {
        if (!P_mathsExceptions(numbers, operators, item)) {
            return;
        }
        else {
            continue;
        }
    }
    cout << "The answer is: " << numbers.top().value << endl;
    cout << "Hex - " << hex(numbers.top().value) << endl;
    cout << "Oct - " << oct(numbers.top().value) << endl;
    cout << "Bin - " << bin(numbers.top().value) << "\n" << endl;
    return;
}

