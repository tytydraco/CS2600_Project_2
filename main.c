#include <stdio.h>

#include "input.h"
#include "calculations.h"

int main(int argc, const char* argv[]) {

  struct InputData b;

  b = request_input_data();
  assert_valid_input(b);

  calculations(b);

  printf("calculations ---");
  printf("\nTotal: %0.2f", total);
  printf("\nAllowed: %0.2f", totalAllowable);
  printf("\nOver: %0.2f", over);
  printf("\nUnder: %0.2f", under);

  return 0;
}
