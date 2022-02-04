#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <class Type, class Container = deque<Type>> class stack;

int main() {

  struct State {
    int cursor;
    int selectedLength;
    string content;
  };

  class TextEditor{

    public:

      create() {
      }

      string append(string word) {
        content += word;
        cursor += content.size() - 1;
        int start = cursor - selectedLength;
        state.replace(start, cursor, word);
        cursor = start + word.size();
        selectedLength = 0;
        return content;
      }

      void move(int pos) {
        selectedLength = 0;
        if (pos <= 0) {
          cursor = 0;
          return;
        }
        if (pos > content.size() - 1) {
          cursor = content.size() - 1;
          return;
        }
        cursor = pos;
      }

      string backspace() {
        content.pop_back();
        --cursor;
        return content;
      }

      string select(int p1, int p2) {
        int start = min(p1, p2);
        int end = max(p1, p2);
        start = max(start, 0);
        end = min(end, int(content.size() - 1));
        cursor = end;
        selectedLength = end - start;
        return content.substr(start, selectedLength);
      }

      string copy() {
        memory = content.substr(cursor - selectedLength, selectedLength);
        return memory;
      }

      string paste() {
         return append(memory);
      }

      string undo() {
        struct curState;
        curState.cursor = cursor;
        curState.selectedLength = selectedLength;
        curState.content = content;
        undoStack.push(curState);
        if (!prevStateStack.empty()) {
          auto p = prevStateStack.top();
          prevStateStack.pop();
          content = p.content;
          cursor = p.cursor;
          selectedLength = p.selectedLength;
        }
        else {
          content = "";
          cursor = 0;
          selectedLength = 0;
        }
        return content;
      }

      string redo() {
        if (undoStack.empty()) {
          //error
        } else {
          struct curState;
          curState.cursor = cursor;
          curState.selectedLength = selectedLength;
          curState.content = content;
          prevStateStack.push(curState);
          auto b = undoStack.top();
          undoStack.pop();
          cursor = b.cursor;
          selectedLength = b.selectedLength;
          content = b.content;
          return content;
        }
      }

      

    private:
      string content;
      int cursor;
      int selectedLength;
      string memory;
      stack<State> undoStack;
      stack<State> prevStateStack;
  };
}