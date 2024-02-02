#include <iostream>
//#include <windows.h>
//#include <conio.h>
#include "Chat.h"
#include <fstream>
#include <iterator>
#include <sstream>

int actions(Chat* chat, bool* user_exist, User *user,User &user1)
{
    if((chat->_userList.empty()))
    {
        std::ifstream file ("UserList.txt");
        std::string line;
        while (std::getline(file, line)){
            std::stringstream sline(line);
            std::istream_iterator<std::string> begin(sline);
            std::istream_iterator<std::string>end;
            std::vector<std::string>vline(begin,end);
            if(!vline.empty()){
            user->setName(vline[0]);
            user->setLogin(vline[1]);
            user->setPassword(vline[2]);
            chat->addUserToList(user1);}
        }
    }

    if (*user_exist == false)
    {
        std::cout << "\nВведите код команды : \n1 - Регистрация \n2 - Логин \n10 - Выход" << std::endl;
        int choice;
        std::cin >> choice;
        //choice = _getch();
        switch (choice)
        {
        case 1:
        {
            std::cout << "\nРегистрация нового пользователя" << std::endl;
            chat->regUser(user_exist);
            break;
        }
        case 2:
        {
            std::cout << "\nАвторизация" << std::endl;
            chat->logInUser(user_exist);
            break;
        }
        case 10:
        {
            std::cout << "\nЗакрытие чата...\nДо свидания!" << std::endl;
            exit(0);
        }
        default:
            std::cout << "\nПожалуйста, введите верный номер команды" << std::endl;
        }
    } else 
    {
        std::cout << "\nВведите код команды : \n1 - Логаут \n2 - Отправить личное сообщение \n3 - Общий чат \n4 - Список пользователей \n5 - Просмотр личных сообщений \n6 - Просмотр общего чата \n10 - Выход" << std::endl;
        int choice;
        //choice = _getch();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "\nЛогаут" << std::endl;
            chat->logOutUser(user_exist);
            break;
        }
        case 2:
        {
            std::cout << "\nОтправка личного сообщения" << std::endl;
            chat->privateChat();
            break;
        }
        case 3:
        {
            std::cout << "\nОбщий чат" << std::endl;
            chat->generalChat();
            break;
        }
        case 4:
        {
            chat->showUserList();
            break;
        }
        case 5:
        {
            std::cout << "Просмотр личных сообщений" << std::endl;
            chat->receive_priv_Message();
            break;
        }
        case 6:
        {
            std::cout << "Просмотр общего чата" << std::endl;
            chat->recive_Message();
            break;
        }
        case 10:
        {
            std::cout << "\nЗакрытие чата...\nДо свидания!" << std::endl;
            exit(0);
        }
        default:
            std::cout << "\nПожалуйста, введите верный номер команды" << std::endl;
    }
    }

    actions(chat, user_exist,user,user1);
}

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    Chat chat;
    User user;
    bool user_exist{ false };
    actions(&chat, &user_exist,&user,user);
    return 0;
}


