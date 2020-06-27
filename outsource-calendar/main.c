#include <stdio.h>

int weekIndex(int y, int m, int d) {
    // Zeller's congruence
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int c = y / 100;
    y %= 100;
    int w = y + y / 4 + c / 4 - 2 * c + (26 * (m + 1)) / 10 + d - 1;
    return (w % 7 + 7) % 7;
}

char *getDayOfWeek(int index) {
    static char *str[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    return str[index];
}

int isLeap(int y) {
    return ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0;
}

int daysOfMonth(int y, int m) {
    if (m == 2)
        return isLeap(y) ? 29 : 28;
    return (m & 1) ^ (m > 7) ? 31 : 30;
}

void printDay(int y, int m, int d) {
    printf("%04d-%02d-%02d: %s\n", y, m, d, getDayOfWeek(weekIndex(y, m, d)));
}

void printMonth(int y, int m) {
    for (int i = 0; i < 7; i++)
        printf("%10s", getDayOfWeek(i));
    putchar('\n');

    int days = daysOfMonth(y, m);
    int weekindex = weekIndex(y, m, 1);
    int d = 1;

    // print space
    for (int i = 0; i < weekindex; i++)
        printf("%10s", "");

    for (; d <= days; d++, weekindex = (weekindex + 1) % 7) {
        printf("%10d", d);
        if (weekindex == 6)
            putchar('\n');
    }
    if (weekindex != 0) putchar('\n');
}

void printYear(int y) {
    for (int i = 1; i <= 12; i++) {
        printf("%d:\n", i);
        printMonth(y, i);
        putchar('\n');
    }
}

int main() {
    puts("Calendar");
    puts("  1. Year");
    puts("  2. Month");
    puts("  3. Day");
    printf("> ");
    int sel, y, m, d;
    scanf("%d", &sel);
    switch (sel) {
    case 1:
        printf("Input year: ");
        scanf("%d", &y);
        printYear(y);
        break;
    case 2:
        printf("Input year: ");
        scanf("%d", &y);
        printf("Input month: ");
        scanf("%d", &m);
        printMonth(y, m);
        break;
    case 3:
        printf("Input year: ");
        scanf("%d", &y);
        printf("Input month: ");
        scanf("%d", &m);
        printf("Input day: ");
        scanf("%d", &d);
        printDay(y, m, d);
        break;
    default:
        puts("Error Selection");
        break;
    }
}
