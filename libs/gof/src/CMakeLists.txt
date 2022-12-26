add_library(
    gof
        abstract_factory.h
        abstract_factory.cpp
        abstract_method.h
        abstract_method.cpp
        adapter.h
        adapter.cpp
        bridge.h
        bridge.cpp
        builder.h
        builder.cpp
        button.h
        button.cpp
        chain_of_response.h
        chain_of_response.cpp
        check_box.h
        check_box.cpp
        command.h
        command.cpp
        composite.h
        composite.cpp
        decorator.h
        decorator.cpp
        facade.h
        facade.cpp
        flyweight.h
        flyweight.cpp
        iterator.h
        iterator.cpp
        mediator.h
        mediator.cpp
        memento.h
        memento.cpp
        observer.h
        observer.cpp
        prototype.h
        prototype.cpp
        proxy.h
        proxy.cpp
        singleton.h
        singleton.cpp
        strategy.h
        strategy.cpp
        template_method.h
        template_method.cpp
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
