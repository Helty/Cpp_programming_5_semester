#define BOOST_TEST_MODULE "AESChipherTest"
#include <boost/test/included/unit_test.hpp>
#include "../LabWork_9/Aes.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <io.h>
#include <fcntl.h>

BOOST_AUTO_TEST_SUITE(AESTest)

BOOST_AUTO_TEST_CASE(TestAES)
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	std::wstring alphabet = L"абвгдеёжзопрстАБВГДЕЁЖЗОПРСТabcdefghABCDEFGH复写复制临摹描摹";

	Aes aes;

	std::wstring firstTestKey = L"7c0c22b3f0a129c571b6867bd49f31a0";
	std::wstring firstTestInitialVector = L"6d253bee5f53edb14b5d93e566f36f13";

	aes.SetKey(firstTestKey);
	aes.SetInitialVector(firstTestInitialVector);

	BOOST_CHECK(aes.GetKey() == firstTestKey);
	BOOST_CHECK(aes.GetInitialVector() == firstTestInitialVector);

	std::wcout << "KEY: " << aes.GetKey() << std::endl;
	std::wcout << "INITIAL VECTOR: " << aes.GetInitialVector() << std::endl << std::endl;

	std::wstring text;
	for (size_t i = 1; i <= alphabet.length(); i++)
	{
		text = alphabet.substr(0, i);

		BOOST_CHECK(text == aes.Decrypt(aes.Encrypt(text)));
		BOOST_CHECK(text == aes.Decrypt(aes.Encrypt(text)));

		std::wcout << "TEXT: " << text << std::endl;
		std::wcout << "ENCRYPT TEXT: " << aes.Encrypt(text) << std::endl << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()
