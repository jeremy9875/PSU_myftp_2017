/*
** EPITECH PROJECT, 2018
** server
** File description:
** 
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>

typedef struct s_client
{
	char *username;
	char *password;
	bool is_login;
	int socketfd;
	int client_fd;
	char *client_ip;
	pid_t child;
	socklen_t s_in_size;
	char *path;
	struct protoent *pe;
	struct sockaddr_in s_in;
	struct sockaddr_in s_in_client;
} t_client;

typedef int (*func)(char *, t_client *);

typedef struct  command
{
    const char *key;
    func func;
}               command;

int main(int ac, char **av);
int server_init(int port, char *path);
int handle_client(int client_fd, char *client_ip, t_client *client);
int my_strcmp(const char *cmp, const char *str);
void bad_command(t_client *client);
char *take_last_path(char *pwd);
char *take_data(char *data);
char *my_strcpy(char *data);
void is_not_log(t_client *client);
int user_connection(char *data, t_client *client);
int pass_connection(char *data, t_client *client);
int cwd_directory(char *data, t_client *client);
int cdup_directory(char *data, t_client *client);
int quit_ftp(char *data, t_client *client);
int pwd_directory(char *data, t_client *client);
int port_ftp(char *data, t_client *client);
int pasv_connect(char *data, t_client *client);
int retr_download(char *data, t_client *client);
int stor_up(char *data, t_client *client);
int delete_file(char *data, t_client *client);
int list_directory(char *data, t_client *client);
int help_client(char *data, t_client *client);
int noop_client(char *data, t_client *client);

extern const command commands[14];

#endif /* SERVER_H_ */
