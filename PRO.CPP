#include<iostream.h>
#include<time.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#define pixTOrc(x) (8*(x-1))
#define INC 5
#define ROW 15
#define COL 8
#define MAXMENU 5
#define MAXITEM 5
void welcomeuser(char *);
void bookings(char *);
void makereservation(char *);
void cancelreservation(char *);
typedef char aaoption[50];
aaoption Menua[]= {"ENTER NEW ENTRY", "DELETE ENTERY","CHECK FOR AVAILABILITY","CHECK DATABASE","LOGOUT"};
void normalvideo(int x,int y,char *str);
void selectedMenu(int x, int y, char *str);
aaoption Menub[]= {"MAKE RESERVATIONS", "CANCEL RESERVATIONS","CHECK FOR AVAILABILITY","BOOKINGS","LOGOUT"};

void adminlogin();
void userlogin();
void searchfl();
void call_menu();
void welcomeadmin();
void views(char *user)
{
clrscr();
cleardevice();
int flag=0;
char board[30],des[30],date[30];
char a[30],b[30],c[30],e[30],g[30],h[30],dd[30],name[30];
int f,i;
char fname[30],flight[30];
int seats;
cout<<"ENTER BOARDING PLACE:- ";
cin>>board;
cout<<"ENTER DESTINATION PLACE:- ";
cin>>des;
cout<<"DATE OF JOURNEY:- ";
cin>>date;
cout<<"\n\n\n\n";
ofstream b1;
b1.open("1.dat",ios::app);
b1.close();
ifstream ab1;
ab1.open("1.dat");
while(1)
{
if(!ab1)
break;
else
{
ab1>>a>>b>>c>>dd>>e>>f>>g>>h;
if(strcmp(board,g)==0&&strcmp(des,h)==0&&strcmp(date,c)==0)
{
flag++;
cout<<flag<<":)"<<"FLIGHT NO :"<<a<<" SERVICE BY:"<<b<<"-"<<a<<"\n"<<" DATE OF JOURNEY:"<<c<<" TIME:"<<dd<<" DURATION:"<<e<<" SEATS:"<<f<<"\n"<<" FROM:"<<g<<" TO:"<<h<<"\n\n\n";
}
}
}
if(flag==0)
{cout<<"RENTER DETAILS/NO SUCH FLIGHTS FOUND";
}
getch();
welcomeuser(user);
}

char aamenu()
{
   settextstyle(3,HORIZ_DIR,2);
   setcolor(15);
   int i,done;
   for(i = 1; i < MAXMENU; i++)
   normalvideo(COL, (i*INC)+ROW, Menub[i]);
   selectedMenu(COL,ROW, Menub[0]);
   i = done = 0;
   do
   {
      setcolor(WHITE);
      settextstyle(3,HORIZ_DIR,2);
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 72: normalvideo(COL, (i*INC)+ROW, Menub[i]);
			  i--;
			      if (i == -1)
			   i = MAXITEM-1;
			   selectedMenu(COL,(i*INC)+ROW,Menub[i]);
			break;
	       case 80: normalvideo(COL, (i*INC)+ROW, Menub[i]);
			  i++;
			  if (i == MAXITEM)
			   i = 0;
			   selectedMenu(COL, (i*INC)+ROW, Menub[i]);
			break;

	    }
	    break;
	 case 13: done = 1;
	 break;

      }
   }
   while (!done);
   return(i+49);
}


