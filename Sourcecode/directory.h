#pragma once
#include <string>
#include <vector>
#include "File.h"

class Directory {
private:
    std::string name;
    std::vector<File> files;
    std::vector<Directory> subDirectories;
public:
    Directory(const std::string& name);
    void addFile(const File& file);
    void addDirectory(const Directory& directory);
    File* getFile(const std::string& name);
    Directory* getDirectory(const std::string& name);
    void deleteFile(const std::string& name);
    void deleteDirectory(const std::string& name);
    std::string getName() const;
};
