#pragma once

#include <gof_export.h>
#include <stack>
#include <string>

namespace lgof
{
    class Memento
    {
    public:
        GOF_EXPORT Memento(std::string const &state);
        GOF_EXPORT std::string const &getState() const;

    private:
        std::string m_state;
    };

    class Originator
    {
    public:
        GOF_EXPORT void setState(std::string state);
        GOF_EXPORT std::string const &getState() const;
        GOF_EXPORT Memento toMemento() const;
        GOF_EXPORT void fromMemento(Memento const &memento);

    private:
        std::string m_state;
    };

    class CareTaker
    {
    public:
        GOF_EXPORT void push(Memento memento);
        GOF_EXPORT void pop();
        GOF_EXPORT Memento const &top() const;
        GOF_EXPORT bool isEmpty() const;

    private:
        std::stack<Memento> m_states;
    };

    class Printer
    {
    public:
        GOF_EXPORT void print(std::string text);
        GOF_EXPORT void print();
        GOF_EXPORT void undo();

    private:
        Originator m_originator;
        CareTaker m_careTaker;
    };
}
