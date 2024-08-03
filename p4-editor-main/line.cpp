/*
 * Visualization for testing the text buffer implementation.
 *
 * Note that this is just for testing! This code will only work once
 * you have all the functionality of the TextBuffer class
 * Originally written for 15-122 Principles of Imperative Computation
 * Ported to C++ by Saquib Razak for EECS 280. */

#include <stdio.h>
#include <iostream>
#include <string>
#include "TextBuffer.hpp"

using namespace std;

void visualize_buffer(TextBuffer &buffer) {
  int left = 0;
  while (buffer.backward()) {
    --left;
  }
  while (!buffer.is_at_end()) {
    if (left == 0) {
      cout << "|";
    }
    char c = buffer.data_at_cursor();
    if (c == '\n') {
      cout << "\\n";
    } else {
      cout << c;
    }
    ++left;
    buffer.forward();
  }

  for (int i = 0; i < left; ++i) {
    buffer.backward();
  }
  if (buffer.is_at_end()) {
    cout << "|";
  }
  cout << "\t:(" << buffer.get_row() << "," << buffer.get_column() << " )";
}

void process_char(TextBuffer &buffer, char c)  {
  if (c == '<') {
    cout << "left  : ";
    buffer.backward();
  } else if (c == '>') {
    cout << "right : ";
    buffer.forward();
  } else if (c == '^') {
    cout << "up    : ";
    buffer.up();
  } else if (c == '!') {
    cout << "down  : ";
    buffer.down();
  } else if (c == '#') {
    cout << "del   : ";
    buffer.remove();
  } else if (c == '[') {
    cout << "home  : ";
    buffer.move_to_row_start();
  } else if (c == ']') {
    cout << "end   : ";
    buffer.move_to_row_end();
  } else if (c == '@') {
    cout << "enter : ";
    buffer.insert('\n');
  } else {
    cout << "add   : ";
    buffer.insert(c);
  }
}

void process_string(TextBuffer &buffer, string s) {
  int limit = s.size();
  for (int i = 0; i < limit; i++) {
    process_char(buffer, s[i]);
    visualize_buffer(buffer);
    cout << "\n";
  }
}

void test() {
  TextBuffer buffer;
  cout << "LINE Is Not an Editor -- it is a linear visualization of a"
       << " TextBuffer.\n"
       << "The '<' character mimics a call to backward()\n"
       << "The '>' character mimics a call to forward()\n"
       << "The '#' character mimics a call to remove()\n"
       << "The '^' character mimics a call to up()\n"
       << "The '!' character mimics a call to down()\n"
       << "The '[' character mimics a call to move_to_row_start()\n"
       << "The ']' character mimics a call to move_to_row_end()\n"
       << "The '@' character mimics a call to insert() with a newline\n"
       << "All other characters just mimic insert() with that character\n\n"
       << "Give initial input (empty line quits):"
       << endl;

  string s;
  while (getline(cin, s) && s != "") {
    cout << "STARTING\nstart : ";
    visualize_buffer(buffer);
    cout << "\n";
    process_string(buffer, s);
    cout << "\n";

    cout << "Done. More input? (empty line quits):" << endl;
  }
}

int main() {
  test();
  cout << "Goodbye." << endl;
}
