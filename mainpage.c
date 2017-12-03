#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	char bookingNo[4]; //String variable to store confirmed Movie Booking Number
	char customerName[30]; //String variable to store confirmed Name of Customer
	char movieName[30]; //String variable to store confirmed Name of Movie
	char movieSchedule[10]; //String variable to store confirmed Movie Schedule
	char time[4]; //String variable to store confirmed Time
	char guestNum[3]; //String variable to store confirmed Number of Guests
	char houseNo[2]; //String variable to store confirmed House Number
	char ticketType[20]; //String variable to store confirmed Ticket Type
	char totalFee[10]; //String variable to store confirmed Total Fee
};

void add();
void display(); 

int main()
{
	char option;
	
	do {
		system("cls");
		
		printf("\n\t*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
		printf("\n\t*** This system is developed by CCIT4020 class No. CL-06 Group E ***\n");
		printf("\n =============== Basic functions ===============\n\n");
		printf("\n 1. Add New movie Ticketing Record(s):\n");
		printf("\n 2. Display All Movie Ticketing Records:\n");	             
		printf("\n 3. Modify Movie Ticketing Record(s):\n");	           
		printf("\n 4. Search Movie Ticketing Record(s):\n");	          
		printf("\n 5. Delete Movie Ticketing Record(s):\n");
		printf("\n =============== =============== ===============\n\n");
		printf("\nWhat is your option (1-5)? [q for quit]");
		printf("\nMy Option: ");
		
		scanf("%c",&option);	//getting option from user
		
		switch(option)
		{
			case '1':
				add();	//Calling method for add record(s)
				break;
			case '2':
				display();	//Calling method for display all record(s)
				break;
			/*case '3':
				modify();
				break;
			case '4':
				search();
				break;
			case '5':
				deleteRecord();
				break;*/
			case 'Q': case 'q':
				printf("Exiting system...");
				exit(1);
				break;
			default:
				printf("Invaild input, please input integer (1-5)");
				break;
		}
	} while(option != 'q' || option != 'Q');
	
	return 0;
}

void add()
{
	char content[30];	//String variable to store user's input
	struct record r;
	
	/* 
	char bookingNo[10]; //String variable to store confirmed Movie Booking Number
	char customerName[30]; //String variable to store confirmed Name of Customer
	char movieName[30]; //String variable to store confirmed Name of Movie
	char movieSchedule[10]; //String variable to store confirmed Movie Schedule
	char time[4]; //String variable to store confirmed Time
	char guestNum[3]; //String variable to store confirmed Number of Guests
	char houseNo[2]; //String variable to store confirmed House Number
	char ticketType[20]; //String variable to store confirmed Ticket Type
	char totalFee[10]; //String variable to store confirmed Total Fee
	*/ 
	char n;	//char for user's answer of add another record
	int next = 1;	//boolean for add another record 1=true 0=false
	int i = 0;
	
	do{
		//printf("\nPlease enter 1)Movie Booking Number, 2)Name of Customer, 3)Name of Movie, 4)Movie Schedule, 5)Time, 6)Number of Guests, 7)House Number, 8)Ticket Type, 9)Total Fee:\n");
		
		//read Movie Booking Number
		printf("\nPlease enter");
		p1: 
		strcpy(content,"");	//reset the string for read input
		printf("\n1)Movie Booking Number: ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content)!=4){
			printf("\nInvalid Input: Invalid Length\n");
			goto p1;
		}
		for(i = 0; i < strlen(content); i++)
		{
			if(!isdigit(content[i])){
				printf("\nInvalid Input: Contain non-digit character\n");
				goto p1;
			}
			if(content[i]==' '){
				printf("\nInvalid Input: Contain space\n");
				goto p1;
			}
		}
		//if input is valid, save it up
		strcpy(r.bookingNo,content);
		printf("bookingNo:");
		puts(r.bookingNo);
		
		//read Name of Customer
		p2: 
		strcpy(content,"");	//reset the string for read input
		printf("\n2)Name of Customer: ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content)>30){
			printf("\nInvalid Input: Invalid Length\n");
			goto p2;
		}
		for(i = 0; i < strlen(content); i++)
		{
			if(!isalpha(content[i]) && content[i] != ' '){
				printf("\nInvalid Input: Contain digit\n");
				goto p2;
			}
		}
		//if input is valid, save it up
		printf("%s\n", content);
		strcpy(r.customerName,content);
		printf("bookingNo:");
		puts(r.bookingNo);
		printf("customerName:");
		puts(r.customerName);
		
		//read Name of Movie
		p3: 
		strcpy(content,"");	//reset the string for read input
		printf("\n3)Name of Movie: ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content)>30){
			printf("\nInvalid Input: Invalid Length\n");
			goto p3;
		}
		//if input is valid, save it up
		strcpy(r.movieName,content);
		printf("movieName:");
		puts(r.movieName);
		
		//read Movie Schedule
		int dd, mm, yy;
		p4:
		strcpy(content,"");	//reset the string for read input
		dd = 0; mm = 0; yy = 0;
		printf("\n4)Movie Schedule(eg.22-01-2017): ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content) > 10){
			printf("\nInvalid Input: too long\n");
			goto p4;
		}
		for(i = 0;i < strlen(content);i++){
			if(!isdigit(content[i]) && content[i] != '-'){
				printf("\nInvalid Input: contains non-digit character\n");
				goto p4;
			}
		}
		sscanf(content, "%d%*c%d%*c%d", &dd, &mm, &yy);
		printf("dd%d mm%d yy%d\n", dd, mm, yy);
		if(mm < 1 || mm > 12){
			printf("\nInvalid Input: month out of range\n");
			goto p4;
		} else if (dd < 1) {
			printf("\nInvalid Input: day too small\n");
			goto p4;
		}
		else if (mm == 2 && dd > 29){
			printf("\nInvalid Input: last day of Feb is 29\n");
			goto p4;
		} else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd > 31){
			printf("\nInvalid Input: last day of big month is 31\n");
			goto p4;
		} else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
			printf("\nInvalid Input: last day of small month is 30\n");
			goto p4;
		} else if (yy < 1 || yy > 9999){
			printf("\nInvalid Input: year out of range\n");
			goto p4;
		}
		//if input is valid, save it up
		strcpy(r.movieSchedule,content);
		printf("movieSchedule:");
		puts(r.movieSchedule);
		
		//read Time
		int t, hr, min;
		p5:
		strcpy(content,"");	//reset the string for read input
		printf("\n5)Time(eg.1945): ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content) > 4){
			printf("\nInvalid Input: Invalid Length\n");
			goto p5;
		}
		for(i = 0; i < strlen(content); i++){
			if(!isdigit(content[i])){
				printf("\nInvalid Input: contains non-digit character\n");
				goto p5;
			}
		}
		sscanf(content, "%d", &t);
		//printf("hr %d min %d", hr, min);
		if(t < 0 || t > 2400){
			printf("\nInvalid Input: not valid time\n");
			goto p5;
		}
		hr = t / 100;
		min = t - (hr*100);
		if(min > 60){
			printf("\nInvalid Input: not valid time (minute)\n");
			goto p5;
		}
		//if input is valid, save it up
		strcpy(r.time,content);
		printf("time:");
		puts(r.time);
		
		//read Number Of Guest
		p6:
		strcpy(content,"");	//reset the string for read input
		printf("\n6)Number Of Guest: ");
		fflush(stdin);
		gets(content);
		//data validation
		for(i = 0; i < strlen(content); i++){
			if(!isdigit(content[i])){
				printf("\nInvalid Input: contains non-digit character\n");
				goto p6;
			}
		}
		sscanf(content,"%d", &i);
		if(i < 1){
			printf("\nInvalid Input: cannot be 0\n");
			goto p6;
		} else if(i > 999){
			printf("\nInvalid Input: value out of range\n");
			goto p6;
		}
		//if input is valid, save it up
		strcpy(r.guestNum,content);
		printf("guestNum:");
		puts(r.guestNum);
		
		//read House Number
		p7:
		strcpy(content,"");	//reset the string for read input
		printf("\n7)House Number: ");
		fflush(stdin);
		gets(content);
		//data validation
		for(i = 0; i < strlen(content); i++){
			if(!isdigit(content[i])){
				printf("\nInvalid Input: contains non-digit character\n");
				goto p7;
			}
		}
		sscanf(content,"%d", &i);
		if(i < 1){
			printf("\nInvalid Input: cannot be 0\n");
			goto p7;
		} else if(i > 99){
			printf("\nInvalid Input: value out of range\n");
			goto p7;
		}
		//if input is valid, save it up
		strcpy(r.houseNo,content);
		printf("houseNo:");
		puts(r.houseNo);
		
		//read Ticket Type
		p8:
		strcpy(content,"");	//reset the string for read input
		printf("\n8)Ticket Type(Adult,Student,Senior and Children): ");
		fflush(stdin);
		gets(content);
		//data validation
		if(strlen(content)>20){
			printf("\nInvalid Input: Invalid Length\n");
			goto p8;
		}
		for(i = 0; i < strlen(content); i++)
		{
			if(!isalpha(content[i])){
				printf("\nInvalid Input: Contain digit\n");
				goto p8;
			}
		}
		//if input is valid, save it up
		strcpy(r.ticketType,content);
		printf("ticketType:");
		puts(r.ticketType);
		
		//read Total Fee
		float l = 0.00;
		p9:
		strcpy(content,"");	//reset the string for read input
		printf("\n9)Total Fee(e.g.140.0): ");
		fflush(stdin);
		gets(content);
		//data validation
		for(i = 0; i < strlen(content); i++){
			if(!isdigit(content[i]) && content[i] != '.'){
				printf("\nInvalid Input: contains non-digit character\n");
				goto p9;
			}
		}
		sscanf(content,"%f", &l);
		if(l < 0.01){
			printf("\nInvalid Input: cannot be 0\n");
			goto p9;
		} else if(l > 9999999.00){
			printf("\nInvalid Input: value out of range\n");
			goto p9;
		}
		//if input is valid, save it up
		strcpy(r.totalFee,content);
		puts(r.totalFee);
		
		FILE *f = fopen("movie.txt", "a");	//opening record.txt for adding record
		
		fprintf(f, "%s\n", r.bookingNo);	//write Movie Booking Number to file
		//fprintf(f, "%s\n", r.customerName);	//write Name of Customer to file
		fprintf(f, "%s\n", r.movieName);	//write Name of Movie to file
		fprintf(f, "%s\n", r.movieSchedule);	//write Movie Schedule to file
		fprintf(f, "%s\n", r.time);	//write Time to file
		fprintf(f, "%s\n", r.guestNum);	//write Number of Guest to file
		fprintf(f, "%s\n", r.houseNo);	//writeHouse Number to file
		fprintf(f, "%s\n", r.ticketType);	//write Ticket Type to file
		fprintf(f, "%s\n\n", r.totalFee);	//write Total Fee to file & add emtpy line at end of record
		
		fclose(f);
		
		printf("\nAdd another record(y/n): ");	//ask do user want to add another record
		scanf("%c",&n);
		if(n=='n'){
			next = 0;	//if not, quit the while-loop
		}
	}while(next == 1);
	
	return;
}

