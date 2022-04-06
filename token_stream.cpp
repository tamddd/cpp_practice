void error (const char* message) {
    cout << message << endl;
    exit(1);
}

class Token_stream{
public:
    Token_stream();
    Token get();
    void putback(Token t);

private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
:full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    fill = true;
}

Token Token_stream::get()
{
    if (full){
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
        case ';':
        case 'q':
            default:
                error("Bad token");
    }
}