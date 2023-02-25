#include "flog.h"
#include <inttypes.h>
#include <mutex>
#include <chrono>

#ifndef FLOG_ANDROID_TAG
#define FLOG_ANDROID_TAG    "flog"
#endif

namespace flog {
    std::mutex outMtx;

    const char* TYPE_STR[_TYPE_COUNT] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR"
    };

    void __log__(Type type, const std::string& fmt, const std::vector<std::string>& args) {
        // Get time
        auto now = std::chrono::system_clock::now();
        auto nowt = std::chrono::system_clock::to_time_t(now);

        // TODO: This is not threadsafe
        auto nowc = std::localtime(&nowt);
        
        // Create line header
        char buf[256];
        sprintf(buf, "[%02d/%02d/%02d %02d:%02d:%02d.%03d] [%s]", nowc->tm_mday, nowc->tm_mon + 1, nowc->tm_year + 1900, nowc->tm_hour, nowc->tm_min, nowc->tm_sec, 0/* TODO */, TYPE_STR[type]);

        // Write to output
        {
            std::lock_guard<std::mutex> lck(outMtx);
            printf("%s %s\n", buf, fmt.c_str());
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