#pragma once

// using verbose strings because it makes debugging messages way clearer
// granted, not implemented yet
#define TYPE_UNKNOWN  "unknown"
#define TYPE_STRING   "string"
#define TYPE_COMMENT  "comment"
#define TYPE_CHAR     "character"
#define TYPE_NUMBER   "number"
#define TYPE_OPERATOR "operator"
#define TYPE_ID       "identifier"
#define TYPE_KEYWORD  "keyword"

// HERE BE KEYWORDS
// declaration keywords
#define KEYWORD_DECL_FUNCTION "function"
#define KEYWORD_DECL_VARIABLE "variable"
// access modifiers
#define KEYWORD_ACCM_PUBLIC    "public"
#define KEYWORD_ACCM_PRIVATE   "private"
#define KEYWORD_ACCM_PROTECTED "protected"
#define KEYWORD_ACCM_STATIC    "static"
#define KEYWORD_ACCM_CONSTANT  "constant"
// execution modifiers
#define KEYWORD_EXEM_ASYNC "async"
#define KEYWORD_EXEM_SYNC  "sync"

// and last but not least, operators
#define OPERATOR_ADDITION       "add"
#define OPERATOR_SUBTRACTION    "subtract"
#define OPERATOR_MULTIPLICATION "multiply"
#define OPERATOR_DIVISION       "divide"
