#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add();
void del();
void backup();
int main()
{
	
	int next=1;
	char option;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf("\n\t*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
	printf("\n\t*** This system is developed by CCIT4020 class No. CL-06 Group No.___ ***\n");
	while (next!=0)
	{
	printf("\n <---Basic functions--->");
	printf("\n 1. Add New movie Ticketing Record(s):");
	printf("\n 2. Display All Movie Ticketing Records:");	             
	printf("\n 3. Modify Movie Ticketing Record(s):");	           
	printf("\n 4. Search Movie Ticketing Record(s):");	          
	printf("\n 5. Delete Movie Ticketing Record(s):");	
	printf("\nWhat is your option (1-5)? [q for quit]");
	printf("\nMy Option: ");
	fflush(stdin);
	scanf("%c",&option);	//getting option from user
	
	switch(option)
	{

		case '5':
			del(); 
			break;
		case '6':
			backup();
			break;
		case 'Q': case 'q':
			printf("Exiting system...");
			next=0;
			break;
		default:
			printf("Invaild input!");
			break;
	}
	}
	

		
	return 0;
}
void del()
{
	char ch[40],con,n,next=1;
	int del, delno,i;	
	FILE *infile, *outfile, *outfile2;
	while(next!=0)
	{
	infile = fopen("movie.txt","r");
	outfile = fopen("del.txt","w");
	outfile2 = fopen("deleted_record.txt","a");
	
	if (infile == NULL)  /*check the file is exist or not*/
	{
		printf("\nFile Lost!!! ");
		printf("\nPlease find administrator to help you fix the problem");
		exit(1);
	}

	
    printf("Please enter the movie booking number that you want to delete<1001-1050>:"); /*ask for input the record that needed for delete*/
    scanf("%d",&del);
    while(del<1000 && del>1050)  /*input check*/
    {
    	printf("invaid movie booking number, please type again<1001-1050>:");
    	fflush(stdin);
    	scanf("%d",&del);   /*retype if invalid*/
	}
	delno = (del-1000)*10 - 10;	
		for(i=0;i<delno;i++)
			{	
			fgets(ch,40,infile);
		fputs(ch, outfile);
			}		
/**/
		for(i=0;i<9;i++)
		{
		fgets(ch,40,infile);
		fputs(ch, outfile2);
		fputs("-deleted-\n",outfile);
		}
/**/
		for(;con != EOF;)
		{
		con=fgetc(infile);
		fputc(con, outfile);
		} 
	fclose(infile);
	fclose(outfile);
    fclose(outfile2);

		
		printf("Are you confirm to delete the record?<y or n>:");
	    fflush(stdin);
		scanf("%c",&n);
		do{
		switch(n)
		{
		 case 'y' : 
		 case 'Y' :
            remove("movie.txt");
	        rename("del.txt","movie.txt");
	        break;
			 
		case 'n' :
		case 'N' :
		     break;
		     
		default :
		     printf("invalid input");
	         printf("\nAre you confirm to delete the record?<y or n>:");
	    	 fflush(stdin);
	    	 scanf("%c",&n);
	    	 break;
		}
	}while(0);
	
		printf("Do you want to remove another customer's movie ticket booking record?<y or n>:");
		fflush(stdin);
		scanf("%c",&n);
		do{
		
		switch(n)
		{
			case 'y' :
			case 'Y' :
				next = 1;
				break;
			case 'n' :
		    case 'N' :
		    	next = 0;
		    	break;
		    default :
		    	printf("invalid input");
		    	printf("\nDo you want to remove another customer's movie ticket booking record?<y or n>:");
		        fflush(stdin);
				scanf("%c",&n);
				break;
		}
	}while(0);
		
		  }
		  return;
		  }
