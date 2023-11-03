project (DataStructures)

add_executable(main)

target_link_libraries(main
    PRIVATE
        datastructures
)

target_sources(main
    PRIVATE
        main.cpp
)