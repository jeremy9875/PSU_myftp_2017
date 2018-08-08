/*
** EPITECH PROJECT, 2018
** server
** File description:
** my_ftp
*/

#include "server.h"

void bad_command(t_client *client)
{
	dprintf(client->client_fd, "500 Unknown command.\n");
	usleep(2);
}

int handle_client(int client_fd, char *client_ip, t_client *client)
{
	static const char const *str = "220 (vsFTPd 3.0.0)\n";
	FILE *fp;
	char *buf;
	int i;
	func func;

	fp = fdopen(client_fd, "r+");
	write(client_fd, str, strlen(str));
	buf = malloc(sizeof(char) * 1000);
	chdir(client->path);
	while (1) {
		i = 0;
		if ((fgets(buf, 1000, fp)) == NULL)
			return (84);
		while (i != 14) {
			if (my_strcmp(buf, commands[i].key) == 0) {
				func = commands[i].func;
				if (func != NULL)
					func(buf, client);
			}
			i++;
		}
	}

	return (0);
}

int create_child(t_client client, int port)
{	
	client.socketfd = socket(AF_INET, SOCK_STREAM, client.pe->p_proto);
	//if (client.socketfd == -1)
	//	return 84;
	client.s_in.sin_family = AF_INET;
	client.s_in.sin_port = htons(port);
	client.s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(client.socketfd, (const struct sockaddr *)&client.s_in, sizeof(client.s_in)) == -1)
		return (84);
	if (listen(client.socketfd, 15) < 0)
		return (84);
	while (1) {
		if (((client.client_fd = accept(client.socketfd,
						(struct sockaddr *)&client.s_in_client,
						&client.s_in_size)) >= 0)) {
			client.child = fork();
			if (client.child == 0)
			{
				client.client_ip = inet_ntoa(client.s_in_client.sin_addr);
				printf("voici l'ip : %s\n", client.client_ip);
				handle_client(client.client_fd, client.client_ip, &client);
			}
		}
	}
	return (0);
}

int server_init(int port, char *path)
{
	t_client client;

	client.s_in_size = sizeof(client.s_in_client);
	client.pe = getprotobyname("TCP");
	client.path = path;
	if (!client.pe)
		return 84;
	create_child(client, port);

	close(client.client_fd);
	close(client.socketfd); //check return value
	
	return (0);
}
