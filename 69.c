#include <stdio.h>

void prime( int min, int max) {

  int arr[100], i = 0, b = 0;

  for (int a = min; a <= max; a++) {
    b = 0;
    for (int k = 2; k < a; k++) {
        int j = a % k;
        if (j == 0) {
          b = 1;
          break;
        }
      }
        if (b == 0) {
          arr[i] = a;
          i++;
        }
    }
  for (int c = 0; c < i; c++) {
    printf("%i ", arr[c]);
  }
}


int main(int argc, char const *argv[]) {
  prime(3, 20);
  return 0;
}
