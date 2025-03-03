#include <string>
#include <vector>
#include "File.h"

File::File(const std::string& name) : name(name), size(0) {}

int File::getSize() const {
    return size;
}

std::vector<char> File::read() const {
    return content;
}

void File::write(const std::vector<char>& data) {
    content = data;
    size = data.size();
}

void File::deleteContent() {
    content.clear();
    size = 0;
}

std::string File::getName() const {
    return name;
}






