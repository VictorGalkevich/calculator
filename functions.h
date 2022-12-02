#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <queue>

using namespace std;

struct identifier {
    char type;
    double value;

    identifier() : type(' '), value(0) {};
};

int getRank(char element);

const double PI = 3.14159265358979323846;

void add_pi(stack<identifier> &numbers_list, identifier &item1, bool &flag1);

void add_number(stack<identifier> &numbers_list, identifier &item1, bool &flag1);


double Sin(double x);

double Cos(double x);

double tg(double x);

double ctg(double x);

double Asin(double x);

double Acos(double x);

double Exp(double x);

double Pow(double x);

double fast_pow(double x, int n);

void SinC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void CosC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

bool tgC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

bool ctgC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

bool lnC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

bool logC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void
ACosC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void
ASinC(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void add_ln(stack<identifier> &operators_list, identifier &item1);

void add_log(stack<identifier> &operators_list, identifier &item1);

void add_sin(stack<identifier> &operators_list, identifier &item1);

void add_asin(stack<identifier> &operators_list, identifier &item1);

void add_cos(stack<identifier> &operators_list, identifier &item1);

void add_acos(stack<identifier> &operators_list, identifier &item1);

void add_tg(stack<identifier> &operators_list, identifier &item1);

void add_ctg(stack<identifier> &operators_list, identifier &item1);

bool maths(stack<identifier> &numbers_list, stack<identifier> &operators_list, identifier &item1);

bool mathsExceptions(stack<identifier> &numbers_list, stack<identifier> &operators_list, identifier &item1);

void
sum(double num1, double num2, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list,
    double c);

void difference(double num1, double num2, stack<identifier> &numbers_list, identifier &item1,
                stack<identifier> &operators_list, double c);

void production(double num1, double num2, stack<identifier> &numbers_list, identifier &item1,
                stack<identifier> &operators_list, double c);

bool division(double num1, double num2, stack<identifier> &numbers_list, identifier &item1,
              stack<identifier> &operators_list, double c);

void exp(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void add_exp(stack<identifier> &operators_list, identifier &item1);

void
power(double num1, double num2, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list,
      double c);

void sinh(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void add_sinh(stack<identifier> &operators_list, identifier &item1);

void add_el(stack<identifier> &operators_list, identifier &item1, char element);

void cosh(double num1, stack<identifier> &numbers_list, identifier &item1, stack<identifier> &operators_list, double c);

void add_cosh(stack<identifier> &operators_list, identifier &item1);

