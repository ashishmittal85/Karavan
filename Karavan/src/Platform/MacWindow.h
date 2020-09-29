#ifndef MACWINDOW_H
#define MACWINDOW_H

#include "Window.h"
#include "Renderer/GraphicsContext.h"

#include "Log.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Karavan {

    class MacWindow : public Window
    {
    public:
        MacWindow(const WindowProps& props);
        virtual ~MacWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        inline virtual void* GetNativeWindow() const override { return m_Window; }
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;
        GraphicsContext* m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };

}
#endif