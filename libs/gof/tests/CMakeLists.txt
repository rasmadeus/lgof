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
