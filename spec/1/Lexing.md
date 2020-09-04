---
parent: Specifications
has_children: true
---

# Lexing

## Token types

### Identifier

A sequence of characters that identifies a variable, class, or method. They cannot be identical to [keywords](#Keyword).

Refer to [Naming](Naming.md) for naming conventions, requirements and more.

### Operators

May have different types. Different types have different specifications, and most can be overridden by the user.

Refer to [Operators](./Lexing/Operators.md) for more information.

### Keyword

A sequence of characters that denotes a functionality.

Refer to [Keywords](./Lexing/Keywords.md) for a list of keywords, their intended function and usage.
