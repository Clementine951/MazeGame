void decision(int choice);
void menu(void);
void runWalk(void);
void torch(void);
void drop(void);
void choiceBotLeft(void);
void choiceLeft(void);
void entrance(void);
void firstChoice(void);
void openDoor(void);
void choiceMidLeft(void);
void dinningRoom(void);
void explore(void);
void dinLeft(void);
void mapFollow(void);
void choiceBotRight(void);
void leftCorri(void);
void bigRoom(void);
void entranceRight(void);
void rightCorri(void);
void bigExplore(void);
void theEnd(void);
void endEnd(void);
void topRight(void);
void toArt(void);
void artRoom(void);
void botPath(void);
void outSeven(void);
void deathDebris(void);
void outWay(void);
void MidLeft(void);
void topPath(void);



void runWalk(void){             // go to the light run or walk
    printf("But, would you like to run to the light source or go carefully?\n");
    printf("1. Run\n");
    printf("2. Walk carefully\n");
    gamer.place = 3;
    int choice = 0;
    scanf( "%d", &choice );

    switch(choice){
        case 1:
            drop();
            torch();
            break;
        case 2:
            printf("This was a safe choice, you avoid a root on the ground.\n");
            torch();
            choiceLeft();
            break;
        default:
            printf("Impossible choice");
            runWalk();
            break;
    }
}


void drop(void){            // When you run + founf torch
    printf("That was a bad idea to run while you can't see the floor.\n");
    printf("You trip over a root.\n");
    printf("You just lost 1 health point out of %d.\n", gamer.hp);
    gamer.hp--;
    if (gamer.hp <= 0){
        dead();
    }
    printf("You have now only %d health points.\n", gamer.hp);
    printf("\n");
    printf("But, you finally reach the light source.\n");
    gamer.place = 3;
    torch();
    choiceLeft();
}

void choiceLeft(void){
    
    printf("\n Now, what do you want to do?\n");
    printf("1. Go back to where you were?\n");
    printf("2. Continue in this way?\n");

    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            choiceBotLeft();
            break;
        case 2:
            choiceMidLeft();        
            break;
        default:
            printf("\nImpossible choice\n");
            choiceLeft();
            break;
    }
}

void choiceBotLeft(void){
    gamer.place = 2;
    printf("You are at the start of a long corridor with the previous closed door in your right.\n You can:\n");
    printf("1. Go to the door and try to open it\n");
    printf("2. Continue to see what's in the corridor\n");
    printf("3. Try the other corridor\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            openDoor();
            break;
        case 2:
            leftCorri();
            break;
        default:
            printf("\nImpossible choice\n");
            choiceBotLeft();
            break;
    }
}

void leftCorri(void){ // from 2 to 4
    printf("You are now at a turning point\n");
    printf("What do you want to do?\n");
    printf("1. The room in front of you \n");
    printf("2.The corridor in your left\n");
    printf("3.Turn back\n");    
    choiceBotRight();
}

void choiceMidLeft(void){       // at 6 from 2
    if(gamer.torch == true){
        printf("Thanks to the torch, you can see 3 different way\n");
        printf("1. A dinning room on your left\n");
        printf("2. The rest of the corridor\n");
        printf("3. A path on your right, that seems blocked\n");
    }else{
        printf("Thanks to the torch, that you didn't take, you can, approximatly see 3 different way\n");
        printf("1. What looks like a room on your left\n");
        printf("2. The rest of the corridor\n");
        printf("3. A path on your right\n");
    }
    int choice = 0;
    scanf( "%d", &choice);
    gamer.place = 6;
    switch(choice){
        case 1:                     
            dinningRoom();
            break;
        case 2:
            toArt();
            break;
        case 3:
            gamer.place = 7;
            botPath();
            break;
        default:
            printf("\nImpossible choice\n");
            choiceMidLeft();
            break;
    }
}

