#include <iostream>
#include <stdexcept>
#include <vector>
#include "sort.hpp"
#include "learning.hpp"

extern "C" 
{
    #include "hello.h"
}

using namespace std;

void switchTest(int num) {
  switch (num) {
    case 1:
      int declare;
      declare = 5;
    case 2:
      cout << declare << endl;
  }
}

void throwTest(int num1, int num2) {
  if (num1 != num2)
    throw std::runtime_error("Not the same.");
  cout << "Same." << endl;
}

void throwTestTest () {
  int num1, num2;
  while (cin >> num1 >> num2) {
    try {
      // execute code that will add the two Sales_items
      // if the addition fails, the code throws a runtime_error exception
      throwTest(num1, num2);
    } catch (std::runtime_error &err) {
      // remind the user that the ISBNs must match and prompt for another pair
      cout << err.what() << "\nTry Again?  Enter y or n" << endl;
      char c;
      cin >> c;
      if (!cin || c == 'n')
        break;      // break out of the while loop
    }
  }
}


template <typename T>
int get_size(const std::vector<T> &first) {
  return (int)first.size();
}

template <typename T, typename... Args>
int get_size(const std::vector<T> &first, const Args&... args)
{
  return (int)(first.size() + get_size(args...));
}

template <typename T>
void add_element(std::vector<T> &clients, T data) {
  clients.push_back(data);
}

template <typename T>
void pop_element(std::vector<T> &clients, int index) {
  auto it = clients.begin() + index;
  clients.erase(it);
}


int main()
{
  printGreeting();
  vector<int> a = {1, 2, 3};
  vector<char> b = {'1', '2', '3'};

  cout << get_size(a) << endl;
  cout << get_size(b) << endl;
  cout << get_size(a, b) << endl;

  return 0;
}