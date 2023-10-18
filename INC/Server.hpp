/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:22:24 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/17 23:21:34 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Includes.hpp"

class Server
{
    private:
        struct pollfd *_pollsfd;
        std::string psswd;
        int port;
        int _active;
        int _serverfd;
        
        void _NewClient();
        void _Request(int i);
    public:
        Server(int port, std::string psswd);
        ~Server();


        void LoopServer();
}