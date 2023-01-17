add_library(
    sdi
        consistent_hashing.h
        consistent_hashing.cpp
        rate_limiter_token_bucket.h
        rate_limiter_token_bucket.cpp
        rate_limiter_leaking_bucket.h
        rate_limiter_leaking_bucket.cpp
        rate_limiter_sliding_window.h
        rate_limiter_sliding_window.cpp
)

target_link_libraries(
    sdi
    PRIVATE
        tools
)

include(GenerateExportHeader)
generate_export_header(
    sdi
        EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/sdi_export.h
)

target_include_directories(
    sdi
        PUBLIC ${CMAKE_BINARY_DIR}/exports
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
    sdi
        PROPERTIES VERSION ${PROJECT_VERSION}
)

install(
	TARGETS sdi
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)
