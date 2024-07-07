#include "Directory.h"
#include <algorithm>

Directory::Directory(const std::string& name) : name(name) {}

void Directory::addFile(const File& file) {
    files.push_back(file);
}

void Directory::addDirectory(const Directory& directory) {
    subDirectories.push_back(directory);
}

File* Directory::getFile(const std::string& name) {
    for (auto& file : files) {
        if (file.getName() == name) {
            return &file;
        }
    }
    return nullptr;
}

Directory* Directory::getDirectory(const std::string& name) {
    for (auto& dir : subDirectories) {
        if (dir.getName() == name) {
            return &dir;
        }
    }
    return nullptr;
}

void Directory::deleteFile(const std::string& name) {
    files.erase(std::remove_if(files.begin(), files.end(), [&name](File& file) {
        return file.getName() == name;
    }), files.end());
}

void Directory::deleteDirectory(const std::string& name) {
    subDirectories.erase(std::remove_if(subDirectories.begin(), subDirectories.end(), [&name](Directory& dir) {
        return dir.getName() == name;
    }), subDirectories.end());
}

std::string Directory::getName() const { // Add this function
    return name;
}
