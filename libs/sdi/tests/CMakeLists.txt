find_package(
    GTest
    REQUIRED COMPONENTS
        gtest
        gtest_main
)

add_executable(
    unit_test_sdi
        main.cpp
        consistent_hashing_test.h
        consistent_hashing_test.cpp
        rate_limiter_token_bucket_test.h
        rate_limiter_token_bucket_test.cpp
        rate_limiter_leaking_bucket_test.h
        rate_limiter_leaking_bucket_test.cpp
        rate_limiter_sliding_window_test.h
        rate_limiter_sliding_window_test.cpp
)

target_link_libraries(
    unit_test_sdi
    PRIVATE
        sdi
        tools
        GTest::gtest
        GTest::gtest_main
)

install(
	TARGETS unit_test_sdi
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)

add_test(NAME unit_test_sdi COMMAND unit_test_sdi)
