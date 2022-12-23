/* ************************************************************************** */
/*                                                                            */
/*                                           =@@*   +@@+                      */
/*                                           =@@*   +@@+ :*%@@@%*:            */
/*                                           =@@*   =@@+.@@@=--%@@-           */
/*                                           :@@%. .#@@--@@*   +@@* .+%@@@    */
/*   main_b.c                                 =%@@@@@@+ =@@*   =@@+.@@@+-=    */
/*                                              .---:   -@@#.  *@@--@@*       */
/*   By: aperez-b <aperez-b@uoc.edu>                     +@@@@@@@* +@@+       */
/*                                                         :-==:.  -@@#       */
/*   Created: 2022/12/23 16:44:33 by aperez-b                       +@@@%@    */
/*   Updated: 2022/12/23 19:56:31 by aperez-b                                 */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Program */
int	main(int argc, char **argv)
{
	int		n;
	pid_t	pid;

	if (argc != 2)
	{
		fprintf(stderr, "Error 0 Missing arguments\n");
		exit(1);
	}
	n = atoi(argv[1]);
	while (1)
	{
		pid = fork();
		if (pid == -1)
		{
			fprintf(stderr, "Fork failed\n");
			exit(1);
		}
		if (!pid)
		{
			system("date");
			sleep(n);
			exit(0);
		}
		waitpid(pid, NULL, 0);
	}
}
