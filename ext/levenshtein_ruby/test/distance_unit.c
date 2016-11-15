#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include "../distance.h"

void test_dist_001(void);

int main() {
  CU_pSuite dist_suite;

  CU_initialize_registry();
  dist_suite = CU_add_suite("Distance", NULL, NULL);
  CU_add_test(dist_suite, "test_001", test_dist_001);
  CU_console_run_tests();
  CU_cleanup_registry();

  return(0);
}

void test_dist_001(void) {

  CU_ASSERT(distance("ads", "asd") == 1);
}

