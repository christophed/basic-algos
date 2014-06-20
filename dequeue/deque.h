/*
 * Author: Christophe
 * Date: 2014/06/17
 * ------------------
 * Interface for a deque
 *
 */

#include <cstddef>
#include <cassert>
#include <iostream>
#include <ios>

const int INITIAL_DEQUE_SIZE = 8;

/*
 * Deque class
 * The tail is one element beyond the current number of items;
 */
template <typename T>
class Deque {

  T *elems;
  int head; // Index of head
  int tail; // Index of tail
  size_t num_elems;
  size_t capacity;

  public:
    Deque();
    Deque(int size);
    ~Deque();

    // Methods operating on the "end" of the deque
    T pop();
    void push(T elem);

    // Methods operating on the "head" of the deque
    T dequeue();
    void insert(T elem);

    // Utilities
    size_t size() { return num_elems; }

    void print();

  private:
    void expand_capacity();
};

template <typename T>
Deque<T>::Deque() {
  elems = new T[INITIAL_DEQUE_SIZE];
  num_elems = 0;
  tail = head = 0;
  capacity = INITIAL_DEQUE_SIZE;
}

template <typename T>
T Deque<T>::pop() {
  assert(num_elems > 0);
  --num_elems;

  if (--tail < 0) {
    tail = capacity - 1;
  }

  T elem = elems[tail]; // save object
  elems[tail] = NULL; // remove reference

  return elem;
}

template <typename T>
void Deque<T>::push(T elem) {
  if (num_elems == capacity) {
    expand_capacity(); // What if this fails?
  }

  elems[tail] = elem;

  if (++tail == capacity) {
    tail = 0;
  }

  ++num_elems;
}

template <typename T>
Deque<T>::~Deque() {
  delete[] elems;
}

template <typename T>
void Deque<T>::expand_capacity() {
  T *new_elems = new T[capacity * 2];

  for (int i = 0; i < num_elems; ++i) {
    int index = (head + i) % capacity;
    new_elems[i] = elems[index];
  }

  capacity *= 2;

  delete[] elems;
  elems = new_elems;
  head = 0;
  tail = num_elems;
}

template <typename T>
T Deque<T>::dequeue() {
  assert(num_elems > 0);
  T elem = elems[head];
  elems[head] = NULL;
  num_elems--;

  if (++head == capacity) {
    head = 0;
  }

  return elem;
}

template <typename T>
void Deque<T>::insert(T elem) {
  if (num_elems == capacity) {
    expand_capacity(); // What if this fails?
  }

  // Edge case -- advance everything to maintain invariant
  if (num_elems == 0) {
    ++tail;
    ++head;
  }

  if (--head < 0) {
    head = capacity - 1;
  }
  elems[head] = elem;
  ++num_elems;
}

using std::cout;
using std::endl;

template <typename T>
void Deque<T>::print() {
  cout << "***********************" << endl;
  cout << "Head: " << head << " Tail: " << tail
       << " Elems: " << num_elems << " Cap: " << capacity << endl;
  for (int i = 0; i < num_elems; ++i) {
    cout.width(4);
    int index = (head + i) % capacity;
    cout << elems[index];
  }
  cout << endl;
}

