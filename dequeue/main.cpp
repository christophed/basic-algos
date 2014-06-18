#include "deque.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Helpers for setting colors and stuff
void setColor(string colorCode) {
  cout << "\033[1;" + colorCode + "m";
}

void setGreen() {
  setColor("61");
}

void setRed() {
  setColor("31");
}

void resetColor() {
  cout << "\033[0m" << endl;
}

// Real tests

int test3() {

  setGreen();
  cout << "Beginning test 3 -- push and pop" << endl;
  resetColor();

  Deque<int> d;

  d.insert(3);
  d.push(4);
  d.insert(2);
  d.insert(1);

  assert(d.dequeue() == 1);
  assert(d.dequeue() == 2);
  assert(d.dequeue() == 3);
  assert(d.dequeue() == 4);

  for (int i = 0; i < 10; ++i) {
    d.insert(i);
    d.push(i);
  }

  for (int i =0; i < 10; ++i) {
    assert(d.pop() == 10 - 1 - i);
  }

  for (int i =0; i < 10; ++i) {
    assert(d.pop() == i);
  }

  setGreen();
  cout << "FINISHED test 3 -- push and pop" << endl;
  resetColor();

  return 0;
}

int test2() {
  Deque<int> d;

  setGreen();
  cout <<  "Beginning ENQUEUE test" << endl;

  for (int i = 0; i < 100; ++i) {
    if (d.size() != i) {
      setRed();
      d.print();
      resetColor();
      return 2;
    }
    d.insert(i);
  }

  for (int i = 0; i < 100; ++i) {
    if (d.size() != (100 - i)) {
      setRed();
      cout << "Expected size to be " << (100 - i) << endl;
      d.print();
      resetColor();
      return 2;
    }
    if (d.dequeue() != (100 - i - 1)) {
      setRed();
      cout << "Expected dequeued element to be " << (100 - i - 1) << endl;
      d.print();
      resetColor();
      return 2;
    }
  }

  cout << "Finished ENQUEUE test" << endl;

  resetColor();
  return 0;
}

int test1() {
  Deque<int> d;

  setGreen();
  cout << "Beginning PUSH test" << endl;

  for (int i = 0; i < 100; ++i) {
    if (d.size() != i) return 1;
    d.push(i);
  }

  for (int i = 100; i > 0; --i) {
    if (d.size() != i) return 1;
    if (d.pop() != (i - 1)) return 1;
  }

  cout << "Finished PUSH test" << endl;

  resetColor();
  return 0;
}

int main() {
  int testFailure = (test1() || test2() || test3());
  if (testFailure) {
    setRed();
    cout << "FAILED TEST " << testFailure << endl;
  }
  resetColor();
  return 0;
}
