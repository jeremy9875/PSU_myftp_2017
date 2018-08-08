/*
** EPITECH PROJECT, 2018
** main
** File description:
** 
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void help(char *str)
{
	printf("USAGE: %s port path\n", str);
	printf("       port is the port number on wich");
	printf(" the server socket listens\n");
	printf("       path is the path to the home");
	printf(" directory for the Anonymous user\n");
}

int main(int ac, char **av)
{
	if (ac >= 3) {
		if (strcmp(av[1], "-help") == 0)
			help(av[0]);
		else
			server_init(atoi(av[1]), av[2]);
	}
	else {
		help(av[0]);
		return 84;
	}
	return 0;
}
