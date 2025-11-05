/*
 * Lotto 6/49 Ticket Generator
 *
 * Generates random Lotto 6/49 tickets with 6 unique numbers from 1 to 49.
 * Numbers are sorted in ascending order and formatted with leading zeros.
 *
 * Usage:
 *   ./lotto649           // Generates 5 tickets by default
 *   ./lotto649 <count>   // Generates <count> tickets (e.g., ./lotto649 10)
 *
 * Example output:
 *   06 09 14 25 32 45
 *   01 07 18 22 33 49
 *
 * Notes:
 * - Each ticket contains 6 distinct numbers.
 * - Numbers are displayed in ascending order.
 * - Leading zeros are added for numbers < 10.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS_PER_TICKET 6
#define MAX_NUMBER 49

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Generate one ticket
void generate_ticket() {
    int numbers[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the array
    for (int i = MAX_NUMBER - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Take the first 6 and sort them
    int ticket[NUMBERS_PER_TICKET];
    for (int i = 0; i < NUMBERS_PER_TICKET; i++) {
        ticket[i] = numbers[i];
    }
    qsort(ticket, NUMBERS_PER_TICKET, sizeof(int), compare);

    // Print formatted ticket
    for (int i = 0; i < NUMBERS_PER_TICKET; i++) {
        printf("%02d ", ticket[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int count = 5;
    if (argc > 1) {
        count = atoi(argv[1]);
        if (count <= 0) {
            fprintf(stderr, "Invalid ticket count. Must be a positive integer.\n");
            return 1;
        }
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; i++) {
        generate_ticket();
    }

    return 0;
}
