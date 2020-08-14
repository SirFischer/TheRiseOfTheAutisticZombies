


file(GLOB_RECURSE MFGUISRCS
"srcs/**.cpp"
"includes/**.hpp"
)


message(STATUS "SOURCES:")
message(STATUS ${SUBDIRS})

add_library(
	mfGUI SHARED
	${MFGUISRCS}
)

target_include_directories(mfGUI PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/includes")
