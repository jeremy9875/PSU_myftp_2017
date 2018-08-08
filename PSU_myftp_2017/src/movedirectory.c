/*
** EPITECH PROJECT, 2018
** movedirectory
** File description:
** my_ftp
*/

#include "server.h"

int cwd_directory(char *data, t_client *client)
{
	if (client->is_login != false) {
		char pwd[4096];
		char *str;

		getcwd(pwd, sizeof(pwd));
		usleep(1);
		data = take_data(data);
		chdir(data);
		getcwd(pwd, sizeof(pwd));
		usleep(1);
		dprintf(client->client_fd, "250 Directory successfully changed.\n");
	}
	else
		is_not_log(client);

	return (0);
}

int cdup_directory(char *data, t_client *client)
{
	if (client->is_login != false) {
		char pwd[4096];
		char *str;

		getcwd(pwd, sizeof(pwd));
		usleep(1);
		str = take_last_path(pwd);
		chdir(str);
		getcwd(pwd, sizeof(pwd));
		usleep(1);
		dprintf(client->client_fd, "250 Directory successfully changed.\n");
	}
	else
		is_not_log(client);

	return (0);
}

int quit_ftp(char *data, t_client *client)
{
	if (client->is_login != false) {
		free(client->username);
		dprintf(client->client_fd, "221 Goodbye\r\n");
		usleep(1);
		shutdown(client->client_fd, 2);
		close(client->client_fd);
		kill(client->child, SIGKILL);
		shutdown(client->socketfd, 2);
		close(client->socketfd);
		exit(0);
	}
	else
		is_not_log(client);

	return (0);
}

int pwd_directory(char *data, t_client *client)
{
	if (client->is_login != false) {
		char  pwd[4096];

		getcwd(pwd, sizeof(pwd));
		dprintf(client->client_fd, "257 \"%s\"\r\n", pwd);
	}
	else
		is_not_log(client);

	return (0);
}

int port_ftp(char *data, t_client *client)
{
	write(client->client_fd, "200 \r\n", 30);

	return (0);
}
