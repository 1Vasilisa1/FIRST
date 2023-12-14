#include <iostream>
#include <windows.h>
#include <vector>

std::vector<char> ReadRAR4File(const std::string& filename)
{
    HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to open file." << std::endl;
        return {};
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    std::vector<char> buffer(fileSize);

    DWORD bytesRead;
    if (!ReadFile(hFile, buffer.data(), fileSize, &bytesRead, NULL))
    {
        std::cerr << "Failed to read file." << std::endl;
        CloseHandle(hFile);
        return {};
    }

    CloseHandle(hFile);

    return buffer;
}

void PrintBufferContents(const std::vector<char>& buffer)
{
    for (char c : buffer)
    {
        std::cout << c;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout<<"Hello world!!";
    std::string filename = "C:\\Example.rar";
    std::vector<char> rarData = ReadRAR4File(filename);
    PrintBufferContents(rarData);
    return 0;
}
