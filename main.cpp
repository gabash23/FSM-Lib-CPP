#include "FiniteStateMachine.cpp"

int main()
{
    StateMachine sm;
    sm.handle(Message::ChangeLight);
    sm.handle(Message::Print);
    return 0;
}