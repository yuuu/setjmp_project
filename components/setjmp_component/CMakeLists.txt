set(LIB_FILE "${COMPONENT_DIR}/libsetjmp_test.a")

idf_component_register(INCLUDE_DIRS .)

add_custom_command(
  OUTPUT ${LIB_FILE}
  COMMAND make
  WORKING_DIRECTORY ${COMPONENT_DIR}
  VERBATIM
)

add_library(libsetjmp_test STATIC IMPORTED)
set_target_properties(libsetjmp_test PROPERTIES IMPORTED_LOCATION ${LIB_FILE})
set_target_properties(libsetjmp_test PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${COMPONENT_PATH}")

target_link_libraries(${COMPONENT_LIB} INTERFACE libsetjmp_test)

add_custom_target(setjmp_test DEPENDS ${LIB_FILE})
add_dependencies(${COMPONENT_LIB} setjmp_test)
