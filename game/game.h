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
void good(void){
    return;
}
// ***********************************


void torch(void){
    if (gamer.torch == false){   
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
                break;
            case 2:
                printf("I mean, why not\n");
                break;
            default:
                torch();
                break;
        }
    }
}