#include <setjmp.h>
#include "setjmp_test.h"

jmp_buf env;
int e = 50;

void func(void)
{
  printf("func()\n");
  e++;
  printf("call longjmp()\n");
  longjmp(env, 1);
  /* not reached. */
}

void setjmp_test() {
  volatile int a = 10;
  int b = 20;
  register int c = 30;
  static int d = 40;

  printf("call setjmp()\n");

  if (setjmp(env) == 0) {
    printf("save context information by setjmp()\n");
    a++;
    b++;
    c++;
    d++;
    func();
  } else {
    printf("restore context information by setjmp()\n");
    printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
  }
}
