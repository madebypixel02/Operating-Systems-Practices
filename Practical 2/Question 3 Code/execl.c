/* ************************************************************************** */
/*                                                                            */
/*                                           =@@*   +@@+                      */
/*                                           =@@*   +@@+ :*%@@@%*:            */
/*                                           =@@*   =@@+.@@@=--%@@-           */
/*                                           :@@%. .#@@--@@*   +@@* .+%@@@    */
/*   execl.c                                  =%@@@@@@+ =@@*   =@@+.@@@+-=    */
/*                                              .---:   -@@#.  *@@--@@*       */
/*   By: aperez-b <aperez-b@uoc.edu>                     +@@@@@@@* +@@+       */
/*                                                         :-==:.  -@@#       */
/*   Created: 2022/12/23 16:45:24 by aperez-b                       +@@@%@    */
/*   Updated: 2022/12/23 19:11:40 by aperez-b                                 */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "Fork failed\n");
		exit(1);
	}
	if (!pid)
	{
		execl("/bin/ls", "ls", "-l", "/", NULL);
	}
	waitpid(pid, NULL, 0);
}
