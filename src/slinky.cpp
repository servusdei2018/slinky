#include <iostream>
#include <string>

#include "FileHandler/FileHandler.hpp"
#include "AnchorProcessor/AnchorProcessor.hpp"
#include "Navigator/Navigator.hpp"
#include "TextFormatter/TextFormatter.hpp"

const std::string LOGO = 
        "     _ _      _        \n"
        "  __| (_)_ _ | |___  _ \n"
        " (_-< | | ' \\| / / || |\n"
        " /__/_|_|_||_|_\\_\\_, |\n"
        "                  |__/  \n";

void displayLogo() {
    std::cout << LOGO;
}

void displayHelp() {
    std::cout << "Commands:\n";
    std::cout << "  go <n>     - Navigate to the document associated with anchor number n\n";
    std::cout << "  back       - Go back to the previous document\n";
    std::cout << "  help       - Display this help message\n";
    std::cout << "  exit       - Exit the browser\n";
}

int main() {
    std::string currentFile;

    displayLogo();
    std::cout << "Welcome to the Slinky Web Browser!\n";
    displayHelp();
    
    std::cout << "Please enter the initial file to open: ";
    std::getline(std::cin, currentFile);

    std::string content;
    while (currentFile != "exit") {
        std::string command;
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "help") {
            displayHelp();
        } else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
    }

    std::cout << "Exiting the Slinky Web Browser. Goodbye!\n";
    return 0;
}
