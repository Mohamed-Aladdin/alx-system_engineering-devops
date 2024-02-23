#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - creates an infinite loop to make the program hang
 *
 * Return: always 0
 */

int inf_while(void)
{
	while (1)
	{
		sleep(1);
	}

	return (0);
}

/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	int i;
	pid_t zombie;

	for (i = 0; i < 5; i++)
	{
		zombie = fork();

		if (!zombie)
			return (0);

		printf("Zombie process created, PID: %d\n", zombie);
	}

	inf_while();
	return (0);
}
