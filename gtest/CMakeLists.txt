set(target "gtest")
create_project_lib(${target})

#if((${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR
#    ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") AND
#    (${CMAKE_SYSTEM_NAME} MATCHES "Linux"))
#    set(pthread "-pthread")
#endif()
#target_link_libraries(${target} ${pthread})

find_package(Threads)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(${target} PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(${target} "${CMAKE_THREAD_LIBS_INIT}")
endif()

