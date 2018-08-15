/* Author: Jianying Chiang      Date: 2018-08-02
   The purpose of this program is to ask the user to input
   a set of brackets and will validate this string to check
   if the user has inputted complete sets of brackets. It uses
   stack, a type of container adaptors with LIFO, for
   validation. The program also includes a user-friendly menu
   system.
*/

#include <iostream>
#include <stack>
using namespace std;

//main
int main()
{
    //variables for menu system.
    bool decision=true;
    string answer;

    cout << "Welcome to this bracket program!" << endl;
    while(decision==true) {
        cout << "\nWould you like to test if a set of brackets are complete? (y/n)\n";
        try {
            cin >> answer;
        } catch(...){}
        if(answer=="Y" || answer=="y") {
            //variables for validating if brackets are complete.
            stack<char> s;
            bool completeSet=true;
            bool bracketInput=false;
            string input;

            cout << endl << "Enter a set of brackets: " << endl;
            cin >> input;

            //loops through input using a stack to validate whether or not the brackets are complete.
            for(char& c : input) {
                if(s.empty()==false) {
                    bracketInput=true;
                }
                if(c=='(' || c=='[' || c=='{') {
                    s.push(c);
                }
                else if(c==')') {
                    if(s.empty()==false && s.top()=='(') {
                        s.pop();
                    }
                    else {
                        input.clear();
                        completeSet=false;
                    }
                }
                else if(c==']') {
                    if(s.empty()==false && s.top()=='[') {
                        s.pop();
                    }
                    else {
                        input.clear();
                        completeSet=false;
                    }
                }
                else if(c=='}') {
                    if(s.empty()==false && s.top()=='{') {
                        s.pop();
                    }
                    else {
                        input.clear();
                        completeSet=false;
                    }
                }
            }

            //checks if all brackets were closed, if user entered any brackets at all, and if brackets are complete.
            if(completeSet==true && bracketInput==true && s.empty()==true) {
                cout << "You have entered a complete set of brackets." << endl;
            }
            else {
                cout << "You have not entered a complete set of brackets." << endl;
            }

        }
        else if(answer=="N" || answer=="n") {
            decision=false;
        }
        else {
            cout << "Invalid character input. Try again." << endl;
        }
    }
    if(decision==false) {
        cout << "Bye then!" << endl;
    }

    return 0;
} //----------------End of main----------------
