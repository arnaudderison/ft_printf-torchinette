#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
//#include "libft/include/libft.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void test_printf(const char *test_name, const char *format, ...) {
    va_list args1, args2;
    int ret1, ret2;
    char buffer1[1024];
    
    va_start(args1, format);
    ret1 = vsnprintf(buffer1, sizeof(buffer1), format, args1);
    va_end(args1);
    
    va_start(args2, format);
    ret2 = ft_printf(format, va_arg(args2, void*));
    va_end(args2);
    
    if (ret1 == ret2) {
        printf(GREEN "[OK] %s" RESET "\n", test_name);
    } else {
        printf(RED "[KO] %s" RESET "\n", test_name);
        printf("Expected return: %d\n", ret1);
        printf("Got return: %d\n", ret2);
    }
}

int main(void) {
    printf("=== DÉBUT DES TESTS FT_PRINTF ===\n\n");

    // Test des caractères simples
    test_printf("Test string simple", "Bonjour");
    test_printf("Test caractère", "Char: %c", 'A');
    
    // Test des strings
    test_printf("Test string", "String: %s", "Hello");
    test_printf("Test string NULL", "String NULL: %s", NULL);
    test_printf("Test string vide", "String vide: %s", "");
    
    // Test des nombres
    test_printf("Test nombre positif", "Nombre: %d", 42);
    test_printf("Test nombre négatif", "Nombre: %d", -42);
    test_printf("Test nombre zéro", "Nombre: %d", 0);
    test_printf("Test INT_MAX", "MAX: %d", INT_MAX);
    test_printf("Test INT_MIN", "MIN: %d", INT_MIN);
    
    // Test des hexadécimaux
    test_printf("Test hexa minuscule", "Hexa: %x", 0xabcdef);
    test_printf("Test hexa majuscule", "Hexa: %X", 0xABCDEF);
    test_printf("Test hexa zéro", "Hexa: %x", 0);
    
    // Test des pointeurs
    int var = 42;
    test_printf("Test pointeur", "Pointeur: %p", (void *)&var);
    test_printf("Test pointeur NULL", "Pointeur NULL: %p", NULL);
    
    // Test des pourcentages
    test_printf("Test pourcentage simple 1", "100%%");
    test_printf("Test pourcentage simple 2 ", "100%%c", 'c');
    test_printf("Test pourcentage simple 2 ", "100%%c%%", 'c');
    test_printf("Test pourcentage simple 2 ", "%%%%%%%%%%%%%%%%", 'c');
    

    ft_printf("\nVotre printf ne doit pas segfault pour etre en accord avec les consignes\n");
    ft_printf(NULL);
    ft_printf(GREEN "OK" RESET);
    printf("\n=== FIN DES TESTS ===\n");
    return 0;
}
