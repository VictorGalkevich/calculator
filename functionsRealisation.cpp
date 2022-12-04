#include "functions.h"

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
    return (x - fast_pow(x, 3) / 6 + fast_pow(x, 5) / 120 - fast_pow(x, 7) / 5040 + fast_pow(x, 9) / 362880 - fast_pow(x, 11) / 39916800 +
        fast_pow(x, 13) / 6227020800);
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
    return (1 - fast_pow(x, 2) / 2 + fast_pow(x, 4) / 24 - fast_pow(x, 6) / 720 + fast_pow(x, 8) / 40320 - fast_pow(x, 10) / 3628800 +
        fast_pow(x, 12) / 479001600 - fast_pow(x, 14) / 87178291200);
}

double ctg(double x) {
    return (Cos(x) / Sin(x));
}

double tg(double x) {
    return (Sin(x) / Cos(x));
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
    return (x + fast_pow(x, 3) / 6 + fast_pow(x, 5) * 3 / 40 + 5 * fast_pow(x, 7) / 112 + 35 * fast_pow(x, 9) / 1152 + 63 *
        fast_pow(x, 11) / 2816);
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
    return(1 + x + fast_pow(x, 2) / 2 + fast_pow(x, 3) / 6 + fast_pow(x, 4) / 24 + fast_pow(x, 5) / 120 + fast_pow(x, 6) / 720 +
        fast_pow(x, 7) / 5040 + fast_pow(x, 8) / 40320 + fast_pow(x, 9) / 362880 + fast_pow(x, 10) / 3628800);
}

double lnX(double x) {
    const double eps = 1.0e-5;
    int A = 0;
    while (x >= 2.0)
    {
        A++;
        x /= E;
    }
    double t = x - 1;
    double u = t;
    double lnabsx = u;
    int n = 1;
    do
    {
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

bool division(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
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

void exp(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Exp(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void sum(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num1 + num2;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void difference(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num2 - num1;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void production(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = num1 * num2;
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void power(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list,
    double c) {
    num2 = numbers_list.top().value;
    numbers_list.pop();
    c = pow(num2, num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void SinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Sin(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void CosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Cos(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void ACosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Acos(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void ASinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Asin(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

bool tgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Cos(num1) == 0) {
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

bool ctgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    if (Sin(num1) == 0) {
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

void sinh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = sinh(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}

void cosh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = cosh(num1);
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

bool lgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
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

bool logC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c, double logBasis) {
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
    case '-':
        difference(a, b, numbers_list, item1, operators_list, c);
        break;
    case '*':
        production(a, b, numbers_list, item1, operators_list, c);
        break;
    case 'e':
        exp(a, numbers_list, item1, operators_list, c);
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
        if (lgC(a, numbers_list, item1, operators_list, c)) {
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

bool mathsExceptions(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1, double logBasis) {
    if (!maths(numbers_list, operators_list, item1, logBasis)) {
        return false;
    }
    return true;
}