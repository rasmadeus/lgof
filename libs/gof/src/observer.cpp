#include "observer.h"
#include <cassert>
#include <format>
#include <iostream>

using namespace lgof;

void EventManager::subscribe(EventType eventType, EventListener &listener)
{
    m_listeners[eventType].emplace_back(std::reference_wrapper{ listener });
}

void EventManager::unsubscribe(EventType eventType, EventListener &listener)
{
    auto &listeners = m_listeners[eventType];
    auto remover = [&listener](std::reference_wrapper<EventListener> &item)
    {
        return &listener == &item.get();
    };

    auto end = std::remove_if(listeners.begin(), listeners.end(), remover);
    listeners.erase(end, listeners.end());
}

void EventManager::notify(EventType eventType, std::string const &data)
{
    auto &listeners = m_listeners[eventType];
    for (auto &listener : listeners)
    {
        listener.get().update(eventType, data);
    }
}

void LabelListener::update(EventType eventType, std::string const &data)
{
    static auto const eventTypeDescriptions = std::unordered_map<EventType, std::string>{
        { EventType::Mouse, "0" },
        { EventType::Keyboard, "1" },
    };

    auto const it = eventTypeDescriptions.find(eventType);
    assert(it != eventTypeDescriptions.cend());
    std::cout << std::format("{}{}", it->second, data);
}
