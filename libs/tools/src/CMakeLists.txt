add_library(
    tools
        timer.h
        timer.cpp
)

include(GenerateExportHeader)
generate_export_header(
    tools
        EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/tools_export.h
)

target_include_directories(
    tools
        PUBLIC ${CMAKE_BINARY_DIR}/exports
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
    tools
        PROPERTIES VERSION ${PROJECT_VERSION}
)

install(
	TARGETS tools
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)
