find_package(
    GTest
    REQUIRED COMPONENTS
        gtest
        gtest_main
)

add_executable(
    unit_test_gof
        main.cpp
        abstract_factory_test.h
        abstract_factory_test.cpp
        abstract_method_test.h
        abstract_method_test.cpp
        adapter_test.h
        adapter_test.cpp
        bridge_test.h
        bridge_test.cpp
        builder_test.h
        builder_test.cpp
        chain_of_response_test.h
        chain_of_response_test.cpp
        command_test.h
        command_test.cpp
        composite_test.h
        composite_test.cpp
        decorator_test.h
        decorator_test.cpp
        facade_test.h
        facade_test.cpp
        flyweight_test.h
        flyweight_test.cpp
        iterator_test.h
        iterator_test.cpp
        mediator_test.h
        mediator_test.cpp
        memento_test.h
        memento_test.cpp
        observer_test.h
        observer_test.cpp
        prototype_test.h
        prototype_test.cpp
        proxy_test.h
        proxy_test.cpp
        singleton_test.h
        singleton_test.cpp
        strategy_test.h
        strategy_test.cpp
        std_cout_redirect.h
        std_cout_redirect.cpp
)

target_link_libraries(
    unit_test_gof
    PRIVATE
        gof
        GTest::gtest
        GTest::gtest_main
)

install(
	TARGETS unit_test_gof
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)

add_test(NAME unit_test_gof COMMAND unit_test_gof)
