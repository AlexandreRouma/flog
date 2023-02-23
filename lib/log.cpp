#include "log.h"
#include <inttypes.h>

#ifndef FLOG_ANDROID_TAG
#define FLOG_ANDROID_TAG    "flog"
#endif

namespace flog {
    void __log__(Type type, const std::string& fmt, const std::vector<std::string>& args) {
        printf("%d '%s'\n", type, fmt.c_str());
        for (const auto& a : args) {
            printf("-> '%s'\n", a.c_str());
        }

        
    }

    std::string __toString__(bool value) {
        return value ? "true" : "false";
    }

    std::string __toString__(char value) {
        return std::string("")+value;
    }

    std::string __toString__(int8_t value) {
        char buf[8];
        sprintf(buf, "%" PRId8, value);
        return buf;
    }

    std::string __toString__(uint8_t value) {
        char buf[8];
        sprintf(buf, "%" PRIu8, value);
        return buf;
    }

    std::string __toString__(int16_t value) {
        char buf[16];
        sprintf(buf, "%" PRId16, value);
        return buf;
    }

    std::string __toString__(uint16_t value) {
        char buf[16];
        sprintf(buf, "%" PRIu16, value);
        return buf;
    }

    std::string __toString__(int32_t value) {
        char buf[32];
        sprintf(buf, "%" PRId32, value);
        return buf;
    }

    std::string __toString__(uint32_t value) {
        char buf[32];
        sprintf(buf, "%" PRIu32, value);
        return buf;
    }

    std::string __toString__(int64_t value) {
        char buf[64];
        sprintf(buf, "%" PRId64, value);
        return buf;
    }

    std::string __toString__(uint64_t value) {
        char buf[64];
        sprintf(buf, "%" PRIu64, value);
        return buf;
    }

    std::string __toString__(float value) {
        char buf[256];
        sprintf(buf, "%f", value);
        return buf;
    }

    std::string __toString__(double value) {
        char buf[256];
        sprintf(buf, "%lf", value);
        return buf;
    }

    std::string __toString__(const char* value) {
        return value;
    }

    std::string __toString__(const void* value) {
        char buf[32];
        sprintf(buf, "0x%p", value);
        return buf;
    }

}