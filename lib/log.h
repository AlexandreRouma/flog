#pragma once
#include <vector>
#include <string>
#include <stdint.h>

namespace rlog {
    enum Type {
        TYPE_DEBUG,
        TYPE_INFO,
        TYPE_WARNING,
        TYPE_ERROR
    };

    // IO functions
    void __log__(Type type, const std::string& fmt, const std::vector<std::string>& args);

    // Bools
    std::string __toString__(bool value);

    // Char
    std::string __toString__(char value);

    // Ints
    std::string __toString__(int8_t value);
    std::string __toString__(uint8_t value);
    std::string __toString__(int16_t value);
    std::string __toString__(uint16_t value);
    std::string __toString__(int32_t value);
    std::string __toString__(uint32_t value);
    std::string __toString__(int64_t value);
    std::string __toString__(uint64_t value);

    // Floats
    std::string __toString__(float value);
    std::string __toString__(double value);

    // Pointers
    std::string __toString__(const char* value);
    std::string __toString__(const void* value);

    // Classes
    template <class T>
    std::string __toString__(const T& value) {
        return (std::string)value;
    }

    // Utility to generate a list from arguments
    inline void __genArgList__(std::vector<std::string>& args) {}
    template <typename First, typename... Others>
    inline void __genArgList__(std::vector<std::string>& args, First first, Others... others) {
        // Add argument
        args.push_back(__toString__(first));

        // Recursive call that will be unrolled since the function is inline
        __genArgList__(args, others...);
    }

    // Logging functions
    template <typename... Args>
    void log(Type type, const std::string& fmt, Args... args) {
        std::vector<std::string> _args;
        __genArgList__(_args, args...);
        __log__(type, fmt, _args);
    }

    template <typename... Args>
    inline void debug(const std::string& fmt, Args... args) {
        log(TYPE_DEBUG, fmt, args...);
    }

    template <typename... Args>
    inline void info(const std::string& fmt, Args... args) {
        log(TYPE_INFO, fmt, args...);
    }

    template <typename... Args>
    inline void warn(const std::string& fmt, Args... args) {
        log(TYPE_WARNING, fmt, args...);
    }

    template <typename... Args>
    inline void error(const std::string& fmt, Args... args) {
        log(TYPE_ERROR, fmt, args...);
    }
}