
#include "..\headers\TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	for (auto texture : textureContainer)
		delete (texture.second);
}

TextureManager & TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

sf::Texture * TextureManager::load(const std::string & file, const std::string & name)
{
	sf::Texture *texture = TextureManager::get(name);

	if (texture)
		texture->loadFromFile(file);
	else {
		texture = new sf::Texture;
		texture->loadFromFile(file);
		getInstance().textureContainer.emplace(name, texture);
	}

	return texture;

}

sf::Texture * TextureManager::get(const std::string & name)
{
	TextureManager &instance = getInstance();
	auto result = instance.textureContainer.find(name);
	if (result == instance.textureContainer.end())
		return nullptr;
	else
		return result->second;
}

bool TextureManager::clear()
{
	TextureManager &instance = getInstance();
	bool result = false;
	for (auto texture : instance.textureContainer) {
		delete (texture.second);
		result = true;
	}
	instance.textureContainer.clear();
	return result;
}

bool TextureManager::remove(const std::string & name)
{
	TextureManager &instance = getInstance();
	auto result = instance.textureContainer.find(name);
	if (result == instance.textureContainer.end())
		return false;
	else {
		delete (result->second);
		instance.textureContainer.erase(result);
		return true;
	}
}

bool TextureManager::isEmpty()
{
	auto & instance = getInstance();
	return instance.textureContainer.empty();
}