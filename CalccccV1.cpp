#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

struct identifier
{
    char type;
    double value;
};

double Sin(double x) {
    return (round(sin(x)*10000) / 10000);
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

bool maths(stack <identifier>& numbers, stack <identifier>& operators, identifier & item){
    double a, b, c;
    a = numbers.top().value;
    numbers.pop();
    switch (operators.top().type) {
        case '+':
            b = numbers.top().value;
            numbers.pop();
            c = a + b;
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case '-':
            b = numbers.top().value;
            numbers.pop();
            c = b - a;
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case '*':
            b = numbers.top().value;
            numbers.pop();
            c = a * b;
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case 'e':
            c = exp(a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case 's':
            c = Sin(a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case 'c':
            c = Cos(a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case 'g':
            if (Sin(a) == 0) {
                return false;
            }
            else
            {
                c = ctg(a);
                item.type = '0';
                item.value = c;
                numbers.push(item);
                operators.pop();
                break;
            }
        case 't':
            if (Cos(a) == 0) {
                return false;
            }
            else
            {
                c = tg(a);
                item.type = '0';
                item.value = c;
                numbers.push(item);
                operators.pop();
                break;
            }
        case 'h':
            c = cosh(a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case 'y':
            c = sinh(a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case '^':
            b = numbers.top().value;
            numbers.pop();
            c = pow(b, a);
            item.type = '0';
            item.value = c;
            numbers.push(item);
            operators.pop();
            break;
        case '/':
            b = numbers.top().value;
            if (a == 0) {
                cerr << "It's forbidden to divide by 0\n";
                return false;
            }
            else
            {
                numbers.pop();
                c = (b / a);
                item.type = '0';
                item.value = c;
                numbers.push(item);
                operators.pop();
                break;
            }
        default:
            cerr << "Error, sth went wrong\n";
            return false;
            break;
          
    }
    return true;
}

int getRank(char element) {
    if (element == 's' || element == 'c' || element == 't' || element == 'g' || element == 'h' || element == 'y')
    {
        return 4;
    }
    if (element == '+' || element == '-'){
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

int main() {
    char element;
    double value;
    bool flag = 1;
    stack <identifier> numbers;
    stack <identifier> operators;
    identifier item;
    while (1)
    {
        element = cin.peek();
        if (element == '\n') {
            break;
        }
        if (element == ' ') {
            cin.ignore();
            continue;
        }
        if (element == 's' || element == 'c' || element == 't' || element == 'e'){
            char func[3];
            for (int i = 0; i < 3; i++) {
                func[i] = cin.peek();
                cin.ignore();
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') {
                item.type = 's';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 's') {
                item.type = 'c';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 't' && func[1] == 'a' && func[2] == 'n') {
                item.type = 't';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 't' && func[2] == 'g') {
                item.type = 'g';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 'e' && func[1] == 'x' && func[2] == 'p') {
                item.type = 'e';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 'c' && func[1] == 'o' && func[2] == 'h') {
                item.type = 'h';
                item.value = 0;
                operators.push(item);
                continue;
            }
            if (func[0] == 's' && func[1] == 'i' && func[2] == 'h') {
                item.type = 'y';
                item.value = 0;
                operators.push(item);
                continue;
            }
        }
        if (element == 'p') {
            item.type = '0';
            item.value = PI;
            numbers.push(item);
            flag = 0;
            cin.ignore();
            continue;
        }
        if (element >= '0' && element <= '9' || element == '-' && flag == 1) {
            cin >> value;
            item.type = '0';
            item.value = value;
            numbers.push(item);
            flag = 0;
            continue;
        }
        if (element == '+' || element == '*' || element == '-' && flag == 0 || element == '/' || element == '^') {
            if (operators.size() == 0) {
                item.type = element;
                item.value = 0;
                operators.push(item);
                cin.ignore();
                continue;
            }
            if (operators.size() != 0 && getRank(element) > getRank(operators.top().type))
            {
                item.type = element;
                item.value = 0;
                operators.push(item);
                cin.ignore();
                continue;
            }
            if (operators.size() != 0 && getRank(element) <= getRank(operators.top().type))
            {
                if (maths(numbers, operators, item) == false) {
                    system("pause");
                    return 0;
                }
                continue;
            }
        }
        if (element == '(') {
            item.type = element;
            item.value = 0;
            operators.push(item);
            cin.ignore();
            continue;
        }
        if (element == ')')
        {
            while (operators.top().type != '(') {
                if (maths(numbers, operators, item) == false) {
                    system("pause");
                    return 0;
                }
                else
                {
                    continue;
                }
            }
            operators.pop();
            cin.ignore();
            continue;
        }
        else
        {
            cout << "Inappropriate expression\n";
            system("pause");
            return 0;
        }
    }
    while (operators.size() != 0) {
        if (maths(numbers, operators, item) == false) {
            system("pause");
            return 0;
        }
        else
        {
            continue;
        }
    }
    cout << "The answer is: " << numbers.top().value << endl;
    return 0;

}
