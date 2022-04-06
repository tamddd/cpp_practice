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
    Token (char ch. double val)
      :kind(ch), value(val) { }
};

Token get_token();   //文字を読み取り、トークンを構築する
double expression(); //+と-に対処する
double term();       //*, /, %に対処する
double primary();    //数値と確固に対処する

vector<Token> tok;

int main(){

    while (cin) {
        Token t = get_token();
        tok.push_back(t);
    }
}

double expression()
{
    double left = term();
    Token t = get_token();
    while (true){
        swith(t.kind){
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