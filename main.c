#include <stdio.h>

#include "input.h"
#include "foodCalc.h"
#include "calculations.h"

int main(int argc, const char* argv[]) {
  request_input_data();
  assert_valid_input();
  return 0;
}
