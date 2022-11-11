#include <stdio.h>
#include <stdlib.h>

#define MOD 10000

int k = 0;

int global[3500];

void
panic (char *m)
{
  fprintf (stderr, "%s\n", m);
  exit (0);
}

void
rec1 ()
{
  k++;
  if (k % MOD == 0)
    fprintf (stderr, "%d ", k / MOD);
  rec1 ();
}

void
rec2 ()
{
  int *tmp;

  tmp = malloc (128 * sizeof (int));
  if (tmp == NULL)
    exit (0);

  k++;
  if (k % MOD == 0)
    fprintf (stderr, "%d ", k / MOD);
  rec2 ();
}

void
rec3 ()
{
  int *tmp;

  tmp = malloc (256 * sizeof (int));
  if (tmp == NULL)
    exit (0);

  k++;
  if (k % MOD == 0)
    fprintf (stderr, "%d ", k / MOD);
  rec3 ();
}

void
rec4 ()
{
  int tmp[16];

  k++;
  if (k % MOD == 0)
    fprintf (stderr, "%d ", k / MOD);
  rec4 ();
}

void
rec5 ()
{
  int tmp[32];

  k++;
  if (k % MOD == 0)
    fprintf (stderr, "%d ", k / MOD);
  rec5 ();
}

void
rec6 ()
{
  global[k] = k;
  if (k % 200 == 0)
    fprintf (stderr, "%d ", k);
  k++;
  rec6 ();
}

int
main (int argc, char *argv[])
{
  int mode = 1;
  if (argc > 1)
    mode = atoi (argv[1]);

  printf ("Testing rec%d...\n", mode);
  switch (mode)
    {
    case 1:
      rec1 ();
      break;
    case 2:
      rec2 ();
      break;
    case 3:
      rec3 ();
      break;
    case 4:
      rec4 ();
      break;
    case 5:
      rec5 ();
      break;
    case 6:
      rec6 ();
      break;
    default:
      panic ("Wrong mode");
    }

  return 0;
}
