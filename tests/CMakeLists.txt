message(STATUS "Catch2 will be retrieved with FetchContent")

Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)


# Testing
add_executable(unit-tests)

target_link_libraries(unit-tests
    PRIVATE
        Catch2::Catch2WithMain
        datastructures
)

target_sources(unit-tests
	PRIVATE
		"dynamic_array_test.cpp"
)

include(CTest)
include(Catch)

catch_discover_tests(unit-tests)