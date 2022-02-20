#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

//COLOUR SCHEME
//only work for ubuntu/linux and macos 
#define RESET   "\033[0m"
#define PURPLE "\033[38;5;93m"
#define PINK_PURPLE "\033[38;5;177m"
#define LIGHT_BLUE "\033[38;5;87m"
#define LIGHT_GREEN "\033[38;5;156m"
#define LIGHT_PINK "\033[38;5;183m"

//Ascii title function
void print_title(){

    std::cout<<PURPLE<<
    "   ___            _                    _            _                   \n"
    "  / __|  __ _    | |    __    _  _    | |   __ _   | |_    ___     _ _  \n"
    " | (__  / _` |   | |   / _|  | +| |   | |  / _` |  |  _|  / _ \\   | '_| \n"
    "  \\___| \\__,_|  _|_|_  \\__|_  \\_,_|  _|_|_ \\__,_|  _\\__|  \\___/  _|_|_  \n"
    "_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"| \n"
    "\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-' \n"
    <<RESET;
                                                                                  
}

//factorial function
double fact(int n){
    return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}
