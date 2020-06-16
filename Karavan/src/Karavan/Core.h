#ifdef KV_PLATFORM_WINDOWS
    #ifdef KV_BUILD_DLL
         #define KARAVAN_API __declspec(dllexport)
    #else
         #define KARAVAN_API __declspec(dllimport)
    #endif
#else
    #define KARAVAN_API
#endif
    