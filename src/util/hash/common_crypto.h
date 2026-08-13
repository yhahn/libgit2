/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#ifndef INCLUDE_hash_common_crypto_h__
#define INCLUDE_hash_common_crypto_h__

#include "hash/sha.h"

/*
 * Patched for Hemlock (github.com/yhahn/libgit2): the system header this
 * backend needs only exists on Darwin. Widen the existing struct guards to
 * also cover the include itself, so this file safely no-ops as an empty
 * translation unit when neither macro is defined (e.g. building for Linux),
 * instead of failing to find <CommonCrypto/CommonDigest.h>.
 */
#if defined(GIT_SHA1_COMMON_CRYPTO) || defined(GIT_SHA256_COMMON_CRYPTO)

#include <CommonCrypto/CommonDigest.h>

#ifdef GIT_SHA1_COMMON_CRYPTO
struct git_hash_sha1_ctx {
	CC_SHA1_CTX c;
};
#endif

#ifdef GIT_SHA256_COMMON_CRYPTO
struct git_hash_sha256_ctx {
	CC_SHA256_CTX c;
};
#endif

#endif

#endif
