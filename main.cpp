/*#include <iostream>
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
}*/

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{
  EVP_MD_CTX *mdctx;
  const EVP_MD *md;
  char mess1[] = "Test Message\n";
  char mess2[] = "Hello World\n";
  unsigned char md_value[EVP_MAX_MD_SIZE];
  unsigned int md_len, i;

  if (argv[1] == NULL) {
    printf("Usage: mdtest digestname\n");
    exit(1);
  }

  OpenSSL_add_all_algorithms();
  md = EVP_get_digestbyname(argv[1]);
  if (md == NULL) {
    printf("Unknown message digest %s\n", argv[1]);
    exit(1);
  }

  mdctx = EVP_MD_CTX_new();
  EVP_DigestInit_ex(mdctx, md, NULL);
  EVP_DigestUpdate(mdctx, mess1, strlen(mess1));
  EVP_DigestUpdate(mdctx, mess2, strlen(mess2));
  EVP_DigestFinal_ex(mdctx, md_value, &md_len);
  EVP_MD_CTX_free(mdctx);

  printf("Digest is: ");
  for (i = 0; i < md_len; i++)
    printf("%02x", md_value[i]);
  printf("\n");

  exit(0);
}