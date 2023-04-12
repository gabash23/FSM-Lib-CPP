#include "FiniteStateMachine.cpp"

int main()
{
    StateMachine sm;

    /* note - I wanted to print success/total tests passed
      but I can't compare output since sm.handle(Message::Print) is void
    */

    // simple flow test
    sm.handle(Message::ChangeLight);
    sm.handle(Message::ChangeLight);
    sm.handle(Message::ChangeLight);
    sm.handle(Message::Print); // The traffic light is currently: green

    // simple blinkingredlight test
    sm.handle(Message::EncounteredProblem);
    sm.handle(Message::Print); // The traffic light is currently: blinking red
    sm.handle(Message::FixedProblem);
    sm.handle(Message::Print); // The traffic light is currently: green

    // testing the previous state
    sm.handle(Message::ChangeLight);
    sm.handle(Message::EncounteredProblem);
    sm.handle(Message::FixedProblem);
    sm.handle(Message::Print); // The traffic light is currently: yellow

    sm.restart();

    // potential edge cases
    sm.handle(Message::ChangeLight);
    sm.handle(Message::EncounteredProblem);
    sm.handle(Message::ChangeLight);
    sm.handle(Message::ChangeLight);
    sm.handle(Message::ChangeLight);
    sm.handle(Message::FixedProblem);
    sm.handle(Message::Print); // The traffic light is currently: yellow

    return 0;
}