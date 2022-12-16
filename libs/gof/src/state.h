#pragma once

#include <gof_export.h>
#include <memory>

namespace lgof::state
{
    class Player;

    class GOF_EXPORT PlayerState
    {
    public:
        virtual ~PlayerState() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual void play() = 0;
    };

    class ReadyState: public PlayerState
    {
    public:
        GOF_EXPORT ReadyState(Player &player);
        GOF_EXPORT void lock() override;
        GOF_EXPORT void unlock() override;
        GOF_EXPORT void play() override;

    private:
        Player &m_player;
    };

    class LockedState: public PlayerState
    {
    public:
        GOF_EXPORT LockedState(Player &player);
        GOF_EXPORT void lock() override;
        GOF_EXPORT void unlock() override;
        GOF_EXPORT void play() override;

    private:
        Player &m_player;
    };

    class Player
    {
    public:
        GOF_EXPORT void clickLock();
        GOF_EXPORT void clickUnlock();
        GOF_EXPORT void clickPlay();
        GOF_EXPORT void setState(std::unique_ptr<PlayerState> state);

    private:
        std::unique_ptr<PlayerState> m_state = std::make_unique<ReadyState>(*this);
    };
}
