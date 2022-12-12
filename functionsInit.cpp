#include "functions.h"

int getRank(char element) {
    if (element == 's' || element == 'c' || element == 't' || element == 'g' || element == 'h' || element == 'y' ||
        element == 'e' || element == 'm' || element == 'l' || element == 'f' || element == 'C' || element == 'S' ||
        element == 'T' || element == 'G' || element == 'L' || element == 'U' || element == 'a') {
        return 5;
    }
    if (element == '+' || element == '-') {
        return 1;
    }
    if (element == '*' || element == '/' || element ==  '%') {
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

void add_pi(stack<identifier>& numbers_list, identifier& item1, bool& flag1) {
    item1.type = '0';
    item1.value = PI;
    numbers_list.push(item1);
    flag1 = false;
}

void add_number(stack<identifier>& numbers_list, identifier& item1, bool& flag1) {
    double value;
    cin >> value;
    item1.type = '0';
    item1.value = value;
    numbers_list.push(item1);
    flag1 = false;
}

void add_exp(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'e';
    item1.value = 0;
    operators_list.push(item1);
}

void add_lwb(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'L';
    item1.value = 0;
    operators_list.push(item1);
}

void add_upb(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'U';
    item1.value = 0;
    operators_list.push(item1);
}

void add_sin(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 's';
    item1.value = 0;
    operators_list.push(item1);
}

void add_cos(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'c';
    item1.value = 0;
    operators_list.push(item1);
}

void add_tg(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 't';
    item1.value = 0;
    operators_list.push(item1);
}

void add_ctg(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'g';
    item1.value = 0;
    operators_list.push(item1);
}

void add_sinh(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'y';
    item1.value = 0;
    operators_list.push(item1);
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

void add_ln(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'l';
    item1.value = 0;
    operators_list.push(item1);
}

void add_lg(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'm';
    item1.value = 0;
    operators_list.push(item1);
}

void add_log(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'f';
    item1.value = 0;
    operators_list.push(item1);
}

void add_asin(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'S';
    item1.value = 0;
    operators_list.push(item1);
}

void add_acos(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'C';
    item1.value = 0;
    operators_list.push(item1);
}

void add_tgh(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'T';
    item1.value = 0;
    operators_list.push(item1);
}

void add_ctgh(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'G';
    item1.value = 0;
    operators_list.push(item1);
}

void add_oct(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'O';
    item1.value = 0;
    operators_list.push(item1);
}

void add_hex(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'H';
    item1.value = 0;
    operators_list.push(item1);
}

void add_bin(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'B';
    item1.value = 0;
    operators_list.push(item1);
}

void add_abs(stack<identifier>& operators_list, identifier& item1) {
    item1.type = 'A';
    item1.value = 0;
    operators_list.push(item1);
}