//_____________________________________________________________________________________________________

#include "header.h"

double version = 1.1;

using namespace std;

//_____________________________________________________________________________________________________

class Token {
    public:
        char kind;        // what kind of token 
        double value;     // for numbers: a value 
        Token(char ch):kind(ch), value(0) {} //construct for operations, brackets/braces
        Token(char ch, double val):kind(ch), value(val) {} //floating points nums of type 8
};
//_____________________________________________________________________________________________________

class Token_stream{
    public:
        Token get(); //reads characters from cin and makes them into Tokens
        void putback(Token t); //puts its argument bcak into the Token_stream's buffer
    private:
        bool full{false};
        Token buffer{0};
};
//_____________________________________________________________________________________________________

void Token_stream::putback(Token t){

    if(full){
        cerr<<"putback() into a full buffer\n"; 
        exit(1);
    }

    buffer = t; //copy the token into the buffer
    full = true; //set buffer to full
    
}
//_____________________________________________________________________________________________________

Token Token_stream::get(){

    if(full){ //if there is already a token in the buffer
        full = false;
        return buffer;
    }

    char ch;
    cin>>ch;

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"

    case '(': case ')': case '+': case '-': case '*': case '/':

        return Token(ch);        

    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         
        double val;
        cin >> val;       

        return Token('8', val); 
    }

    default:
        cerr<<"Bad token\n"; exit(1);
    }
}
//_____________________________________________________________________________________________________

Token_stream ts;
//_____________________________________________________________________________________________________

double expression();  
double term();   
double primary();     
//_____________________________________________________________________________________________________

double expression(){ //+ & -

    double left = term();      // read and evaluate a Term

    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}
//_____________________________________________________________________________________________________

double term(){ // / & *

    double left = primary();
    
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
        
            left /= d;
            t = ts.get();
            break;
        }
        default:

            ts.putback(t);

            return left;
        }
    }
}
//_____________________________________________________________________________________________________

double primary(){ //numbers, ()

    Token t = ts.get();

    switch(t.kind){
    case '(':
    {
        double d = expression();
       
        t = ts.get();

        if(t.kind != ')'){
            cerr<<"Expected end )\n";
            exit(1);
        }

        return d;
    }
    case '8':
        return t.value;
    default:
        cerr<<"Primary expected\n"; exit(1);

    }
}
//_____________________________________________________________________________________________________
int main(){

    print_title();
    cout<<"[ Version: "<<version<<" ]\n";
    cout<<"END EXPRESSION WITH A SEMICOLON (;)\n-> program will not return answer otherwise\n\t\t-> EXAMPLE:[1+2+3\e[5m;\e[0m]\nTo quit enter \e[1mq\e[0m\n";
    cout<<"ENTER EXPRESSION: ";


    try {
        double answer;
        
        double val = 0;

        while (cin){
            Token t = ts.get();

            if(t.kind == 'q'){
                cout<<"-Program ended-\n";
                return EXIT_SUCCESS;
            }
            if(t.kind == ';')
                cout<<"= "<<val<<"\nENTER EXPRESSION: ";
            else{
                ts.putback(t);
                val = expression();
            }
            
        }

        cout<<answer<<'\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n';

        return 1;
    }
    catch (...) {
        cerr << "exception\n";

        return 2;
    }
}
//_____________________________________________________________________________________________________
