#
# unibilium - a terminfo parsing library
#
# Meson wrapper for unibilium. To use, install the Python 3 package "meson" via
# pip, as well as the "ninja" build system. Then run
#
# > mkdir build; cd build
# > meson -Dbuildtype=release ..
# > ninja
# > ninja test
#
# File: meson.build
# Author: Andreas Stöckel, 2019  https://github.com/astoeckel
#

project('unibilium',
    ['c'],
    default_options: ['c_std=c99', 'b_ndebug=if-release'],
    version: '2.0')

################################################################################
# Library                                                                      #
################################################################################

inc_unibilium = include_directories('.')
lib_unibilium = library(
    'unibilium',
    [
        'unibilium.c',
        'uniutil.c',
        'uninames.c',
    ],
    include_directories: [inc_unibilium],
    install: true,
    c_args: ['-DTERMINFO_DIRS="' + get_option('terminfo_dirs') + '"']
)

################################################################################
# Unit tests                                                                   #
################################################################################

exe_perl = find_program('perl')

arr_test_names = run_command(exe_perl, 't/list-tests.pl').stdout().strip().split('\0')
foreach test_name: arr_test_names
    exe_test = executable(
        'test_' + test_name,
        [
            't/' + test_name + '.c',
        ],
        include_directories: [inc_unibilium],
        link_with: [lib_unibilium])
    test(test_name, exe_test)
endforeach


################################################################################
# Installation                                                                 #
################################################################################

# Meson dependency
dep_unibilium = declare_dependency(
    link_with: [lib_unibilium],
    include_directories: [inc_unibilium]
)

# Install all public header files
install_headers([
    'unibilium.h'
])

# Generate a Pkg config file
pkg = import('pkgconfig')
pkg.generate(
    lib_unibilium,
    name: 'unibilium',
    version: meson.project_version(),
    description: 'A terminfo parsing library')

