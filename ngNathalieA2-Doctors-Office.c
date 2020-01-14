//Nathalie Ng
//nng01@uoguelph.com
//March 5th, 2018
#include <stdio.h>
#include <string.h>
int main(){
    int choice;
    int patChoice;
    int day=5;
    int time;
    int userInput;
    int j=6;
    int i; //row
    int k; //column
    int schedule[day][j];
    int staffChoice;
    int monAvail=0;
    int tuesAvail=0;
    int wedAvail=0;
    int thurAvail=0;
    int friAvail=0;
    int tenAvail=0;
    int elevenAvail=0;
    int twelveAvail=0;
    int oneAvail=0;
    int twoAvail=0;
    int threeAvail=0;
    int sumAvail3=0;
    char timeSlot[30];
    char daySlot[30];
    char daySlotMon[7]="Monday";
    char daySlotTue[8]="Tuesday";
    char daySlotWed[9]="Wednsday";
    char daySlotThu[9]="Thursday";
    char daySlotFri[7]="Friday";
    int assignMon;
    int assignTue;
    int assignWed;
    int assignThu;
    int assignFri;
    char tenSlot[8]="10-11AM";
    char elevenSlot[10]="11-12NOON";
    char twelveSlot[7]="12-1PM";
    char oneSlot[6]="1-2PM";
    char twoSlot[6]="2-3PM";
    char threeSlot[6]="3-4PM";
    int assign11;
    int assign12;
    int assign1;
    int assign2;
    int assign3;
    int assign10;
    int maxNumDay;
    int maxNumTime;
    
    
    //start up schedule
    for(i=0;i<5;i++){
        for(k=0;k<6;k++){
            schedule[i][k] = 1;
        }
    }
    
    //start up message, first question
    userInput=3;
    //loop to take patient back to main menu after making an appointment
    while(userInput!=2){
        printf("******Welcome to Dr.E. Musks's Office******\n\n");
        printf("Are you a\n\n");
        printf("1. Patient \n2. Staff\n\n");
    
        //loop to keep asking for choice for first question
        userInput = 1;
        while(userInput!=0){
            printf("Please enter choice here (1 for patient 2 for staff)? ");
            scanf("%d", &choice);
            if(choice ==1 || choice==2){
                userInput = 0;
            }
        }
    
        printf("\n");

        if(choice==1){
        //if they are a patient
            printf("Welcome. Here are your choices.\n");
            printf("Would you like to\n\n");
            printf("1. Schedule an appointment based on day\n");
            printf("2. Schedule an appointment based on time slot\n\n");
            
            //loop to keep asking for 1 or 2
            userInput = 1;
            while(userInput !=0){
                printf("Enter your choice here (1 or 2): ");
                scanf("%d", &patChoice);
                if(patChoice ==1 || patChoice==2){
                    userInput = 0;
                }
            }
            
            //if they want to book a time slot based on day
            if(patChoice==1){
                userInput = 1;
                while(userInput!=0){
                    printf("Enter the day (1 for Monday, 2 for Tuesday, 3 for Wednesday, 4 for Thursday, 5 for Friday): ");
                    scanf("%d", &day);
                    if(day<=5 && day>0){
                        userInput=0;
                    }
                }
                printf("\n");
                
                if(day==1){
                    printf("Slots available for Monday are:\n\n");
                }
                if(day==2){
                    printf("Slots available for Tuesday are:\n\n");
                }
                if(day==3){
                    printf("Slots available for Wednesday are:\n\n");
                }
                if(day==4){
                    printf("Slots available for Thursday are:\n\n");
                }
                if(day==5){
                    printf("Slots available for Friday are:\n\n");
                }
                
                //find which times have availability for selected day.
                if(schedule[day-1][0]==1){
                    printf("10-11AM\n");
                }
                if(schedule[day-1][1]==1){
                    printf("11-12NOON\n");
                }
                if(schedule[day-1][2]==1){
                    printf("12-1PM\n");
                }
                if(schedule[day-1][3]==1){
                    printf("1-2PM\n");
                }
                if(schedule[day-1][4]==1){
                    printf("2-3PM\n");
                }
                if(schedule[day-1][5]==1){
                    printf("3-4PM\n");
                }
                printf("\n");
                
                userInput=1;
                while(userInput!=0){
                    printf("Enter your preferred time-slot: ");
                    scanf("%s", timeSlot);
                
                    assign10 = strcmp(timeSlot, tenSlot);
                    assign11 = strcmp(timeSlot, elevenSlot);
                    assign12 = strcmp(timeSlot, twelveSlot);
                    assign1 = strcmp(timeSlot, oneSlot);
                    assign2 = strcmp(timeSlot, twoSlot);
                    assign3 = strcmp(timeSlot, threeSlot);
                    //to change schedule availability
                    if(assign10==0){
                        schedule[day-1][0] = 0;
                        userInput=0;
                    }
                    if(assign11==0){
                        schedule[day-1][1] = 0;
                        userInput=0;
                    }
                    if(assign12==0){
                        schedule[day-1][2] = 0;
                        userInput=0;
                    }
                    if(assign1==0){
                        schedule[day-1][3] = 0;
                        userInput=0;
                    }
                    if(assign2==0){
                        schedule[day-1][4] = 0;
                        userInput=0;
                    }
                    if(assign3==0){
                        schedule[day-1][5] = 0;
                        userInput=0;
                    }
                }
                
                printf("\nGreat. Your appointment is booked for ");
                //to print out whichever day they selected
                if(day==1){
                    printf("Monday ");
                }
                if(day==2){
                    printf("Tuesday ");
                }
                if(day==3){
                    printf("Wednesday ");
                }
                if(day==4){
                    printf("Thursday ");
                }
                if(day==5){
                    printf("Friday ");
                }
                printf("for ");
                
                //to print out whichever time they selected
                if(assign10==0){
                    printf("10-11AM.\n\n");
                }
                if(assign11==0){
                    printf("11-12NOON.\n\n");
                }
                if(assign12==0){
                    printf("12-1PM.\n\n");
                }
                if(assign1==0){
                    printf("1-2PM.\n\n");
                }
                if(assign2==0){
                    printf("2-3PM.\n\n");
                }
                if(assign3==0){
                    printf("3-4PM.\n\n");
                }
                
                //goodbye message
                for(int a=0;a<4;a++){
                    for(int b=0;b<=a;b++){
                        printf("*");
                    }
                    for(int c=5;c>a;c--){
                        printf(" ");
                    }
                    for(int d=0;d<41;d++){
                        printf(" ");
                    }
                    for(int e=5;e>a;e--){
                        printf(" ");
                    }
                    for(int f=0; f<=a; f++){
                        printf("*");
                    }
                    printf("\n");
                }
                printf("*****Thank you for visiting Dr.E. Musks's Office*****\n\n");
                
            }
            
        
            //if they pick the second option to book a day based on time
            if(patChoice==2){
                //ask them what time they wanna book
                userInput = 1;
                while(userInput!=0){
                    printf("Enter a time slot(1 for 10-11AM, 2 for 11-12NOON, 3 for 12-1PM, 4 for 1-2PM, 5 for 2-3PM, 6 for 3-4PM): ");
                    scanf("%d", &time);
                    if(time<=6 && time>0){
                        userInput=0;
                    }
                }
                printf("\n");
                if(time==1){
                    printf("Days available for 10-11AM are:\n\n");
                }
                if(time==2){
                    printf("Days available for 11-12NOON are:\n\n");
                }
                if(time==3){
                    printf("Days available for 12-1PM are:\n\n");
                }
                if(time==4){
                    printf("Days available for 1-2PM are:\n\n");
                }
                if(time==5){
                    printf("Days available for 2-3PM are:\n\n");
                }
                if(time==6){
                    printf("Days available for 3-4PM are:\n\n");
                }
                //to print out available days for the selected time
                if(schedule[0][time-1]==1){
                    printf("Monday\n");
                }
                if(schedule[1][time-1]==1){
                    printf("Tuesday\n");
                }
                if(schedule[2][time-1]==1){
                    printf("Wednesday\n");
                }
                if(schedule[3][time-1]==1){
                    printf("Thursday\n");
                }
                if(schedule[4][time-1]==1){
                    printf("Friday\n");
                }
                printf("\n");
                
                userInput = 1;
                while(userInput!=0){
                    printf("Enter your preferred day-slot: ");
                    scanf("%s", daySlot);
                    
                    assignMon = strcmp(daySlot, daySlotMon);
                    assignTue = strcmp(daySlot, daySlotTue);
                    assignWed = strcmp(daySlot, daySlotWed);
                    assignThu = strcmp(daySlot, daySlotThu);
                    assignFri = strcmp(daySlot, daySlotFri);
                    //If the user picks an available slot, it will become unavailable after these if statements
                    if(assignMon==0){
                        schedule[0][time-1] = 0;
                        userInput=0;
                    }
                    if(assignTue==0){
                        schedule[1][time-1] = 0;
                        userInput=0;
                    }
                    if(assignWed==0){
                        schedule[2][time-1] = 0;
                        userInput=0;
                    }
                    if(assignThu==0){
                        schedule[3][time-1] = 0;
                        userInput=0;
                    }
                    if(assignFri==0){
                        schedule[4][time-1] = 0;
                        userInput=0;
                    }
                }
            
                printf("\n\n");
                printf("Great. Your appointment is booked for ");
                //to print what day they booked for
                if(assignMon==0){
                    printf("Monday ");
                }
                if(assignTue==0){
                    printf("Tuesday ");
                }
                if(assignWed==0){
                    printf("Wednesday ");
                }
                if(assignThu==0){
                    printf("Thursday ");
                }
                if(assignFri==0){
                    printf("Friday ");
                }
                printf("for ");
                //to print what time they booked for
                if(time==1){
                    printf("10-11AM.\n\n");
                }
                if(time==2){
                    printf("11-12NOON.\n\n");
                }
                if(time==3){
                    printf("12-1PM.\n\n");
                }
                if(time==4){
                    printf("1-2PM.\n\n");
                }
                if(time==5){
                    printf("2-3PM.\n\n");
                }
                if(time==6){
                    printf("3-4PM.\n\n");
                }
                //goodbye message
                for(int a=0;a<4;a++){
                    for(int b=0;b<=a;b++){
                        printf("*");
                    }
                    for(int c=5;c>a;c--){
                        printf(" ");
                    }
                    for(int d=0;d<41;d++){
                        printf(" ");
                    }
                    for(int e=5;e>a;e--){
                        printf(" ");
                    }
                    for(int f=0; f<=a; f++){
                        printf("*");
                    }
                    printf("\n");
                }
                printf("*****Thank you for visiting Dr.E. Musks's Office*****\n\n");
            }
        }
        if(choice==2){
            userInput=2;
            //if the user picks the staff menu, it will not return to the main menu again
        }
    }
        if(choice==2){
        // if they are staff, start menu
            userInput=0;
            while(userInput!=1){
                
                printf("FOR OFFICE USE ONLY:\n\n");
                printf("CURRENT SCHEDULE IS\n\n");
                printf("    10-11AM 11-12NOON   12-1PM  1-2PM   2-3PM   3-4PM\n");
                printf("Mon     %d      %d          %d        %d      %d      %d\n", schedule[0][0], schedule[0][1], schedule[0][2], schedule[0][3], schedule[0][4], schedule[0][5]);
                printf("Tue     %d      %d          %d        %d      %d      %d\n", schedule[1][0], schedule[1][1], schedule[1][2], schedule[1][3], schedule[1][4], schedule[1][5]);
                printf("Wed     %d      %d          %d        %d      %d      %d\n", schedule[2][0], schedule[2][1], schedule[2][2], schedule[2][3], schedule[2][4], schedule[2][5]);
                printf("Thu     %d      %d          %d        %d      %d      %d\n", schedule[3][0],    schedule[3][1], schedule[3][2], schedule[3][3], schedule[3][4], schedule[3][5]);
                printf("Fri     %d      %d          %d        %d      %d      %d\n", schedule[4][0], schedule[4][1], schedule[4][2], schedule[4][3], schedule[4][4], schedule[4][5]);
                printf("\n");
            
                printf("Please choose one of the following options:\n\n");
                printf("    1. Display the day(s) with maximum number of available spots\n");
                printf("    2. Display the time-slot(s) with maximum number of available spots\n");
                printf("    3. Display how many days have more than 2 available spots\n");
                printf("    4. None of the above - Exit the program\n\n");
         
                userInput = 1;
                while(userInput!=0){
                    printf("Enter your choice here: ");
                    scanf("%d", &staffChoice);
                        if(staffChoice <5 && staffChoice>0){
                            userInput = 0;
                        }
                    printf("\n");
                    
                if(staffChoice == 1){
                    monAvail = 0;
                    tuesAvail=0;
                    wedAvail=0;
                    thurAvail=0;
                    friAvail=0;
                    //loops to determine how many available spots per day
                    for(j=0;j<6;j++){
                        if(schedule[0][j] == 1){
                            monAvail = monAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[1][j] == 1){
                            tuesAvail = tuesAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[2][j] == 1){
                            wedAvail = wedAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[3][j] == 1){
                            thurAvail = thurAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[4][j] == 1){
                            friAvail = friAvail + 1;
                        }
                    }
                    //to determine the day with the greatest number of spots available
                    if(monAvail>=maxNumDay){
                        maxNumDay = monAvail;
                    }
                    if(tuesAvail>=maxNumDay){
                        maxNumDay = tuesAvail;
                    }
                    if(wedAvail>=maxNumDay){
                        maxNumDay = wedAvail;
                    }
                    if(thurAvail>=maxNumDay){
                        maxNumDay = thurAvail;
                    }
                    if(friAvail>=maxNumDay){
                        maxNumDay=friAvail;
                    }
                    
                    printf("Maximum number of available spots: %d\n", maxNumDay);
                    printf("Day(s) with maximum number of available spots are:\n\n");
                    
                    //if statements to print out the days that have the max days available
                    if(monAvail==maxNumDay){
                        printf("Monday\n");
                    }
                    if(tuesAvail==maxNumDay){
                        printf("Tuesday\n");
                    }
                    if(wedAvail==maxNumDay){
                        printf("Wednesday\n");
                    }
                    if(thurAvail==maxNumDay){
                        printf("Thursday\n");
                    }
                    if(friAvail==maxNumDay){
                        printf("Friday\n");
                    }
                    //reinitializing all values to 0
                    monAvail = 0;
                    tuesAvail=0;
                    wedAvail=0;
                    thurAvail=0;
                    friAvail=0;
                    maxNumDay=0;
                    printf("\n");
                }
            
                if(staffChoice == 2){
                    tenAvail=0;
                    elevenAvail=0;
                    twelveAvail=0;
                    oneAvail=0;
                    twoAvail=0;
                    threeAvail=0;
                    maxNumTime=0;
                    //loops for time to determine how many available spots in each time slot
                    for(day=0;day<5;day++){
                        if(schedule[day][0] == 1){
                            tenAvail = tenAvail + 1;
                        }
                    }
                    for(day=0;day<5;day++){
                        if(schedule[day][1] == 1){
                            elevenAvail = elevenAvail + 1;
                        }
                    }
                    for(day=0;day<5;day++){
                        if(schedule[day][2] == 1){
                            twelveAvail = twelveAvail + 1;
                        }
                    }
                    for(day=0;day<5;day++){
                        if(schedule[day][3] == 1){
                            oneAvail = oneAvail + 1;
                        }
                    }
                    for(day=0;day<5;day++){
                        if(schedule[day][4] == 1){
                            twoAvail = twoAvail + 1;
                        }
                    }
                    for(day=0;day<5;day++){
                        if(schedule[day][5] == 1){
                            threeAvail = threeAvail + 1;
                        }
                    }
                    
                    //compare available slots to find greatest number
                    
                    if(tenAvail>=maxNumTime){
                        maxNumTime = tenAvail;
                    }
                    if(elevenAvail>=maxNumTime){
                        maxNumTime = elevenAvail;
                    }
                    if(twelveAvail>=maxNumTime){
                        maxNumTime = twelveAvail;
                    }
                    if(oneAvail>=maxNumTime){
                        maxNumTime = thurAvail;
                    }
                    if(twoAvail>=maxNumTime){
                        maxNumTime = twoAvail;
                    }
                    if(threeAvail>=maxNumTime){
                        maxNumTime = threeAvail;
                    }
                    printf("Maximum number of available spots: %d\n", maxNumTime);
                    printf("Time(s) with maximum number of available spots are:\n\n");
                    //if statements to print out which times have the max number of spots available
                    if(tenAvail==maxNumTime){
                        printf("10-11AM\n");
                    }
                    if(elevenAvail==maxNumTime){
                        printf("11-12NOON\n");
                    }
                    if(twelveAvail==maxNumTime){
                        printf("12-1PM\n");
                    }
                    if(oneAvail==maxNumTime){
                        printf("1-2PM\n");
                    }
                    if(twoAvail==maxNumTime){
                        printf("2-3PM\n");
                    }
                    if(threeAvail==maxNumTime){
                        printf("3-4PM\n");
                        maxNumTime=0;
                    }
                    
                    printf("\n");
                }
                    
                if(staffChoice == 3){
                    monAvail=0;
                    tuesAvail=0;
                    wedAvail=0;
                    thurAvail=0;
                    friAvail=0;
                    //counter to count how many spots available for each day
                    for(j=0;j<6;j++){
                        if(schedule[0][j] == 1){
                            monAvail = monAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[1][j] == 1){
                            tuesAvail = tuesAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[2][j] == 1){
                            wedAvail = wedAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[3][j] == 1){
                            thurAvail = thurAvail + 1;
                        }
                    }
                    for(j=0;j<6;j++){
                        if(schedule[4][j] == 1){
                            friAvail = friAvail + 1;
                        }
                    }
                
                    sumAvail3=0;
                    //if statements to determine the number of days with more than two available spots.
                    if(monAvail>2){
                        sumAvail3 = sumAvail3+1;
                    }
                    if(tuesAvail>2){
                        sumAvail3 = sumAvail3+1;
                    }
                    if(wedAvail>2){
                        sumAvail3 = sumAvail3+1;
                    }
                    if(thurAvail>2){
                        sumAvail3 = sumAvail3+1;
                    }
                    if(friAvail>2){
                        sumAvail3 = sumAvail3+1;
                    }
                    printf("\n");
                    printf("There are currently %d days this week with more than two available spots. They are: \n\n", sumAvail3);
                    //if statements to print what days have more than two available spots.
                    if(monAvail>2){
                        printf("Monday\n");
                    }
                    if(tuesAvail>2){
                        printf("Tuesday\n");
                    }
                    if(wedAvail>2){
                        printf("Wednesday\n");
                    }
                    if(thurAvail>2){
                        printf("Thursday\n");
                    }
                    if(friAvail>2){
                        printf("Friday\n");
                    }
                    printf("\n");
                }
                    
                if(staffChoice == 4){
                    //goodbye message
                    for(int a=0;a<4;a++){
                            for(int b=0;b<=a;b++){
                                printf("*");
                            }
                        for(int c=5;c>a;c--){
                            printf(" ");
                        }
                        for(int d=0;d<41;d++){
                        printf(" ");
                        }
                        for(int e=5;e>a;e--){
                            printf(" ");
                        }
                        for(int f=0; f<=a; f++){
                            printf("*");
                        }
                        printf("\n");
                        }
                        printf("*****Thank you for visiting Dr.E. Musks's Office*****\n");
                }
            }
                if(staffChoice==4){
                    userInput=1;
                    //this will exit the loop for the staff menu.
                }
            }
    }


    return 0;
}

