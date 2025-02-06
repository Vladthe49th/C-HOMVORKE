#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std; 

bool isValidBrackets(const string& s) {
    stack<char> st;
    unordered_map<char, char> bracketPairs = { {')', '('}, {'}', '{'}, {']', '['} };

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (bracketPairs.count(c)) {
            if (st.empty() || st.top() != bracketPairs[c]) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string with brackets: ";
    cin >> input;

    if (isValidBrackets(input)) {
        cout << "Valid bracket sequence." << endl;
    }
    else {
        cout << "Invalid bracket sequence." << endl;
    }
}
