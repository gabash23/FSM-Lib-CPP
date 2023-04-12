#include "Message.h"
#include "TrafficState.h"

class StateMachine
{
public:
    StateMachine();
    void handle(Message m);
    inline TrafficState getCurState() const { return curState; };
    inline TrafficState getPrevState() const { return prevState; };
    inline void setCurState(TrafficState ts)
    {
        prevState = curState;
        curState = ts;
    }
    inline void restart()
    {
        prevState = TrafficState::Green;
        curState = TrafficState::Green;
    }

private:
    TrafficState curState;
    TrafficState prevState;
};