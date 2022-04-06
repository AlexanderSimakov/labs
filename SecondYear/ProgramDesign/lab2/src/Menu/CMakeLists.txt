set(Menu_source_files
    menu.hpp
    menu.cpp
)

add_library(Menu ${Menu_source_files})

target_link_libraries(Menu Console)
