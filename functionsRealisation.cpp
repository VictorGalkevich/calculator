#include "functions.h"
#include "Sort.h"

//definitions for all the provided functions

double Cosh(double x) {
    return (Exp(x) + Exp(-x)) / 2;
}

double Sinh(double x) {
    return (Exp(x) - Exp(-x)) / 2;
}

double Tanh(double x) {
    return Sinh(x) / Cosh(x);
}

double Ctgh(double x) {
    return Cosh(x) / Sinh(x);
}

double Sin(double x) {
    double temp;
    if (x == PI) {
        return 0;
    }
    if (x == 3 * PI / 2) {
        return -1;
    }
    if (x > 2 * PI || x < -2 * PI) {
        temp = x / (2 * PI);
        x = x - (temp * 2 * PI);
    }
    return (x - fast_pow(x, 3) / 6 + fast_pow(x, 5) / 120 - fast_pow(x, 7) / 5040 + fast_pow(x, 9) / 362880 -
        fast_pow(x, 11) / 39916800 +
        fast_pow(x, 13) / 6227020800); //just taylor series, nothing special
}

double Cos(double x) {
    double temp;
    if (x == PI / 2 || x == 3 * PI / 2) {
        return 0;
    }
    if (x > 2 * PI || x < -2 * PI) {
        temp = x / (2 * PI);
        x = x - (temp * 2 * PI);
    }
    return (1 - fast_pow(x, 2) / 2 + fast_pow(x, 4) / 24 - fast_pow(x, 6) / 720 + fast_pow(x, 8) / 40320 -
        fast_pow(x, 10) / 3628800 +
        fast_pow(x, 12) / 479001600 - fast_pow(x, 14) / 87178291200); //just taylor series, nothing special
}

double ctg(double x) {
    return (Cos(x) / Sin(x));
}

double tg(double x) {
    return (Sin(x) / Cos(x));
}

double upb(double x) {
    if (x >= 0) {
        return static_cast<int>(x) + 1;
    }
    else {
        return static_cast<int>(x);
    }
}

double Abs(double x) {
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}

double lwb(double x) {
    if (x >= 0) {
        return static_cast<int>(x);
    }
    else {
        return static_cast<int>(x) - 1;
    }
    
}

double fast_pow(double x, int n) {
    if (n < 0) {
        return fast_pow(1 / x, -n);
    }
    else if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return fast_pow(x * x, n / 2);
    }
    else {
        return x * fast_pow(x * x, (n - 1) / 2);
    }
}

double Asin(double x) {
    if (x == -1) {
        return -PI / 2;
    }
    if (x == 1) {
        return PI / 2;
    }
    return (x + fast_pow(x, 3) / 6 + fast_pow(x, 5) * 3 / 40 + 5 * fast_pow(x, 7) / 112 + 35 * fast_pow(x, 9) / 1152 +
        63 *
        fast_pow(x, 11) / 2816); //just taylor series, nothing special
}

double Acos(double x) {
    if (x == -1) {
        return PI;
    }
    if (x == 1) {
        return 0;
    }
    return PI / 2 - Asin(x);
}

double Exp(double x) {
    return (1 + x + fast_pow(x, 2) / 2 + fast_pow(x, 3) / 6 + fast_pow(x, 4) / 24 + fast_pow(x, 5) / 120 +
        fast_pow(x, 6) / 720 +
        fast_pow(x, 7) / 5040 + fast_pow(x, 8) / 40320 + fast_pow(x, 9) / 362880 + fast_pow(x, 10) / 3628800); //just taylor series, nothing special
}

double lnX(double x) {
    constexpr double eps = 1.0e-5; // accuracy
    int A = 0;
    while (x >= 2.0) { //just taylor series, nothing special
        A++;
        x /= E;
    }
    double t = x - 1;
    double u = t;
    double lnabsx = u;
    int n = 1;
    do {
        n++;
        u *= -((n - 1) * t) / n;
        lnabsx += u;
    } while (u > eps || u < -eps);
    return A + lnabsx;
}

double lgX(double x) {
    return lnX(x) / lnX(10);
}

double logX(double x, int y) {
    return lnX(x) / lnX(y);
}

