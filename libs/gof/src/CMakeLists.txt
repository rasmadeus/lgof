add_library(
    gof
        abstract_factory.h
        abstract_factory.cpp
        abstract_method.h
        abstract_method.cpp
        builder.h
        builder.cpp
        button.h
        button.cpp
        check_box.h
        check_box.cpp
        prototype.h
        prototype.cpp
        singleton.h
        singleton.cpp
)

include(GenerateExportHeader)
generate_export_header(
    gof
        EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/gof_export.h
)

target_include_directories(
    gof
        PUBLIC ${CMAKE_BINARY_DIR}/exports
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
    gof
        PROPERTIES VERSION ${PROJECT_VERSION}
)

install(
	TARGETS gof
	DESTINATION ${CMAKE_BINARY_DIR}/bin
)