void toArt(void){       // at 10 from 6 8 or 9
    if (gamer.place == 6){
        printf("At the end of the corridor, you have: \n");
        if (gamer.torch == true){
            printf("1. A room full of painting\n");
            printf("2. Weird, another corridor on your right\n");
            printf("3. Go back\n");
        }else {
            printf("1. A kind of a door in front of you\n");
            printf("2. A path on your right\n");
            printf("3. Go back\n");
        }
    }else if (gamer.place == 8){
        printf("You finally arrived at the of this weird path, you are now at a turning point with: \n");
        if (gamer.torch == true){
            printf("1. A room full of painting to your left\n");
            printf("2. Weird, another corridor on your right\n");
            printf("3. Go back\n");
        }else {
            printf("1. A kind of a door to your left\n");
            printf("2. A path on your right\n");
            printf("3. Go back\n");
        }
    }else if (gamer.place == 9){
        printf("You finally arrived at the of this weird path, you are now at a turning point with: \n");
        if (gamer.torch == true){
            printf("1. A room full of painting to your left\n");
            printf("2. Weird, another corridor on your right\n");
            printf("3. Go back\n");
        }else {
            printf("1. A kind of a door to your left\n");
            printf("2. A path on your right\n");
            printf("3. Go back\n");
        }
    }else {
        printf("don't have the place");
    }
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            artRoom();
            break;
        case 2:
            topRight();
            break;
        case 3:
            if (gamer.place == 6){
                gamer.place = 10;
                choiceMidLeft();
            }else if (gamer.place == 8){
                gamer.place = 10;
                topPath();
            }else if (gamer.place == 9){
                choiceBotRight();
            }
            break;
        default:
            printf("\nImpossible choice\n");
            choiceMidLeft();
            break;
    }
    
}

void artRoom(void){
    gamer.place = 12;
    if (gamer.torch == true){
        printf("This room is full of treasure, like really\n");
        printf("Should you take something from this room?\n");
        printf("1. Heck yeah! And something big\n");
        printf("2. Mmmh yes, but a small thing\n");
        printf("3. Yeah, no, in case I have to run\n");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:
                gamer.treasure = true;
                break;
            case 2:
                gamer.treasure = true;
                break;
            case 3:
                gamer.treasure = false;
                break;
            default:
                artRoom();
                break;
        }
    }else {
        printf("While entering the room, you trip over something\n");
        printf("You lose 2 health points out of %d \n", gamer.hp);
        gamer.hp--;
        gamer.hp--;
        if (gamer.hp <= 0){
            dead();
        }else {
            printf("You have now %d health points left\n", gamer.hp);
            printf("And in bonus, you limp now\n");
        }
        printf("Without light, you can't see anything in here\n");
    }
    printf("There nothing more in this room, what do you want to do?\n");
    printf("1. Explore the room again\n");
    printf("2. The corridor in front of the room\n");
    printf("3. the corridor of the left\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:
            artRoom();
            break;
        case 2:
            gamer.place = 6;
            MidLeft();
            break;
        case 3:
            gamer.place = 10;
            topRight();
            break;
        default:
            artRoom();
            break;
    }
}

void MidLeft(void ){        // 6 from 12
    if (gamer.torch == false){
        printf("You finally can see somthing here thanks to this torch on the wall\n");
        torch();
    }
    printf("What do you want to do now?\n");
    printf("1. Try a weird path of your left\n");
    printf("2. Try the turn in front of you\n");
    printf("3. Try the room on your right\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:
            gamer.place = 7;
            botPath();
            break;
        case 2:
            gamer.place = 2;
            choiceBotLeft();
            break;
        case 3:
            gamer.place = 1;
            dinningRoom();
            break;
        default:
            MidLeft();
            break;
    }
}

void dinningRoom(void){
    gamer.place = 1;
    if(gamer.torch == true){
        printf("It really looks like a dinning room\n");
        printf("Maybe there is someting interesting here\n");
        printf("1. Explore the room\n");
        printf("2. Leave the room\n");
        printf("3. Steel things\n");
    }else {
        printf("It is really dark in here, You can't see anything\n");
        printf("1. Try to explore the room\n");
        printf("2. Leave the room\n");
    }
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            explore();
            break;
        case 2:
            choiceBotRight(); 
            break;
        case 3:
            if (gamer.torch == true){
                gamer.treasure = true; 
            }else {
                choiceMidLeft();
            }
            break;
        default:
            printf("\nImpossible choice\n");
            choiceMidLeft();
            break;
    }
}


void explore(void){
    if (gamer.torch == true){
        printf("The dinning room is full of silverware\n");
        printf("Oh\n Here is a map of a maze!\n");
        printf("What do you want to do?\n");
        printf("1. Follow the map\n");
        printf("2. Leave the room\n");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:                     
                mapFollow();
                break;
            case 2:
                dinLeft();   
                break;
            default:
                explore();
                break;
        }
    }else {
        printf("You really thought you could find something here without light?\n");
        printf("What do you want to do?\n");
        printf("1. Try to explore the room\n");
        printf("2. Leave the room\n");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:                     
                explore();
                break;
            case 2:
                dinLeft();   
                break;
            default:
                explore();
                break;
        }
    }
}

