#include "state.h"
#include <iostream>

using namespace lgof::state;

ReadyState::ReadyState(Player &player)
    : m_player{ player }
{
}

void ReadyState::lock()
{
    m_player.setState(std::make_unique<LockedState>(m_player));
}

void ReadyState::unlock()
{
}

void ReadyState::play()
{
    std::cout << "play";
}

LockedState::LockedState(Player &player)
    : m_player{ player }
{
}

void LockedState::lock()
{
}

void LockedState::unlock()
{
    m_player.setState(std::make_unique<ReadyState>(m_player));
}

void LockedState::play()
{
}

void Player::clickLock()
{
    m_state->lock();
}

void Player::clickUnlock()
{
    m_state->unlock();
}

void Player::clickPlay()
{
    m_state->play();
}

void Player::setState(std::unique_ptr<PlayerState> state)
{
    m_state = std::move(state);
}
