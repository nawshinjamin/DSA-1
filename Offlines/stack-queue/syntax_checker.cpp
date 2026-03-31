#include <stack>
#include <string>
using namespace std;

/**
 * Helper function to check if an opening bracket matches a closing bracket
 * @param opening: The opening bracket character
 * @param closing: The closing bracket character
 * @return true if they form a matching pair, false otherwise
 */
bool isMatchingPair(char opening, char closing) {
    // TODO: Implement this helper function

    // Check if opening and closing brackets match
    // Valid pairs: (), [], {}
  return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
 // Replace this with your implementation
}

/**
 * Checks if brackets in an arithmetic expression are properly matched
 * @param expression: A string containing an arithmetic expression
 * @return true if all brackets are properly matched and balanced, false otherwise
 */
bool isValidExpression(const string& expression) {
    // TODO: Implement the syntax checker using std::stack
   stack<char> st;

    for(int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];

        // opening brackets
        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        // closing brackets
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if(st.empty())
                return false;

            char top = st.top();
            st.pop();
     if(!isMatchingPair(top, ch))
                return false;
        }
        // all other characters are ignored
    }

    return st.empty();
     // Replace this with your implementation
}
