#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("\nexiting file b/c of SIGINT, pce\n");
    exit(1);
  }
  if (signo == SIGUSR1) {
    printf("process id thanks to SIGUSR1: %d\n", getpid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1) {
    printf("process id: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
