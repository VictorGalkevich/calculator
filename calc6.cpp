#include "functions.h"
#include "programming_operations.h"

int main() {
    int mode;
    label1:
    std::cout << "Enter working mode: \n For engineer mode enter \"0\" \n For programming mode enter \"1\": ";
    cin >> mode;
    if (mode == 1) {
        cin.ignore();
        P_calculate();
    } else if (mode == 0) {
        cin.ignore();
        calculate();
    } else {
        cout << "Wrong working mode! ";
        goto label1;
    }
}