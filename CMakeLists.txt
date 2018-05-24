cmake_minimum_required(VERSION 3.8)

project(hashlib++)

option(BUILD_SHARED OFF)

function(ADD_PREFIX list_var prefix out_var)
    set(_result "")
    foreach(_item IN LISTS ${list_var})
        list(APPEND _result "${prefix}${_item}")
    endforeach()
    set(${out_var} "${_result}" PARENT_SCOPE)
endfunction()

set(PUBLIC_HEADER
    hashlibpp.h
    hl_exception.h
    hl_hashwrapper.h
    hl_md5.h
    hl_md5wrapper.h
    hl_sha1.h
    hl_sha1wrapper.h
    hl_sha256.h
    hl_sha256wrapper.h
    hl_sha2ext.h
    hl_sha2mac.h
    hl_sha384wrapper.h
    hl_sha512wrapper.h
    hl_types.h
    hl_wrapperfactory.h)

set(PRIVATE_HEADER "")
   
set(CPP_SRC
    hl_md5.cpp
    hl_md5wrapper.cpp
    hl_sha1.cpp
    hl_sha1wrapper.cpp
    hl_sha256.cpp
    hl_sha256wrapper.cpp
    hl_sha2ext.cpp
    hl_sha384wrapper.cpp
    hl_sha512wrapper.cpp
    hl_wrapperfactory.cpp)

ADD_PREFIX(PUBLIC_HEADER "src/" PF_PUBLIC_HEADER)
ADD_PREFIX(PRIVATE_HEADER "src/" PF_PRIVATE_HEADER)
ADD_PREFIX(CPP_SRC "src/" PF_CPP_SRC)

if(BUILD_SHARED)
    add_library(hl++ SHARED
        ${PF_PUBLIC_HEADER}
        ${PF_PRIVATE_HEADER}
        ${PF_CPP_SRC})
else()
    add_library(hl++
        ${PF_PUBLIC_HEADER}
        ${PF_PRIVATE_HEADER}
        ${PF_CPP_SRC})
endif()

export(
    TARGETS hl++
    FILE hl++.cmake)


install(
    TARGETS hl++
    EXPORT install_hl++.cmake
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
    INCLUDES DESTINATION include)
install(
    FILES ${PF_PUBLIC_HEADER}
    DESTINATION include)
install(
    EXPORT install_hl++.cmake
    FILE hl++.cmake
    DESTINATION cmake)