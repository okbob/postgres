/*-------------------------------------------------------------------------
 *
 * filter.h
 *	  Common header file for the parser of filter file
 *
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/bin/pg_dump/filter.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef FILTER_H
#define FILTER_H
#include "c.h"

#include "lib/stringinfo.h"

/*
 * State data for reading filter items from stream
 */
typedef struct
{
	FILE	   *fp;
	const char *filename;
	int			lineno;
	StringInfoData linebuff;
}			FilterStateData;

/*
 * List of objects that can be specified in filter file
 */
typedef enum
{
	FILTER_OBJECT_TYPE_NONE,
	FILTER_OBJECT_TYPE_DATA,
	FILTER_OBJECT_TYPE_DATABASE,
	FILTER_OBJECT_TYPE_FOREIGN_DATA,
	FILTER_OBJECT_TYPE_FUNCTION,
	FILTER_OBJECT_TYPE_INDEX,
	FILTER_OBJECT_TYPE_SCHEMA,
	FILTER_OBJECT_TYPE_TABLE,
	FILTER_OBJECT_TYPE_TRIGGER,
}			FilterObjectType;

extern void exit_invalid_filter_format(FilterStateData *fstate, char *message);
extern void exit_unsupported_filter_object_type(FilterStateData *fstate,
												const char *appname, FilterObjectType fot);
extern bool read_filter_item(FilterStateData *fstate, bool *is_include, char **objname, FilterObjectType *objtype);

#endif
