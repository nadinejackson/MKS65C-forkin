#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
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
    int staytus;
    int fave = wait(&staytus);
    int sec = WEXITSTATUS(staytus);
    //printf("but w h ERE's the SeG fAUlt?!??\n");
    printf("my favorite child: %d, was asleep for %d seconds\n", fave, sec);
    printf("I suppose my living child can fend for themself; I'm done.\n");
  }
  return 0;
}
