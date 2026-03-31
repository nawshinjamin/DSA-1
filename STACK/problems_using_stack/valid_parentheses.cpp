/*

given a string s containing just the characters of parentheses likw: 
str = "({})"   str = "({}]"    str = "({}"   
determine if the input string is valid or invalid

An iput string is valid if:
1. open brackets must be closed by the same type of brackets
2. open brackets must be closed in the correct order 
3. every close bracket has a corresponding opemn bracket of the same type

ex 1:
input : "()"
output : valid

ex 2:
input : "{)[]{}"
output : invalid

*/

#include<iostream>
#include<stack>

using namespace std;

bool isValid(string str){
    stack<char> st;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '[' ||  str[i] == '{' || str[i] == '(' ){
            st.push(str[i]);

        }
        else {
            if(st.size() == 0){
                return false;
            }
            else{
               
                char top = st.top();
if((str[i] == ')' && top == '(') ||
   (str[i] == '}' && top == '{') ||
   (str[i] == ']' && top == '[')) {
    st.pop();
} else {
    return false;
}
    
                }
            }
        }
    
    return st.empty();
}


int main(){
    string s;
cin >> s;
cout << (isValid(s) ? "valid" : "Invalid");
return 0;
}