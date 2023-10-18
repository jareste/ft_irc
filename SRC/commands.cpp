/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:33:55 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/19 01:22:50 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to redirect each client to a concrete cmd

static std::string	*splitcmd(std::string static input);//to be done

void	Server::comand(std::string static input, int static client_fd)
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