void dinLeft(void){ // at 6 from 1
    if (gamer.torch == true){
        printf("You have now 4 different choice:\n");
        printf("1. Go back to the dinning room\n");
        printf("2. The turn on your right\n");
        printf("3. The corridor on your left\n");
        printf("4. Take the weird path in front of you\n");
    }else{
        printf("You have now 5 different choice:\n");
        printf("1. Go back to the dinning room\n");
        printf("2. The turn on your right\n");
        printf("3. The corridor on your left\n");
        printf("4. Take the weird path in front of you\n");
        printf("5. take the torch\n");
    }
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            dinningRoom();
            break;
        case 2:
            choiceBotLeft();
            break;
        case 3:
            gamer.place = 6;
            toArt();
            break;
        case 4: 
            botPath();
            break;
        default:
            dinLeft();
            break;
    }
}

void botPath(void){
    printf("In front of you you have some debris, that blocks the path\n");
    printf("But, there is a hole in the middle where you can pass\n");
    printf("Do you want to try it?\n");
    printf("1. Let's try\n");
    printf("2. Yeah, no, not for me\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:
            if (gamer.treasure == true){
                deathDebris();
            }else {
                gamer.place = 8;
                outWay();
            }
            break;
        case 2:
            outSeven();
            break;
        default:
            botPath();
            break;
    }
}

void topPath(void){
    printf("In front of you you have some debris, that blocks the path\n");
    printf("But, there is a hole in the middle where you can pass\n");
    printf("Do you want to try it?\n");
    printf("1. Let's try\n");
    printf("2. Yeah, no, not for me\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:
            if (gamer.treasure == true){
                deathDebris();
            }else {
                gamer.place = 7;
                outWay();
            }
            break;
        case 2:
            topRight();
            break;
        default:
            topPath();
            break;
    }
}

void deathDebris(void){
    printf("Do you believe in karma?\n");
    printf("You should have, because you just died because of your booty\n");
    dead();
}

void outWay(void){
    printf("Congratulation, you went through this tiny path\n");
    printf("But you lose 1 health point because you cut your arm\n");
    gamer.hp--;
    printf("You have now %d health points", gamer.hp);
    printf("Anyway, what do you want to do new?");

    if (gamer.place == 8){          // at the top
        printf("You arrived at a turning point\n");
        printf("1. Left \n2. Right");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:
                toArt();
                break;
            case 2:
                choiceBotRight();
            default:
                outWay();
                break;
        }
    }else{
        outSeven();
    }
}

void outSeven(void){    // from 7 to 6  
    gamer.place = 6;
    printf("You are now, in front of a dinning room, \n");
    printf("For my part, I wouldn't eat what's on the table\n");
    printf("1. Let's go to the dinning room\n");
    printf("2. The corridor on your right\n");
    printf("3. The turn on your left\n");
    printf("4. Go back from where you were\n");

    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:
            dinningRoom();
            break;
        case 2:
            choiceBotLeft();
            break;
        case 3:
            toArt();
            break;
        case 4:
            botPath();
            break;
        default:
            outSeven();
            break;
    }
}

void mapFollow(void){
    gamer.place = 4;
    printf("After 5 minutes of following the map, you realise that it's not the map of this maze.\n");
    printf("You are now, even more lost than before");
    printf("...\n");
    printf("What do you want to do?\n");
    printf("\n1. The room in your right\n");
    printf("2. The corridor in front of you\n");
    printf("3. The corridor on your left\n");
    choiceBotRight();
}

