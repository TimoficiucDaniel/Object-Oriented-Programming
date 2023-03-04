cmake_minimum_required(VERSION 3.22)
project(A5_6)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/qt/6.3.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(A8-9 main.cpp
        Domain/Dog.cpp
        Domain/Dog.h
        Service/Service.cpp
        Service/Service.h
        Ui/Interface.cpp
        Ui/Interface.h
        Repo/Database.cpp
        Repo/Database.h
        Ui/User.cpp
        Ui/User.h
        Ui/Administrator.cpp
        Ui/Administrator.h
        Test.cpp
        Test.h
        Ui/Ui.cpp
        Ui/Ui.h
        Repo/RepoExceptions.cpp
        Repo/RepoExceptions.h
        Ui/UiValidators.cpp
        Ui/UiValidators.h
        Ui/ValidatorException.cpp
        Ui/ValidatorException.h
        Repo/SaveToCSV.h
        Repo/SaveToHTML.h
        Comparator/CompatatorBase.cpp
        Comparator/CompatatorBase.h
        Comparator/CompareByAge.cpp
        Comparator/CompareByAge.h
        Comparator/CompareByName.cpp
        Comparator/CompareByName.h
        Comparator/Sort.cpp
        GUI/GUI.cpp
        GUI/GUI.h)
target_link_libraries(A8-9
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

#if (WIN32)
#    set(DEBUG_SUFFIX)
#    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
#    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
#    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        endif ()
#    endif ()
#    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif ()
#    foreach (QT_LIB Core Gui Widgets)
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach (QT_LIB)
#endif ()



