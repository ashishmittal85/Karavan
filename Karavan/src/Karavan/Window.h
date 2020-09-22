#ifndef WINDOW_H
#define WINDOW_H

#include "Core.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

namespace Karavan {
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Karavan Engine",
                    unsigned int width = 1920,
                    unsigned int height = 1080)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class KARAVAN_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}
#endif