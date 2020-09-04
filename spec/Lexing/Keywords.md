---
parent: Lexing
grand_parent: Specification
---

# Keywords

**Note** these values may be used as templates in definitions:

| Identifier   | Description/template                                         |
| ------------ | ------------------------------------------------------------ |
| `identifier` | An [identifier token](../Lexing.md#Identifier)               |
| `mods`       | One or multiple modifier keywords. Different uses have different rules on what keywords can be used. |
|              |                                                              |

## Functions

Function keywords are keywords that are intended to be used for function definitions.

### **`function`**

Defines a function. Can be used within any scope.

Definition:

```locke
[mods] function <identifier>(<arg>[, <arg>...]) [returns <typename>] { <code> }
```

Valid modifiers are:

| Modifier(s)         | Reference                                   | Other notes                                                  |
| ------------------- | ------------------------------------------- | ------------------------------------------------------------ |
| Access modifiers    | [Access modifiers](#Access_modifiers)       | For global functions (i.e. those declared outside of a class), `static`. By default, all functions are public. |
| Execution modifiers | [Execution modifiers](#Execution_modifiers) |                                                              |
|                     |                                             |                                                              |

## Access modifiers

### `static`

## Execution modifiers
