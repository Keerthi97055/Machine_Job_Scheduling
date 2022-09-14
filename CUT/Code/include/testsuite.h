#ifndef TESTHEAD
#define TESTHEAD

#include "CUnit/Basic.h"
#include "header.h"
#include "test.h"

int init_suite_func(void);
int clean_suite_func(void);

void testSunnyCases(void);
void testRainyCases(void);

#endif  //End of TESTHEAD here