void choiceBotRight(void){
    int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:                     
                bigRoom();
                break;
            case 2:
                rightCorri();   
                break;
            case 3:
                entranceRight();
                break;
            default:
                choiceBotRight();
                break;
        }
}
void bigRoom (void){
    printf("This room is a huge mess!\n There are things everywhere\n");
    printf("Do you want to:\n");
    printf("1. Explore the room \n");
    printf("2. Leave the room\n");
    int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:                     
                bigExplore();
                break;
            case 2:
                printf("What do you want to do?\n");
                printf("\n1. Try the room again?\n");
                printf("2. The corridor on your right\n");
                printf("3. The corridor in front of you\n");
                choiceBotRight();   
                break;
            default:
                bigRoom();
                break;
        }
}
void bigExplore(void){
    if (gamer.torch == true){
        printf("While exploring the room, you heard a wind noise\n");
        printf("Should you check from where it came?\n");
        printf("1. Heck yeah\n");
        printf("2. Heck no\n");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
            case 1:                     
                theEnd();
                break;
            case 2:
                printf("What do you want to do?\n");
                printf("\n1. Return to the room\n");
                printf("2. The corridor on your right\n");
                printf("3. The corridor in front of yout\n");
                choiceBotRight();   
                break;
            default:
                bigExplore();
                break;
        }
    }else {
        printf("Shame that you don't have a light, you can't find anything here");
        bigRoom();
    }
}

void theEnd(void){
    printf("The sound came from behind a painting\n");
    printf("Should we look?\n");
    printf("1. Heck yeah\n");
    printf("2. Heck no\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            endEnd();
            break;
        case 2:
            bigExplore();   
            break;
        default:
            theEnd();
            break;
    }
}

void entranceRight(void){
    if (gamer.torch == true){
        printf("I recognise this path\n It's the door from the start!\n");
    }else{
        printf("You can see a light far off, it looks like a good thing\n");
    }
    printf("1. Run to the target\n");
    printf("2. Walk carrfully to the target\n");
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
        case 1:                     
            drop();
            break;
        case 2:
            choiceLeft();   
            break;
        default:
            entranceRight();
            break;
    }
}

void rightCorri(void){
    printf("Yeah, just a long corridor without anything\n");
    if (gamer.torch == true){
        printf("Do you want to do a deeper exploration of this corridor?\n");
        printf("1. Yep\n 2. Nope\n");
        int choice = 0;
        scanf( "%d", &choice);
        switch(choice){
        case 1:                     
            printf("Nothing, sorry\n");
            topRight();
            break;
        case 2:
            topRight();   
            break;
        default:
            rightCorri();
            break;
        }
    } else {
        topRight();
    }
}

void topRight(void){
    printf("You have now three possibilities:\n");
    if (gamer.place == 10){
        printf("1. Go back\n");
        printf("2. Take a weird path \n");
        printf("3. Take the corridor on your right\n");
    }else if (gamer.place == 8){
        printf("1. Take the corridor on your left\n");
        printf("2. Go back \n");
        printf("3. Take the corridor on your right\n");
    }else if (gamer.place == 9){
        printf("1. Take the corridor on your left\n");
        printf("2. Take a weird path on your left \n");
        printf("3. Go back\n");
    }
    int choice = 0;
    scanf( "%d", &choice);
    switch(choice){
    case 1:                     
        toArt();
        break;
    case 2:
        topPath();  
        break;
    case 3:
        printf("What do you want to do?\n");
        printf("\n1. The room in your left\n");
        printf("2. Back from where you came\n");
        printf("3. The corridor on your right\n");
        choiceBotRight();
        break;
    default:
        topRight();
        break;
    }
}

void openDoor(void){            // Try to open to front door
    printf("Oooh...\n...\n...\n");
    printf("Yeah, no, it doesn't work\n");
    firstChoice();
}

void firstChoice(void){        // choice of direction in front of the door
    printf("What do you want to do?\n\n");
    if (gamer.light == false){
        printf("1. To your left, where you can see a light after a turn\n");
    } else if (gamer.light == true){
        printf("1. To your left, where you got your torch\n");
    }
    printf("2. To your right, where you can't a lot of things\n");
    printf("3. Try to open the path\n");
    int choice = 0;
    scanf( "%d", &choice);

    switch(choice){
        case 1:                     // left
            runWalk();
            break;
        case 2:
            leftCorri();
            break;
        case 3:
            openDoor();       // door
            break;
        default:
            printf("\nImpossible choice\n");
            firstChoice();
            break;
    }
}

void endEnd(void){
    printf("While moving the painting, you feel a breeze\n");
    printf("You also start seeing the light of the day\n");
    printf("You are finally out of this maze\n");
    printf("Congratulation, you will not die in this maze!");
    if (gamer.treasure == true){
        printf("You got out with %d health points and some tresure\n", gamer.hp);
    }else {
        printf("You got out with %d health points and no treasure\n", gamer.hp);
    }
}