
add_library(edit
            editline.c
            el_globals.c
            fn_complete.c
            history.c)
if(BUILD_SHARED_LIBS)
  target_compile_definitions(edit PRIVATE _USRDLL)
  # NOTE: CMake will define edit_EXPORTS, however, because we provide interfaces
  # for both libedit and readline, provide a separate exports macro to
  # differentiate between the interfaces.
  target_compile_definitions(edit PRIVATE readline_EXPORTS)
endif()
target_compile_definitions(edit PRIVATE _UNICODE UNICODE)
set_target_properties(edit PROPERTIES PREFIX "")

include(GenerateExportHeader)
generate_export_header(edit
                       BASE_NAME edit
                       EXPORT_MACRO_NAME edit_EXPORT
                       EXPORT_FILE_NAME edit_Export.h
                       STATIC_DEFINE edit_BUILT_AS_STATIC)

install(TARGETS edit
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
# install(FILES $<TARGET_PDB_FILE:edit>
#         DESTINATION bin
#         OPTIONAL)
install(FILES editline/readline.h
        DESTINATION include/editline)
