#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
u8 n  = 5 , number = 1;
typedef struct 
{
	u8 name[50];
	u8 age;
	u8 gender[6];
	u16 ID;
	u8 date;
	
}patient;
patient pat[10] = {{"Ahmed Mohamed" , 45 , "male" ,5555 , 0},
                  {"Assmaa Ebrahiem" , 35 , "female" ,4444, 0}};
u8 *pointer_date[5] =  /*Available reservation.*/
	{ "2 pm to 2:30 pm",
	  "2:30 pm to 3:00 pm",
	  "3:00 pm to 3:30 pm",
	  "4:00 pm to 4:30 pm",
	  "4:30 pm to 5:00"
	};
void Add(void)
{
	u8 i;
	u16 ID;
	printf("Enter the ID of the patient you want to add containing of 4 number : ");
    scanf("%d",&ID);
    for(i = 0 ; i < 10 ; i++)
	{
	    if(ID == pat[i].ID) /*Check if this ID is already exist or not.*/
        {
	        printf("This ID is already exist\n");
            break;
        }
    }
	if(i == 10) /*This ID is available.*/
    {
		number++; /* Increase the number of patients by one.*/
		printf("Enter the name of the patient : ");  
        scanf("%s",&pat[number].name);
	    printf("Enter the age of the patient : ");
     	scanf("%d",&pat[number].age);
   		printf("Enter the gender of the patient : ");
        scanf("%s",&pat[number].gender);
        pat[number].ID = ID;
		printf("The information has added successfully\n");	
	}
}
void Edit() /*Edit patient information.*/
{
	u8 i , flag = 0;
	u16 ID;
	printf("Enter the ID of the patient you want to edit containing of 4 number : ");
	scanf("%d",&ID);
    for(i = 0 ; i <= number ; i++)
	{
	    if(ID == pat[i].ID) /*Check if the required ID is already exist or not.*/
	    {
			flag = 1; 
			/* Edit the information of the patient.*/
		    printf("Enter the new name of the patient you want to edit : ");
			scanf("%s",&pat[i].name); /*get and gets function can be uesd to enter name with spaces.*/
		    printf("Enter the new age of the patient you want to edit : ");
		    scanf("%d",&pat[i].age);
		    printf("Enter the new gender of the patient you want to edit : ");
		    scanf("%s",&pat[i].gender);
		    printf("Enter the new ID of the patient you want to edit containing of 4 number : ");
	        scanf("%d",&pat[i].ID);
			pat[i].date = 0;
		    printf("The information has edited successfully\n");
            break;    					
		}
    }
    if(flag == 0) /*Not able to find the ID.*/
    {
		printf("This ID is not exist\n"); 
	}
}
void Reserve() /*For new reservation.*/
{    	
    u8 i;	 
    u16 ID; 
	printf("The available slots is : \n"); /*Display the available slots.*/
	for (i = 0; i < n ; i++)
	{
		printf("%d : %s\n" , i+1 , pointer_date[i]);
	}
	printf("Enter the ID : "); /*Entry ID must be exist in the system to be able to reserve.*/
    scanf("%d",&ID);
    for(i = 0 ; i <= number ; i++)
	{
	    if(ID == pat[i].ID) /*The ID is exist.*/
		{
			printf("Enter number of the desired slot : "); /*Choose the number of available slot you want.*/
        	scanf("%d",&pat[i].date);
			if(pat[i].date == 1) 
			{
		    	pointer_date[0] = "2 pm to 2:30 pm";
            }
            else if(pat[i].date == 2)
			{
		    	pointer_date[1] = "2:30 pm to 3:00 pm";
            } 
            else if(pat[i].date == 3)
			{
		    	pointer_date[2] =  "3:00 pm to 3:30 pm";
            }
            else if(pat[i].date == 4)
			{
		    	pointer_date[3] = "4:00 pm to 4:30 pm";
            }
            else if(pat[i].date == 5)
			{
				pointer_date[4] = "4:30 pm to 5:00";
			}
			printf("The slot is confirmed\n");
			/* Delete the desired slot from the available slot*/
			for(u8 j = (pat[i].date - 1)  ; j <= n ; j++)
			{
				pointer_date[j] = pointer_date[j+1];						
		    }
			n--;
	        break;
		}
	}
    if(i > number) /*This ID is not exist.*/
	{
        printf("Incorrect ID\n");
    }	
}
void Cancel() /*To cancel reservation.*/
{
	u8 i , j ,flag = 0;
	u16 ID;
	printf("Enter the ID of the patient you want to cancel : ");
    scanf("%d",&ID);
    for(i = 0 ; i <= number ; i++) /*Search for the ID.*/
	{
	    if(ID == pat[i].ID) /*ID is exist*/
		{ 
	        flag = 1;   
			n++;
		    for(j = n ; j >= (pat[i].date - 1) ; j--) /*Delete the reservation*/
			{
                pointer_date[j] = pointer_date[j-1];
			}
			switch(j) /*Add the canceled reservation to the available reservation.*/
			{
			case 0 :
            pointer_date[j] = "2 pm to 2:30 pm";
			break;
			case 1 :
            pointer_date[j] = "2:30 pm to 3:00 pm";
			break;
			case 2 :
            pointer_date[j] = "3:00 pm to 3:30 pm";
			break;
			case 3 :
            pointer_date[j] = "4:00 pm to 4:30 pm";
			break;
			case 4 :
            pointer_date[j] = "4:30 pm to 5:00";
			break;
			}
			pat[i].date = 0;
			printf("The reservation has canceled\n");
            break;			
		}
	}
    if(flag == 0) /*Incorrect ID or ID is not exist.*/
	{
	    printf("Incorrect ID\n");
	}
}
void patient_record() /*Information about the patient.*/
{
	u8  i , flag = 0 ;
	u16 ID;
	printf("Enter the ID of the patient : ");
	scanf("%d",&ID); 
    for(i = 0 ; i < 10 ; i++) /*Search for the ID.*/
	{
	    if(ID == pat[i].ID) /*ID is exist.*/
		{
			/* View patient record .*/
			flag = 1;
            printf("Name : %s\n",pat[i].name);
	     	printf("Age : %d\n",pat[i].age);
			printf("Gender : %s\n",pat[i].gender);
			if(pat[i].date == 0) 
			{
				printf("No reservation yet\n");
			}
			else if(pat[i].date == 1)
			{
		    	printf("Reservation date : %s\n",pointer_date[0]);
            }
            else if(pat[i].date == 2)
			{
		    	printf("Reservation date : %s\n",pointer_date[1]);
            } 
            else if(pat[i].date == 3)
			{
		    	printf("Reservation date : %s\n",pointer_date[2]);
            }
            else if(pat[i].date == 4)
			{
		    	printf("Reservation date : %s\n",pointer_date[3]);
            }
            else if(pat[i].date == 5)
			{
				printf("Reservation date : %s\n",pointer_date[4]);
			}
            printf("*****************************\n");			
		}
	}
    if(flag == 0) /*Incorrect ID or ID is not exist.*/
    {
		printf("Incorrect ID");
	} 		
}
void today_reservation() 
{
	u8 i , flag = 0;
	for(i = 0 ; i <= number ; i++)
	{
		if((pat[i].date > 0) && (pat[i].date <= 5)) /*Display the reservation of the current day.*/
		{ 
			flag = 1;
		    printf("Name : %s\n",pat[i].name);
			printf("ID : %d",pat[i].ID);
		    switch(pat[i].date)
		    {
				case 1:
		   	    printf("Reservation date : 2 pm to 2:30 pm \n");
				break;
				case 2:
				printf("Reservation date : 2:30  pm to 3:00 pm \n");
				break;
				case 3:
				printf("Reservation date : 3:00 pm to 3:30 pm \n");
				break;
                case 4:
 				printf("Reservation date : 4: pm to 4:30 pm \n");
				break;
				case 5:
				printf("Reservation date : 4:30 pm to 5:00 pm \n");
				break;
            }
		}
    }
    if(flag == 0) /*No reservation between 1 and 5.*/
	{
		printf("There is no reservation todeay\n");
	}		
}