#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

class TextureManager final {
public:
	~TextureManager();

	TextureManager(const TextureManager &) = delete;
	void operator=(const TextureManager &) = delete;

	

	static sf::Texture * load(const std::string &file, const std::string &name);

	static sf::Texture * load(const std::string &mainName, const std::string &name, const sf::IntRect &area);

	static sf::Texture * load(const std::string &mainName, const std::string &name, const int &rotate);

	static sf::Texture * get(const std::string &name);

	static bool removeColor(const std::string &name, const sf::Color & color);

	static bool setColor(const std::string &name, const int &value, const sf::Color &color);

	static bool clear();

	static bool remove(const std::string &name);

	static bool isEmpty();

	//Typedef
	typedef std::unordered_map<std::string, sf::Texture *> TextureContainer;

private:
	TextureManager();
	TextureContainer textureContainer;
	static TextureManager &getInstance();
};

#endif TEXTUREMANAGER_H