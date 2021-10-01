#include<stdio.h>
#include"STD_TYPES.h"
#include"Clinic.h"

s32 main()
{   
    while(1)
	{	
	    u8 mood;
	    printf("Choosing Mood :\nFor Admin mode Enter 1\nFor User mode Enter 0\n");	
	    scanf("%d",&mood);
	    if(mood == 1)
     	{
	    	u8 counter = 1;
		    u16 password;
		    printf("Enter the password : ");
		    scanf("%d",&password);
		    while(password != 1234 && counter != 3) 
		    {
			    counter++;
			    printf("Sorry , Incorrect password pleas try again : ");
			    scanf("%d",&password);
		    }
		    if(password == 1234 && counter <= 3)
	        {
			    u8 operation;
				printf("***************************************\n");
		     	printf("Welcome sir , Admin mode is enabled\n");
				printf("***************************************\n");
		    	printf("TO Add new patient record : Enter 1\n");
	        	printf("To Edit patient record : Enter 2\n");
		        printf("To Reserve a slot with the doctor : Enter 3\n");
		        printf("To Cancel reservation : Enter 4\n");
		        scanf("%d",&operation);
			    switch(operation)
			    {   
                    case 1 :
                    /* Add new patient.*/
				    Add();
                    break; 				
			        case 2 :
				    /* Edit information of a patient.*/
				    Edit();
				    break;
			        case 3 :
                    /* Reserve a slot with the doctor.*/
			    	Reserve();
                    break;  				
			        case 4 :
				    /* Cancel an confirmed slot.*/
				    Cancel();
                    break;
                    default :
				    printf("Invalid operation\n");
			    }
		    }
		    else
	     	{
		    	printf("Sorry,too many attempts\n");  	/* Number of attempts more than 3 */
		    }
	    }
        else if(mood == 0) /* User mood.*/
	    {
		    u8 operation , ID;
			printf("***************************************\n");
		    printf("Welcome sir , User mode is enabled\n");
			printf("***************************************\n");
		    printf("To view patient record : Enter 1\n");
		    printf("To view today reservations : Enter 2 \n");
		    scanf("%d",&operation);
		    if(operation == 1)
		    {
			    /* View patient record.*/
                patient_record();  	/* Display the record of the patient.*/		
		    }
	       	else if(operation == 2)
		    {
			    /*Display the reservation of the patient attached to ID.*/
			    today_reservation();
		    }
	      	else
		    {
			    printf("Invalid operation\n"); 
		    }
	    }
	    else
	    {
		    printf("Invalid mode"); 
	    }
    }
}	