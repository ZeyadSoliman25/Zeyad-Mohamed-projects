#include <stdio.h>

/* force the compiler to align the structure members with byte */
#pragma pack(4)

// structure A
struct struct_a {
    char c;
    short s;
}struct1;

// structure B
struct struct_b {
    short s;
    char c;
    int i;
}struct2;

// structure C
struct struct_c {
    char c;
    double d;
    int s;
}struct3;

// structure D
struct struct_d {
    double d;
    int s;
    char c;
}struct4;

int main(void)
{
	/* sizeof(char) + 1 (padding) + sizeof(short), 1 + 1 + 2 = 4 bytes. */
    printf("sizeof(struct_a) = %lu\n", sizeof(struct1));

    /* sizeof(short) + sizeof(char) + 1 (padding) + sizeof(int), 2 + 1 + 1 + 4 = 8 bytes. */
    printf("sizeof(struct_b) = %lu\n", sizeof(struct2));

    /* sizeof(char) + padding(3) + sizeof(double) + sizeof(int) = 1 + 3 + 8 + 4 = 16 bytes */
    printf("sizeof(struct_c) = %lu\n", sizeof(struct3));

    /* sizeof(double) + sizeof(int) + sizeof(char) + padding(3) = 8 + 4 + 1 + 3 = 16 bytes */
    printf("sizeof(struct_d) = %lu\n", sizeof(struct4));

    return 0;
}
