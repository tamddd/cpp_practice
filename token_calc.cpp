#include <stdexcept>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

class Token {
public:
    char kind;
    double value;                      // トークンの種類
    Token (char ch)                    //　数値の場合の値
      :kind(ch), value(0) { }          // Tokenをcharから作成する
    Token (char ch, double val)
      :kind(ch), value(val) { }
};

void error (const char* message) {
    cout << message << endl;
    exit(1);
}

Token get_token();   //文字を読み取り、トークンを構築する
double expression(); //+と-に対処する
double term();       //*, /, %に対処する
double primary();    //数値と確固に対処する

vector<Token> tok();

int main(){

    try {
        while(cin)
            cout << expression() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception" << endl;
        return 2;
    }
}

double expression()
{
    double left = term();
    Token t = get_token();
    while (true){
        switch(t.kind){
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true){
        switch (t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/':
            {double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = get_token();
            break;
            }
            default:
                return left;
        }
    }
}

double primary()
{
    Token t = get_token();
    switch (t.kind){
        case '(': {
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
            return 1;
    }
}