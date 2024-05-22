/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:20:42 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/22 12:06:26 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

PhoneBook::PhoneBook()
{
    total_contact = 0;
}

PhoneBook::~PhoneBook()
{
    
}


void    PhoneBook::check_number(int &index)
{
    std::string str;
    str = protec_getline(str);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            std::cout << "The phone number must be only digit !" << std::endl;
            std::cout << "Type the phone number : ";
            check_number(index);
            return ;
        }
    }
    repertory[index].set_phone(str); 
}


void    PhoneBook::add_to_contact(int &index)
{
    std::string phone;
    std::string secret;
    std::string str;
    std::cout << "Enter the information of your new contact" << std::endl;
    if (total_contact >= 8)
        index = total_contact - 8;
    repertory[index].index = index;
    std::cout << "Type the first name : ";
    repertory[index].first_name = protec_getline(repertory[index].first_name);
    std::cout << "Type the last name : ";
    repertory[index].last_name = protec_getline(repertory[index].last_name);
    std::cout << "Type the nickname : ";
    repertory[index].nickname = protec_getline(repertory[index].nickname);
    std::cout << "Type the phone number : ";
    check_number(index);
    std::cout << "Type his darkest secret : ";
    secret = protec_getline(secret);
    repertory[index].set_darkest(secret);
    std::cout << "We have successfully save your informations\n";
    index++;
    total_contact++;
    type_command(index);
}

std::string    PhoneBook::resize_string(std::string str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (padding_left(str, 10, ' '));
}

std::string    PhoneBook::padding_left(std::string &str, size_t size, char c)
{
    if (str.size() == size)
        return (str);
    else
    {
        size_t padding_size;
        padding_size = size - str.size();
        std::string padding;
        padding.resize(padding_size, c);
        std::string new_str;
        new_str = padding + str;
        return (new_str);
    }
}


void    PhoneBook::print_list(int &index)
{
    if (total_contact > index)
        index = 8;
    for(int i = 0; i < index; i++)
    {
        std::cout << "        " << repertory[i].index << "|" << resize_string(repertory[i].first_name)
        << "|" << resize_string(repertory[i].last_name) << "|" << resize_string(repertory[i].nickname) << "|" << std::endl;
    }
}

void    PhoneBook::print_contact(int &select, int &index)
{
    std::cout << "Index #" << repertory[select].index << std::endl;
    std::cout << "First name : " << repertory[select].first_name << std::endl;
    std::cout << "Last name : " << repertory[select].last_name << std::endl;
    std::cout << "Nickname : " << repertory[select].nickname << std::endl;
    std::cout << "Phone number : " << repertory[select].get_phone() << std::endl;
    std::cout << "Darkest secret : " << repertory[select].get_darkest()<< std::endl;
    std::cout << std::endl;
    type_command(index);
}
std::string     PhoneBook::protec_getline(std::string str)
{
    if (!std::getline(std::cin >> std::ws, str))
    {
        std::cerr << "Input error ^D" << std::endl;
        exit (EXIT_FAILURE);
    }
    else
        return (str);
}

int    PhoneBook::check_select(int &index)
{
    std::string select;
    select = protec_getline(select);
    check_length(select, index);
    check_digit(select, index);
    return (select[0] - '0');
}

void    PhoneBook::check_digit(std::string select, int &index)
{
     if (isdigit(select[0]) == false)
    {
        std::cout << "This index is not valid, must be only digit" << std::endl;
        std::cout << "One more time whitch contact do you to see ?" << std::endl;
        std::cout << "Enter the index : ";
        index_selection(index);
    }
}

void    PhoneBook::check_length(std::string select, int &index)
{
    if (select.length() > 1)
    {
        std::cout << "This index is not valid ! Please enter only the index number" << std::endl;
        std::cout << "One more time whitch contact do you to see ?" << std::endl;
        std::cout << "Enter the index : ";
        index_selection(index);
    }
}
void    PhoneBook::check_index(int &result, int &index)
{
    if (result < 0 || result > 7 || result > total_contact - 1)
    {
        std::cout << "This index doesn't match with any index of the list" << std::endl;
        std::cout << "Please try again !" << std::endl;
        std::cout << "One more time whitch contact do you to see ?" << std::endl;
        std::cout << "Enter the index : ";
        index_selection(index);
    }
}

void    PhoneBook::index_selection(int &index)
{
    int result;
    result = check_select(index);
    check_index(result, index);
    print_contact(result, index);
}

void    PhoneBook::search_contact(int &index)
{
    std::cout << "There is the list of contact : " << std::endl;
    print_list(index);
    std::cout << "Witch contact do you want to see ?" << std::endl;
    std::cout << "Entre the index : ";
    index_selection(index);
    type_command(index);
}

void    PhoneBook::type_command(int &index)
{
    std::string buffer;
    std::cout << "What do you want to do ? (ADD, SEARCH or EXIT)" << std::endl;    
    buffer = protec_getline(buffer);
    if (buffer == "ADD")
    {
        if (index == 8)  
            std::cout << "The phonebook is full (8 max), the next add will erase the fisrt contact" << std::endl;
        add_to_contact(index);
    }
    if (buffer == "SEARCH")
        search_contact(index);
    if (buffer == "EXIT")
        exit(EXIT_SUCCESS);
    else
    {
        std::cout << "Wrong command !" << std::endl;
        type_command(index);
    }
}

void    PhoneBook::run()
{
    int index;

    index = 0;
    std::cout << "Welcone to My Awesome PhoneBook" << std::endl;
    type_command(index);
}