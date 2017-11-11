//**********************************************************
//	PROJECT FOOD COURT- MANAGEMENT
//**********************************************************
//INCLUDED HEADER FILES
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <iomanip.h>


//**********************************************************
//	CLASS NAME : menu
//	DETAILS    : IT CONTROLLS OVER ALL THE FUNCTIONS
//**********************************************************

class menu
{
	public :
			void main_menu() ;
			void z(char *);
	private :
			void edit_menu() ;
} ;


//**********************************************************
//	CLASS NAME : food
//	DETAILS    : IT CONTROLLS OVER ALL THE FUNCTIONS
//                   RELATED TO FOOD ITEMS
//**********************************************************

class food
{
	public :
			void add_item(void) ;
			void delete_item(void) ;
			void modify_item(void) ;
			void list_of_item(void) ;
			void purchase(void) ;

			int  last_code(void) ;
			void delete_record(int) ;
			void modify_record(int) ;
			void display_record(int) ;
			int  item_found(int) ;
			int  recordno(int) ;
			int   itemcode;
			int itemstock ;
			char  itemname[30],itemtype[30] ;
			float itemprice ;
} ;


//**********************************************************
//	CLASS NAME : account
//	DETAILS    : IT CONTROLLS OVER ALL THE FUNCTIONS
//                   RELATED TO MAKING BILL
//**********************************************************

class account
{
	public :        int   code;
			float price, quantity ;
			char  name[30],type[30] ;
} ;



//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: main_menu(void)
{
	clrscr() ;
	char ch ;
	do
	{
		clrscr() ;
		cout <<"\n\n\t\tTHE HOGGER-FOR THE EXCLUSIVE PIZZAS EVER" ;
		cout <<"\n\n\n1:ORDER" ;
		cout <<"\n\n\n2:SEE MENU";
		cout <<"\n\n\n3:EDIT" ;
		cout <<"\n\n\n4:ENQUIRIES";
		cout <<"\n\n\n0:QUIT" ;
		cout <<"\n\n\nENTER CHOICE : " ;
		cin>>ch;
		if (ch == '1')
		{
			food f ;
			f.purchase() ;
		}
		else if (ch == '2')
		{
			food f ;
			f.list_of_item() ;
		}
		else if (ch == '3')
			edit_menu() ;
		else if (ch == '4')
		{
			clrscr();
			getch();
			cout<<"\n\n\t\t\t\tTHE HOGGER";
			cout<<"\n\n#TIMING:\n\n 10 AM TO 10 PM ";
			cout<<"\n\n#THE HOGGER WILL BE CLOSED ON SUNDAYS";
			cout<<"\n\n#CUSTOMER SATISFACTION IS OUR MOTIVE";
			cout<<"\n\n#CALL US AT ";
			cout<<"\n\n#28140110\n\n#28114225\n\n#42658764";
			cout<<"\n\n#or email us at : ";
			cout<<"\n\n#dav@yahoo.com\n\n ";
			cout<<"#for queries and suggestions";
			cout<<"\n\npress a key to continue";
			getch();
			}
		}while (ch!='0');
		char b[]="\n\n\n\n\n\tTHANK YOU FOR VISITING US! PLEASED TO SERVE YOU!!!";
		if(ch=='0')
		{	clrscr();
			z(b);
		}

		}
//**********************************************************
// THIS FUNCTION CREATE EDIT MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: edit_menu()
{
	clrscr();
	char ch ;
	do
	{
		cout <<"\n\nEDIT MENU:" ;
		cout <<"\n\n1:Add item" ;
		cout <<"\n\n2:Modify item" ;
		cout <<"\n\n3:Delete item" ;
		cout <<"\n\n4:Exit" ;
		cout <<"\n\nEnter Choice : " ;
		cin>>ch;
		if (ch == '1')
		{
			food f ;
			f.add_item() ;
			break;
			}
		else if (ch == '2')
		{
			food f ;
			f.modify_item() ;
			break;
			}
		else if (ch == '3')
		{
			food f ;
			f.delete_item() ;
			break ;
			}
		}while(ch!='4');
			   }



