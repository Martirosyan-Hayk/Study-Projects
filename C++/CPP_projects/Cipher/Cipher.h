#ifndef _CIPHER_
#define _CIPHER_

#include<string>

class Cipher
{
public:
	/* Encoded text whit En (x) = (x + n) algorithm wher n = 3 */
	void encode(std::string&, const std::string&);
	/* Decoded text whit Dn (x) = (x - n) algorithm wher n = 3 */
	void decode(std::string&, const std::string&);
	/* Decoded from file whit Dn (x) = (x - n) algorithm wher n = 3 */
	void decodeFromFile(const std::string&, const std::string&);
	/* Reading encoding file */
	void readingEncodingFile(const std::string&);
	/* Reading decoding file */
	void readingDecodingFile(const std::string&);
};


#endif /* _CIPHER_ */