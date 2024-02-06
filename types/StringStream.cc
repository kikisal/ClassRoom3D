#include "StringStream.hpp"
#include <stdlib.h>

// Creates new string that is the concat of all the StringStream string elements
// Separated by separator
std::shared_ptr<char> StringStream::Join(const char* separator) const {
    if (!separator || _Strings.size() < 1)
        return nullptr;

    size_t sep_len = strlen(separator);
    if (sep_len < 1)
        return nullptr;

    size_t outputBuffSize = totalStringsSize + strlen(separator) * (_Strings.size() - 1);

    // allocate it all at once
    char* buff     = (char*) malloc(outputBuffSize + 1);
    auto curr_buff = buff;

    if (!buff)
        return nullptr; // Buy more ram

    for (auto const& str : _Strings) {        
        size_t src_len = strlen(str);

        memcpy(buff, str, src_len);
        memcpy(buff + src_len, separator, sep_len);

        // src_len + sep_len -> bytes written
        buff    += src_len + sep_len;
    }
 
    buff = curr_buff;
    buff[outputBuffSize] = '\0';

    return std::shared_ptr<char>(buff);
}

StringStream::~StringStream() {
    for (auto str : _Strings)
        delete str;
}