#pragma once
#include <string>
#include <map>
#include "FileStream.h"

class FileStream; 

class Language
{
#pragma region f/p
private: 

	std::string languageName = ""; 
	std::string filePath = " "; 
	FileStream* stream = nullptr; 
	std::map < std::string, std::string> allMessage = std::map < std::string, std::string>(); 

#pragma endregion f/p

public: 
	Language() = default;
	Language(const std::string& _languageName);
	~Language();

	void InitMessage(); 
	std::string GetMessage(const std::string& _key) const;
	void AddMessageToFile(const std::string& _key, const std::string& _message);
	std::string LanguageName() const;
	std::string FilePath() const;

};

