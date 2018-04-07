#include "cpuinfo_x86.h"
#include <stdio.h>
/*
1. 编译：
gcc main.c -o main.o -I../../github/cpu_features/include -L../../github/cpu_features/build -lcpu_features

2. 运行测试：
./main.o #
*/

void ComputeTest(void) {
  const X86Features features = GetX86Info().features;
  if (features.aes && features.sse4_2) {
    printf("The CPU supports both the AES and the SSE4.2 instruction sets! \n\
        you can Run optimized code!\n");
  } else {
    printf("The CPU  do notsupports both the AES and the SSE4.2 instruction sets! \n\
        you can Run standard code.!\n");
  }
}

int main(int argc, const char* argv[]) {
  ComputeTest();
  return 0;
}



