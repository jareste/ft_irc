/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:33:55 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/31 12:26:55 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/Server.hpp"

cmd Server::_parse(const char *str, char c)
{
    cmd command;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, c)) {
        command.args.push_back(token);
    }
    return command;
}

static bool is_empty(const std::string& str) {
    return str.empty();
}

void Server::_runCmd(cmd c, int const client_fd)
{
	for (std::vector<std::string>::iterator it = c.args.begin(); it != c.args.end(); )
	{
		if (is_empty(*it))
		    it = c.args.erase(it);
		else
	    ++it;
	}
	if (!_clients[client_fd]->Autenticated() || c.args[0] == "PASS" ||\
	(!_clients[client_fd]->Registered() && c.args[0] != "USER" && c.args[0] != "NICK"))
	{
		if (c.args[0] == "PASS")
			_pass(client_fd, c);
	}
	else
	{
		if (c.args[0] == "JOIN")
		{
			_join(client_fd, c);
		}
		if (c.args[0] == "USER")
		{
			_user(client_fd, c);
		}
		if (c.args[0] == "NICK")
		{
			_nick(client_fd, c);
		}
		if (c.args[0] == "PRIVMSG")
		{
			_privmsg(client_fd, c);
		}
		if (c.args[0] == "INVITE")
		{
			_invite(client_fd, c);
		}
		if (c.args[0] == "TOPIC")
		{
			_topic(client_fd, c);
		}
		if (c.args[0] == "NAMES" && c.args.size() > 1)
		{
			_names(client_fd, c);
		}
		if (c.args[0] == "MODE")
		{
			_mode(client_fd, c);
		}
		if (c.args[0] == "KICK")
		{
			_kick(client_fd, c);
		}
	}
}

std::vector<std::string> Server::_splitByDelimiters(const std::string& input, const std::string& delimiters) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while (start < input.length()) {
        start = input.find_first_not_of(delimiters, end);
        if (start == std::string::npos) {
            break;
        }
        end = input.find_first_of(delimiters, start);
        if (end == std::string::npos) {
            tokens.push_back(input.substr(start));
            break;
        } else {
            tokens.push_back(input.substr(start, end - start));
        }
    }
    return tokens;
}