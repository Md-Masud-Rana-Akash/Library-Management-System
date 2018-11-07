#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<cstdlib>
#include <ctime>

using namespace std;

 #define DTTMFMT "%Y-%m-%d %H:%M:%S "
 #define DTTMSZ 21

   static char *getDtTm (char *buff){
    time_t t = time (0);
    strftime (buff, DTTMSZ, DTTMFMT, localtime (&t));
    return buff;
    }


  class book{
      public:
        void check();
   };


class st:public book{
     char id[30],s[30],d[30];
     public:
     void reg();

};

class tc:public book{
    int room;
    char t[30],id[30],dp[30];
    public:
    void reg();

};

class stf:public book{
     char id[30];
     char n[30];
     public :
     void reg();
};


void book::check(){



char sid[20][30],sid2[30],bo[30],bid[30],wr[30],b[20][30],k[20][30];
    int x,as,q;
    int p,p2,v,p3,i,g,l,j,is,am=10,cnt=0,c=0;


    fflush(stdin);
    cout<<"Enter your ID Number"<<endl;
    cin.getline(sid2,30);
    ifstream reg;
    reg.open("Reg.txt",ios::app);                      //file 1
    for(as=0;as<10;as++){
    reg.getline(sid[as],30);
    }
    reg.close();
    p=strlen(sid2);
   for(is=0;is<20;is++) {
           for(q=0; q<p; q++) {

               if(strcmp(sid2,sid[is])==0) {
                        printf("Match Found ");
                        c++;
                        break;
               }
              else
                 break;
        }


      }


        if(c!=0){
            cout<<"Yes You are Registred"<<endl;
             fflush(stdin);
            cout<<"Which Book do you want to take: ?";
            cin.getline(bo,30);
            fflush(stdin);
            cout<<"Enter the Writer name: ?";
            cin.getline(wr,30);



        ifstream ak;
        ak.open("Tfile.txt",ios::app);                           //file 2
     for(x=0;x<20;x++){
        ak.getline(b[x],30);
        ak.getline(k[x],30);
        }
     ak.close();

    p2=strlen(bo);
            p3=strlen(wr);
        for(v=0;v<20;v++){
            for(j=0;j<p2;j++){
                for(l=0;l<p3;l++){

                          if((strcmp(bo,b[v])==0)&&(strcmp(wr,k[v])==0)) {
                        cnt++;
                        break;
               }
              else
                 break;
                    }
                }
            }
            if(cnt!=0){
                cout<<"Yes this book is Available "<<am<<" copy in our Library"<<endl;
                cout<<"Book id is :";
                for(g=0;g<p;g++){
                        bid[g]=sid2[p-g];
                            cout<<bid[g];

            }

            time_t now = time(0);
            tm* localtm = localtime(&now);
            cout<<endl<<endl<<endl<<"Today is "<< asctime(localtm)<<"You Have to return the Book within a week otherwise you will be fined 50 tk"<<endl;
            cout<<"Thank You :)"<<endl;




    char buff[DTTMSZ];

    ofstream take;
    ofstream rec;


    take.open("take.txt",ios::app);
    rec.open("rec.txt",ios::app);
                    take<< getDtTm (buff);    //Here at file First save local date,then time,then the id number
                    fflush(stdin);
                    take<<sid2<<endl;
                rec<< getDtTm (buff)<<endl;
                rec.close();
                    take.close();


}

        else
            cout<<"Sorry this Book is not available"<<endl;
    }


    else

        cout<<"Please Register First to Take book from the Library"<<endl;

}


void st::reg(){
             int pr;
                ofstream  stf;
                 stf.open("Info_stdnt.txt",ios::app);                   //file 3
                 ofstream reg;
                    reg.open("Reg.txt",ios::app);
                    fflush(stdin);
                    cout<<"Enter your ID number: ";
                    cin.getline(id,30);
                    stf<<id<<endl;
                    reg<<id<<endl;
                    reg.close();
                    fflush(stdin);
                    cout<<"Enter your Name: ";
                    cin.getline(s,30);
                    stf<<s<<endl;
                    fflush(stdin);
                    cout<<"Enter your Department: ";
                    cin.getline(d,30);
                    stf<<d<<endl;
                    cout<<"Congratulation Your Registration is Successfull"<<endl;
                stf.close();
                cout<<"Now You Can Take Book from the Library,Do you want to take now?"<<endl<<"If yes Then Press 1 otherwise Press 2"<<endl;
                 cin>>pr;
                if(pr==1){
                 check();
                }
                else
                    cout<<"Thank you for your Registration;"<<endl;
            }

