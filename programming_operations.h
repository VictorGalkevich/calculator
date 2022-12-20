#include <iostream>
#include <string>
#include <stack>
#include <memory>

using namespace std;

//struct to analyze the stroke in programming mode

struct int_identifier {
    int value;
    char ch;

    int_identifier() : value(0), ch(' ') {};
};

//method to get the priority(rank) in programming mode

int P_get_prior(char ch);

//here we declare the operations

string hex(double x);

string bin(double x);

string oct(double x);

//declare the functions that add to the stacks

void P_add_number(stack<int_identifier>& numbers_list, int_identifier& item1, bool& flag1);

void P_add_el(stack<int_identifier>& operators_list, int_identifier& item1, char element);

void add_not(stack<int_identifier>& operators_list, int_identifier& item1);

void P_sum(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

void P_difference(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

void P_prod(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

void P_xor(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

void P_and(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

void P_or(int num1, int num2, stack<int_identifier>& numbers_list, int_identifier& item1,
    stack<int_identifier>& operators_list, int c);

bool P_maths(stack<int_identifier>& numbers_list, stack<int_identifier>& operators_list, int_identifier& item1);

bool
P_mathsExceptions(stack<int_identifier>& numbers_list, stack<int_identifier>& operators_list, int_identifier& item1);
void P_not(int num1, stack<int_identifier>& numbers_list, int_identifier& item1, stack<int_identifier>& operators_list, int c);
void P_calculate();
void P_calculatorStart();

