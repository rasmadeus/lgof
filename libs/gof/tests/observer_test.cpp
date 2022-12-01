#include "observer_test.h"
#include "std_cout_redirect.h"
#include <observer.h>

using namespace lgof;

TEST_F(ObserverTest, TestObserver)
{
    auto const stdCoutRedirect = StdCoutRedirect{};
    auto manager = EventManager{};
    auto listener = LabelListener{};

    manager.subscribe(EventType::Mouse, listener);
    manager.notify(EventType::Mouse, "2");
    EXPECT_EQ("02", stdCoutRedirect.string());

    manager.notify(EventType::Keyboard, "2");
    EXPECT_EQ("02", stdCoutRedirect.string());

    manager.unsubscribe(EventType::Keyboard, listener);
    manager.notify(EventType::Mouse, "2");
    EXPECT_EQ("0202", stdCoutRedirect.string());

    manager.unsubscribe(EventType::Mouse, listener);
    manager.notify(EventType::Mouse, "2");
    EXPECT_EQ("0202", stdCoutRedirect.string());
}
