#pragma once

#ifdef _WIN32
    // hide dll-interface warnings
    #pragma warning(disable: 4251)
    // Windows requires dll export for entry points
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT
#endif