//**********************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE FOOD FILE (FOOD.DAT)
//**********************************************************
int food :: item_found(int tcode)
{
	fstream file ;
	food f;
	file.open("FOOD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *)&f, sizeof(food)))
	{
		if (f.itemcode == tcode)
		{
			found++ ;
			break ;
		}
	}
	file.close() ;
	return found ;
}


//**********************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

int food :: recordno(int tcode)
{
	fstream file ;
	file.open("FOOD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(food)))
	{
		found++ ;
		if (itemcode == tcode)
			break ;
	}
	file.close() ;
	return found ;
}
//**********************************************************
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// FOOD FILE (FOOD.DAT).
//**********************************************************
int food :: last_code()
{
	fstream file ;
	food f;
	file.open("FOOD.DAT",ios::in|ios::binary);
	file.seekg(0,ios::end);
	int t=file.tellg()/sizeof(f);
	file.close() ;
	return t+1;
	}



//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE FOOD ITEMS
//**********************************************************

void food :: list_of_item()
{
	clrscr() ;
	fstream file ;
	food f;
	file.open("FOOD.DAT", ios::in|ios::binary) ;
	file.seekg(0) ;
	cout<<"\n\n*******************************************************************************\n";
	cout <<"\n\t\t          THE HOGGER-MENU CARD"<<"\n\n";
	cout<<"*******************************************************************************\n\n\n";
	cout <<setw(2)<<"FOOD CODE"<<setw(18)<<"FOOD NAME"<<setw(17)
	<<"FOOD TYPE"<<setw(17)<<"FOOD PRICE"<<setw(17)<<"FOOD STOCK"
	;
	while (file.read((char*)&f,sizeof(food)))
	{
		cout <<"\n";
		cout <<"\n";
		cout <<setw(2)<<f.itemcode ;
		cout <<setw(25)<<f.itemname ;
		cout <<setw(17)<<f.itemtype ;
		cout <<setw(17)<<f.itemprice ;
		cout <<setw(17)<<f.itemstock;
				}
	cout<<"\n\n*******************************************************************************\n";
	cout<<"Note The Food Code Of Your Pick!";
	getch() ;
	clrscr() ;
	file.close () ;
}


//**********************************************************
// THIS FUNCTION ADD RECORDS IN THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: add_item()
{
	food f;
	char ch ;
	fstream file("FOOD.DAT",ios::app|ios::binary);
	clrscr() ;
		cout <<"\nADD FOOD ITEM TO THE MENU" ;
		cout <<"\n\nFood Code  : ";
		f.itemcode=last_code();
		cout<<f.itemcode;
		cout <<"\n\nFood Name  : " ;
		gets(f.itemname);
		cout <<"\nFood Type  : " ;
		gets(f.itemtype);
		cout <<"\nPrice      : " ;
		cin>>f.itemprice;
		cout <<"\nStock      : " ;
		cin>>f.itemstock;
		file.write((char*)&f,sizeof(f));
		file.close();
		}
//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: display_record(int tcode)
{
	fstream file ;
	food f;
	int flag=0;
	file.open("FOOD.DAT", ios::in|ios::binary) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char*)&f,sizeof(f)))
	{
		  if(f.itemcode==tcode)
		  {
			cout <<"\nFood Code  : "<<f.itemcode ;
			cout <<"\nFood Name  : "<<f.itemname ;
			cout <<"\nFood type  : "<<f.itemtype ;
			cout <<"\nPrice      : "<<f.itemprice;
			cout <<"\nStock      : "<<f.itemstock;
			flag=1;
			}

			}
			file.close();
		  if(flag==0)
		  cout<<"\nitem does not exist\n";
		    }






