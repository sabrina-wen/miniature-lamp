#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    char str[] = "exiting file b/c of SIGINT, pce\n";
    int file = open("blah.txt", O_RDWR | O_APPEND);
    write(file, "exiting file b/c of SIGINT, pce\n", 1000);
    close(file);
    printf("\n%s", str);
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
