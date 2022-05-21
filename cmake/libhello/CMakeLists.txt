add_library(libhello STATIC hello.cc hello.hh)
set_target_properties(libhello PROPERTIES PREFIX "")
