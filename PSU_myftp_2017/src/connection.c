/*
** EPITECH PROJECT, 2018
** connection
** File description:
** my_ftp
*/

#include "server.h"

const command commands[14] = {
	{"PASS", pass_connection},
	{"USER", user_connection},
	{"CWD", cwd_directory},
	{"CDUP", cdup_directory},
	{"QUIT", quit_ftp},
	{"PWD", pwd_directory},
	{"PORT", port_ftp},
	{"PASV", pasv_connect},
	{"RETR", retr_download},
	{"STOR", stor_up},
	{"DELE", delete_file},
	{"LIST", list_directory},
	{"HELP", help_client},
	{"NOOP", noop_client},
};

int my_strcmp(const char *cmp, const char *str)
{
int i;

	i = 0;
	while (cmp[i] != ' ' && cmp[i] != '\0'
	       && cmp[i] != '\n' && str[i] != '\n') {
		if (cmp[i] != str[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char *my_strcpy(char *data)
{
	int i;
	int index;
	char *str;

	i = 5;
	index = 0;
	str = malloc(sizeof(char) * (strlen(data) - 5));
	while (data[i] != '\0') {
		str[index] = data[i];
		i++;
		index++;
	}
	str[index] = '\0';

	return (str);
}

int pass_connection(char *data, t_client *client)
{
	if (client->is_login != true) {
		client->password = malloc(sizeof(char) * strlen(data) - 5);
		client->password = my_strcpy(data);
		usleep(5);
		if (client->password = NULL)
			dprintf(client->client_fd, "530 Login incorrect.\n");
		else
			dprintf(client->client_fd, "230 Login successful.\n");
		usleep(3);
		client->is_login = true;
		usleep(2);
	}
	else if (client->is_login == false)
		is_not_log(client);

	return (0);
}

int user_connection(char *data, t_client *client)
{
	if (data != NULL) {
		client->username = malloc(sizeof(char) * strlen(data) - 5);
		client->username = my_strcpy(data);
		usleep(5);
		dprintf(client->client_fd, "331 Please specify the password.\n");
		usleep(2);
	}

	return (0);
}
