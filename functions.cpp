#include "functions.h"

int getRank(char element) {
    if (element == 's' || element == 'c' || element == 't' || element == 'g' || element == 'h' || element == 'y' || element == 'o' || element == 'n' || element == 'l')
    {
        return 4;
    }
    if (element == '+' || element == '-') {
        return 1;
    }
    if (element == '*' || element == '/') {
        return 2;
    }
    if (element == '^') {
        return 3;
    }
    else
    {
        return 0;
    }
}

double Sin(double x) {
    return (round(sin(x) * 10000) / 10000);
}

double Cos(double x) {
    return (round(cos(x) * 10000) / 10000);
}

double ctg(double x) {
    return (Cos(x) / Sin(x));
}

double tg(double x) {
    return (Sin(x) / Cos(x));
}

void add_pi(stack<identifier>& numbers_list, identifier& item1, bool flag1) {
    item1.type = '0';
    item1.value = PI;
    numbers_list.push(item1);
    flag1 = 0;
};

void add_number(stack<identifier>& numbers_list, identifier& item1, bool& flag1) {
    double value;
    cin >> value;
    item1.type = '0';
    item1.value = value;
    numbers_list.push(item1);
    flag1 = 0;
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

bool division(double num1, double num2, stack<identifier>& numbers_list, identifier& item1,
    stack<identifier>& operators_list, double c) {
    num2 = numbers_list.top().value;
    if (num1 == 0) {
        cerr << "It's forbidden to divide by 0\n";
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
    c = exp(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void add_exp(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'e';
    item1.value = 0;
    operators_list.push(item1);
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

void SinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Sin(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void add_sin(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 's';
    item1.value = 0;
    operators_list.push(item1);
}
void CosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = Cos(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void add_cos(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'c';
    item1.value = 0;
    operators_list.push(item1);
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
void add_tg(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 't';
    item1.value = 0;
    operators_list.push(item1);
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
void add_ctg(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'g';
    item1.value = 0;
    operators_list.push(item1);
}
void
sinh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = sinh(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void add_sinh(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'y';
    item1.value = 0;
    operators_list.push(item1);
}
void
cosh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c) {
    c = cosh(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
}
void add_cosh(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'h';
    item1.value = 0;
    operators_list.push(item1);
}
void add_el(stack<identifier>& operators_list, identifier& item1, char element) {
    item1.type = element;
    item1.value = 0;
    operators_list.push(item1);
    cin.ignore();
}
bool lnC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c)
{
    if (num1 == 0)
    {
        return true;
    }
    c = log(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
    return false;
}
bool logC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c)
{
    if (num1 == 0)
    {
        return true;
    }
    c = log10(num1);
    item1.type = '0';
    item1.value = c;
    numbers_list.push(item1);
    operators_list.pop();
    return false;
}
void add_ln(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'l';
    item1.value = 0;
    operators_list.push(item1);
}
void add_log(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'o';
    item1.value = 0;
    operators_list.push(item1);
}
bool maths(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1)
{
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
        if (lnC(a, numbers_list, item1, operators_list, c))
        {
            return false;
        }
        else
        {
            break;
        }
    case 'o':
        if (logC(a, numbers_list, item1, operators_list, c))
        {
            return false;
        }
        else
        {
            break;
        }
    default:
        cerr << "Error, sth went wrong\n";
        return false;
    }
    return true;
}
bool mathsExceptions(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1) {
    if (!maths(numbers_list, operators_list, item1)) {
        return 0;
    }
    return 1;
}