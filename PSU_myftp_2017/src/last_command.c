/*
** EPITECH PROJECT, 2018
** last_command
** File description:
** my_ftp
*/

#include "server.h"

int help_client(char *data, t_client *client)
{
	if (client->is_login != false) {
		dprintf(client->client_fd, "214-The following commands are recognized.\n");
		usleep(1);
		dprintf(client->client_fd, "CDUP CWD DELE HELP LIST NOOP ");
		usleep(1);
		dprintf(client->client_fd, "PASS PASV PORT PWD QUIT RETR ");
		usleep(1);
		dprintf(client->client_fd, "STOR USER\n");
		usleep(1);
		dprintf(client->client_fd, "214 Help OK.\n");
	}
	else
		is_not_log(client);

	return (0);
}

int noop_client(char *data, t_client *client)
{
	if (client->is_login != false) {
		dprintf(client->client_fd, "200 NOOP ok.\n");
		sleep(1);
	}
	else
		is_not_log(client);

	return (0);
}

char *take_last_path(char *pwd)
{
	char *str;
	int i;
	int index;

	index = 0;
	i = strlen(pwd);
	while (i >= 0 && pwd[i] != '/')
		i--;
	str = malloc(sizeof(char) * i);
	while (index <= i) {
		str[index] = pwd[index];
		index++;
	}
	str[index] = '\0';

	return (str);
}

char *take_data(char *data)
{
	char *str;
	int i;
	int index;

	index = 0;
	i = 4;
	str = malloc(sizeof(char) * strlen(data));
	while (data[i] != '\0' && data[i] != '\n') {
		str[index] = data[i];
		index++;
		i++;
	}
	str[index] = '\0';

	return (str);
}

void is_not_log(t_client *client)
{
	dprintf(client->client_fd, "530 Please login with USER and PASS.\n");
	usleep(3);
}
