#ifndef _ECE150_PROJ_3_PROVIDED
#define _ECE150_PROJ_3_PROVIDED

/**
 * URI served by the server.
 */
struct uri {
    char *name;
    unsigned size, priority;
    uri *next;
};

/**
 * Timestamp
 */
struct timestamp {
    unsigned hh, mm, ss;
};

/**
 * Client-request
 */
struct request {
    char *name;
    timestamp t;
    request *next;
};

/**
 * Function you need to implement
 */

timestamp maxClientDelay(uri *, request *);

#endif
