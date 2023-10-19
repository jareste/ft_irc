/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:22:00 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:39 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Includes.hpp"

class Client
{
    private:
        bool aut;
        int _fd;
        std::string _username;
        std::string _realname;
        std::string _nick = "";

    public:
        Client();
        ~Client();
        bool operator=(const Client & cl);

        void SendMessage(const std::string &s);



        //getters
        const std::string &getNick() const {return this->_nick;}
        const std::string &getName() const {return this->_username;}
};
