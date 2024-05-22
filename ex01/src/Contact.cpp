/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:40:08 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/22 13:42:33 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

Contact::Contact()
{
    index = 0;
    // std::cout << "construct" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "destruct" << std::endl;
}

void    Contact::set_fname(std::string &fname)
{
    first_name = fname;
}

void    Contact::set_lname(std::string &lname)
{
    last_name = lname;
}

void    Contact::set_nname(std::string &nname)
{
    nickname = nname;
}
void    Contact::set_phone(std::string &number)
{
    phone_number = number;
}

void    Contact::set_darkest(std::string &secret)
{
    darkest_secret = secret;
}

void    Contact::set_index(int &idx)
{
    index = idx;
}


std::string Contact::get_fname()
{
    return (first_name);
}

std::string Contact::get_lname()
{
    return (last_name);
}
std::string Contact::get_nname()
{
    return (nickname);
}

std::string Contact::get_phone()
{
    return (phone_number);
}

std::string Contact::get_darkest()
{
    return (darkest_secret);
}

int Contact::get_index()
{
    return (index);
}
