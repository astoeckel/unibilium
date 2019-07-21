#!/usr/bin/perl

#
# This script is used by meson.build to enumerate all test files in the "t/"
# directory. We're using Perl here since the build system for libvterm requires
# Perl anyways -- this code should thus be more portable than using "find" or a
# "sh" script.
#
# File: list-tests.pl
# Author: Andreas Stöckel, 2018  https://github.com/astoeckel
#

# Fetch the name of the directory this script is located in
use File::Basename;
my $dirname = dirname(__FILE__);

# List all files in the directory and sort them
opendir(my $dh, $dirname) || die "Couldn't open dir '$dirname': $!";
my @tests;
while (readdir $dh) {
    if ($_ =~ s/^([^.\/]*)\.c$/\1/s) {
        push @tests, $_;
    }
}
closedir $dh;

# Sort the tests and print them with '\0' as a separator
print join("\0", sort @tests)
