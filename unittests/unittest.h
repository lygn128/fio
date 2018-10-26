#ifndef FIO_UNITTEST_H
#define FIO_UNITTEST_H

#include <sys/types.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

struct fio_unittest_entry {
	const char *name;
	CU_TestFunc fn;
};

/* XXX workaround lib/memalign.c's dependency on smalloc.c */
void *smalloc(size_t);
void sfree(void*);

CU_ErrorCode fio_unittest_add_suite(const char*, CU_InitializeFunc,
	CU_CleanupFunc, struct fio_unittest_entry*);

CU_ErrorCode fio_unittest_lib_memalign(void);
CU_ErrorCode fio_unittest_lib_strntol(void);
CU_ErrorCode fio_unittest_oslib_strlcat(void);

#endif
