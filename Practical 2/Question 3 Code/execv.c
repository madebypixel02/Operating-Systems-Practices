/* ************************************************************************** */
/*                                                                            */
/*                                           =@@*   +@@+                      */
/*                                           =@@*   +@@+ :*%@@@%*:            */
/*                                           =@@*   =@@+.@@@=--%@@-           */
/*                                           :@@%. .#@@--@@*   +@@* .+%@@@    */
/*   execv.c                                  =%@@@@@@+ =@@*   =@@+.@@@+-=    */
/*                                              .---:   -@@#.  *@@--@@*       */
/*   By: aperez-b <aperez-b@uoc.edu>                     +@@@@@@@* +@@+       */
/*                                                         :-==:.  -@@#       */
/*   Created: 2022/12/23 16:45:34 by aperez-b                       +@@@%@    */
/*   Updated: 2022/12/23 19:20:47 by aperez-b                                 */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	pid_t	pid;
	char	*argv[4] = {"ls", "-l", "/", NULL};

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "Fork failed\n");
		exit(1);
	}
	if (!pid)
	{
		execv("/bin/ls", argv);
	}
	waitpid(pid, NULL, 0);
}