bool division(double num1, double num2, stack<identifier>& numbers_list, identifier& item1,
    stack<identifier>& operators_list, double c) { // the same logic as it was in the programming_functions
    num2 = numbers_list.top().value;
    if (num1 == 0) {
        cerr << "It's forbidden to divide by 0\n";
        exit(0);
        return true;
    }
    else {
        numbers_list.pop();
        c = (num2 / num1);
        item1.type = '0';
        item1.value = c;
        numbers_list.push(item1);
        operators_list.pop();
    }
    return false;
}

//all the other functions follow the same logic as it was in the file programming_functions_realisation
//thats why i will nor comment anything here except the last function

void exp(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Exp(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
absC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Abs(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

int factorial_calculate(int num) {
    if (num > 1) {
        return num * factorial_calculate(num - 1);
    }
    else {
        return 1;
    }
}

void factorial(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list,
    double c) {
    int temp = num1;
    if (num1 - temp != 0 || temp < 0) {
        cerr << "Cannot take factorial of non int number! ";
        exit(0);
    }
    c = factorial_calculate(temp);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
sum(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list,
    double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num1 + num2;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
mod(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list,
    double c) {
    if (num1 - (int)num1 != 0 || num2 - int(num2) != 0) {
        cerr << "modulo operation is only available for integers";
        exit(0);
    }
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = (int)num2 % (int)num1;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void difference(double num1, double num2, stack<identifier>& numbers_list, identifier& item1,
    stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 - num1;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void production(double num1, double num2, stack<identifier>& numbers_list, identifier& item1,
    stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num1 * num2;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
power(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list,
    double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = pow(num2, num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

double powC(double a, double b) {
    if (a < 0) {
        cerr << "Cant use negative value as a base! ";
        exit(0);
    }
    static int count = 1;
    static double res = 1;
    static double tmp = 1;
    if (count == 100) {
        const int temp = res;
        if (temp - res <= 0.002) {
            return temp;
        }
        return res;
    }
    else {
        tmp = tmp * b * lnX(a) / count;
        res += tmp;
        count++;
        powC(a, b);
    }
}

void
SinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Sin(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
CosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Cos(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
ACosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Acos(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
ASinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Asin(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

bool tgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Cos(num1) == 0) {
        cerr << "Tan doesn't exist when cos = 0" << std::endl;
        return true;
    }
    else {
        c = tg(num1);
        item1.type = '0';
        item1.value = c;
        numbers_list.push(item1);
        operators_list.pop();
    }
    return false;
}


bool
ctgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Sin(num1) == 0) {
        cerr << "Ctg doesn't exist when sin = 0" << std::endl;
        return true;
    }
    else {
        c = ctg(num1);
        item1.type = '0';
        item1.value = c;
        numbers_list.push(item1);
        operators_list.pop();
    }
    return false;
}

bool
tghC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Cosh(num1) == 0) {
        cerr << "Tanh doesn't exist when cosh = 0" << std::endl;
        return true;
    }
    else {
        c = Tanh(num1);
        item1.type = '0';
        item1.value = c;
        numbers_list.push(item1);
        operators_list.pop();
    }
    return false;
}

bool
ctghC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Sinh(num1) == 0) {
        cerr << "Ctgh doesn't exist when sinh = 0" << std::endl;
        return true;
    }
    else {
        c = Ctgh(num1);
        item1.type = '0';
        item1.value = c;
        numbers_list.push(item1);
        operators_list.pop();
    }
    return false;
}

void
sinh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Sinh(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void upb(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = upb(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void lwb(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = lwb(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void
cosh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Cosh(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

bool lnC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (num1 == 0) {
        cerr << "Cannot take log of 0! " << std::endl;
        return true;
    }
    if (num1 < 0) {
        cerr << "arg must be > 0!";
        return true;
    }
    c = lnX(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
    return false;
}

bool lgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c,
    double logBasis) {
    if (num1 == 0) {
        cerr << "Cannot take log of 0! " << std::endl;
        return true;
    }
    if (num1 < 0) {
        cerr << "arg must be > 0!";
        return true;
    }
    c = lgX(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
    return false;
}

bool logC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c,
    double logBasis) {
    if (num1 == 0) {
        cerr << "Cannot take log of 0! " << std::endl;
        return true;
    }
    if (num1 < 0) {
        cerr << "arg must be > 0!";
        return true;
    }
    if (logBasis == 1 || logBasis == 0 || logBasis < 0) {
        cerr << "log basis must be > 0 and not equal to 1";
        return true;
    }
    c = logX(num1, logBasis);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
    return false;
}

bool maths(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1, double logBasis) {
    double a, b, c;
    b = 0;
    c = 0;
    a = numbers_list.top().value;
    numbers_list.pop();
    bool bol;
    switch (operators_list.top().type) {
    case '+':
        sum(a, b, numbers_list, item1, operators_list, c);
        break;
    case '!':
        factorial(a, numbers_list, item1, operators_list, c);
        break;
    case '-':
        difference(a, b, numbers_list, item1, operators_list, c);
        break;
    case 'A':
        absC(a, numbers_list, item1, operators_list, c);
        break;
    case '%':
        mod(a, b, numbers_list, item1, operators_list, c);
        break;
    case '*':
        production(a, b, numbers_list, item1, operators_list, c);
        break;
    case 'e':
        exp(a, numbers_list, item1, operators_list, c);
        break;
    case 'L':
        lwb(a, numbers_list, item1, operators_list, c);
        break;
    case 'U':
        upb(a, numbers_list, item1, operators_list, c);
        break;
    case 's':
        SinC(a, numbers_list, item1, operators_list, c);
        break;
    case 'c':
        CosC(a, numbers_list, item1, operators_list, c);
        break;
    case 'S':
        if (a > 1 || a < -1) {
            cerr << "Cannot take asin of " << a << "!" << std::endl;
            return false;
        }
        ASinC(a, numbers_list, item1, operators_list, c);
        break;
    case 'C':
        if (a > 1 || a < -1) {
            cerr << "Cannot take acos of " << a << "!" << std::endl;
            return false;
        }
        ACosC(a, numbers_list, item1, operators_list, c);
        break;
    case 'g':
        bol = ctgC(a, numbers_list, item1, operators_list, c);
        if (bol) {
            return false;
        }
        else {
            break;
        }
    case 'T':
        bol = tghC(a, numbers_list, item1, operators_list, c);
        if (bol) {
            return false;
        }
        else {
            break;
        }
    case 'G':
        bol = ctghC(a, numbers_list, item1, operators_list, c);
        if (bol) {
            return false;
        }
        else {
            break;
        }
    case 't':
        bol = tgC(a, numbers_list, item1, operators_list, c);
        if (bol) {
            return false;
        }
        else {
            break;
        }
    case 'h':
        cosh(a, numbers_list, item1, operators_list, c);
        break;
    case 'y':
        sinh(a, numbers_list, item1, operators_list, c);
        break;
    case '^':
        power(a, b, numbers_list, item1, operators_list, c);
        break;
    case '/':
        bol = division(a, b, numbers_list, item1, operators_list, c);
        if (bol) {
            return false;
        }
        else {
            break;
        }
    case 'l':
        if (lnC(a, numbers_list, item1, operators_list, c)) {
            return false;
        }
        else {
            break;
        }
    case 'm':
        if (lgC(a, numbers_list, item1, operators_list, c, logBasis)) {
            return false;
        }
        else {
            break;
        }
    case 'f':
        if (logC(a, numbers_list, item1, operators_list, c, logBasis)) {
            return false;
        }
        else {
            break;
        }
    default:
        cerr << "Error, sth went wrong\n";
        return false;
    }
    return true;
}

bool mathsExceptions(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1,
    double logBasis) {
    if (!maths(numbers_list, operators_list, item1, logBasis)) {
        return false;
    }
    return true;
}

//this method works to parse the stroke and then calculate all the operations

void calculate() {
    stack<identifier> numbers;
    stack<identifier> operators; //just declarations of the stacks, variables that we'll work with
    identifier item;
    char element;
    bool flag = true;
    int logBasis = 0;
    while (true) {
        element = cin.peek();
        if (element == '\n') { //when we met the end of the line we understand that the expression ended
            break;
        }
        if (element == ' ') { //we skip all the void spaces in the stroke to calculate even the (1        +1) as (1+1)
            cin.ignore();
            continue;
        }
        if (element == 's' || element == 'c' || element == 't' || element == 'e' || element == 'l' ||
            element == 'n' || element == 'o' || element == 'g' || element == 'a' || element == 'u' ||
            element == 'h' || element == 'b') {
            char func[4]; // here is what we do when we met a functions
            for (int i = 0; i < 4; i++) {
                func[i] = cin.peek();
                if (isdigit(func[i]) || func[i] == '(' || func[i] == 'p') {
                    break;
                }
                cin.ignore();
            }
            if (func[0] == 'l' && func[1] == 'n') {
                add_ln(operators, item);
                continue;
            }
            if (func[0] == 'a' && func[1] == 's' && func[2] == 'i' && func[3] == 'n' && func[1] != 'b') { // here is what we do when we met asin
                add_asin(operators, item);
                continue;
            }
            if (func[0] == 'a' && func[1] == 'c' && func[2] == 'o' && func[3] == 's' && func[1] != 'b') { // here is what we do when we met acos
                add_acos(operators, item);
                continue;
            }
            if (func[0] == 'l' && func[1] == 'g') { // here is what we do when we met lg
                add_lg(operators, item);
                continue;
            }
            if (func[0] == 'l' && func[1] == 'o' && func[2] == 'g' && func[3] >= '0' && func[3] <= '9') { // here is what we do when we met log
                logBasis = func[3] - '0';
                add_log(operators, item);
                continue;
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'n' && func[3] != 'h') { // here is what we do when we met sin
                add_sin(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 's' && func[3] != 'h') { // here is what we do when we met cos
                add_cos(operators, item);
                continue;
            }
            if (func[0] == 't' && func[1] == 'a' && func[2] == 'n' && func[3] != 'h') { // here is what we do when we met tan
                add_tg(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 't' && func[2] == 'g' && func[3] != 'h') { // here is what we do when we met ctg
                add_ctg(operators, item);
                continue;
            }
            if (func[0] == 't' && func[1] == 'a' && func[2] == 'n' && func[3] == 'h') { // here is what we do when we met tanh
                add_tgh(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 't' && func[2] == 'g' && func[3] == 'h') { // here is what we do when we met ctgh
                add_ctgh(operators, item);
                continue;
            }
            if (func[0] == 'e' && func[1] == 'x' && func[2] == 'p') { // here is what we do when we met exp
                add_exp(operators, item);
                continue;
            }
            if (func[0] == 'a' && func[1] == 'b' && func[2] == 's') { // here is what we do when we met abs
                add_abs(operators, item);
                continue;
            }
            if (func[0] == 'u' && func[1] == 'p' && func[2] == 'b') { // here is what we do when we met upper border
                add_upb(operators, item);
                continue;
            }
            if (func[0] == 'l' && func[1] == 'w' && func[2] == 'b') { // here is what we do when we met lower border
                add_lwb(operators, item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 's' && func[3] == 'h') { // here is what we do when we met sinh
                add_cosh(operators, item);
                continue;
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'n' && func[3] == 'h') { //here is what we do when we met cosh
                add_sinh(operators, item);
                continue;
            }
        }
        if (element == 'p') { // here is what we do when we met PI
            add_pi(numbers, item, flag);
            cin.ignore();
            continue;
        }
        if (element >= '0' && element <= '9' || element == '-' && flag == 1) { // here is what we do when we met a number
            add_number(numbers, item, flag);
            continue;
        }
        if (element == '+' || element == '*' || element == '-' && flag == 0 || element == '/' || element == '^' ||
            element == '&' || element == '|' || element == '!' || element == '%') {                                   // here is what we do when we met a operation
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
        if (element == '(') {// here is what we do when we met a brace to open
            flag = true;
            add_el(operators, item, element);
            continue;
        }
        if (element == ')') {// here is what we do when we met a brace to close
            while (operators.top().type != '(') {
                mathsExceptions(numbers, operators, item, logBasis);
                continue;
            }
            operators.pop();
            cin.ignore();
            continue;
        }
        else {
            cout << "\nInappropriate expression\n";
            system("pause");
            return;
        }
    }
    while (!operators.empty()) { //calculating
        if (!mathsExceptions(numbers, operators, item, logBasis)) {
            return;
        }
        else {
            continue;
        }
    }
    cout << "\nThe answer is: " << numbers.top().value << endl << endl;
    return;
}
