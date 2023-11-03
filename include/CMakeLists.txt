project (DataStructures)

add_library(datastructures INTERFACE)

target_sources(datastructures
	INTERFACE
		"datastructures/dynamic_array.h"
)

target_include_directories(datastructures
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)