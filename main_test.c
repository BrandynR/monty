#include "monty.h"
/**
  * main - Monty bytecode interpreter.
  * @argc: number of argments.
  * @argv: pointer to array of arguments(strings).
  * Return: 0, -1 if fails.
  */
int main(int argc, char *argv[])
{
    FILE *fd;
    char *buff = NULL, *ops, *tok_str;
    stack_t *stack = NULL;
    size_t length = 0;
    ssize_t read;
    unsigned int line_count;

    /* verify argument count */
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    /* Open file to be read */
    fd = fopen(argv[1], "r");
    /* Check for NULL */
    if (fd == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /*  Testing inside for loop, Initialize line # count 
    line_count = 0;
    */
    /* Read line from stream, allocate buffer */
    for (line_count = 0; (read = getline(&buff, &length, fd)) != -1; line_count++)
    {
        /* Set variable to tokenized string */
        ops = strtok(buff, DLIMIT);
        /* Check for NULL & comments */
        if (strncmp(ops, "#", 1) == 0 || ops == NULL)
            continue;
        get_ops(ops, &stack, line_count, tok_str);
    /* Handle memory */
    free_func_to_be_created(stack, line, fd);
    return (EXIT_SUCCESS);
}
