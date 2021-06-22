#include <iostream>
#include <stdexcept>
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



int main()
{
  printGreeting();
  QuickSort sort = QuickSort();
  int arr[] = {-1, 0, 1, 2, -1, -4};
  for (auto &num : arr)
    cout << num << " ";
  cout << endl;
  sort.sort(arr, 6);
  for (auto &num : arr)
    cout << num << " ";
  cout << endl;
  cout << "Hi" << endl;
  return 0;
}