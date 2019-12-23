#pragma once

#include <switch.h>
#include <cstdio>
#include <string>

#include "util.hpp"

#define DEBUG

extern FILE* g_debug_file;

#ifdef DEBUG
// vscode INTELLISENSE doesn't work with __VA_OPT__ apparently
#    ifndef __INTELLISENSE__
#        define LOG(fmt, ...)                                                                       \
            fprintf(g_debug_file, "%s: " fmt "\n", __PRETTY_FUNCTION__ __VA_OPT__(, ) __VA_ARGS__); \
            fflush(g_debug_file);
#    else
#        define LOG(...) ({})
#    endif
#else
#    define LOG(...) ({})
#endif
#define LOG32(v) LOG(STRINGIFY(v) " = %d", v)
#define LOG64(v) LOG(STRINGIFY(v) " = %ld", v)
#define LOG32X(v) LOG(STRINGIFY(v) " = 0x%x", v)
#define LOG64X(v) LOG(STRINGIFY(v) " = 0x%lx", v)

void debugInit();

void debugExit();
