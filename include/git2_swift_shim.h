#ifndef GIT2_SWIFT_SHIM_H
#define GIT2_SWIFT_SHIM_H

/*
 * git_libgit2_opts(int option, ...) is a true C variadic function, which
 * Swift's ClangImporter marks unavailable outright -- there is no way to
 * call a bare `...` function from Swift (only va_list-based functions,
 * via withVaList, which this isn't). Fixed-arity wrappers for the two
 * options SwiftGit2Init() needs (see SwiftGit2.swift) sidestep that
 * entirely: this file calls the variadic function in plain C, where
 * variadic calls work normally, and exposes a fixed-arity API instead.
 */
int git2_swift_set_server_connect_timeout(int millis);
int git2_swift_set_server_timeout(int millis);

#endif
