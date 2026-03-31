/*

Postfix Expression Evaluation

Expression: 5 1 2 + 4 * + 3 -
● Push 5 → [5]
● Push 1 → [5, 1]
● Push 2 → [5, 1, 2]
● + → Pop 2 & 1, compute 1 + 2 = 3, push 3 → [5, 3]
● Push 4 → [5, 3, 4]
● * → Pop 4 & 3, compute 3 * 4 = 12, push 12 → [5, 12]
● + → Pop 12 & 5, compute 5 + 12 = 17, push 17 → [17]
● Push 3 → [17, 3]
● - → Pop 3 & 17, compute 17 - 3 = 14, push 14 → [14]
● Final result: 14





*/

#include<iostream>
#include<stack>

using namespace std;

int postfix(string str){
    stack<int> s;

for(int i=0; i<str.size() ;i++){
    if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
        s.push(str[i] - '0');
    }
    else if(str[i] == '+' ){
       int a = s.top(); s.pop();
      int b =s.top(); s.pop();

        int sum = a + b;
        s.push(a+b);
    }
     else if(str[i] == '-' ){
       int a = s.top(); s.pop();
      int b =s.top(); s.pop();
        int sum = a - b;
        s.push(a-b);
    }
     else if(str[i] == '*' ){
       int a = s.top(); s.pop();
      int b =s.top(); s.pop();
        int sum = a * b;
        s.push(a*b);
    }
     else if(str[i] == '/' ){
       int a = s.top(); s.pop();
      int b =s.top(); s.pop();
        int sum = a / b;
        s.push(a/b);
    }
    

    }
    return s.top();
}




int main(){

   string s;

   getline(cin,s);


   cout << postfix(s);



    return 0;
}