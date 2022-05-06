string minRemoveToMakeValid(string s)
{
  stack<int> st;
  for (int i = 0; i < s.size(); ++i)
  {
    if (!st.empty() && s[st.top()] == '(' && s[i] == ')')
      st.pop();
    else if (s[i] == ')' || s[i] == '(')
      st.push(i);
  }

  while (!st.empty())
  {
    s[st.top()] = '*';
    st.pop();
  }

  s.erase(remove(s.begin(), s.end(), '*'), s.end());
  return s;
}

//Time complexity: O(N)
//Auxiliary space complexity: O(N)