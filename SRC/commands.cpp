/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:33:55 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/19 16:11:55 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to redirect each client to a concrete cmd

#include "../INC/Server.hpp"

cmd &Server::_parse(char *str)
{
    cmd command;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        command.args.push_back(token);
    }
}

void Server::_runCmd(cmd &c, int fd)
{
	//split input 

	//array de strings amb els noms de les comandes per comparar amb l'input:
	std::string cmds[] = {"INVITE", "JOIN", "USER", "NICK", "PASS", "MODE", "KICK", "TOPIC", ""}
	//array de funcions a executar:
	void	(*execmd[])(int static client_fd, cmd_s info) = {&Server::invite, &Server::join, &Server::user}
	
	int i;//definicio fora de l'if per veure si trobem coincidencia o no dins el for.
	for (i = 0; i < 10;i++)//10 is a placeholder
		if (split input[1] == cmds[i])
		{
			execmd[i](client_fd, info);
			return ;
		}
	if (i == 10)//10 is a placeholder
		// NO COMMAND FOUND; //not sure if we have to throw an exception or?
}