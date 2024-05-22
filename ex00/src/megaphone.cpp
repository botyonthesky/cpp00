/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:08:14 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/16 09:12:56 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/megaphone.hpp"

void    upper_lower(char c)
{
    char a;
    if (isupper(c))
        std::cout << c;
    else
        std::cout << (a = toupper(c));
}

void    check_letter(char *av)
{
    for (int i = 0; av[i]; i++)
    {
        if (isalpha(av[i]) > 0)
            upper_lower(av[i]);
        else
            std::cout << av[i];
    }
}

void    megaphone(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        check_letter(av[i]);
    std::cout << std::endl;
}

int main(int argc, char **argv)
{   
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        megaphone(argc, argv);
    return (0);
}