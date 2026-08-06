// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    vector<int> s;
    for (auto& token : tokens) {
      if (isdigit(token.back()))
        s.push_back(stoi(token));
      else {
        int op2 = s.back();
        s.pop_back();
        int op1 = s.back();
        s.pop_back();
        int r;
        switch (token.front()) {
          case '+':
            r = op1 + op2;
            break;
          case '-':
            r = op1 - op2;
            break;
          case '*':
            r = op1 * op2;
            break;
          case '/':
            r = op1 / op2;
            break;
        }
        s.push_back(r);
      }
    }
    return s.back();
  }
};
// @leet end