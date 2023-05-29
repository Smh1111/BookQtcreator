cmake_minimum_required(VERSION 3.5)

project(BookApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Core Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Core Test)

set(PROJECT_SOURCES
    main.cpp
    homepage.cpp
    homepage.h
    homepage.ui
    api_logic.h
    api_logic.cpp
    apiparameters.h
    apiparameters.cpp
    jsonparse.h
    jsonparse.cpp
    book.h
    book.cpp
    searchresultwindow.cpp
    searchresultwindow.h
    bookdetailswindow.h
    bookdetailswindow.cpp

    clickablelabel.cpp
    clickablelabel.h
    icons8-book-64.ico
    home_logo.png
)
# Copy the icon file to the build directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/icons8-book-64.ico DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add the icon file to the resource file
set(RESOURCE_FILES resources.qrc)

# Include the generated resource files in your executable
qt6_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})


# Find Doxygen package
find_package(Doxygen)

if(DOXYGEN_FOUND)
    # Set input and output directories for Doxygen
    set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)

    # Configure Doxyfile using variables
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    # Add a custom target for generating Doxygen documentation
    add_custom_target(docs COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()


# Test files
set(TEST_SOURCES
    test/test_main.cpp

    test/test_book.cpp
    book.cpp

    test/test_apiLogic.cpp
    api_logic.cpp

    test/test_apiParameters.cpp
    apiparameters.cpp

    test/test_bookDetailswindow.cpp
    bookdetailswindow.cpp

    test/test_homePage.cpp
    #homepage.cpp

    test/test_jsonParse.cpp
    jsonparse.cpp

    test/test_searchResultwindow.cpp
    #searchresultwindow.cpp
)

# Create the test executable
add_executable(BookAppTests ${TEST_SOURCES})

target_link_libraries(BookAppTests PRIVATE
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Core

)


add_test(NAME BookAppTests COMMAND BookAppTests)

# Add each individual test case as a test
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_test(NAME ${TEST_NAME} COMMAND BookAppTests ${TEST_NAME})
endforeach()

# Link the main executable with the necessary libraries
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BookApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    # Define target properties for Android with Qt 6 as:
    # set_property(TARGET BookApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #              ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BookApp SHARED
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BookApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()


# Link the main executable with the necessary libraries
target_link_libraries(BookApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Core)
install(TARGETS BookApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BookApp)
endif()

if(DOXYGEN_FOUND)
    # Add target dependency on 'docs' to generate documentation during build
    add_dependencies(BookApp docs)
endif()
