find_package(
    GTest
    REQUIRED COMPONENTS
        gtest
        gtest_main
)

add_executable(
    unit_test_tools
        main.cpp
        timer_test.h
        timer_test.cpp
)

target_link_libraries(
    unit_test_tools
    PRIVATE
        tools
        GTest::gtest
        GTest::gtest_main
)

install(
	TARGETS unit_test_tools
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)

add_test(NAME unit_test_tools COMMAND unit_test_tools)
