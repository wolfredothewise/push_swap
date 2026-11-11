*This project has been created as part of the 42 curriculum by vhedo-ga.*

# push_swap

[English](#push_swap) · [Español](#español)

> A 42 project about sorting integers with two stacks using the smallest possible sequence of operations.

![C](https://img.shields.io/badge/language-C-00599C?style=flat-square&logo=c)
![42 Project](https://img.shields.io/badge/42-project-000000?style=flat-square&logo=42)

## Description

`push_swap` receives a sequence of integers in stack **A** and prints a valid sequence of operations that sorts them in ascending order. Stack **B** can be used as auxiliary storage.

The goal is to sort the input with the lowest practical number of operations while respecting the limited instruction set defined by the 42 subject. The project focuses on argument parsing, linked-list based stacks, algorithm design, optimisation, memory management and operation counting.

This implementation uses dedicated routines for small inputs and coordinate compression followed by LSD binary radix sort for larger inputs.

> **Important:** This project was completed in **2025**. The 42 subject, evaluation criteria and toolchain may have changed since then, so this repository may not exactly match the current version. The core exercise and workflow remain almost identical.

## Allowed operations

| Operation | Description |
|---|---|
| `sa` / `sb` | Swap the first two elements of stack A / B |
| `pa` / `pb` | Push the top element from B to A / A to B |
| `ra` / `rb` | Rotate a stack upwards |
| `rr` | Rotate both stacks |
| `rra` / `rrb` | Reverse rotate a stack |
| `rrr` | Reverse rotate both stacks |

## Algorithm

The program validates numeric input, rejects duplicates and values outside the signed 32-bit integer range, then applies coordinate compression so every value receives its rank in sorted order.

- 2 numbers: direct swap
- 3 numbers: dedicated case-based algorithm
- Up to 5 numbers: small-stack strategy using stack B
- Larger inputs: LSD binary radix sort

Radix sort processes each bit of the compressed indexes, moving zero-bit values to B, rotating one-bit values in A, and pushing the values back until A is sorted.

## Instructions

### Requirements

- A C compiler
- `make`
- The included `libft` and `ft_printf` subprojects

### Compilation

```bash
make
```

Useful targets:

```bash
make clean
make fclean
make re
```

### Execution

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

The program prints one operation per line. Invalid input, duplicates and values outside the signed 32-bit integer range are rejected.

### Check the result

The repository includes `checker_linux`:

```bash
ARGS="4 67 3 87 23"
./push_swap $ARGS | ./checker_linux $ARGS
```

Expected output:

```text
OK
```

Random test with 100 values:

```bash
ARGS="$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"
./push_swap $ARGS | ./checker_linux $ARGS
```

Count operations:

```bash
./push_swap $ARGS | wc -l
```

## Project structure

```text
.
├── includes/push_swap.h
├── src/                   # Parsing, operations and sorting algorithms
├── libft/                 # C library dependency
├── ft_printf/             # Formatted output dependency
├── checker_linux          # Supplied output validator
└── Makefile
```

## Red team mini-lab

This project is also a small exercise in defensive and red-team thinking: command-line input should be treated as untrusted data.

Try authorised local tests such as:

```bash
./push_swap "1 2 nope"
./push_swap "1 1 2"
./push_swap "2147483648"
./push_swap "-2147483649"
./push_swap "+1 -2 3"
```

The objective is to identify weaknesses in input validation, integer conversion, duplicate detection, memory handling and stress behaviour. Only test software and systems that you own or are authorised to assess.

## Resources

- [42 push_swap guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [Radix sort explanation](https://www.youtube.com/watch?v=Nz1KZXbghj8)
- [Stacks in C](https://www.geeksforgeeks.org/c/implement-stack-in-c/)

### AI usage

AI was used as a study and review aid, not as a replacement for understanding or testing the implementation. It helped with:

- Organising the project structure and breaking the problem into parsing, stack operations and sorting stages.
- Explaining linked lists, stack behaviour, coordinate compression and binary radix sort.
- Reviewing edge cases such as malformed arguments, duplicate values, integer limits and already sorted input.
- Improving documentation and suggesting manual test cases.

The final algorithm choices, integration, compilation and validation were performed and reviewed by the project author.

---

## Español

`push_swap` recibe una secuencia de enteros en la pila **A** y muestra una secuencia válida de operaciones para ordenarla de menor a mayor. La pila **B** se utiliza como almacenamiento auxiliar.

### Descripción

El objetivo es ordenar los valores utilizando el menor número práctico de operaciones y respetando el conjunto limitado de instrucciones del subject de 42. El proyecto utiliza listas enlazadas, parsing de argumentos, gestión de memoria, algoritmos de ordenación y optimización del número de movimientos.

> **Nota importante:** Este proyecto se realizó en **2025**. El subject, los criterios de evaluación y las herramientas de 42 pueden haber cambiado desde entonces, por lo que este repositorio quizá no coincida exactamente con la versión actual. El ejercicio y el flujo principal siguen siendo prácticamente iguales.

### Instrucciones

```bash
make
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Para comprobar el resultado:

```bash
ARGS="4 67 3 87 23"
./push_swap $ARGS | ./checker_linux $ARGS
```

El proyecto utiliza algoritmos específicos para entradas pequeñas y **LSD binary radix sort** con compresión de coordenadas para entradas grandes. También valida valores inválidos, duplicados y límites de enteros.

### Mini apartado de red team

Se pueden probar de forma autorizada entradas inválidas, duplicados, límites numéricos y casos de estrés para detectar fallos en el parser, conversión numérica, gestión de memoria y validación de datos.

### Recursos y uso de IA

Los recursos principales son la guía de 42, documentación sobre radix sort y referencias sobre pilas en C. La IA se utilizó para estudiar conceptos, revisar casos límite, organizar la documentación y proponer pruebas manuales; la implementación final fue integrada y validada por el autor.

[Volver a English](#push_swap)
