#include "memento.h"
#include <cassert>
#include <iostream>

using namespace lgof;

Memento::Memento(std::string const &state)
    : m_state{ state }
{
}

std::string const &Memento::getState() const
{
    return m_state;
}

void Originator::setState(std::string state)
{
    m_state = std::move(state);
}

std::string const &Originator::getState() const
{
    return m_state;
}

Memento Originator::toMemento() const
{
    return { m_state };
}

void Originator::fromMemento(Memento const &memento)
{
    m_state = memento.getState();
}

void CareTaker::push(Memento memento)
{
    m_states.emplace(std::move(memento));
}

void CareTaker::pop()
{
    assert(!m_states.empty());
    m_states.pop();
}

Memento const &CareTaker::top() const
{
    assert(!m_states.empty());
    return m_states.top();
}

bool CareTaker::isEmpty() const
{
    return m_states.empty();
}

void Printer::print(std::string text)
{
    m_originator.setState(std::move(text));
    m_careTaker.push(m_originator.toMemento());
    std::cout << m_originator.getState();
}

void Printer::print()
{
    std::cout << m_originator.getState();
}

void Printer::undo()
{
    if (!m_careTaker.isEmpty())
    {
        m_careTaker.pop();
        m_originator.fromMemento(m_careTaker.top());
        std::cout << m_originator.getState();
    }
}
