#ifndef _SEKAI_ENGINE_BASE_TYPE_H_
#define _SEKAI_ENGINE_BASE_TYPE_H_

#if defined(_WIN32)
    #if defined(BUILD_LIBTYPE_SHARED)
        #if defined(__TINYC__)
            #define __declspec(x) __attribute__((x))
        #endif
        #define EXTENDAPI __declspec(dllexport)     // We are building the library as a Win32 shared library (.dll)
    #elif defined(USE_LIBTYPE_SHARED)
        #define EXTENDAPI __declspec(dllimport)     // We are using the library as a Win32 shared library (.dll)
    #endif
#endif

#ifndef EXTENDAPI
    #define EXTENDAPI       // Functions defined as 'extern' by default (implicit specifiers)
#endif

#if UINT_MAX == 65535
typedef char16_t EngineChar_t;
#define ENGINE_TEXT(TEXT) u ## TEXT

#else
typedef char32_t EngineChar_t;
#define ENGINE_TEXT(TEXT) U ## TEXT
#endif

#endif //!_SEKAI_ENGINE_BASE_TYPE_H_