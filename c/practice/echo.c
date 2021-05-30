#include <stdio.h>

/* echo: 1st version */
int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1)? " ": "");
    printf("\n");
    return 0;
}

/* echo: 2st version */
int main(int argc, char *argv[])
{
    int i;

    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1)? " ": "");
        //// printf((argc > 1)? "%s ": "%s", *++argv);
    printf("\n");
    return 0;
}
