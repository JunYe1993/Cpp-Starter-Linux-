#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef double (*cal_funcptr)(double, double); // function pointer type

enum ErrorCode {
    Success = 0,
    Invalid_Operand,
    Invalid_Operator,
    Not_Enough_Operands,
    Too_Many_Operands
};

class Operators {
public:
    map<string, cal_funcptr> m;
    bool isValid (string& s) {
        return (m.find(s) != m.end());
    }
    double caculate (string& s, vector<double>& stack) {
        double a, b;
        b = stack.back();
        stack.pop_back();
        a = stack.back();
        stack.pop_back();
        return m[s](a, b);
    }
};

int isValidNumber (string& s, double& num) {
    
    num = 0;
    int size = s.size();
    int degree = 1;
    bool isNegative = false;

    for (int i = 0; i < size; ++i) {
        
        if (i == 0 && s[i] == '-') {
            isNegative = true;
        
        } else if (s[i] == '.') {
            if ((i == 1 && isNegative) || degree > 1) 
                return Invalid_Operator;
            degree *= 10;

        } else if (isdigit(s[i])) {
            if (degree == 1)
                num = num * 10 + s[i] - '0';
            else {
                num += (double) (s[i] - '0') / degree;
                degree *= 10;
            }
                
        } else 
            return Invalid_Operand;
    }

    if (isNegative) num = num * -1;
    return Success;
}

int ErrorMessageHandler(int code) {
    vector<string> message = {
        "Invalid operand",
        "Invalid operator",
        "Not enough operands",
        "Too many operands"
    };
    cout << message[--code] << endl;
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string operand;
    double temp;
    vector<double> stack;

    Operators opts;
    opts.m.emplace("+", [](double a, double b){ return a + b; });
    opts.m.emplace("-", [](double a, double b){ return a - b; });
    opts.m.emplace("*", [](double a, double b){ return a * b; });
    opts.m.emplace("/", [](double a, double b){ return a / b; });
    
    while (cin >> operand) {

        if (operand == "exit") break;
     
        if (opts.isValid(operand)) {
            if (stack.size() < 2) 
                return ErrorMessageHandler(Not_Enough_Operands);
            stack.push_back(opts.caculate(operand, stack));
        
        } else {
            int retCode = isValidNumber(operand, temp);
            if (retCode > 0)
                return ErrorMessageHandler(retCode);
            stack.push_back(temp);
        }
    }


    // cout << endl;
    if (stack.size() == 1)
        cout << stack[0] << endl;
    else if (stack.size() > 1)
        return ErrorMessageHandler(Too_Many_Operands);

    return 0;
}