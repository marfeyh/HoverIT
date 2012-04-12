#include "../../src/list.h"

CalcStatePtr calc = NULL;

/* Set up and clean up test suite */

int init_suite(void) {
  calc = mkCalcState();
  return calc == NULL;
}

int clean_suite(void) {
  freeCalcState(calc);
  calc=NULL;
  return 0;
}

void testCase1(void) {
  // Enter 17+3=, monitor buffer between button presses

  // Initial buffer is empty
  CU_ASSERT(!strcmp(getBuffer(calc), ""));

  // Press '1'  (expected buffer: "1")
  pressDigit(calc, '1');
  CU_ASSERT(!strcmp(getBuffer(calc), "1"));

  // Press '7'  (expected buffer: "17")
  pressDigit(calc, '7');
  CU_ASSERT(!strcmp(getBuffer(calc), "17"));
  
  // Press '+'  (expected buffer: "17")
  pressPlus(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "17"));

  // Press '3'  (expected buffer: "3")
  pressDigit(calc, '3');
  CU_ASSERT(!strcmp(getBuffer(calc), "3"));

  // Press '='  (expected buffer: "20")
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "20"));
}

