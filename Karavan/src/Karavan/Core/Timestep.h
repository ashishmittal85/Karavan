#ifndef TIMESTEP_H
#define TIMESTEP_H

namespace Karavan {
    class Timestep {
    public:
        Timestep(float time = 0.0f)
            : m_Time(time)
        {
        
        }
        operator float() { return m_Time; }
        float GetSeconds() { return m_Time; }
        float GetMilliseconds() { return m_Time * 1000.0; }
    private:
        float m_Time;
    };
}
#endif