/*
** EPITECH PROJECT, 2018
** command
** File description:
** my_ftp
*/

#include "server.h"

int pasv_connect(char *data, t_client *client)
{
	write(client->client_fd, "227\n", 30);

	return (0);
}

int retr_download(char *data, t_client *client)
{
	write(client->client_fd, "150\n", 30);
	write(client->client_fd, "226\n", 30);

	return (0);
}

int stor_up(char *data, t_client *client)
{
	write(client->client_fd, "150\n", 30);
	write(client->client_fd, "226\n", 30);

	return (0);
}

int delete_file(char *data, t_client *client)
{
	write(client->client_fd, "250\n", 30);

	return (0);
}

int list_directory(char *data, t_client *client)
{
	write(client->client_fd, "150\n", 30);
	write(client->client_fd, "226\n", 30);

	return (0);
}
