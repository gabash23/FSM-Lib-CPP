#include "Message.h"
#include "TrafficState.h"

namespace FiniteStateMachine
{
    class StateMachine
    {
    public:
        void handle(Message m);

    private:
        TrafficState curState;
    }

};