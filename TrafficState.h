#pragma once

enum class TrafficState
{
    Green,
    Yellow,
    Red,
    BlinkingRed
};

constexpr const char *toString(TrafficState ts)
{
    switch (ts)
    {
        case TrafficState::Green:
            return "green";
        case TrafficState::Yellow:
            return "yellow";
        case TrafficState::Red:
            return "red";
        case TrafficState::BlinkingRed:
            return "blinking red";
    }
}