
add_executable(edit_test libedit_test.c)
target_link_libraries(edit_test edit)

add_executable(edit_test_dll libedit_test_dll.c)

if(INSTALL_EXAMPLES)
  install(TARGETS edit_test edit_test_dll
          RUNTIME DESTINATION bin)
endif()