void tc::reg(){
            int pr;
                ofstream tcf;
                tcf.open("Info_tch.txt",ios::app);
                    fflush(stdin);                                      //file 4
                    cout<<"Enter your Name: ";
                    cin.getline(t,30);
                    tcf<<t<<endl;
                    ofstream reg;
                    reg.open("Reg.txt",ios::app);
                    fflush(stdin);
                    cout<<"Enter your ID Number: ";
                    cin.getline(id,30);
                    tcf<<id<<endl;
                    reg<<id<<endl;
                    reg.close();
                    fflush(stdin);
                    cout<<"Enter your Department: ";
                    cin.getline(dp,30);
                    tcf<<dp<<endl;
                    cout<<"Enter your room number: ";
                    cin>>room;
                    tcf<<room<<endl;
                    cout<<"Congratulation Your Registration is Successfull"<<endl;
                tcf.close();
                 cout<<"Now You Can Take Book from the Library,Do you want to take now?"<<endl<<"If yes Then Press 1 otherwise Press 2"<<endl;
                  cin>>pr;
                if(pr==1){

                check();
                }
                else
                    cout<<"Thank you for your Registration;"<<endl;
            }

void stf::reg(){
        int pr;
                ofstream st;
                st.open("Info_staff.txt",ios::app);             //file 5
                    fflush(stdin);
                    cout<<"Enter your Name: ";
                    cin.getline(n,30);
                    st<<n<<endl;
                 ofstream reg;
                 reg.open("Reg.txt",ios::app);

                    fflush(stdin);
                    cout<<"Enter your ID Number: ";
                    cin.getline(id,30);
                    st<<id<<endl;
                    reg<<id<<endl;
                    reg.close();
                    cout<<"Congratulation Your Registration is Successfull"<<endl;
                st.close();
                 cout<<"Now You Can Take Book from the Library,Do you want to take now?"<<endl<<"If yes Then Press 1 otherwise Press 2"<<endl;
                 cin>>pr;
                if(pr==1){
                 check();
                }
                else
                    cout<<"Thank you for your Registration;"<<endl;
            }

int main(){
    st a;
    tc b;
    stf c;
    book d;
    int tu,ch,zx,c1,c2;
 for(;;){
    to:
time_t now = time(0);
    tm* localtm = localtime(&now);
    cout<<"Current local time and date is:  "<< asctime(localtm) <<endl;
      cout<<endl<<endl<<endl<<          "                            EWU LIBRARY"<<endl<<endl<<endl<<"How Can I Help You?"<<endl;

      cout<<"Please Select From Below :"<<endl;
       cout<<endl<<"1.ADMIN Mode"<<endl;
       cout<<"2.NORMAL Mode"<<endl;
        cout<<"3.Exit"<<endl;
       cin>>zx;
      if(zx==1)
      {
          char pwd[]="akash";
            char s[5];
                int c=0,p,i;
                    cout<<"Enter password"<<endl;
                for(i=0;i<5;i++){
                    s[i]=getch();
                        cout<<"*";
                                }
                    for(p=0;p<5;p++){
                        if (s[p]==pwd[p])
                                    c++;
                                    }
                            if(c==5){

                                cout<<endl<<"Correct :)"<<endl;

                            int xi,jh;
                            cout<<"How many  Books"<<endl;
                            cin>>jh;


                             char bi[jh][15];
                             char ki[jh][15];
                                  ofstream ak;
                                        ak.open("Tfile.txt",ios::app);                                   //file 2
                                            for(xi=0;xi<jh;xi++){
                                                fflush(stdin);
                                                cout<<"ENTER THE BooK NAME:";
                                                cin.getline(bi[xi],15);
                                             ak<<bi[xi]<<endl;
                                             fflush(stdin);
                                                 cout<<"ENTER The WRITER NAME:";
                                                 cin.getline(ki[xi],15);
                                             ak<<ki[xi]<<endl;
                                              ak.close();


                                        cout<<"    *****************************************";
                                        cout<<endl<<"       Book Name:"<<bi[xi];
                                        cout<<endl<<"       Writer Name:"<<ki[xi]<<endl;
                                        cout<<"    *****************************************"<<endl;
                                             cout<<endl<<"Stored Successfully"<<endl<<endl<<endl<<endl;

                                            }
                                            goto to;

                            }
                            else
                                    cout<<endl<<"!!!Access Denied!!!";

                        return 0;
      }

else if(zx==2){
      cout<<"  1. For Registration"<<endl;
      cout<<"  2. For taking Books from the library"<<endl;
      cin>>ch;}
else if(zx==3)
    return 0;
else
    cout<<"Invalid Input"<<endl;


 if(ch==1){

        cout<<"Are you a Student,Teacher or Staff ?"<<endl;
        cout<<" Press 1 if you are a Student"<<endl<<" Press 2 if you are a Teacher"<<endl<<" Press 3 if you are a Staff"<<endl;
        cin>>c1;
            if(c1==1)
               a.reg();
            else if(c1==2)
               b.reg();
            else if(c1==3)
               c.reg();
            else
                cout<<"Sorry input a valid number and try again"<<endl;

}

else if(ch==2){
        cout<<"Are you a Student,Teacher or Staff ?"<<endl;
        cout<<" Press 1 if you are a Student"<<endl<<" Press 2 if you are a Teacher"<<endl<<" Press 3 if you are a Staff"<<endl;
        cin>>c2;
        if(c2==1)
          d.check();
        else if(c2==2)
          d.check();
        else if(c2==3)
          d.check();
          else
             cout<<"!!!Sorry Invalid Input!!!"<<endl;
}
else
    cout<<"!!!Sorry Invalid Input!!!"<<endl;
getchar();
}


getchar();

return 0; }

