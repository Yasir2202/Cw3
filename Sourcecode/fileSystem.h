#pragma once
#include <string>
#include <vector>
#include "Directory.h"

class FileSystem {
private:
    Directory root;
    Directory* getDirectoryFromPath(const std::string& path);
    File* getFileFromPath(const std::string& path);
public:
    FileSystem();
    Directory* getRoot();
    File* createFile(const std::string& path, const std::string& name);
    Directory* createDirectory(const std::string& path, const std::string& name);
    File* readFile(const std::string& path);
    void writeFile(const std::string& path, const std::vector<char>& data);
    void deleteFile(const std::string& path);
    void deleteDirectory(const std::string& path);
};
