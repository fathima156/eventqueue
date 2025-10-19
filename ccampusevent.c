#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>


struct node
{
    char event[100];
    int day,month,year,hor,mint;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;



void enque (char name[],int day,int month,int year,int hor,int mint )
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->event,name);
    newnode->day  = day;
    newnode->month  = month;
    newnode->year  = year;
    newnode->hor  = hor;
    newnode->mint  = mint;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("added the event %s on %02d-%02d-%02d at %02d:%02d \n", name,day,month,year,hor,mint);
}


void deque()
{
   

     if (front == NULL)
        {
            printf("no events in list\n");
          
        }
        else
    {
         struct node *temp = front;
        printf("removed event  %s\n", temp->event);
        front = front->next;
        if (front==NULL)
        {
              rear = NULL;
        }
        
        free(temp);
       
    }
}


void display()
{
   

    if (front == NULL)
    {
        printf("no events in list\n");
    }
    else
    {
        struct node *temp = front;
        printf("\n___Event List___\n ");
        while (temp != NULL)
        {
            printf("\nEvent : %s | Date : %02d-%02d-%02d | Time : %02d:%02d\n", temp->event, temp->day,temp->month,temp->year,temp->hor,temp->mint);
            temp = temp->next;
        }
        printf("\n");
    }
}
 void peek() {
    if (front == NULL) {
        printf("no event in the list\n");
    } else {
        struct node *temp=front;
       time_t t = time(NULL);
        struct tm *current = localtime(&t);

        int todayDate = current->tm_mday;
        int todayMonth = current->tm_mon + 1;
        int todayYear = current->tm_year + 1900;
        int currentHour = current->tm_hour;
        int currentMin = current->tm_min;

        // check if event is happening now (same date, hour, and minute)
        if (temp->day == todayDate &&
            temp->month == todayMonth &&
            temp->year == todayYear &&
            temp->hor == currentHour &&
            temp->mint == currentMin) {
            printf("Reminder: %s\n", temp->event);
        }

       

        printf("Nearest event is %s on %02d-%02d-%02d at %02d:%02d \n", temp->event,temp->day,temp->month,temp->year,temp->hor,temp->mint);
    }
 }
 
int main()
{
    int choice,day,month,year,hor,mint;
    char name[100];
    
    time_t hgj;
   
    struct tm *currenttime;
    
        hgj=time(NULL);
        currenttime=localtime(&hgj);
    
        printf("\nCurrent Time : %02d:%02d:%02d\n",
        currenttime->tm_hour,
        currenttime->tm_min,
        currenttime->tm_sec);
                                                                                                            
    
    //operation
   

    while (1) 
    {
       
        //choices
        printf("\n___MENU___\n");
        printf("\n1.Add event \n");
        printf("2. Remove Event\n");
        printf("3. Display Events\n");
        printf("4. Nearest Event\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        // printf("enter event date and time [dd:mm:yyyy hh:mm] \n");
        // scanf("%d:%d:%d %d:%d",&day,&month,&year,&hor,&mint);
        
        switch (choice)
        {
        case 1:
            printf("\nEnter event name: \n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            
          
          // remove newline

                    printf("Enter event date and time [dd-mm-yyyy hh:mm]: ");
                    scanf("%d-%d-%d %d:%d", &day, &month, &year, &hor, &mint);

                    enque(name, day, month, year, hor, mint);
                    break;

            case 2:
                deque();
                break;
            

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;
                break;
                
            default:
                printf("Invalid choice!\n");
           
        }
         Sleep(2000);
    }

       
}
     
        