void display()
{
	system("cls");
	struct record r;
	char dataWhole[50]; // array for data inside the saved file 
	
	FILE *f;
	f = fopen("movie.txt", "r");
	printf("\n===================================================\n\n");
	printf("\t\tAll Movie Records\n\n");
	printf("===================================================\n\n");
	// start file checking 
	if (f == NULL)
	{
		printf("\nFile does not exist");
		printf("\nFile was not succesfully opened\n");
		exit(1);			//resides in stdlib.h
	}
	// end file checking 
	printf("File was succesfully opened!\n\n");
	// start reading the file
	while(1){
		fscanf(f, "%s\n", &r.bookingNo);	//read Movie Booking Number to file
		//fprintf(f, "%s\n", r.customerName);	//read Name of Customer to file
		fscanf(f, "%s\n", &r.movieName);	//read Name of Movie to file
		fscanf(f, "%s\n", &r.movieSchedule);	//read Movie Schedule to file
		fscanf(f, "%s\n", &r.time);	//read Time to file
		fscanf(f, "%s\n", &r.guestNum);	//read Number of Guest to file
		fscanf(f, "%s\n", &r.houseNo);	//read House Number to file
		fscanf(f, "%s\n", &r.ticketType);	//read Ticket Type to file
		fscanf(f, "%s\n\n", &r.totalFee);	//read Total Fee to file & add emtpy line at end of record
		
		printf("___________________________");
		printf( "\nMovie booking Number: %s\n", r.bookingNo);	
		printf( "Name of Movie: %s\n", r.movieName);	
		printf( "Movie Schedule: %s\n", r.movieSchedule);	
		printf( "Time: %s\n", r.time);	
		printf( "Name of Guest: %s\n", r.guestNum);
		printf( "House Number: %s\n", r.houseNo);	
		printf("Ticket Type: %s\n", r.ticketType);	
		printf( "Total Fee: %s\n\n", r.totalFee);	
		
		
		if(feof(f)){
			break;
		}
	}
	
	printf("\nPress any key to back to main menu...\n");
	getch();
	
	return;
}

/*
void modify()
{
	
}

void search()
{
	
}

void deleteRecord()	//delete is constrution word of C language, so we need to use a different method name
{
	
}
*/

