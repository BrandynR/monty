#include "monty.h"

/**
 * get_ops - checks for opcode & its function,executes
 * @ops: inputted opcode
 * @stack: pointer to the stack
 * @line_count: line number of opcode from user
 * Return: 0 on success, 1 on failure
 */
int get_ops(char *ops, stack_t **stack, unsigned int line_count, char *tok_str)
{
    int count;

    instruction_t op_codes[] = {
        {"push", push}
        {"pall", pall},
        {"pint", pint},
        {"pchar", pchar},
        {"pstr", pstr},
        {"pop", pop},
        {"swap", swap},
        {"nop", nop},
        {"add", _add},
        {"sub", _sub},
        {"mul", _mul},
        {"div", _div},
        {"mod", _mod},
        {NULL, NULL}
    };

    for (count = 0; op_codes[i].ops != NULL; count++)
    {
        if (strcmp(ops, "push") == 0)
        {
            tok_str = strtok(NULL, DLIMIT);
            push(&stack, line_count, tok_str);
        }
        else if (strcmp(ops, opcodes[i].ops) == 0)
        {
            (op_codes[i].f)(stack, line_count);
            return (EXIT_SUCCESS);
        }
    }
    printf("L%d: unknown instruction %s\n", line_count, ops);
    exit(EXIT_FAILURE);
}