void welcomeuser(char *user)
{
clrscr();
cleardevice();
char *s="Welcome! ";

settextstyle(4,0,3);
setcolor(BLUE);
outtextxy(100,10,s);
outtextxy(200,10,user);
setfillstyle(6,9);
   bar(pixTOrc(7),pixTOrc(14),pixTOrc(50),pixTOrc(40));
   char choice;
      choice =aamenu();
      switch (choice)
      {
	 case '1':makereservation(user);

		 break;
	case '2': cancelreservation(user);

		  break;
	case '3':views(user);
		 break;
	case '4':bookings(user);
		 break;
	case '5': call_menu();
		 break;
	 }

getch();
exit(0);

}
void cancelreservation(char *user)
{
int p ,i=0;
char can[26]="c";
clrscr();
cleardevice();
char s[30];
strcpy(s,user);
strcat(user,".dat");
int fffs,seats,pnr;
char nam[30],dat[30],fl[30],g[30],h[30],c[30],b[30],a[30],name[30];

cout<<"ENTER PNR NO OF TICKET TO BE CANCELLED :";
cin>>p;
ofstream bas;
bas.open(user,ios::app);
bas.close();
ifstream bs;
bs.open(user);
ofstream bs1;
strcat(can,user);
bs1.open(can,ios::app);
ofstream aaa;
aaa.open("122.dat",ios::app);
ofstream cann;
while(bs)
{
if(bs)
{
bs>>pnr>>name>>seats>>g>>h>>c>>b>>a;
if(bs&&pnr==p)
{
fffs=seats;
i=1;
strcpy(nam,b);
strcpy(fl,a);
strcpy(dat,c);
bs1<<pnr<<" "<<name<<" "<<seats<<" "<<g<<" "<<h<<" "<<c<<" "<<b<<" "<<a<<"\n";
}else if(bs)
aaa<<pnr<<" "<<name<<" "<<seats<<" "<<g<<" "<<h<<" "<<c<<" "<<b<<" "<<a<<"\n";

}
else
break;
}
bs.close();
bs1.close();
aaa.close();
remove(user);
rename("122.dat",user);
if(i==1)
   {
    cout<<"SUCCESSFULLY CANCELLED";
     char flight[30],date[30];
    char e[30],dd[30];
    int noofseats;
    char via[30],from[30],to[30];

     int f;
    strcpy(date,dat);
    strcpy(name,nam);
    strcpy(flight,fl);

    ifstream file1;
    file1.open("1.dat");
    ofstream file2;
    file2.open("2.dat",ios::app);
  while(file1)
    {
    file1>>a>>b>>c>>dd>>e>>f>>g>>h;
    if(!file1)
    break;
      if(strcmp(a,flight)==0&&strcmp(b,name)==0&&strcmp(c,date)==0)
       {
       f=f+fffs;
	  file2<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";
	   }
	else{
      file2<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";
	}
    }
    file1.clear();
    file1.seekg(0, ios::beg);
    file1.close();
    file2.close();
    remove("1.dat");
    rename("2.dat","1.dat");
    ifstream op;
op.open("booking.dat");
ofstream abbl,abbl1;
abbl.open("can.dat",ios::app);
abbl1.open("sd9.dat",ios::app);
while(1)
{
if(!op)
break;
else
{
op>>pnr>>nam>>noofseats>>from>>to>>via>>fl>>dat;
if(op&&pnr==p)
{
abbl<<pnr<<" "<<nam<<" "<<noofseats<<" "<<from<<" "<<to <<" "<<via<<" "<<fl<<" "<<dat<<"\n";
}
else if(op)
abbl1<<pnr<<" "<<nam<<" "<<noofseats<<" "<<from<<" "<<to <<" "<<via<<" "<<fl<<" "<<dat<<"\n";
}
}
op.close();
abbl.close();
abbl1.close();
       op.clear();
    op.seekg(0, ios::beg);
    remove("booking.dat");
    rename("sd9.dat","booking.dat");

    }
getch();
welcomeuser(s);
}
void makereservation(char *user)
{

clrscr();
cleardevice();
int flag=0;
char s[30];
char board[30],des[30],date[30];
char a[30],b[30],c[30],e[30],g[30],h[30],dd[30],name[30];
int f,i;
char fname[30],flight[30];
int seats;
strcpy(s,user);
line:cout<<"ENTER BOARDING PLACE:- ";
cin>>board;
cout<<"ENTER DESTINATION PLACE:- ";
cin>>des;
cout<<"DATE OF JOURNEY:- ";
cin>>date;
cout<<"\n\n\n\n";
ofstream b1;
b1.open("1.dat",ios::app);
b1.close();
ifstream ab1;
ab1.open("1.dat");
while(1)
{
if(!ab1)
break;
else
{
ab1>>a>>b>>c>>dd>>e>>f>>g>>h;
if(strcmp(board,g)==0&&strcmp(des,h)==0&&strcmp(date,c)==0)
{
flag++;
cout<<flag<<":)"<<"FLIGHT NO :"<<a<<" SERVICE BY:"<<b<<"-"<<a<<"\n"<<" DATE OF JOURNEY:"<<c<<" TIME:"<<dd<<" DURATION:"<<e<<" SEATS:"<<f<<"\n"<<" FROM:"<<g<<" TO:"<<h<<"\n\n\n";
}
}
}
if(flag==0)
{cout<<"RENTER DETAILS/NO SUCH FLIGHTS FOUND\n";
cout<<"\n\n\n\t\t ESC TO RETURN";
if(getch()==27)
welcomeuser(s);
}
if(flag>0)
{  cout<<"-----------------------------ENTER TO PROCEED OR ESC TO BACK----------------------- \n";
if(getch()==27)
welcomeuser(s);
cout<<"ENTER NO OF SEATS:-";
cin>>seats;
cout<<"ENTER NAME OF PASSENGER:-";
cin>>name;
cout<<"ENTER FLIGHT NO:-";
cin>>flight;
cout<<"ENTER FLIGHT NAME:-";
cin>>fname;
 ifstream file1;
    file1.open("1.dat");
    ofstream file2;
    file2.open("2.dat",ios::app);
  while(file1)
    {
    file1>>a>>b>>c>>dd>>e>>f>>g>>h;
    if(!file1)
    break;
      if(strcmp(a,flight)==0&&strcmp(b,fname)==0&&strcmp(c,date)==0)
       {if(f>=seats)
       {
       f=f-seats; i=1;  }
       else
       i=0;
       file2<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";
	   }
	else{
      file2<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";
	}
    } if(i==1)
    cout<<"SUCCESSFULLY BOOKED";
    file1.clear();
    file1.seekg(0, ios::beg);
    file1.close();
    file2.close();
    remove("1.dat");
    rename("2.dat","1.dat");
      if(i==0)
   { cout<<"WRONG DETAILS/NO SEATS AVAILABLE";
   getch();
    welcomeuser(s);
    }


ofstream a1;
a1.open("booking.dat",ios::app);
a1.close();
ofstream fo1;
strcat(user,".dat");

int pnr=0,noofseats;
char nam[30],from[30],to[30],via[30],fl[30],dat[30];
ifstream acc;
acc.open("pnr.txt");
while(1)
{if(acc)
acc>>pnr;
if(!acc)
break;
}
acc.close();
ofstream assss;
pnr=pnr+1;
assss.open("pnr.txt",ios::app);
assss<<pnr<<"\n";
assss.close();
ofstream ob1;
ob1.open("booking.dat",ios::app);
strcpy(nam,name);
strcpy(from, board);
strcpy(to,des);
noofseats=seats;
strcpy(fl,fname);
strcpy(dat,date);
strcpy(via,flight);
ob1<<pnr<<" "<<nam<<" "<<noofseats<<" "<<from<<" "<<to <<" "<<via<<" "<<fl<<" "<<dat<<"\n";
ob1.close();
fo1.open(user,ios::app);
strcpy(g,board);
strcpy(h,des);
strcpy(c,date);
strcpy(b,fname);
strcpy(a,flight);
fo1<<pnr<<" "<<name<<" "<<seats<<" "<<g<<" "<<h<<" "<<c<<" "<<b<<" "<<a<<"\n";
fo1.close();

}
getch();
cleardevice();
welcomeuser(s);

}
void bookings(char *user)
{
int pnr,seats;
char s[30];
char name[30],g[30],h[30],c[30],b[30],a[30];
clrscr();
cleardevice();
strcpy(s,user);
int i=0;
strcat(user,".dat");
ofstream dl;
dl.open(user,ios::app);
dl.close();
ifstream dd;
dd.open(user);
while(dd)
{
if(!dd)
{
break;
}
else
{
dd>>pnr>>name>>seats>>g>>h>>c>>b>>a;
if(dd)
{
i++;
cout<<"\n"<<i<<")PNR:"<<pnr<<"\n"<<"NAME:"<<name<<"\t"<<"NO OF SEATS:"<<seats<<"\n"<<"FROM:"<<g<<"\t"<<"TO:"<<h<<"\n"<<"DATE:"<<c<<"\t"<<"FLIGHT NAME:"<<b<<"\n";
}
}
}
if(i==0)
cout<<"\n\n\n\n\n\t\t\tNo Bookings";
getch();
welcomeuser(s);
}

