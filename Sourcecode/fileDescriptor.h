#pragma once
#include "File.h"

class FileDescriptor {
private:
    File* file;
    int position;
public:
    FileDescriptor(File* file);
    std::vector<char> read(int size);
    void write(const std::vector<char>& data);
    void seek(int position);
};
