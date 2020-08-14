#ifndef IMGUILAYER_H
#define IMGUILAYER_H
#include "../Layer.h"

namespace Karavan {
    class KARAVAN_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        float m_Time = 0.0f;
    };
};
#endif