#include"Cipher.h"
#include<string>
#include<fstream>
#include<iostream>


/* Encoded text whit En (x) = (x + n) algorithm wher n = 3 */
void Cipher::encode(std::string& text, const std::string& nameOfFile)
{
	std::fstream file(nameOfFile, std::fstream::out | std::fstream::app);
	for (size_t i = 0; i < text.length(); ++i)
	{
		if (text[i] == '\n')
		{

		}
		else
		{
			text[i] += 3;
		}
	}
	file << text << std::endl;
	file.close();

}
/* Decoded text whit Dn (x) = (x - n) algorithm wher n = 3 */
void Cipher::decode(std::string& decryptedText, const std::string& nameOfDecodingFile)
{
	std::fstream decodingFile(nameOfDecodingFile, std::fstream::out | std::fstream::app);
	for (size_t i = 0; i < decryptedText.length(); ++i)
	{
		if (decryptedText[i] == '\n')
		{

		}
		else
		{
			decryptedText[i] -= 3;
		}
	}
	std::cout << decryptedText << std::endl;
	decodingFile << decryptedText << std::endl;
	decodingFile.close();
}
/* Decoded text whit Dn (x) = (x - n) algorithm wher n = 3 */
void Cipher::decodeFromFile(const std::string& nameOfDecodingFile, const std::string& nameOfEncodingFile)
{
	std::fstream encodingFile(nameOfEncodingFile, std::fstream::in | std::fstream::app);
	std::fstream decodingFile(nameOfDecodingFile, std::fstream::out | std::fstream::app);
	std::string text;
	while (!encodingFile.eof())
	{
		std::getline(encodingFile, text);
		for (size_t i = 0; i < text.length(); ++i)
		{
			if (text[i] == '\n')
			{

			}
			else
			{
				text[i] -= 3;
			}
		}
		decodingFile << text << std::endl;
		std::cout << text << std::endl;
	} 
	
	encodingFile.close();
}
/* Reading encoding file */
void Cipher::readingEncodingFile(const std::string& nameOfEncodingFile)
{
	std::fstream encodingFile(nameOfEncodingFile, std::fstream::in);
	std::string text;
	while (!encodingFile.eof())
	{
		std::getline(encodingFile, text);
		std::cout << text << std::endl;
	}
	encodingFile.close();
	
}
/* Reading decoding file */
void Cipher::readingDecodingFile(const std::string& nameOfDecodingFile)
{
	std::fstream decodingFile(nameOfDecodingFile, std::fstream::in);
	std::string text;
	while (!decodingFile.eof())
	{
		std::getline(decodingFile, text);
		std::cout << text << std::endl;
	}
	decodingFile.close();
}