#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
//#include <random.h> //apparently this never existed :(

int main()
{
  int orig = getpid(); //parent's pid, all child processes will have this stored
  printf("out some initial message.\n"); //sorry
  fork(); //make first child
  if (getpid() == orig) //make second child (only the parent does this)
    fork();
  if (getpid() != orig) //now both children
    {
      printf("%d\n", getpid()); //intially printing pid
      srand(getpid()); //seeding the random num gen with different values
      int sleeptime = rand() % 16 + 5; //gotta be between 5 and 20 incl
      sleep(sleeptime); //sleep that long
      printf("Good morning! I'm done sleeping :)\n"); //wake up
      return sleeptime; //return
    }
  else{
    int staytus; //didn't know if status would be taken
    int fave = wait(&staytus); //storing child's pid, putting status as a ptr didn't work for some reason
    int sec = WEXITSTATUS(staytus); //the retval of the child
    //printf("but w h ERE's the SeG fAUlt?!??\n"); //testing purposes
    printf("my favorite child: %d, was asleep for %d seconds\n", fave, sec); //printing child and sleep time
    printf("I suppose my living child can fend for themself; I'm done.\n"); //parent about to die
  }
  return 0;
}
