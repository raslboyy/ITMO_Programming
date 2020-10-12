#include <stdio.h>
#include <locale.h>

enum Print_edition {
    BOOK = 1,
    MAGAZINE,
    NEWSPAPER
};

struct Triangle {
    int a;
    int b;
    int c;
};

struct Triangle create_triangle(int a, int b, int c) {
    struct Triangle res = {a, b, c};
    return res;
}

int get_perimeter(struct Triangle *triangle) {
    return triangle->a + triangle->b + triangle->c;
}

union Condition {
    unsigned number;
    struct {
        unsigned included: 1;
        unsigned sd_card_active: 1;
        unsigned compact_flash_card_active: 1;
        unsigned MemoyStick_card_active: 1;
    } byte;
};

int main() {

    enum Print_edition print_edition;
    print_edition = NEWSPAPER;
    printf("newspaper = %d\n", print_edition);

    struct Triangle triangle = create_triangle(3, 4, 5);
    printf("the perimeter of a triangle with sides %d, %d, %d is %d\n", triangle.a, triangle.b, triangle.c,
           get_perimeter(&triangle));

    union Condition condition;
    scanf("%x", &condition.number);
    printf("%d\n%d\n%d\n%d\n", condition.byte.included, condition.byte.sd_card_active, condition.byte.compact_flash_card_active, condition.byte.MemoyStick_card_active);


    return 0;
}
