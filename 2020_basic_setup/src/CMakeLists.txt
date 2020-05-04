# cmake-format: off
# option(CPP_STARTER_USE_QT "Enable compilation of QT sample" OFF)
# option(CPP_STARTER_USE_FLTK "Enable compilation of FLTK sample" OFF)
# option(CPP_STARTER_USE_GTKMM "Enable compilation of GTKMM sample" OFF)
# option(CPP_STARTER_USE_IMGUI "Enable compilation of ImGui sample" OFF)
# option(CPP_STARTER_USE_NANA "Enable compilation of Nana GUI sample" OFF)
# option(CPP_STARTER_USE_SDL "Enable compilation of SDL sample" OFF)

# # sdl
# if(CPP_STARTER_USE_SDL)
#   message("Using SDL2")
#   add_subdirectory(sdl)
# endif()

# # qt
# if(CPP_STARTER_USE_QT)
#   message("Using Qt")
#   add_subdirectory(qt)
# endif()

# # fltk test
# if(CPP_STARTER_USE_FLTK)
#   message("Using FLTK")
#   add_subdirectory(fltk)
# endif()

# # gtkmm test
# if(CPP_STARTER_USE_GTKMM)
#   message("Using gtkmm")
#   add_subdirectory(gtkmm)
# endif()

# # imgui example
# if(CPP_STARTER_USE_IMGUI)
#   message("Using Dear ImGui")
#   add_subdirectory(imgui)
# endif()

# # Nana
# if(CPP_STARTER_USE_NANA)
#   message("Using Nana")
#   add_subdirectory(nana)
# endif()
# cmake-format: on

# ######################################################################################################################
# Create a library
# ######################################################################################################################

# Generate the static library from the library sources with the name libperson_library.a with the sources
add_library(person_library SHARED faculty/Person.cpp faculty/Student.cpp)

target_include_directories(person_library PUBLIC ${PROJECT_SOURCE_DIR}/include/faculty)
target_compile_features(person_library PUBLIC cxx_std_14)

# Generic test that uses conan libs
add_executable(test_person main_person.cpp)
target_link_libraries(test_person PRIVATE project_options project_warnings person_library)

add_executable(test_student main_student.cpp)
target_link_libraries(test_student PRIVATE project_options project_warnings person_library)
