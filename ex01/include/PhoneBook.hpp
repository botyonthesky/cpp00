/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:17:26 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/22 13:44:12 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void run();
        
    private:
        Contact repertory[8];
        int             total_contact;
        void            type_command(int &index);
        void            add_to_contact(int &index);
        void            check_number(int &index);
        void            print_list(int &index);
        void            search_contact(int &index);
        void            index_selection(int &index);
        int             check_select(int &index);
        void            print_contact(int &select,int &index);
        void            check_index(int &result, int &index);
        void            check_digit(std::string select, int &index);
        void            check_length(std::string select, int &index);
        std::string     resize_string(std::string str);
        std::string     protec_getline(std::string str);
        std::string     padding_left(std::string &str, size_t size, char c);

};

#endif