include(ExternalProject)

find_package(Git REQUIRED)

set(CatchVer v2.6.1)

ExternalProject_Add(
  get_catch
  PREFIX thirdparties
  GIT_REPOSITORY https://github.com/catchorg/Catch2
  GIT_TAG ${CatchVer}
  CMAKE_ARGS -DCATCH_BUILD_TESTING=OFF
  INSTALL_COMMAND ""
  UPDATE_COMMAND ""
  )

add_library(catch INTERFACE)

ExternalProject_Get_Property(get_catch SOURCE_DIR)
set_target_properties(catch PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${SOURCE_DIR}/single_include)
set_target_properties(catch PROPERTIES INTERFACE_SYSTEM_INCLUDE_DIRECTORIES ${SOURCE_DIR}/single_include)

add_dependencies(catch get_catch)