void viewseats()
{         char name[30],flight[30],date[30];
    char a[30],b[30],c[30],e[30],g[30],h[30],dd[30];
       int f=-100;
    cleardevice();
    cout <<"Enter Name Of The Flight :-";
    gets(name);
    cout<<"Enter Boieng No :-";
    gets(flight);
    cout<<"Enter Date Of Journey :-";
    gets(date);
    ifstream file1;
    file1.open("1.dat");
  while(file1)
    {
    file1>>a>>b>>c>>dd>>e>>f>>g>>h;
    if(!file1)
    break;
      if(strcmp(a,flight)==0&&strcmp(b,name)==0&&strcmp(c,date)==0)
     { cout<<"\n\n\nSeats Available :-"<<f;
     getch();
      break;
      }
       }
       if(f==-100)
       {
       cout<<"-------------------------WRONG DETAILS ENTERED----------------------";
	getch();
	}
       file1.close();
       welcomeadmin();
}
void deletedata()
{
    char name[30],flight[30],date[30];
    char a[30],b[30],c[30],e[30],g[30],h[30],dd[30];
     int i=0;
     int f;
     clrscr();
     cleardevice();
    cout <<"Enter name of the flight you want to erase from database :-";
    gets(name);
    cout<<"Enter flight no :-";
    gets(flight);
    cout<<"Enter date of journey :-";
    gets(date);
    ifstream file1;
    file1.open("1.dat");
    ofstream file2;
    file2.open("2.dat",ios::app);
  while(file1)
    {
    file1>>a>>b>>c>>dd>>e>>f>>g>>h;
    if(!file1)
    {
    break;
    }
      if(strcmp(a,flight)==0&&strcmp(b,name)==0&&strcmp(c,date)==0)
       {
       i=1;
	continue;
	   }
	else
	{
      file2<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";
	}
    }
    if(i==1)
    cout<<"SUCCESSFULLY DELETED";
    if(i==0)
    cout<<"------------------------------WRONG DETAILS ENTERED-------------------------------";
    getch();
    file1.clear();
    file1.seekg(0, ios::beg);
    file1.close();
    file2.close();
    remove("1.dat");
    rename("2.dat","1.dat");
    welcomeadmin();
}
void dispall()
{
char a[30],b[30],c[30],e[30],g[30],h[30],dd[30];
ifstream fl;
int f;
int i=0;
	clrscr();
	cleardevice();
	ofstream f1;
	f1.open("1.dat",ios::app);
	f1.close();
	fl.open("1.dat");
	while(fl)
	{
	fl>>a>>b>>c>>dd>>e>>f>>g>>h;
	if(!fl)
	break;
	i++;
	cout<<"\n\n"<<i<<")BOIENG NO :"<<a<<"\tFLIGHT NAME :"<<b<<"\n"<<"DATE OF JOURNEY:"<<c<<"\tTIME:"<<dd<<"\nDURATION:"<<e<<"hrs\tSEATS:"<<f<<"\n"<<"FROM:"<<g<<" \tTO:"<<h<<"\n";
	}
	 fl.close();
	 if(i==0)
	 {
	 cout<<"------------------------------------------------------------------------";
	 cout<<"\t\t\tNO RECORD IN DATABASE";
	  }
	  getch();
	 welcomeadmin();
}
void newone()
{
//char month[][3]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char a[30],b[30],c[30],e[30],g[30],h[30],*date,mo[4],year[5],dat[3];
int i,l,x,n,flag,d,f;
clrscr();
cleardevice();
cout<<"\nENTER THE FLIGHT NO/BOEING NO:";
gets(a);
cout<<"\nENTER THE TRAVEL SERVICE:";
gets(b);
cout<<"\nDATE OF JOURNEY:";
gets(c);

time_t timer;
timer=time(NULL);
date = asctime(localtime(&timer));
 l=strlen(date);
 x=l-5;
for(i=0;i<4;i++)
year[i]=date[x++];
x=l-21;
year[4]='\0';
for(i=0;i<4;i++)
mo[i]= date[x++];
x=l-17;
mo[4]='\0';
for(i=0;i<2;i++)
dat[i]=date[x++];
dat[3]='\0';
cout<<"\nTIME OF TAKEOFF (24 hrs format hhmm):";
char dd[30];
/*cin>>dd;
while(dd<0||dd%10000==0)
{cout<<"\nREENTER TIME OF TAKEOFF";
cin>>dd;
}
int tt=dd%100;
d=dd/100;
while(1)
{
if(d<0||d>23||tt<0||tt>59)
{
cout<<"\nREENTER TIME OF TAKEOFF";
cin>>dd;
while(dd<0||dd%10000==0)
{cout<<"\nREENTER TIME OF TAKEOFF";
cin>>dd;
}
tt=dd%100;
d=dd/100;
}
else
break;
} */
gets(dd);
cout<<"\nDURATION OF JOURNEY (IN HOURS:MIN):";
gets(e);
n=strlen(e);
 while(1){
for(i=0;i<n;i++)
{
if(e[i]=='0'||e[i]=='1'||e[i]=='2' ||e[i]=='3'||e[i]=='4'||e[i]=='5' ||e[i]=='6'||e[i]=='7'||e[i]=='8'||e[i]=='9'||e[i]==':')
flag=0;
else
{
flag=1;
break;
}
}if(flag==1) {
cout<<"\nREENTER DURATION:";
gets(e);
n=strlen(e);
}if(flag==0)
break;
}

cout<<"\nFROM:";
gets(g);
cout<<"\nTO:";
gets(h);
cout<<"\nNO OF SEATS:";
cin>>f;
/*n=strlen(f);
 while(1){for(i=0;i<n;i++)
{
if(f[i]=='0'||f[i]=='1'||f[i]=='2' ||f[i]=='3'||f[i]=='4'||f[i]=='5' ||f[i]=='6'||f[i]=='7'||f[i]=='8'||f[i]=='9')
flag=0;
else
{
flag=1;
break;
}
}if(flag==1) {
cout<<"\nREENTER NO OF SEATS:";
gets(f);
n=strlen(f);
}if(flag==0)
break;
} */
ofstream we;
we.open("1.dat",ios::app);
we<<a<<" "<<b<<" "<<c<<" "<<dd<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<"\n";

we.close();
cout<<"SUCCESSFULLY ";
getch();
welcomeadmin();
}


