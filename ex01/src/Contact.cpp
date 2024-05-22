/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:40:08 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/17 12:25:29 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

Contact::Contact()
{
    // std::cout << "construct" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "destruct" << std::endl;
}
void    Contact::set_phone(std::string& number)
{
    phone_number = number;
}

void    Contact::set_darkest(std::string &secret)
{
    darkest_secret = secret;
}

std::string Contact::get_phone()
{
    return (phone_number);
}

std::string Contact::get_darkest()
{
    return (darkest_secret);
}
