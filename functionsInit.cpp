#include "functions.h"

//the dame logic as it was many many times in other places

int getRank(char element) {
    if (element == 's' || element == 'c' || element == 't' || element == 'g' || element == 'h' || element == 'y' ||
        element == 'e' || element == 'm' || element == 'l' || element == 'f' || element == 'C' || element == 'S' ||
        element == 'T' || element == 'G' || element == 'L' || element == 'U' || element == 'a') {
        return 5;
    }
    if (element == '+' || element == '-') {
        return 1;
    }
    if (element == '*' || element == '/' || element == '%') {
        return 2;
    }
    if (element == '^') {
        return 3;
    }
    if (element == '!') {
        return 4;
    }
    else {
        return 0;
    }
}

void add_pi(stack<identifier>& numbers_list, identifier& item1, bool& flag1) {// add pi to stack
    item1.type = '0';
    item1.value = PI;
    numbers_list.push(item1);
    flag1 = false;
}

void add_number(stack<identifier>& numbers_list, identifier& item1, bool& flag1) {// add number to stack
    double value;
    cin >> value;
    item1.type = '0';
    item1.value = value;
    numbers_list.push(item1);
    flag1 = false;
}

void add_exp(stack<identifier>& operators_list, identifier& item1) {// add exp to stack
    item1.type = 'e';
    item1.value = 0;
    operators_list.push(item1);
}

void add_lwb(stack<identifier>& operators_list, identifier& item1) {// add lwb to stack
    item1.type = 'L';
    item1.value = 0;
    operators_list.push(item1);
}

void add_upb(stack<identifier>& operators_list, identifier& item1) {// add upb to stack
    item1.type = 'U';
    item1.value = 0;
    operators_list.push(item1);
}

void add_sin(stack<identifier>& operators_list, identifier& item1) {// add sin to stack
    item1.type = 's';
    item1.value = 0;
    operators_list.push(item1);
}

void add_cos(stack<identifier>& operators_list, identifier& item1) {// add cos to stack
    item1.type = 'c';
    item1.value = 0;
    operators_list.push(item1);
}

void add_tg(stack<identifier>& operators_list, identifier& item1) {// add tg to stack
    item1.type = 't';
    item1.value = 0;
    operators_list.push(item1);
}

void add_ctg(stack<identifier>& operators_list, identifier& item1) {// add ctg to stack
    item1.type = 'g';
    item1.value = 0;
    operators_list.push(item1);
}

void add_sinh(stack<identifier>& operators_list, identifier& item1) {// add sinh to stack
    item1.type = 'y';
    item1.value = 0;
    operators_list.push(item1);
}

void add_cosh(stack<identifier>& operators_list, identifier& item1) {// add cosh to stack
    item1.type = 'h';
    item1.value = 0;
    operators_list.push(item1);
}

void add_el(stack<identifier>& operators_list, identifier& item1, char element) {// add operation to stack
    item1.type = element;
    item1.value = 0;
    operators_list.push(item1);
    cin.ignore();
}

void add_ln(stack<identifier>& operators_list, identifier& item1) {// add ln to stack
    item1.type = 'l';
    item1.value = 0;
    operators_list.push(item1);
}

void add_lg(stack<identifier>& operators_list, identifier& item1) {// add lg to stack
    item1.type = 'm';
    item1.value = 0;
    operators_list.push(item1);
}

void add_log(stack<identifier>& operators_list, identifier& item1) {// add log to stack
    item1.type = 'f';
    item1.value = 0;
    operators_list.push(item1);
}

void add_asin(stack<identifier>& operators_list, identifier& item1) {// add asin to stack
    item1.type = 'S';
    item1.value = 0;
    operators_list.push(item1);
}

void add_acos(stack<identifier>& operators_list, identifier& item1) {// add acos to stack
    item1.type = 'C';
    item1.value = 0;
    operators_list.push(item1);
}

void add_tgh(stack<identifier>& operators_list, identifier& item1) {// add tgh to stack
    item1.type = 'T';
    item1.value = 0;
    operators_list.push(item1);
}

void add_ctgh(stack<identifier>& operators_list, identifier& item1) {// add ctgh to stack
    item1.type = 'G';
    item1.value = 0;
    operators_list.push(item1);
}

void add_oct(stack<identifier>& operators_list, identifier& item1) {// add oct to stack
    item1.type = 'O';
    item1.value = 0;
    operators_list.push(item1);
}

void add_hex(stack<identifier>& operators_list, identifier& item1) {// add hex to stack
    item1.type = 'H';
    item1.value = 0;
    operators_list.push(item1);
}

void add_bin(stack<identifier>& operators_list, identifier& item1) {// add bin to stack
    item1.type = 'B';
    item1.value = 0;
    operators_list.push(item1);
}

void add_abs(stack<identifier>& operators_list, identifier& item1) {// add abs to stack
    item1.type = 'A';
    item1.value = 0;
    operators_list.push(item1);
}
