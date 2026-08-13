#include "git2_swift_shim.h"
#include "git2/common.h"

int git2_swift_set_server_connect_timeout(int millis) {
	return git_libgit2_opts(GIT_OPT_SET_SERVER_CONNECT_TIMEOUT, millis);
}

int git2_swift_set_server_timeout(int millis) {
	return git_libgit2_opts(GIT_OPT_SET_SERVER_TIMEOUT, millis);
}