//**********************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: delete_record(int tcode)
{
	fstream file ;
	food f;
	file.open("FOOD.DAT", ios::in|ios::binary) ;
	fstream temp ;
	temp.open("temp.dat", ios::out|ios::binary) ;
	while (file.read((char *)&f,sizeof(food)))
	{
		if (f.itemcode != tcode )
			temp.write((char *)&f, sizeof(food)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("FOOD.DAT",ios::out|ios::trunc| ios::binary) ;
	temp.open("temp.dat", ios::in|ios::binary) ;
	while (temp.read((char *)&f, sizeof(food)))
	file.write((char *)&f, sizeof(food)) ;
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO DELETE RECORD FROM
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: delete_item()
{
	clrscr() ;
	char ch ;
	int tcode ;
	food f;
	cout <<"\n\nEnter Item Code of the item to be deleted : " ;
	cin>>tcode ;
	display_record(tcode) ;
	do
	{
		cout <<"\nDo you want to delete this record (y/n) : " ;
		cin>>ch;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	delete_record(tcode) ;
	cout <<"\nRecord Deleted" ;

	getch() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: modify_record(int tcode)
{
	int recno ;
	recno = recordno(tcode) ;
	char ch ;
	int c;
	food f;
	int flag=0;
	fstream file("FOOD.DAT",ios::in|ios::binary);
	while(file.read((char*)&f,sizeof(f)))
	{
		if(tcode==f.itemcode)
		{
		display_record(tcode) ;
		flag=1;
		break;
		}
		}
	if(flag==0)
	{
	cout<<"\nSORRY!ITEM DOES NOT EXIST!";
	getch();
	return;
	}

	do
	{
		cout <<"\n\nChange (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		}while (ch != 'N' && ch != 'Y') ;
	int valid = 0 ;
	if (ch == 'Y' && !valid)
	{
		MENU2:
		cout<<"\n\nWHAT DO YOU WANT TO MODIFY?";
		cout<<"\n\n1.Item name\n2.Item Type\n3.Item price" ;
		cout<<"\n4.Update Stock";
		cout<<"\n\nEnter Your Choice";
		cin>>c;
		if(c==1)
		{
		 cout<<"\n\nENTER FOOD NAME TO ADD IN THE MENU  :";
		 gets(f.itemname);
		 cout<<"\n\nDO YOU WANT TO MODIFY ANYTHING ELSE?";
		 cin>>ch;
		 if(ch=='y')
		 goto MENU2;
		 }
		else if(c==2)
		{
		 cout<<"\n\nENTER FOOD TYPE TO ADD IN THE MENU :";
		 gets(f.itemtype);
		 cout<<"\n\nDO YOU WANT TO MODIFY ANYTHING ELSE?";
		 cin>>ch;
		 if(ch=='y')
		 goto MENU2;
		 }
		else if(c==3)
		{
		 cout<<"\n\nENTER THE PRICE OF THE FOOD ITEM   :";
		 cin>>f.itemprice;
		 cout<<"\n\nDO YOU WANT TO MODIFY ANYTHING ELSE?";
		 cin>>ch;
		 if(ch=='y')
		 goto MENU2;
		 }
		else if(c==4)
		{
	  cout<<"\n\nENTER THE STOCK OF THE FOOD ITEM   :";
		 cin>>f.itemstock;

		 cout<<"\n\nDO YOU WANT TO MODIFY ANYTHING ELSE?";
		 cin>>ch;
		 if(ch=='y')
		 goto MENU2;
		 else
		 return;
		 }
		else
		{
		 cout<<"\nENTER 1,2,3,4 ONLY!";
		 goto MENU2;
		 }
		cout <<"\n\nDO YOU WANT TO SAVE THIS RECORD(y/n)? : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		}
	if (ch == 'N')
		return ;
	file.close();
	file.open("FOOD.DAT", ios::out | ios::ate|ios::binary) ;
	int location ;
	location = (recno-1) * sizeof(food) ;
	file.seekp(location) ;
	file.write((char *)&f, sizeof(food)) ;
	file.close() ;
	clrscr() ;
	cout <<"\n\n\n\n\t\t\tRECORD MODIFIED" ;
	getch() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE FOOD FILE (FOOD.DAT)
//**********************************************************

void food :: modify_item()
{
	clrscr() ;
	getch();
	char ch ;
	int tcode;
	cout <<"\n\nEnter Item Code of the item to be modified :\n\n " ;
	cin>>tcode ;
	modify_record(tcode) ;
}





//**********************************************************
// THIS FUNCTION PURCHASES THE FOOD ITEM IN THE MENU
//**********************************************************

void food :: purchase(void)
{
	  clrscr() ;
	fstream f1;
	f1.open("bill.dat",ios::out|ios::binary);
	char  ch ;
	int  tcode ;
	int qty ;

	do
	{

		clrscr() ;
		 Menu3:
		food f;
		cout <<"\nEnter Item Code of the item to be Purchased : " ;
		cin>>tcode;
		cout<<"\nEnter quantity:";
		cin>>qty;
		fstream file("FOOD.DAT",ios::in|ios::binary|ios::out);
		while(file.read((char*)&f,sizeof(food)))
		{
		if(tcode==f.itemcode)
		{
			if(qty>=f.itemstock)
			{
			cout<<"\n\nSORRY! FOOD NOT AVAILABLE!!"
			    <<"\n\nDO YOU WANT TO CHOOSE SOMETHING ELSE(y/n)?";
			char a;
			cin>>a;
			if(a=='y'||a=='Y')
			goto Menu3;
			else
			return;
			}
			else
			{
			f.itemstock-=qty;
			long n=sizeof(food);
			file.seekp(-n,ios::cur);
			file.write((char*)&f,sizeof(food));

			}
			break;
			}
			}
			file.close();


		display_record(tcode);

	      account a;
		do
		{
				cout <<"\n\nDo you want to cancel this purchase (y/n) : " ;
		cin>>ch;
	       ch = toupper(ch) ;	    } while (ch != 'N' && ch != 'Y') ;
		if (ch == 'N') {
		file.open("FOOD.DAT", ios::in|ios::binary|ios::out) ;
			while (file.read((char *)&f, sizeof(food)))
			{
			if (f.itemcode == tcode)
			{
			       a.code=f.itemcode;
			       strcpy(a.name,f.itemname);
			       strcpy(a.type,f.itemtype);
			       a.quantity=qty;
			       a.price=f.itemprice;
			      f1.write((char*)&a,sizeof(a));
				}
			       }

		cout <<"\n\nDo you want to purchase more (y/n) : " ;
		cin>>ch;

		}
		else
		{f.itemstock+=qty;
		long n=sizeof(food);
			file.seekp(-n,ios::cur);
			file.write((char*)&f,sizeof(f));
			}

		file.close();
		}while(ch=='Y'||ch=='y');

		f1.close();
		clrscr();
		getch();
		account a;

		f1.open("bill.dat",ios::in|ios::binary);
		int total_bill=0;
		cout <<"\n\n\t\tCUSTOMER BILL"<<"\n\t\t============\n\n\n";
		cout<<"\n================================================================================\n" ;
		cout <<setw(8)<<"Foodcode"<<setw(15)<<"Foodname"<<setw(15)<<"foodtype"<<
		 setw(8)<<"Price"<<setw(8)<<"Qty"<<setw(10)<<"Total"<<"\n\n";
		cout <<"\n================================================================================" ;
		while (f1.read((char *)&a, sizeof(account)))
		{
			cout<<"\n";
			cout <<setw(8)<<a.code ;
			cout <<setw(15)<<a.name ;
			cout <<setw(15)<<a.type;
			cout <<setw(8)<<a.price;
			cout <<setw(8)<<a.quantity ;
			int total = a.quantity * a.price ;

			cout <<setw(10)<<total ;
			 total_bill = total_bill + total ;
			cout<<"\n\n";
			}

		f1.close() ;
		cout<<"\n\n\t\t";
		cout<<"\n\n*******************************************************************************\n";

		cout <<"\n  TOTAL BILL: Rs." <<total_bill <<" /=" ;
		cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^VISIT US AGAIN!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
		cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

		getch() ;
}







void menu::z(char *b)
{	for( int z=1;z<=30;z++)
	 {
		gotoxy(z,10);
		cout<<b;
		delay(100);
		gotoxy(z,10);
		clreol();
		if(z==30) z=1;
		if(kbhit()) break;
	  }
}
//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************
void main()
{
 clrscr();
 printf("\n +++++++++++++++++++++++++++++++++++++++*++++++++++++++++++++++++++++++++++++++");
 printf("\n +                                     ***                                    +");
 printf("\n +                                    *****                                   +");
 printf("\n +                                   *******                                  +");
 printf("\n +                                  *********                                 +");
 printf("\n +                                 ***********                                +");
 printf("\n +                                *************                               +");
 printf("\n +                               ***************                              +");
 printf("\n +                              *****************                             +");
 printf("\n +                             *******************                            +");
 printf("\n +                            *********************                           +");
 printf("\n +                           ***********************                          +");
 printf("\n +                          *************************                         +");
 printf("\n +                         ***************************                        +");
 printf("\n +                        *****************************                       +");
 printf("\n +                       *******************************                      +");
 printf("\n +                      *********************************                     +");
 printf("\n +                     ***********************************                    +");
 printf("\n +                    *************************************                   +");
 printf("\n +                   ***************************************                  +");
 printf("\n +                  *****************************************                 +");
 printf("\n +                 *******************************************                +");
 printf("\n +                *********************************************               +");
 printf("\n +               ***********************************************              +");
 printf("\n +              *************************************************             +");
 printf("\n +             *********************WELCOME***********************            +");
 printf("\n +              *************************************************             +");
 printf("\n +               ***********************************************              +");
 printf("\n +                *********************************************               +");
 printf("\n +                 *******************************************                +");
 printf("\n +                   ***************************************                  +");
 printf("\n +                    *************************************                   +");
 printf("\n +                     ***********************************                    +");
 printf("\n +                      *********************************                     +");
 printf("\n +                       *******************************                      +");
 printf("\n +                        *****************************                       +");
 printf("\n +                         ***************************                        +");
 printf("\n +                          *************************                         +");
 printf("\n +                           ***********************                          +");
 printf("\n +                            *********************                           +");
 printf("\n +                             *******************                            +");
 printf("\n +                              *****************                             +");
 printf("\n +                               ***************                              +");
 printf("\n +                                *************                               +");
 printf("\n +                                 ***********                                +");
 printf("\n +                                  *********                                 +");
 printf("\n +                                   *******                                  +");
 printf("\n +                                    *****                                   +");
 printf("\n +                                     ***                                    +");
 printf("\n +++++++++++++++++++++++++++++++++++++++*++++++++++++++++++++++++++++++++++++++");

	char A[]="COMPUTER SCIENCE PROJECT DONE BY N.SWETHA";
	menu m;
	m.z(A);
	getch();
	clrscr();
	char s[]=" WELCOME TO THE GREATEST PIZZA COURT IN TOWN-THE HOGGER!!";
	m.z(s);
	getch();
	m.main_menu() ;
	getch();
}
