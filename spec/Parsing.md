---
parent: Specification
has_children: true
---

# Parsing

This document specifies how an implementation of Locke should parse tokens.

## Token types

A token type has 3 properties:

- a match pattern

- a priority

The match pattern property dictates what qualifies as a token of that type.

The priority property dictates, in certain cases, which type a token is.

For example, if the compiler found a valid identifier at the same place it found a valid keyword, the priority of the types of tokens will dictate which one is correct.

> In this case, the keyword would win as it has a higher priority.

### Identifier

A sequence of characters that identifies a variable, class, or method. They cannot be identical to [keywords](#Keyword).

Refer to [Naming](Naming.md) for naming conventions, requirements and more.

Identifiers have the lowest priority of all types. All other types should be prioritized over identifiers.

Exceptions are keywords. Keywords may be contained inside identifiers.

### Operators

May have different types. Different types have different specifications, and most can be overridden by the user.

Refer to [Operators](./Lexing/Operators.md) for more information.

Operators are under keywords.

### Keyword

A sequence of characters that denotes a functionality.

Refer to [Keywords](./Lexing/Keywords.md) for a list of keywords, their intended function and usage.

Keywords are under string literals.

### Primitive literals

A primitive literal.

Primitives include but are not limited to numbers and characters.

Primitive literals are under operators.

#### String literal

A sequence of characters between 2 quotation marks (").

String literals have the highest priority of all types.
