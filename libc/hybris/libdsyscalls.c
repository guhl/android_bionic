/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <errno.h>
#include <sys/cdefs.h>

/* Define __set_errno here so it can be hijacked by libhybris
 * at runtime (called from __set_syscall_errno)
 */
int __set_errno(int n)
{
    errno = n;
    return -1;
}

long __set_errno_internal(int n) {
    errno = n;
    return -1;
}

static __thread void *tls_hooks[16];

void *__get_tls_hooks()
{
    return tls_hooks;
}

