#include <memory>

#ifdef KV_PLATFORM_WINDOWS
    #ifdef KV_BUILD_DLL
         #define KARAVAN_API __declspec(dllexport)
    #else
         #define KARAVAN_API __declspec(dllimport)
    #endif
#else
    #define KARAVAN_API
#endif
    
	
#define BIT(x) (1 << x)

#define KV_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 

namespace Karavan {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

}