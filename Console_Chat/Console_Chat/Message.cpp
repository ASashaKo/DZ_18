#include "Message.h"
#include <fstream>


Message::Message(std::string login, std::string name,std::string name_recipient, std::string message) : _login(login), _name(name), _name_recipient(name_recipient), _message(message)
{

}
 
Message::Message(std::string login, std::string name, std::string message) : _login(login), _name(name), _message(message)
{

}

Message::Message(std::string name, std::string message) : _name(name), _message(message)
{

}

Message::Message(std::string name) : _name(name)
{

}

Message::Message()
{

}

Message::~Message()
{

}

void Message::setSender(std::string& sender)
{
	_name = sender;
}

std::string Message::getSender()
{
	return _name;
}

void Message::setRecipient(std::string& recipient)
{
	_name_recipient = recipient;
}

std::string Message::getRecipient()
{
	return _name_recipient;
}

std::string Message::inputAndClearStream(std::string& message)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, message);
	return message;
}

void Message::createMessage(std::string name)
{
	setSender(name);
	std::string message;
	inputAndClearStream(message);
	setMessage(message);
	std::cout << "Вы создали сообщение" << std::endl << "Отправитель:  " << getSender() << std::endl << "Текст сообщения: " << getMessage() << std::endl;
    std::ofstream file("Message_list_general.txt", std::ios::app);
    file << "Отправитель: " << getSender() << '\t' << "Текст сообщения: " <<  getMessage() << '\r' << '\n';
    file.close();
}

void Message::showMessage()
{
	std::cout << "Отправитель: " << getSender() << std::endl << "Текст сообщения: " << getMessage() << std::endl;
}

void Message::setMessage(std::string& message)
{
	_message = message;
}

void Message::createMessage_priv(std::string name, std::string name_recipient)
{
	setSender(name);
	setRecipient(name_recipient);
	std::string message;
	inputAndClearStream(message);
	setMessage(message);
	std::cout << "Вы написали сообщение для: " << getRecipient() << std::endl << "Отправитель: " << getSender() << std::endl << "Текст сообщения: " << getMessage() << std::endl;
    std::ofstream file("Message_list_priv.txt", std::ios::app);
    file << "Cообщение для: " << getRecipient() << '\t' << "Отправитель: " << getSender() << '\t' << "Текст сообщения: " << getMessage() << std::endl;
    file.close();
}

void Message::showMessage_priv()
{
	std::cout << "Это сообщения для получателя " << getRecipient() << std::endl << "Отправитель: " << getSender() << std::endl << "Текст сообщения: " << getMessage() << std::endl;
}

std::string Message::getMessage()
{
	return _message;
}
