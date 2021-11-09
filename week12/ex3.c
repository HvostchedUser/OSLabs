
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

int main() {
  
    printf("The shortcuts: h+e, p+e, c+a+p");
    struct input_event events[1000];
    int pehotkeys=0;
    int caphotkeys=0;
    int hehotkeys=0;
  
    while (1) {
        int val = read(open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY), events, sizeof(events));
        for (int i = 0; i < (int) (val / sizeof(struct input_event)); i++) {
            if (events[i].type == EV_KEY){
              if (events[i].value == 1) {
                  printf("PRESS 0x%x (%d)\n", events[i].code, events[i].code);
                  if (events[i].code==18||events[i].code==35){
                    hehotkeys+=1;
                  }
                  if (events[i].code==25||events[i].code==18){
                    pehotkeys+=1;
                  }
                  if (events[i].code==46||events[i].code==30||events[i].code==25){
                    caphotkeys+=1;
                  }
              } else if (events[i].value == 0){
                  printf("RELEASE 0x%x (%d)\n", events[i].code, events[i].code);
                  if (events[i].code==18||events[i].code==35){
                    hehotkeys-=1;
                  }
                  if (events[i].code==25||events[i].code==18){
                    pehotkeys-=1;
                  }
                  if (events[i].code==46||events[i].code==30||events[i].code==25){
                    caphotkeys-=1;
                  }
              }
            }
        }
        if (pehotkeys<0){
          pehotkeys=0;
        }
        if (caphotkeys<0){
          caphotkeys=0;
        }
        if (hehotkeys<0){
          hehotkeys=0;
        }
        if (hehotkeys>=2){
          printf("Hello world!\n");
          pehotkeys=0;
        }
        if (pehotkeys>=2){
          printf("I passed the Exam!\n");
          pehotkeys=0;
        }
        if (caphotkeys>=3){
          printf("Get some cappuccino!\n");
          caphotkeys=0;
        }
    }
    return 0;
}
