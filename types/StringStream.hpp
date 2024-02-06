#pragma once

#include <utils/generics.hpp>
#include <vector>
#include <cstring>
#include <memory>


struct StringStream {
    template<typename... StringType>
    StringStream(StringType&&... strings) {
        using namespace generics;
        auto pack = depack_parameters<const char*>(((const char*)strings)...);

        for (size_t i = 0; i < pack.elements(); ++i) {
            size_t size = strlen(pack[i]) + 1;
            auto cloned = new char[size];
            
            memcpy(cloned, pack[i], size);
            cloned[size - 1] = '\0';

            _Strings.push_back(cloned);
            totalStringsSize += size - 1;
        }
    }

    StringStream(StringStream const&)            = delete;
    StringStream& operator=(StringStream const&) = delete;

    std::shared_ptr<char> Join(const char* separator) const;

    ~StringStream();

private:
    std::vector<char*> _Strings;
    size_t totalStringsSize { 0 };
};