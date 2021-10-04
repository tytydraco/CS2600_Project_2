#include <stdio.h>

#include "input.h"
#include "foodCalc.h"
#include "calculations.h"

int main(int argc, const char* argv[]) {
  request_input_data();
  assert_valid_input();

  calculations();

  printf("calculations ---");
  printf("\tTotal: %f", total);
  printf("\tOver: %f", over);
  printf("\tUnder: %f", under);

  return 0;
}
