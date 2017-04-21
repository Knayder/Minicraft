
#include "..\headers\TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	std::cout << "TEST: Deleting dynamicly alocated memory in TextureManager singleton class\n";
	for (auto texture : textureContainer)
		delete texture;
}

TextureManager & TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

sf::Texture * TextureManager::loadOne(const std::string &file)
{
	sf::Texture *texture = new sf::Texture;
	if (texture->loadFromFile(file))
		TextureManager::getInstance().textureContainer.push_back(texture);

	else {
		std::cout << "ERROR: Cannot open file:\n" << file << "\n";
		delete texture;
		texture = nullptr;
	}

	return texture;

}

void TextureManager::load(const std::string &file, const sf::Vector2u &eachSize, const bool &getRidOfColor, const sf::Color &color)
{
	sf::Image image;
	if (image.loadFromFile(file)) {
		if (getRidOfColor)
			image.createMaskFromColor(color);
		for (int y = 0; y < image.getSize().y / eachSize.y; y++) {
			for (int x = 0; x < image.getSize().x / eachSize.x; x++) {
				sf::Texture *texture = new sf::Texture;
				texture->loadFromImage(image, { (int)(x*eachSize.x), (int)(y*eachSize.y), (int)(eachSize.x), (int)(eachSize.y) });
				TextureManager::getInstance().textureContainer.push_back(texture);
			}
		}
	}
	else
		std::cout << "ERROR: Cannot open file:\n" << file << "\n";
}

sf::Texture * TextureManager::get(const unsigned int &index)
{
	TextureManager &instance = getInstance();
	if (index < instance.textureContainer.size())
		return instance.textureContainer[index];
	else
		return nullptr;
}

void TextureManager::clear()
{
	TextureManager &instance = getInstance();
	for (auto texture : instance.textureContainer)
		delete texture;

	instance.textureContainer.clear();
}

bool TextureManager::remove(const unsigned int &index)
{
	TextureManager &instance = getInstance();
	sf::Texture *texture = TextureManager::get(index);
	if (texture != nullptr) {
		delete texture;
		instance.textureContainer.erase(instance.textureContainer.begin() + index);
		return true;
	}
	else
		return false;

}

sf::Texture * TextureManager::replace(const unsigned int & index, const unsigned int & newIndex)
{
	sf::Texture *texture = TextureManager::get(index);
	if (texture != nullptr) {
		sf::Texture *newTexture = TextureManager::get(newIndex);
		if (newTexture != nullptr) {
			texture->loadFromImage(newTexture->copyToImage());
		}
	}
	return texture;
}

sf::Texture * TextureManager::replace(const unsigned int &index, const std::string &file, const bool &isArea, const sf::IntRect &area)
{
	sf::Texture *texture = TextureManager::get(index);
	if (texture != nullptr) {
		sf::Image image;
		if (!image.loadFromFile(file))
			std::cout << "ERROR: Cannot open file:\n" << file << "\n";
		else {
			if(isArea)
				texture->loadFromImage(image, area);
			else
				texture->loadFromImage(image);
		}
	}
	return texture;
}

bool TextureManager::isEmpty()
{
	return TextureManager::getInstance().textureContainer.empty();
}

