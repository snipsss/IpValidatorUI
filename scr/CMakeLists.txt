cmake_minimum_required(VERSION 3.16)

project(IpValidatorUI VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
add_executable(IpValidatorUI /
    ReadFromFile.h 
    TableCls.h 
    ValidatorCls.h 
    mainwindow.h    
    DefineTableCls.cpp 
    HighLighterColumns.cpp 
    ValidatorDefine.cpp 
    main.cpp 
    mainwindow.cpp
    mainwindow.ui
)

target_link_libraries(IpValidatorUI PRIVATE Qt5::Widgets)
set_target_properties(IpValidatorUI PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
