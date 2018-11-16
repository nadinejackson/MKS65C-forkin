#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
//#include <random.h> //apparently this never existed :(

int main()
{
  int orig = getpid();
  printf("out some initial message.\n");
  fork();
  if (getpid() == orig)
    fork();
  if (getpid() != orig)
    {
      printf("%d\n", getpid());
      srand(getpid());
      int sleeptime = rand() % 16 + 5;
      sleep(sleeptime);
      printf("Good morning! I'm done sleeping :)\n");
      return sleeptime;
    }
  else{
    int * staytus;
    printf("my favorite child: %d, was asleep for %d seconds\n", 123, wait());
    //printf("my second child: %d", waitpid(getpid+2, staytus,0));
   }
  return 0;
}