char amenu()
{
   settextstyle(3,HORIZ_DIR,2);
   setcolor(15);
   int i,done;
   for(i = 1; i < MAXMENU; i++)
   normalvideo(COL, (i*INC)+ROW, Menua[i]);
   selectedMenu(COL,ROW, Menua[0]);
   i = done = 0;
   do
   {
      setcolor(WHITE);
      settextstyle(3,HORIZ_DIR,2);
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 72: normalvideo(COL, (i*INC)+ROW, Menua[i]);
			  i--;
			      if (i == -1)
			   i = MAXITEM-1;
			   selectedMenu(COL,(i*INC)+ROW,Menua[i]);
			break;
	       case 80: normalvideo(COL, (i*INC)+ROW, Menua[i]);
			  i++;
			  if (i == MAXITEM)
			   i = 0;
			   selectedMenu(COL, (i*INC)+ROW, Menua[i]);
			break;

	    }
	    break;
	 case 13: done = 1;
	 break;

      }
   }
   while (!done);
   return(i+49);
}

void welcomeadmin()
{
cleardevice();
char *s="Welcome! ADMINISTRATOR ";
settextstyle(4,0,3);
setcolor(BLUE);
outtextxy(100,10,s);
setfillstyle(6,9);
   bar(pixTOrc(7),pixTOrc(14),pixTOrc(50),pixTOrc(40));
  char choice;
      choice =amenu();
      switch (choice)
      {
	 case '1':newone();

	 break;
	case '2': deletedata();

	break;
	case '3':viewseats();
		 break;
	case '4':dispall();

		 break;
	case '5': call_menu();
	break;
	 }



getch();
exit(0);
}
void login1(char *s, char *p)
{   ofstream fo1;
   fo1.open("admin.dat",ios::app);
   fo1.close();
char user[30],pass[30];
ifstream fin1;
fin1.open("admin.dat");
while(1)
{
if(!fin1)
{
outtextxy(130,100,"Either Password Or Username Is Incorrect");
getch();
if(getch()==27)
call_menu();

adminlogin();
}
fin1>>user>>pass;
if(strcmpi(user,s)==0&&strcmpi(pass,p)==0)
{
welcomeadmin();
getch();
}
}
}
void login2(char *s, char *p)
{   ofstream fo1;
   fo1.open("user.dat",ios::app);
   fo1.close();
char user[30],pass[30];
ifstream fin1;
fin1.open("user.dat");
while(1)
{
if(!fin1)
{
outtextxy(130,100,"Either Password Or Username Is Incorrect");
getch();
if(getch()==27)
call_menu();
userlogin();
}
fin1>>user>>pass;
if(strcmpi(user,s)==0&&strcmpi(pass,p)==0)
{
welcomeuser(s);
getch();
exit(0);
}
}
}

