---
parent: Specification
---

# Naming

Identifiers must conform to a certain standard. This file describes what counts as a valid identifier.

This document also describes the preferred naming conventions so that all code can follow the same naming standard.

## Valid identifiers

A valid identifier must conform to these rules:

- The first character must be a valid character in the Unicode "Letter" category, or an allowed special character.

- All characters proceeding this must be a valid character in the Unicode "Letter" category, an allowed special character or a digit.

Allowed special characters are `_`, `$`, and `@`.

## Naming convention

The naming convention of Locke is as follows:

- Variables are camel case (`variableName`).

- Type names are pascal case (`TypeName`).

- Function names are camel case (`functionName`).

- Namespaces are lowercase (`lowercase.namespace`).
