option(SHOW_SECRET_MESSAGE "Display the secret message?" OFF)

file(WRITE ${CMAKE_BINARY_DIR}/cpp23test.cpp "
	#if __cplusplus < 202301L
		;aong;an
	#else
		int main() { }
	#endif")
try_compile(HAVE_CPP23 ${CMAKE_BINARY_DIR} SOURCES ${CMAKE_BINARY_DIR}/cpp23test.cpp)

if(NOT HAVE_CPP23)
	if ("$ENV{TARDIS_OVERRIDE}" STREQUAL "")
		message(FATAL_ERROR "You Do not Have C++23")
	else()
		message(WARNING "You Do not Have C++23")
	endif()
endif()

add_library(WidgetObj OBJECT Widget.cpp)
target_include_directories(WidgetObj PRIVATE ../include)

add_executable(Widget main.cpp $<TARGET_OBJECTS:WidgetObj>)
target_include_directories(Widget PRIVATE ../include)

if(SHOW_SECRET_MESSAGE)
	target_compile_definitions(Widget PRIVATE SHOW_SECRET_MESSAGE=1)
endif()

add_library(WidgetLib $<TARGET_OBJECTS:WidgetObj> ../include/Widget.h)

#target_include_directories(WidgetLib PUBLIC ../include)

install(TARGETS Widget WidgetLib RUNTIME DESTINATION bin ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)
