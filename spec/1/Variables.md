# Variables
Variables in Locke are statically typed.

A variable is denoted by the keyword `var`.

The modifiers a variable may have are:

* Access modifiers but only if it is a property of a type.

* `const`, makes the variable constant. It cannot be modified after being set if this modifier is present.

The variable must also have an identifier (see [Naming](./Naming.md)), which should be placed after the `var` keyword.

After the identifier, the variable can be given an explicit type or have an inferred type.

To give a variable an explicit type, add `:T` after the identifier, where T is the type. It is recommended to add spaces to it for readability (`: T`)

Next, declaring its value is done by `=val`. Once again, spaces are optional but recommended (`= val`).

## Examples
* No type inferring `var x: int = 3`
* Constant `const var x = 93.2` 