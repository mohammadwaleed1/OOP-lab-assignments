#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string input;
    cout << "Enter String = ";
    getline(cin, input);

    cout << "Normal Text:= " << input << endl;

    ofstream outFile("encrypted.txt");
    for (int i = 0; i < input.length(); ++i)
    {
        char encryptedChar = input[i] + (i + 1);
        outFile << encryptedChar;
    }
    outFile.close();
    cout << "Encrypted text inserted in file" << endl;

    ifstream inFile("encrypted.txt");
    string decrypted = "";
    char ch;
    int index = 0;
    while (inFile.get(ch))
    {
        decrypted += (ch - (index + 1));
        index++;
    }
    inFile.close();

    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decrypted << endl;

    return 0;
}
