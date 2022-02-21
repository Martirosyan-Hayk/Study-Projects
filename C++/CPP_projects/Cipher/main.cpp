#include<iostream>
#include<string>
#include<fstream>
#include"Cipher.h"

int main()
{
	std::cout << "Hello, you are logged in to an encryption or decryption program." << std::endl;
	std::cout << "Encode or decode text by Caesar algorithm. " << std::endl;


	Cipher cipher;
	std::string exitProgram = "start";

	while (exitProgram != "exit")
	{
		std::cout << "Which you want to do encoding or decoding? " << std::endl;

		std::string encodingOrDecoding;
		std::cin >> encodingOrDecoding;

		if (encodingOrDecoding == "encoding" || encodingOrDecoding == "ENCODING")
		{

			std::string nameOfEncodingFile = "encoding.txt";
			std::fstream file(nameOfEncodingFile, std::fstream::out | std::fstream::app);

			if (!file.is_open())
			{
				std::cout << "ERROR: failed to open." << std::endl;
				exit(0);
			}
			else
			{
				std::string exitOrEnterd = "enterd";
				while (exitOrEnterd != "no")
				{
					std::cout << "Enter the encrypted text." << std::endl;

					std::string encryptedText;
					std::cin.get();
					std::getline(std::cin, encryptedText);
					cipher.encode(encryptedText, nameOfEncodingFile);
					std::cout << "Continue: (yes/ no)" << std::endl;
					std::cin >> exitOrEnterd;
					
				}

				file.close();
			}
		}
		else if (encodingOrDecoding == "decoding" || encodingOrDecoding == "DECODING")
		{
			std::string decodeIs;
			std::cout << "You want to decode from the file? (yes/no)" << std::endl;
			std::cin >> decodeIs;

			if (decodeIs == "yes")
			{
				std::string nameOfDecodingFile = "decoding.txt";
				std::fstream decodingFile(nameOfDecodingFile, std::fstream::out);
				std::string nameOfEncodingFile = "encoding.txt";
				std::fstream file(nameOfEncodingFile, std::fstream::in);

				if (!file.is_open())
				{
					std::cout << "ERROR: failed to open." << std::endl;
					exit(0);
				}
				else
				{
					cipher.decodeFromFile(nameOfDecodingFile, nameOfEncodingFile);

					file.close();
				}
			}
			else if (decodeIs == "no")
			{
				std::string exitOrEnterd = "enterd";
				std::string nameOfDecodingFile = "decoding.txt";
				std::fstream decodingFile(nameOfDecodingFile, std::fstream::out | std::fstream::app);
				std::string nameOfEncodingFile = "encoding.txt";
				std::fstream encodingFile(nameOfEncodingFile, std::fstream::out | std::fstream::app);

				while (exitOrEnterd != "no")
				{
					std::cout << "Enter the encrypted text." << std::endl;

					std::string decryptedText;
					std::cin.get();
					std::getline(std::cin, decryptedText);
					encodingFile << decryptedText << std::endl;
					cipher.decode(decryptedText, nameOfDecodingFile);
					std::cout << "Continue: (yes/ no)" << std::endl;
					std::cin >> exitOrEnterd;

				}
				decodingFile.close();
				encodingFile.close();
			}
			else
			{
				std::cout << "ERROR: wrong command" << std::endl;
				exit(0);
			}
		}
		else
		{
			std::cout << "ERROR: wrong command" << std::endl;
			exit(0);

		}
		std::cout << "Do you can continue encoding or decoding ? (continue/ exit)";
		std::cin.get();
		std::getline(std::cin, exitProgram);
	}
	std::string readingFile = "none";
	std::cout << "Do you want to see the encoding or decoding file. (encoding file/ decoding file/ none)" << std::endl;
	std::getline(std::cin, readingFile);

	while (readingFile == "encoding file" || readingFile == "decoding file")
	{
		if (readingFile == "encoding file")
		{
			std::string nameOfEncodingFile = "encoding.txt";
			cipher.readingEncodingFile(nameOfEncodingFile);
		}
		else if (readingFile == "decoding file")
		{
			std::string nameOfDecodingFile = "decoding.txt";
			cipher.readingDecodingFile(nameOfDecodingFile);
		}
		std::cout << "Do you want to see the encoding or decoding file. (encoding file/ decoding file/ none)" << std::endl;
		std::getline(std::cin, readingFile);
	}



	std::cout << "Thank you goodbye... :)" << std::endl;

}
