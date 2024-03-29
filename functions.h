#pragma once

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//here we create a struct to analyze a stroke from the user and divide all the elements
//into functions or numbers, operands

struct identifier {
    char type;
    double value;

    identifier() : type(' '), value(0) {};
};

//getRank helps us to understand what is the prioeity of each function, operation

int getRank(char element);

//here we initialise the constants 

constexpr double E = 2.71828182846;

constexpr double PI = 3.14159265358979323846;

//here we declarare all the functions for engineer mode

double Sin(double x);

double Cos(double x);

double Abs(double x);

double tg(double x);

double ctg(double x);

double Asin(double x);

double Acos(double x);

double Exp(double x);

double lnX(double x);

double lgX(double x);

double upb(double x);

double lwb(double x);

double Cosh(double x);

double Sinh(double x);

double Tanh(double x);

double Ctgh(double x);

double logX(double x, int y);

double fast_pow(double x, int n);

//here we declare the functions that link our operations and stacks, in some cases we throw exceptions

void SinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void absC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void CosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool tgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool ctgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool tghC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool ctghC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool lnC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool lgC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c, double logBasis);

void ACosC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void ASinC(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

//here the functions for additions into stacks are declared

void add_pi(stack<identifier>& numbers_list, identifier& item1, bool& flag1);

void add_number(stack<identifier>& numbers_list, identifier& item1, bool& flag1);

void add_ln(stack<identifier>& operators_list, identifier& item1);

void add_abs(stack<identifier>& operators_list, identifier& item1);

void add_hex(stack<identifier>& operators_list, identifier& item1);

void add_bin(stack<identifier>& operators_list, identifier& item1);

void add_oct(stack<identifier>& operators_list, identifier& item1);

void add_lg(stack<identifier>& operators_list, identifier& item1);

void add_log(stack<identifier>& operators_list, identifier& item1);

void add_sin(stack<identifier>& operators_list, identifier& item1);

void add_asin(stack<identifier>& operators_list, identifier& item1);

void add_cos(stack<identifier>& operators_list, identifier& item1);

void add_acos(stack<identifier>& operators_list, identifier& item1);

void add_tg(stack<identifier>& operators_list, identifier& item1);

void add_ctg(stack<identifier>& operators_list, identifier& item1);

void add_tgh(stack<identifier>& operators_list, identifier& item1);

void add_ctgh(stack<identifier>& operators_list, identifier& item1);

bool maths(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1, double logBasis);

bool mathsExceptions(stack<identifier>& numbers_list, stack<identifier>& operators_list, identifier& item1, double logBasis);

void factorial(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

int factorial_calculate(int num);

double powC(double a, double b);

void sum(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void mod(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void difference(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void production(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

bool division(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void exp(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void upb(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void lwb(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void add_exp(stack<identifier>& operators_list, identifier& item1);

void add_upb(stack<identifier>& operators_list, identifier& item1);

void add_lwb(stack<identifier>& operators_list, identifier& item1);

void power(double num1, double num2, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void sinh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void add_sinh(stack<identifier>& operators_list, identifier& item1);

void add_el(stack<identifier>& operators_list, identifier& item1, char element);

void cosh(double num1, stack<identifier>& numbers_list, identifier& item1, stack<identifier>& operators_list, double c);

void add_cosh(stack<identifier>& operators_list, identifier& item1);

void calculate();



struct programming_identifier {
    int val;
    char ch;
    programming_identifier() :val(0), ch(' ') {};
};
int programming_getRank(char element);
