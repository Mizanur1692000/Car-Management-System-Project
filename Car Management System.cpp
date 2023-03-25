#include<iostream>
using namespace std;

struct Car{
  int carPlateNumber;
  struct Car*next;
};

void entryANewCar(struct Car** headRef)
{
  int carPlateNumber;
  cout<<"Enter a car plate number: ";
  cin>>carPlateNumber;
  struct Car* newCar=(struct Car*)malloc(sizeof(struct Car));
  struct Car* last=*headRef;
  newCar->carPlateNumber=carPlateNumber;
  newCar->next=NULL;
  if(*headRef==NULL)
  {
    *headRef=newCar;
  }
  else
  {
    while(last->next!=NULL)
    {
      last=last->next;
    }
    last->next=newCar;
  }
}

void removeCar(struct Car** headRef,int key)
{
  struct Car*temp=*headRef,*prev;
  if(temp!=NULL && temp->carPlateNumber==key)
  {
    *headRef=temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL && temp->carPlateNumber!=key)
  {
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL)
  {
    return;
  }
  prev->next=temp->next;
  free(temp);
}

void displayAvailableCar(struct Car* temp)
{
  while(temp!=NULL)
  {
    cout<<endl<<temp->carPlateNumber<<endl;
    temp=temp->next;
  }
}

void numberOfAvailableCar(struct Car** headRef)
{
  int carPlateNumber;
  cout<<"Enter the number of available cars: ";
  cin>>carPlateNumber;
  struct Car* newCar=(struct Car*)malloc(sizeof(struct Car));
  newCar->carPlateNumber=carPlateNumber;
  newCar->next=*headRef;
  *headRef=newCar;
}



int main()
{
  int choice,number;
  struct Car* car=NULL;
  while(true)
  {
   cout << "\n\t\tWelcome to the car parking system: "
          "\n\n\t\t Press\n\t\t 1 to "
                "entry a new car\n\t\t 2 to remove a car\n\t\t 3 to display available cars in the car parking area\n\t\t 4 to view the number of avialable cars\n\t\t 5 to Exit\n";
    cout << "\n\tEnter your Choice\n";
   cin>>choice;
    if(choice==1)
   {
     entryANewCar(&car);
     cout<<endl<<"A new car entered!!!"<<endl;
   }
   else if(choice==2)
   {
     int number;
     cout<<"Enter a car plate number to remove: ";
     cin>>number;
    removeCar(&car,number);
    cout<<"The car number "<<number<<" removed from the car parking!!!";
   }
   else if(choice==3)
   {
    cout<<"The plate number of available cars in the parking are: ";
    displayAvailableCar(car);
   }
   else if(choice==4)
   {
      numberOfAvailableCar(&car);
      cout<<"A new car entered as available car!!!";
   }
   else if(choice==5)
   {
     exit(0);
   }
}
}
