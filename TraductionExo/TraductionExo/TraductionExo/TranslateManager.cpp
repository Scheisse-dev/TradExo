#include "TranslateManager.h"
#include "Path.h"
#include "Environment.h"
#include <filesystem>
#include "Utils.h"
#include "Directory.h"
#include "Languages.h"

TranslateManager::TranslateManager()
{
	InitLanguages(); 
}

void TranslateManager::InitLanguages()
{
	const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "Language"); 
	if (!Directory::Exist(_path)) return; 
	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_path.c_str()))
	{
		if (entry.is_directory()) continue; 
		std::string _filePath = Path::GetPath(entry.path().string());
		std::string _fileName = _filePath.substr(_filePath.find_last_of('/') + 1);
		_fileName = _fileName.substr(0, _fileName.find_first_of('.')); 
		languages.insert(std::pair(_fileName, new Language(_fileName))); 
	};
}

Language* TranslateManager::GetLanguage(const std::string& _languageName)
{
	if (!languages.contains(_languageName)) return nullptr; 
	return languages[_languageName]; 
}

Language* TranslateManager::AddLanguage(const std::string& _languageName)
{
	if (languages.contains(_languageName)) return languages[_languageName];
	Language* _newLanguage = new Language(_languageName); 
	languages.insert(std::pair(_languageName, _newLanguage));
	return _newLanguage; 
}

std::string TranslateManager::GetMessage(const std::string& _languageName, const std::string& _key)
{
	Language* _language = GetLanguage(_languageName); 
	if (_language == nullptr) return "";
	return _language->GetMessage(_key); 
}
