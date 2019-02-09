// Auther: Elliot Rihan
// Created: 30/11/18
// Last Modified Date: 08/12/18
// Description: C++ program to encrypt a message encrypted with a XOR Cipher
// XOR_Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string messageToEncrypt = "IY1S461 Secure Computer Programming is the greatest module in the whole "
						  "university. I enjoy it so much!";
string customMessagetoEncrypt = "";
string encryptyionKey = "QOIVJOPNKTQZ";
string customEncryptyionKey = "";
string encryptDecryptMessage = "";
string TESTdecryptedMessage = "";
char yesOrNo;

void cinYesOrNo(string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		cout << yNQuestion << "[Y/N] --> ";
		cin >> yesOrNo;
	} while (!cin.fail() && yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	cin.ignore();
}

void saveFile(string encryptedMessage)
{ // saveFile uses ofstream to save decrypted message to .txt
	ofstream decryptedMessage("xor_encrypted.txt");
	decryptedMessage << encryptedMessage;
	decryptedMessage.close();
	cout << "Message has been saved\n";
	cinYesOrNo("Close application? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		cout << "Application will close\n";
		exit(0);
	}	
}

void encryptDecryptXOR(string message, string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	encryptDecryptMessage = "";
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	for (int i = 0; i < messageLength; i++)
	{
		encryptDecryptMessage += message[i] ^  (int(key[i % keyLength]));
	}	
}

int main()
{
	cout << "\t\t\t\t\tXOR Message Encrypter\n\n\n";
	cout << "Original Messsage\n" << messageToEncrypt << "\n";
	cinYesOrNo("Would you like to change the message to Encrypt? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		cout << "Input message to encrypt\n";
		getline(cin, customMessagetoEncrypt);
		messageToEncrypt = customMessagetoEncrypt;
	}
	cout << "\nThis default encryptyion Key: " << encryptyionKey <<"\n";
	cinYesOrNo("Would you like to change the encryptyion Key? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		cout << "Input custom encryptyion Key\n";
		getline(cin, customEncryptyionKey);
		encryptyionKey = customEncryptyionKey;
	}	
	encryptDecryptXOR(messageToEncrypt, encryptyionKey);
	cout << "\n" << encryptDecryptMessage << "\n";
	cinYesOrNo("Would you like to save to .txt file? ");	
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		saveFile(encryptDecryptMessage);
	}
	encryptDecryptXOR(encryptDecryptMessage, encryptyionKey);
	cout << "Decrypted Message\n"<< encryptDecryptMessage;
}
