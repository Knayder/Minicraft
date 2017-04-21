#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

class TextureManager final {
public:
	~TextureManager();

	TextureManager(const TextureManager &) = delete;
	void operator=(const TextureManager &) = delete;

	
	//Load new texture to container
	static sf::Texture * loadOne(const std::string &file);

	//Load new texture sheet to container
	static void load(const std::string &file, const sf::Vector2u &eachSize, const bool &getRidOfColor = false, const sf::Color &color = {0,0,0});

	static sf::Texture * get(const unsigned int &index);

	static void clear();

	//Decrement value after index 
	static bool remove(const unsigned int &index);

	static sf::Texture * replace(const unsigned int &index, const unsigned int &newIndex);

	static sf::Texture * replace(const unsigned int &index, const std::string &file, const bool &isArea = false, const sf::IntRect &area = {0,0,0,0});

	static bool isEmpty();

	static unsigned int getSize() {
		return TextureManager::getInstance().textureContainer.size();
	}

	//Typedef
	typedef std::vector<sf::Texture *> TextureContainer;

private:
	TextureManager();
	TextureContainer textureContainer;
	static TextureManager &getInstance();
};

#endif TEXTUREMANAGER_H