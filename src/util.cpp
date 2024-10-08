/**
 * @file util.cpp
 * @author Green Alligators
 * @brief
 * @version 0.2
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "util.h"


namespace fs = std::filesystem;
bool isTestMode = false;

/**
 * @brief Get the app path object
 * @fn get the path of the application
 * @return std::filesystem::path The path to the executable
 */
std::filesystem::path getAppPath()
{
    // Buffer to store the path of the executable
    char exePath[MAX_PATH];

    // Get the path to the executable
    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0)
    {
        std::cerr << "Failed to get exe path" << std::endl;
        // TODO deal with error
    }

    // Convert the path to the exe to a filesystem path object
    fs::path exeFsPath(exePath);
    // Get the directory of the exe
    fs::path exeDir = exeFsPath.parent_path();

    return exeDir;
};


/**
 * @brief starts a countdown timer for a specified number of minutes
 *
 * @param minutes
 */
void timer(int minutes)
{
    // TODO: implement function
    std::cout << "length of timer is " << minutes << " minutes.";
}


void pause()
{
    std::string line;
    std::cout << "Press ENTER to continue..." << std::endl;
    if (!isTestMode)
    {
        std::getline(std::cin, line); // Wait for user input in production
    }
    else
    {
        std::cout << "[Simulated ENTER]" << std::endl; // Simulate "ENTER" press in test mode
    }
}

void clearScreen()
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count))
        return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
        return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

bool yesNoPrompt()
{
    std::string input{};

    while (true)
    {

        std::cout << "Press Y/N to continue...\n" << std::endl;
        std::getline(std::cin, input);
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        // std::cout << "Input now: " << input << std::endl;
        if (input == "Y")
        {
            return true;
        }
        else if (input == "N")
        {
            return false;
        }
    }
}


bool isValidDeckFileName(std::string name)
{
    int max_length{20};
    if (name == "")
    {
        std::cout << "Name must not be empty" << std::endl;
        return false;
    }
    if (name.length() > max_length)
    {
        std::cout << "'" << name << "' exceeds maximum length of " << max_length << " characters." << std::endl;
        return false;
    }

    // check to see if ASCII value is outside of alphanumeric range
    for (char c : name)
    {
        if (!(('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || (('a' <= c && c <= 'z'))))
        {
            std::cout << "'" << name << "' contains non-alphanumeric characters" << std::endl;
            return false;
        }
    }
    return true;
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
