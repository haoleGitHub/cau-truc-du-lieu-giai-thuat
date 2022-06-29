#include<iostream>
int main() {
  for (int i = 10; i < 1000; i++) {
    if (i % 3 == 1 && i % 5 == 2 && i % 7 == 4 && i % 13 == 6)
      std::cout << i;
  }
  return 0;
}