#pragma once

#include <functional>
#include <gof_export.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace lgof
{
    enum class GOF_EXPORT EventType
    {
        Mouse,
        Keyboard,
    };

    class GOF_EXPORT EventListener
    {
    public:
        virtual ~EventListener() = default;
        virtual void update(EventType eventType, std::string const &data) = 0;
    };

    class EventManager
    {
    public:
        GOF_EXPORT void subscribe(EventType eventType, EventListener &listener);
        GOF_EXPORT void unsubscribe(EventType eventType, EventListener &listener);
        GOF_EXPORT void notify(EventType eventType, std::string const &data);

    private:
        std::unordered_map<EventType, std::vector<std::reference_wrapper<EventListener>>> m_listeners;
    };

    class LabelListener: public EventListener
    {
    public:
        GOF_EXPORT void update(EventType eventType, std::string const &data) override;
    };
}
