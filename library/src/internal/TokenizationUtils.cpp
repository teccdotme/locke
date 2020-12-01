#include <locke/internal/TokenizationUtils.h>
#include <locke/TokenTypes.h>
#include <locke/Util.h>

bool analyzeForKeywords(string_t content) {
    // declaration keywords
    if (content == KEYWORD_DECL_FUNCTION || content == KEYWORD_DECL_VARIABLE)
        return true;
    // access modifiers / visibility
    if (content == KEYWORD_ACCM_PUBLIC || content == KEYWORD_ACCM_PROTECTED || content == KEYWORD_ACCM_PRIVATE)
        return true;
    // access modifiers / access
    if (content == KEYWORD_ACCM_CONSTANT || content == KEYWORD_ACCM_STATIC)
        return true;
    // execution modifiers
    if (content == KEYWORD_EXEM_ASYNC || content == KEYWORD_EXEM_SYNC)
        return true;

    return false;
}