#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AnchorProcessor/AnchorProcessor.hpp"
#include "FileHandler/FileHandler.hpp"
#include "Navigator/Navigator.hpp"
#include "TextFormatter/TextFormatter.hpp"

const std::string LOGO =
    "     _ _      _        \n"
    "  __| (_)_ _ | |___  _ \n"
    " (_-< | | ' \\| / / || |\n"
    " /__/_|_|_||_|_\\_\\_, |\n"
    "                  |__/  \n";

void displayLogo() { std::cout << LOGO; }

void displayHelp() {
  std::cout << "Commands:\n";
  std::cout << "  go <n>     - Navigate to the document associated with anchor "
               "number n\n";
  std::cout << "  back       - Go back to the previous document\n";
  std::cout << "  help       - Display this help message\n";
  std::cout << "  exit       - Exit the browser\n";
}

int main() {
  std::string currentFile;
  Navigator navigator;
  FileHandler fileHandler;
  AnchorProcessor anchorProcessor;

  displayLogo();
  std::cout << "Welcome to the Slinky Web Browser!\n";
  displayHelp();

  std::cout << "Display width (default 80):  ";
  std::string widths;
  std::getline(std::cin, widths);
  const int width{std::atoi(widths.c_str()) > 0 ? std::atoi(widths.c_str())
                                                : 80};

  std::cout << width << std::endl;  // widths is still unused

  std::cout << "Please enter the initial file to open: ";
  std::getline(std::cin, currentFile);
  navigator.addToHistory(currentFile);

  std::string content;
  while (currentFile != "exit") {
    // Load content from the current file
    content = fileHandler.loadFile(currentFile);
    if (content.empty()) {
      std::cout << "Error loading file: " << currentFile << "\n";
      break;
    }

    // Parse anchors
    std::vector<std::string> anchors = anchorProcessor.processAnchors(content);

    std::cout << content << '\n';

    std::string command;
    std::cout << "> ";
    std::getline(std::cin, command);

    if (command == "exit") {
      break;
    } else if (command == "back") {
      currentFile = navigator.goBack();
    } else if (command == "help") {
      displayHelp();
    } else {
      std::cout << "Unknown command. Type 'help' for a list of commands.\n";
    }
  }

  std::cout << "Exiting the Slinky Web Browser. Goodbye!\n";
  return 0;
}
