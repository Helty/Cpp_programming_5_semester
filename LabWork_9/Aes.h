#pragma once
#include <vector>
#include <string>

using ByteArray = std::vector<unsigned char>;

struct DataBlock
{
	size_t numPaddingBytes;
	ByteArray data;
};

class Aes
{
public:
	enum
	{
		AES_BLOCK_SIZE = 16
	};

	std::wstring Encrypt(std::wstring const& text);
	std::wstring Decrypt(std::wstring const& encrytedText);

	void SetKey(std::wstring const& key);
	void SetInitialVector(std::wstring const& initialVector);

	std::wstring GetKey() const;
	std::wstring GetInitialVector() const;


private:

	ByteArray m_key;
	ByteArray m_initialVector;
	DataBlock GetUnencryptedData(std::wstring const& text);
	DataBlock GetEncryptedData(std::wstring const& text);
};


