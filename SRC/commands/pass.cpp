/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:38:15 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/31 12:25:01 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/Includes.hpp"

void	Server::_pass(int const client_fd, cmd &info)
{
	Client		*client = _clients[client_fd]; 

	if (info.args.size() < 2)
	{
		client->sendMessage(ERR_NEEDMOREPARAMS(client->getNick(), info.args[0]));
		return ;
	}
	if (client->Autenticated() == true)
	{
		client->sendMessage(ERR_ALREADYREGISTERED(client->getNick()));
		return ;
	}
	if (info.args[1] != _psswd)
	{
		client->sendMessage(ERR_PASSWDMISMATCH(client->getNick()));
		client->sendMessage("ERROR :Password missmatch");
		_rmClient(*client);

		return ;
	}
	client->setPwd();
}

