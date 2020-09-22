#ifndef MACINPUT_H
#define MACINPUT_H
#include "KVPCH.h"
#include "Karavan/Input.h"

namespace Karavan {
    class MacInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}
#endif