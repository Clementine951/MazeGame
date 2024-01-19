#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "choices.h"

struct player {
    int hp;
    bool torch;
    bool map;
    bool litTorch;
    int place;
    int light;      // 1 -> light entrance / 2 -> light art / 3 -> both
    bool treasure;
}player_t;

struct player gamer = {5, false, false, false, 8, 0, false};

struct room {
    int time;
    int losePoint;
    bool torch;
    bool map;
    bool in;
}room_t;

// ***********************************
// Rooms
// struct room dinning         = { 0, 0, false, true, false};     // 1
// struct room corriBot        = { 0, 0, true, false, false};     // 2
struct room start           = { 0, 0, true,  false, true};     // 3
// struct room corriBotRight   = { 0, 0, false, false, false};    // 4
// struct room big             = { 0, 0, false, false, false};    // 5
// struct room corriLeft       = { 0, 0, false, false, false};    // 6
// struct room botWay          = { 0, 0, false, false, false};    // 7
// struct room topWay          = { 0, 2, false, false, false};    // 8
// struct room corriRight      = { 0, 0, false, false, false};    // 9
// struct room corriTop        = { 0, 0, false, false, false};    // 10
// struct room end             = { 0, 1, false, false, false};    // 11
struct room art             = { 0, 0, true, false, false};     // 12


// ***********************************
void dead(void){
    printf("GAME OVER");
    return;
}
// ***********************************


void torch(void){
    if (start.torch == true){       // entrance + torch available
            if (gamer.torch == true){   
                printf("Here is a torch!\n");
                printf("Do you want to lit your torch?\n");
                printf("1. Let's go!\n");
                printf("2. Yeah, no. It's more challenging like that.\n");
                int choice = 0;
                scanf( "%d", &choice );
                switch(choice){
                    case 1:
                        printf("You can finally see in front of your feet. \n");
                        gamer.litTorch = true;
                        // next
                        break;
                    case 2:
                        printf("I mean, why not\n");
                        //next
                        break;
                    default:
                        printf("Impossible choice");
                        break;
                }
            }else{          // no torch
                printf("Niiiice, a torch!\n\n");
                printf("Do you want to take it?\n");
                printf("1. Hell yeah! I want to see.\n");
                printf("2. Hell, no. I want to be discret.\n");
                int choice = 0;
                scanf( "%d", &choice );
                switch(choice){
                    case 1:
                        printf("You can finally see in front of your feet. \n");
                        gamer.torch = true;
                        gamer.litTorch = true;
                        start.torch = false;
                        // next
                        break;
                    case 2:
                        printf("I mean why not. \n");
                        //next 
                        break;
                    default:
                        printf("Impossible choice. ");
                        break;
                }
            }
    }else{
        printf("Yeah, that's the place where I get the torch\n");
    }

}