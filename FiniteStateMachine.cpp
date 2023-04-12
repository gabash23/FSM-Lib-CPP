#include "FiniteStateMachine.h"
#include <map>
#include <iostream>

using std::cout;
using std::map;

StateMachine::StateMachine()
{
    curState = TrafficState::Green;
    prevState = TrafficState::Green; // basically a blank line
}

void StateMachine::handle(Message m)
{
    // modeling the green --> yellow --> red --> green, etc. flow
    map<TrafficState, TrafficState> transitions = {
        {TrafficState::Green, TrafficState::Yellow},
        {TrafficState::Yellow, TrafficState::Red},
        {TrafficState::Red, TrafficState::Green},
        {TrafficState::BlinkingRed, getPrevState()}};

    if (m == Message::Print)
        cout << "The traffic light is currently: " << toString(getCurState()) << '\n';

    else if ((m == Message::ChangeLight && getCurState() != TrafficState::BlinkingRed) || m == Message::FixedProblem && getCurState() == TrafficState::BlinkingRed)
        setCurState(transitions[getCurState()]);

    else if (m == Message::EncounteredProblem && getCurState() != TrafficState::BlinkingRed)
        setCurState(TrafficState::BlinkingRed);
}