---
parent: Specification
---

# Functions

Functions in Locke are pieces of code which can take inputs and give an output.

They can be defined using the `function` keyword.

After the `function` keyword has been added, you add an identifier to it.

The defintion then requires 2 brackets after the identifier. These brackets hold function parameter information.

To define a function parameter, you simply create a variable defintion. If you want multiple parameters, append a comma to the previous parameter.

A sidenote is that a function parameter must have its type explicit.

Next, to define its return type you do as you would do with variables; by using the `:type` syntax. By default, functions return void, that is to say nothing.

After you have defined its return type you add a code block after it.

## Examples

* Simple definition `function doSomething() { Console.println("Done something."); }`
* Slightly more complex definition `function add(var x: int, var y: int): int { return x + y; }`
