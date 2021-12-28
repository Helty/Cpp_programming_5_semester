#include "Aes.h"
#include <stdexcept>
#include <codecvt>
#include <boost/algorithm/hex.hpp>
#include <boost/algorithm/string.hpp>
#include "../cryptopp/aes.h"
#include "../cryptopp/default.h"

namespace
{
	ByteArray HexToByteArray(std::wstring const& textHex)
	{
		ByteArray result;
		if (textHex.size() % 2 != 0)
		{
			throw std::invalid_argument("Hex должен быть кратен 2");
		}
		boost::algorithm::unhex(textHex.begin(), textHex.end(), std::back_inserter(result));
		return result;
	}
	ByteArray StringToUtf8ByteArray(std::wstring const& text)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
		std::string wstringUtf8 = convert.to_bytes(text);
		ByteArray byteArray(wstringUtf8.begin(), wstringUtf8.end());
		return byteArray;
	}
	std::wstring ByteArrayToHex(ByteArray const& byteArray)
	{
		std::wstring result;
		boost::algorithm::hex(byteArray.begin(), byteArray.end(), std::back_inserter(result));
		boost::algorithm::to_lower(result);
		return result;
	}

} // namespace

DataBlock Aes::GetUnencryptedData(std::wstring const& text)
{
	ByteArray byteArrayText = StringToUtf8ByteArray(text);
	size_t countNeedCharFullBlock = (Aes::AES_BLOCK_SIZE - (byteArrayText.size() % Aes::AES_BLOCK_SIZE))
		% Aes::AES_BLOCK_SIZE;
	byteArrayText.resize(byteArrayText.size() + countNeedCharFullBlock, 0);

	DataBlock cryptedData = { countNeedCharFullBlock, byteArrayText };

	return cryptedData;
}
DataBlock Aes::GetEncryptedData(std::wstring const& encryptedTextWithPadding)
{
	std::vector<std::wstring> results;
	boost::split(results, encryptedTextWithPadding, [](wchar_t ch) { return ch == ':'; });

	if (results.size() != 2)
	{
		throw std::invalid_argument("Wrong amount of data");
	}

	DataBlock cryptedData = { (size_t)(std::stoi(results[0], nullptr, 10)),
		HexToByteArray(results[1]) };

	return cryptedData;
}

std::wstring Aes::Encrypt(std::wstring const& text)
{
	if (text.empty()) return text;

	DataBlock unencryptedData = GetUnencryptedData(text);

	CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption encryption;
	encryption.SetKeyWithIV(&m_key[0], m_key.size(), &m_initialVector[0], m_initialVector.size());

	std::string encryptedData;
	CryptoPP::StringSource(&unencryptedData.data[0],
		unencryptedData.data.size(), /* pumpAll*/ true,
		new CryptoPP::StreamTransformationFilter(encryption,
			new CryptoPP::StringSink(encryptedData),
			CryptoPP::StreamTransformationFilter::NO_PADDING));

	ByteArray encryptedText(encryptedData.begin(), encryptedData.end());

	return std::to_wstring(unencryptedData.numPaddingBytes) + L":" + ByteArrayToHex(encryptedText);
}
std::wstring Aes::Decrypt(std::wstring const& text)
{
	if (text.empty()) return text;

	DataBlock encryptedData = GetEncryptedData(text);

	CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryption;
	decryption.SetKeyWithIV(&m_key[0], m_key.size(), &m_initialVector[0], m_initialVector.size());

	std::string unencryptedData;
	CryptoPP::StringSource cbcDecryption(&encryptedData.data[0],
		encryptedData.data.size(), /* pumpAll*/ true,
		new CryptoPP::StreamTransformationFilter(decryption,
			new CryptoPP::StringSink(unencryptedData),
			CryptoPP::StreamTransformationFilter::NO_PADDING));

	unencryptedData.resize(unencryptedData.size() - encryptedData.numPaddingBytes);

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.from_bytes(unencryptedData);
}

void Aes::SetKey(std::wstring const& key)
{
	m_key = HexToByteArray(key);
}
std::wstring Aes::GetKey() const
{
	return ByteArrayToHex(m_key);
}
void Aes::SetInitialVector(std::wstring const& initialVector)
{
	m_initialVector = HexToByteArray(initialVector);
}
std::wstring Aes::GetInitialVector() const
{
	return ByteArrayToHex(m_initialVector);
}
