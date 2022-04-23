cmake_minimum_required (VERSION 3.8)
project (gui-example)

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED ON)


## 
# TODO
# Stuff with the manifest.
# Enabling the Win10 styling.
##
# set (TARGET_TARGETNAME ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe)
# message (${TARGET_TARGETNAME})
# set (CMAKE_CXX_LINKER_FLAGS "/MANIFEST:EMBED /MANIFESTFILE:${CMAKE_SOURCE_DIR}/src/gui-example.exe.manifest")
# message (${CMAKE_CXX_LINKER_FLAGS})

add_subdirectory (src)

# add_custom_command (
# 	TARGET ${TARGET_TARGETNAME}
# 	POST_BUILD
# 	COMMAND "mt.exe" -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\gui-example.exe.manifest\" -inputresource:\"$<TARGET_FILE:${TARGET_TARGETNAME}>\"\;\#1 -outputresource:\"$<TARGET_FILE:${TARGET_TARGETNAME}>\"\;\#1
# 	COMMENT "Adding additional manifest.."
# )