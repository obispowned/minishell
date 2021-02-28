#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	pid_t	pid;
	char	comando[64];
	printf("Minishell: ");
	memset(comando, '\0', 64);
	scanf("%s", comando);
	while (strcmp(comando, "exit"))
	{
		pid = fork();
		if (pid == 0)
		{
			execlp(comando, comando, NULL);
			printf("comando no valido\n");
			exit(0);
		}
		else
		{
			if (pid > 0)
			{
				waitpid(pid, 0, 0);
				printf("Minishell: ");
				memset(comando, '\0', 64);
				scanf("%s", comando);
			}
			else
				perror("Error Fork\n");
		}
	}
	exit(0);
}
