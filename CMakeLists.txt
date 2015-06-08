cmake_minimum_required(VERSION 3.2)
project(ThreadingTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(ThreadingTest ${SOURCE_FILES} Entity/Field.cpp Entity/Field.h Entity/Cell.cpp Entity/Cell.h Application/Application.cpp Application/Application.h Display/FieldDisplay.cpp Display/FieldDisplay.h Events/Event.cpp Events/Event.h Events/EventManager.cpp Events/EventManager.h Events/EventListener.cpp Events/EventListener.h Events/EventTypes/QuitEvent.cpp Events/EventTypes/QuitEvent.h)