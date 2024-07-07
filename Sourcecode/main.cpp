#include <iostream>
#include "FileSystem.h"

void printMenu() {
    std::cout << "File System Menu:" << std::endl;
    std::cout << "1. Create File" << std::endl;
    std::cout << "2. Create Directory" << std::endl;
    std::cout << "3. Read File" << std::endl;
    std::cout << "4. Write File" << std::endl;
    std::cout << "5. Delete File" << std::endl;
    std::cout << "6. Delete Directory" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    FileSystem fs;
    int choice;
    std::string path, name, data;
    std::vector<char> content;

    while (true) {
        printMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter path and name: ";
                std::cin >> path >> name;
                fs.createFile(path, name);
                std::cout << "File created successfully!" << std::endl;
                break;
            case 2:
                std::cout << "Enter path and name: ";
                std::cin >> path >> name;
                fs.createDirectory(path, name);
                std::cout << "Directory created successfully!" << std::endl;
                break;
            case 3:
                std::cout << "Enter path: ";
                std::cin >> path;
                {
                    File* file = fs.readFile(path);
                    if (file) {
                        std::vector<char> content = file->read();
                        std::cout << "File content: ";
                        for (char c : content) {
                            std::cout << c;
                        }
                        std::cout << std::endl;
                    } else {
                        std::cout << "File not found!" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Enter path: ";
                std::cin >> path;
                std::cout << "Enter data to write: ";
                std::cin.ignore(); // Ignore leftover newline character from previous input
                std::getline(std::cin, data);
                content.assign(data.begin(), data.end());
                fs.writeFile(path, content);
                std::cout << "File written successfully!" << std::endl;
                break;
            case 5:
                std::cout << "Enter path: ";
                std::cin >> path;
                fs.deleteFile(path);
                std::cout << "File deleted successfully!" << std::endl;
                break;
            case 6:
                std::cout << "Enter path: ";
                std::cin >> path;
                fs.deleteDirectory(path);
                std::cout << "Directory deleted successfully!" << std::endl;
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