aaoption MMenu[]= {"ADMIN LOGIN", "USER LOGIN","SEARCH","PNR STATUS","EXIT"};
void normalvideo(int x,int y,char *str)
{            setcolor(2);
   x=pixTOrc(x);
   y=pixTOrc(y);
   outtextxy(x,y,str);
}

void selectedMenu(int x,int y,char *str)
{
   x=pixTOrc(x);
   y=pixTOrc(y);
   setcolor(4);
   outtextxy(x,y,str);
}
void regisu()
{ ofstream fo1;
   fo1.open("user.dat",ios::app);
   fo1.close();

cleardevice();
settextstyle(4,0,4);
setcolor(RED);
outtextxy(70,100," USER REGISTER PAGE");
settextstyle(1,0,2);
char usern[30],user[30],pass[30];
   cout<<"\n\n\n\n\n\n\n\n\n\n\tenter username: ";
   cin>>usern;
   int fl=0;
ifstream fin1;
while(1){
fin1.open("user.dat");
while(1)
{
if(!fin1)
{
fl=1;
break;
}
fin1>>user>>pass;
if(strcmpi(usern,user)==0)
{
cout<<"\n\t\t CHOOSE ANOTHER USERNAME !";
break;
 }
 }
 if(fl==1)
 break;
 else
{ cout<<"\n\t enter username: ";
 cin>>usern;
 fl=0;
 fin1.close();
 }
 }
   fin1.close();
   cout<<"\tenter password: ";
   cin>>pass;
   strcpy(user,usern);
   fo1.open("user.dat",ios::app);
   fo1<<user<<" "<<pass<<"\n";
   fo1.close();
cout<<"\t\tSUCCESSFULLY REGISTERED";
getch();
call_menu();
}
void regisa()
{
ofstream fo1;
   fo1.open("admin.dat",ios::app);
   fo1.close();
cleardevice();
settextstyle(4,0,4);
setcolor(BLUE);
outtextxy(70,100," ADMIN REGISTER PAGE");
settextstyle(1,0,2);
char u[30],user[30],pass[30];
   cout<<"\n\n\n\n\n\n\n\n\n\n\tenter username: ";
   cin>>u;
   int fl=0;
ifstream fin1;
while(1)
{
fin1.open("admin.dat");
while(1)
{
if(!fin1)
{
fl=1;
break;
}
fin1>>user>>pass;
if(strcmpi(u,user)==0)
{
cout<<"\n\t CHOOSE ANOTHER USERNAME !";
break;
 }
 }
 if(fl==1)
 break;
 else
{ cout<<"\n\t enter username: ";
 cin>>u;
 fl=0;

 }
 }
 fin1.close();
 strcpy(user,u);
   cout<<"\tenter password: ";
   cin>>pass;
   fo1.open("admin.dat",ios::app);
    fo1<<user<<" "<<pass<<"\n";
     fo1.close();
cout<<"\t\tSUCCESSFULLY REGISTERED";
getch();
call_menu();


}

