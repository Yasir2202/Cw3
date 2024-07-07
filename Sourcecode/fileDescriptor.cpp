#include "FileDescriptor.h"

FileDescriptor::FileDescriptor(File* file) : file(file), position(0) {}

std::vector<char> FileDescriptor::read(int size) {
    std::vector<char> data;
    if (file) {
        auto content = file->read();
        for (int i = 0; i < size && static_cast<size_t>(position) < content.size(); ++i) {
            data.push_back(content[position++]);
        }
    }
    return data;
}

void FileDescriptor::write(const std::vector<char>& data) {
    if (file) {
        auto content = file->read();
        for (size_t i = 0; i < data.size(); ++i) {
            if (static_cast<size_t>(position) < content.size()) {
                content[position++] = data[i];
            } else {
                content.push_back(data[i]);
                position++;
            }
        }
        file->write(content);
    }
}

void FileDescriptor::seek(int position) {
    if (file && static_cast<size_t>(position) < file->getSize()) {
        this->position = position;
    }
}
