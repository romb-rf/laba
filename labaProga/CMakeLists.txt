cmake_minimum_required(VERSION 3.16)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)  # необходимо для работы сигналов/слотов

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appuntitled
    main.cpp
)

qt_add_qml_module(appuntitled
    URI untitled
    QML_FILES
        Main.qml
        CastomButton.qml
        OutRes.qml
        Dop.qml
        TreeView.qml
    SOURCES
        recursionVar1.cpp recursionVar1.h
        datamanager.cpp datamanager.h
        iteration.cpp iteration.h
        intvalidator.cpp intvalidator.h
        doptask.cpp doptask.h
        treenode.cpp treenode.h
)

# Установка свойств (для macOS и Windows)
set_target_properties(appuntitled PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appuntitled
    PRIVATE Qt6::Quick
)

# ------------------------------------------------------
# Деплой для Windows (только в Release)
# ------------------------------------------------------
# ------------------------------------------------------
# Деплой для Windows (только в Release)
# ------------------------------------------------------
if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    # Путь к windeployqt
    set(WINDEPLOYQT "${CMAKE_PREFIX_PATH}/bin/windeployqt.exe")
    if(EXISTS "${WINDEPLOYQT}")
        set(QML_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
        add_custom_command(TARGET appuntitled POST_BUILD
            COMMAND "${WINDEPLOYQT}"
                --qmldir "${QML_SOURCE_DIR}"
                --no-compiler-runtime
                "$<TARGET_FILE:appuntitled>"
            COMMENT "Running windeployqt for Release build..."
        )
    else()
        message(WARNING "windeployqt not found at ${WINDEPLOYQT}")
    endif()

    # Копируем MinGW DLL (если используется MinGW)
    if(MINGW)
        get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
        get_filename_component(MINGW_BIN_DIR "${MINGW_BIN_DIR}/../bin" ABSOLUTE)
        set(MINGW_DLLS
            libgcc_s_seh-1.dll
            libstdc++-6.dll
            libwinpthread-1.dll
        )
        foreach(dll ${MINGW_DLLS})
            set(src "${MINGW_BIN_DIR}/${dll}")
            if(EXISTS "${src}")
                add_custom_command(TARGET appuntitled POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        "${src}"
                        "$<TARGET_FILE_DIR:appuntitled>"
                    COMMENT "Copying ${dll}"
                )
            endif()
        endforeach()
    endif()
endif()

# Установка (опционально)
include(GNUInstallDirs)
install(TARGETS appuntitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