char menu()
{
   settextstyle(3,HORIZ_DIR,2);
   setcolor(15);
   int i,done;
   for(i = 1; i < MAXMENU; i++)
   normalvideo(COL, (i*INC)+ROW, MMenu[i]);
   selectedMenu(COL,ROW, MMenu[0]);
   i = done = 0;
   do
   {

      setfillstyle(SOLID_FILL,BLUE);
      settextstyle(SMALL_FONT,HORIZ_DIR,5);
     bar(pixTOrc(2),pixTOrc(52.5),pixTOrc(75),pixTOrc(55));
      setcolor(15);
      switch(i)
      {
	case 0 : outtextxy(pixTOrc(5),pixTOrc(52.75),"ADMINISTRATION PANEL LOGIN ");
		 break;
	case 1 : outtextxy(pixTOrc(5),pixTOrc(52.75),"USER PANEL LOGIN");
			  break;


	case 2 : outtextxy(pixTOrc(5),pixTOrc(52.75),"SEARCH FOR FLIGHTS");
		 break;
	case 3 : outtextxy(pixTOrc(5),pixTOrc(52.75),"PNR STATUS");
		 break;
	case 4 : outtextxy(pixTOrc(5),pixTOrc(52.75),"EXIT SOFTWARE");
		 break;
      }

      setcolor(WHITE);
      settextstyle(3,HORIZ_DIR,2);
      int key = getch();
      if (key==49)
      regisu();
      if(key==48)
      regisa();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 72: normalvideo(COL, (i*INC)+ROW, MMenu[i]);
			  i--;
			      if (i == -1)
			   i = MAXITEM-1;
			   selectedMenu(COL,(i*INC)+ROW,MMenu[i]);
			break;
	       case 80: normalvideo(COL, (i*INC)+ROW, MMenu[i]);
			  i++;
			  if (i == MAXITEM)
			   i = 0;
			   selectedMenu(COL, (i*INC)+ROW, MMenu[i]);
			break;

	    }
	    break;
	 case 13: done = 1;
	 break;

      }
   }
   while (!done);
   return(i+49);
}
void pnr()
{
clrscr();
cleardevice();
settextstyle(4,0,4);
setcolor(BLUE);
outtextxy(130,10,"  PNR STATUS ");
settextstyle(1,0,2);
int noofseats,pnr;
char nam[30],from[30],to[30],via[30],fl[30],dat[30];
cout<<"\n\n\n\n\nENTER PNR :-";
int p;
cin>>p;
int flag=0;
ifstream op;
op.open("booking.dat");
while(1)
{
if(!op)
break;
else
{
op>>pnr>>nam>>noofseats>>from>>to>>via>>fl>>dat;
if(op&&pnr==p)
{
flag=1;
cout<<"\n\n\n\n\nPNR NO:- "<<pnr<<"\n\nNAME OF PASSENGER:-"<<nam<<"\n\nNO OF SEATS BOOKED:- "<<noofseats<<"\n\nBOARDING :- "<<from<<"\t UPTO:- "<<to <<"\n\nFLIGHT NAME:- "<<fl<<"\t BOIENG NO:-"<<via<<"\n\nDATE OF JOURNEY:-"<<dat<<"\n";
break;
}
}
}
op.close();
if(flag==0)
{ ifstream ip;
ip.open("can.dat");
while(1)
{
if(!ip)
break;
ip>>pnr>>nam>>noofseats>>from>>to>>via>>fl>>dat;
if(ip&&pnr==p)
{
flag=1;
cout<<"\n\n__________________________THIS IS CANCELLED TICKET___________________________ ";
cout<<"\n\n\n\n\nPNR NO:- "<<pnr<<"\n\nNAME OF PASSENGER:-"<<nam<<"\n\nNO OF SEATS BOOKED:- "<<noofseats<<"\n\nBOARDING :- "<<from<<"\t UPTO:- "<<to <<"\n\nFLIGHT NAME:- "<<fl<<"\t BOIENG NO:-"<<via<<"\n\nDATE OF JOURNEY:-"<<dat<<"\n";

cout<<"__________________________THIS IS CANCELLED TICKET___________________________ ";
break;

}
}
}
if(flag==0)
{
cout<<"\n\n------------------------ENTER A VALID PNR NO-----------------------------";
cout <<"\n\n\n\n\t\t\tPRESS ANY KEY TO RETURN";
}getch();
call_menu();
}
void call_menu()
{
clrscr();
cleardevice();
setcolor(RED);
settextstyle(4,0,4);
outtextxy(50,30,"Welcome To Airline Reservation System");
setfillstyle(4,9);
   bar(pixTOrc(7),pixTOrc(14),pixTOrc(25),pixTOrc(50));
   char choice;

      choice = menu();
      switch (choice)
      {
	 case '1':adminlogin();

	 break;
	case '2':userlogin();

	break;
	case '3': searchfl();


		 break;
	case '4':pnr();

		 break;
	case '5': exit(1);
	 }
}

