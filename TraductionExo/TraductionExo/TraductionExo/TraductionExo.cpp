#include <iostream>
#include "Utils.h"
#include "TranslateManager.h"
#include "Languages.h"
#include "StringUtils.h"

int main()
{
	setlocale(LC_ALL, ""); 
	//TranslateManager manager = TranslateManager(); 
	//Language* _frLanguage = manager.AddLanguage("fr");
	//Language* _enLanguage = manager.AddLanguage("en"); 
	//_frLanguage->AddMessageToFile("Hello", "ça va t'y bien ?"); 
	//_enLanguage->AddMessageToFile("Hello", "how are you"); 
	//Utils::Log(manager.GetMessage("fr", "Hello"));
	//Utils::Log(manager.GetMessage("en", "Hello"));
	std::string _str = "Salut comment vas tu ?";
	StringUtils::Replace(_str, " ", "");
	Utils::Log(_str); 
}