#ifndef HASH_H
#define HASH_H

#include <stdint.h>

/**
 * Hashdb object
 */
typedef struct hashdb_s* hashdb;


/**
 * Open or create a hashdb file
 * The database or null is returned in the hashdb param
 * @return 0 on success, -1 on open error, other values on other errors
 */
int hash_open(hashdb *db, const char* f_name, int readonly, int overwrite);

/**
 * lookup a key
 * @return value of key
 */
char* hash_get(const hashdb db, const char* key, uint32_t nkey);

/**
 * Insert or overwrite a key
 */
int hash_put(hashdb db, const char* key, uint32_t nkey, const char* value,
             uint32_t nvalue);

/**
 * Initialize a new empty db
 */
int hash_init(hashdb db);

/**
 * Check header / checksums / etc
 */
int hash_check(const hashdb db);

#endif
