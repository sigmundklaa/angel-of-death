
#ifndef TAGS_BASE_H
#define TAGS_BASE_H

#include "gedcom.h"
#include "hashmap.h"

struct ged_record; // defined in gedcom.h

struct tag_interface;

struct tag_base {
    struct tag_interface* interface;
};

typedef struct tag_base* (*fn_create)(struct tag_interface*, struct ged_record*,
                                      struct lex_token*);

typedef void (*fn_free)(struct tag_base*);

struct tag_interface {
    fn_create create;
    fn_free free;
};

void tag_base_free(struct tag_base* tag);

struct tag_interface* tag_i_get(const char* key);

void tags_init();
void tags_cleanup();

#endif // TAGS_BASE_H