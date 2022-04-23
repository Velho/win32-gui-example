
add_executable ( gui-example WIN32
    BaseWindow.h
    MainWindow.h
    Control.h
    Button.h
    Button.cpp
    Control.cpp
    MainWindow.cpp
    # gui-example.exe.manifest
)

target_link_libraries ( gui-example 
	comctl32.lib)

# target_link_libraries ( gui-example
#     -manifest:embed 
#     -manifestinput:"${PROJECT_SOURCE_DIR}/gui-example.exe.manifest" )

# target_sources (gui-example PRIVATE gui-example.exe.manifest)