void logo()
{
rectangle(245,143,368,160);
rectangle(245,175,368,192);
}
void adminlogin()
{ if(getch()==27)
call_menu();
char au[30],*ap;
int x,j;
cleardevice();
logo();


gotoxy(25,10);
setcolor(9);
settextstyle(4,0,1);
outtextxy(150,136,"Username:");
outtextxy(150,168,"Password:");
setcolor(5);
outtextxy(380,136,"(Press enter after entering)") ;
outtextxy(380,168,"(Enter your 8 digits password)");
settextstyle(4,0,3);
while(!kbhit())
{
setcolor(BLUE);
outtextxy(210,30,"Administration Login");
delay(50);
setcolor(RED);
outtextxy(210,30,"Administration Login");
delay(50);
}
gotoxy(32,10);
gets(au);
gotoxy(32,12);
ap=getpass("");
gotoxy(30,30);
settextstyle(4,0,2);
setcolor(6);
outtextxy(160,280,"loading! please wait.");
setcolor(BLUE);
rectangle(180,325,280,330);
x=180;
for(j=0;j<=100;++j)
{
if(j%2==0)
setcolor(RED);
else
setcolor(GREEN);
line(x,325,x,330);
delay(10);
x=x+1;
}
login1(au,ap);
}


void userlogin()
{ if(getch()==27)
call_menu();
cleardevice();
char uu[30],*up;
int x,j;
logo();

gotoxy(25,10);
setcolor(9);
settextstyle(4,0,1);
outtextxy(150,136,"Username:");
outtextxy(150,168,"Password:");
setcolor(5);
outtextxy(380,136,"(Press enter after entering)") ;
outtextxy(380,168,"(Enter your 8 digits password)");
settextstyle(4,0,3);
while(!kbhit())
{
setcolor(BLUE);
outtextxy(210,30,"User Login");
delay(50);
setcolor(RED);
outtextxy(210,30,"User Login");
delay(50);
}
gotoxy(32,10);
gets(uu);
gotoxy(32,12);
up=getpass("");
gotoxy(30,30);
settextstyle(4,0,2);
setcolor(6);
outtextxy(160,280,"loading! please wait.");
setcolor(BLUE);
rectangle(180,325,280,330);
x=180;
for(j=0;j<=100;++j)
{
if(j%2==0)
setcolor(RED);
else
setcolor(GREEN);
line(x,325,x,330);
delay(10);
x=x+1;
}
login2(uu,up);
}

