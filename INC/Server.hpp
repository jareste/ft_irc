/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:22:24 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/19 14:59:08 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#pragma once
#include "Includes.hpp"

class Client;
typedef struct cmd
{
    std::vector<std::string> args;
};

class Server
{
    private:
        std::vector<pollfd> _pollsfd;
        std::string _psswd;
        int _port;
        int _active;
        struct pollfd _serverfd;
        std::map<int, Client*> _clients;
        std::vector<Channel *> _channels;

        cmd &_parse(char *str);
        void _runCmd(cmd &c, int fd);
        void _newClient();
        void _request(int i);
        int _searchChannel(const std::string &name);
        void _addClientToChannel(int fd, const std::string &ch_name);
        bool _existsClient(const std::string &nick);
    public:
        Server(int port, const std::string &psswd);
        ~Server();

        
        void LoopServer();
};
