#include "CUnit/Basic.h"

#include "../include/test.h" //(the header file containing function)

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite_func(void)
{
    /*
     *   if (problem during initialisation)
     *     return -1; // this number can be used to explicit the problem
     */
    return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_func(void)
{
    return 0;
}

void testSunnyCases(void)
{
    CU_ASSERT_EQUAL(stringValid("j0020:Sand blasting:m1:35"), 1);
    CU_ASSERT_EQUAL(stringValid("Jobno=31:Feeding:m3:30:Mechanical"), 1);
    CU_ASSERT_EQUAL(stringValid("J:Rubber Stamp making:M2:55"), 1);
    CU_ASSERT_EQUAL(stringValid("January:February:m2:24:april:may"), 1);
    CU_ASSERT_EQUAL(stringValid("J00:Baking:M1:45:VT Corp"), 1);
}
void testRainyCases(void)
{
    CU_ASSERT_EQUAL(stringValid("j16:M3:fourty two:Paper_industry"), 0);
    CU_ASSERT_EQUAL(stringValid("J0yz:Pressing:M9:55:Machinery_process:Power on&off"), 0);
    CU_ASSERT_EQUAL(stringValid("J20:M1:60:Raphael WNP Pvt.ltd"), 0);
    CU_ASSERT_EQUAL(stringValid("J005:Book binding:30:Leon Associates"), 0);
    CU_ASSERT_EQUAL(stringValid("j41/Drilling/m1"), 0);
}





