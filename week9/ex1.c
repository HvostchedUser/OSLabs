
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct frame {
    int page;
    int count;
} frame;


int main() {
    int frames;
    printf("Enter the amount of frames: ");
    scanf("%d", &frames);

    FILE *file = fopen("my_input.txt", "r");

    frame* mem = malloc(frames * sizeof(frame));

    for (int i = 0; i < frames; i++) {
        frame fram;
        fram.page = -1;
        fram.count = 0;
        mem[i] = fram;
    }

    int requested;
    unsigned int hits = 0;
    unsigned int misses = 0;
    
    while (fscanf(file, "%d", &requested) == 1) {
        int found = 0;
        for (int i = 0; i < frames; ++i) {
            if (mem[i].page == requested) {
                found = 1;
                mem[i].count = mem[i].count |= 1 << 1;
            } else {
                mem[i].count >>= 1;
            }
        }
        
        if (found == 0) {
            struct frame *pmin = &mem[0];
            if (pmin->count != -1) {
                for (int i = 1; i < frames; ++i) {
                    if (mem[i].page == -1) {
                        pmin = &mem[i];
                        break;
                    }
                    if (mem[i].count < pmin->count) {
                        pmin = &mem[i];
                    }
                }
            }
            pmin->page = requested;
            pmin->count = 1 << 1;
        }
        if (found)
          hits++;
        else
          misses++;
    }

    printf("Hit amount:\t%d\n", hits);
    printf("Miss amount:\t%d\n", misses);
    printf("Hit/Miss:\t%f\n", (float) hits / (float) misses);

}
