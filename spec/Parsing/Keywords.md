---
parent: Parsing
grand_parent: Specification
---

# Keywords

**Note** these values may be used as templates in definitions:

| Identifier   | Description/template                                         |
| ------------ | ------------------------------------------------------------ |
| `identifier` | An [identifier token](../Lexing.md#Identifier)               |
| `mods`       | One or multiple modifier keywords. Different uses have different rules on what keywords can be used. |
|              |                                                              |

## Declaration keywords

Declaration keywords are keywords that are intended to be used for declaring functions, variables and alike.

### `function`

Declares a function. See [Functions](../Functions.md) for more information.

### `var`

Declares a variable or property. See [Variables](../Variables.md) for more information.

## Access modifiers

### `public`

Makes a given property or function accessible for usage outside of the current file or class.

### `private`

Makes a given property or function private inaccessible outside of the current file or class.

### `protected`

Makes a given property or function inaccesible outside of the current class or subclasses.

### `static`

Makes a given property or function accessible outside of class instances.

## Execution modifiers

### `async`

Declares a function asynchronous.

### `sync`

Declares a function synchronous. This is implied by default.
