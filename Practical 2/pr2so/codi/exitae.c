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

void
func (void)
{
  char *m = "That's all folks!\n";

  write (1, m, strlen (m));
}

int
main (int argc, char *argv[])
{
  char *m[3] = { "Always look on the bright side of life\n",
    "Houston, we have a problem\n",
    "I'm going to count to three.  There will not be a four.\n"
  };

  srand (getpid ());            /* Random generator inialization */

  atexit (func);

  switch (rand () % 4)
    {

    case 0:
      write (1, m[0], strlen (m[0]));
      exit (0);

    case 1:
      write (1, m[1], strlen (m[1]));
      exit (0);

    case 2:
      write (1, m[2], strlen (m[2]));
      exit (0);

    }

  _exit (0);


}