void searchfl()
{
cleardevice();
settextstyle(4,0,4);
outtextxy(30,30,"flight search");
getch();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
int flag=0;
char s[30];
char board[30],des[30],date[30];
char a[30],b[30],c[30],e[30],g[30],h[30],dd[30],name[30];
int f,i;
char fname[30],flight[30];
int seats;

cout<<"ENTER BOARDING PLACE:- ";
cin>>board;
cout<<"ENTER DESTINATION PLACE:- ";
cin>>des;
cout<<"DATE OF JOURNEY:- ";
cin>>date;
cout<<"\n\n\n\n";
ofstream b1;
b1.open("1.dat",ios::app);

b1.close();
ifstream ab1;
ab1.open("1.dat");
while(1)
{
if(!ab1)
break;
else
{
ab1>>a>>b>>c>>dd>>e>>f>>g>>h;
if(strcmp(board,g)==0&&strcmp(des,h)==0&&strcmp(date,c)==0)
{
flag++;
cout<<flag<<":)"<<"FLIGHT NO :"<<a<<" SERVICE BY:"<<b<<"-"<<a<<"\n"<<" DATE OF JOURNEY:"<<c<<" TIME:"<<dd<<" DURATION:"<<e<<" SEATS:"<<f<<"\n"<<" FROM:"<<g<<" TO:"<<h<<"\n\n\n";
}
}
}
if(flag==0)
{cout<<"RENTER DETAILS/NO SUCH FLIGHTS FOUND\n";
cout<<"\n\n\n\t\t ESC TO RETURN";
}
getch();
call_menu();
}




void main()
{
int gm=0,gr;
initgraph(&gm,&gr,"C:\\TurboC3\\BGI");

   call_menu();
}