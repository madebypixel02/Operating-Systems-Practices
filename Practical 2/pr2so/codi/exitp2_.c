#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void
error (char *m)
{
  char s[128];

  sprintf (s, "Error %d %s\n%s\n", errno, m, strerror (errno));
  write (2, s, strlen (s));

  exit (0);
}

int
main (int argc, char *argv[])
{
  char *m = "Helo world!!!!!             \n";

  printf ("%s", m);

  _exit (0);
}
