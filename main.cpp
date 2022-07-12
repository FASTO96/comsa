#include <iostream>
#include <limits>
#include <fstream>




using namespace std;


class fun
{
    public:
        string finl;
        string name = "";
        string ports ="";
        string volume ="";
        string interface ="";
        string subnet ="";
        string gateway ="";
        string netconf ="\nnetworks:";
        string ip ="";
        string dockerfile;
        string environment = "\n    environment:";
        string buildoption;
        string depends_on;
        ofstream dffille,dffille2;
        int ibi = 0;
        string image ="";
        bool creatint=0;
        int opft[3];
        // string listofinterface[1];
        string n;
        string listofinterface [24];




        string sername1();
//listoffunc

        string fun_interface();
        string fun_new_interface();
        string fun_ip();

        string dockerfilecreate();
        string fup();
        string build();
        string volumes();
        string net(int alfa,string interx);
        void optn();


};


string fun::sername1()
{

    string i = "debian";

        string x = "\n  "+name+":\n    image: "+image;
        return x;

}


string fun::fup()

{


   string w="\n    ports:\n     - \""+ports+"\"";
    return w;

}

string fun::build()

{


   string w= "\n  "+name+":\n    build:\n      context: .\n      dockerfile: "+dockerfile;
    return w;

}


string fun::volumes()

{


   string w="\n    volumes:\n     - \""+volume+"\"";
    return w;

}

string fun::net(int alfa,string interx)

{


    if (alfa==0){
      netconf+="\n     "+interface+":"+"\n       driver: bridge\n       ipam:";
      netconf+="\n          config:\n            - subnet: "+subnet;
      netconf += "\n              gateway: "+gateway;
      string w="\n    networks:\n      "+interface+":"+"\n        ipv4_address: "+ip;


    return w;}
      if (alfa==1){
      netconf+="\n     "+interx+":"+"\n       driver: bridge\n       ipam:";
      netconf+="\n          config:\n            - subnet: "+subnet;
      netconf += "\n              gateway: "+gateway;
      string w="\n    networks:\n      "+interface+":"+"\n        ipv4_address: "+ip;


    return w;}


}

void fun::optn()

{
    system("clear");
     cout<<"options:";
     cout <<"\nports" ;
          if(opft[1]==0)

        cout <<"\nnetwork" ;
          if(opft[2]==0)

        cout <<"\nvolumes" ;
          if(opft[3]==0)
        cout <<"\ndepends_on" ;
         if(opft[4]==0&&creatint==1)
          cout <<"\nnew_network" ;

         if(opft[6]==0&&creatint==1)
          cout <<"\nip" ;

        if(opft[8]==0)

        cout <<"\nrestart";

    cout <<"\nenvironment" ;
    cout <<"\nexit" ;
}
string fun::dockerfilecreate()
{
    string q,fo,w,s2,ser2;
    int fr = 0;
    //cout <<"\noptions:\n-FROM(image name)\n-RUN(install)\n-ADD(move file)\n-CMD(command)";
    while(q!="exit")
    {
        system("clear");
        cout <<"\noptions:\n-FROM(image name)\n-RUN(install)\n-ADD(move file)\n-CMD(command)\nsupervisor";
        cout <<"\noption->";
        cin >>q;
        if(fr!=1)
        {

            cout<<"\nentre image name\nFROM->";
            cin >>w;
            fo+="\nFROM "+w;
            fr= 1;
        system("clear");

        }
        if(q == "RUN"||q=="run")
        {
            cout<<"\nentre what you want to install\nRUN->";

            cin >>w;
            fo+="\nRUN apt update && apt install -y "+w;
            system("clear");
        }

        if(q == "ADD"||q=="add")
        {
            cout<<"\nentre path\nfilepathinyourmachine->";
            cin >>w;
            fo+="\nADD "+w;
            cout<<"\nfilepathincont->";
            cin >>w;
            fo+= w;

            system("clear");
        }
        if(q == "CMD"||q=="cmd")
        {
            cin >>w;
            fo+=w;
            system("clear");
        }

            if(q == "supervisor")
        {
              cout<<"\nenter dire name\n";
              cout <<"\ndir->";
              cin >>s2;
              cout<<"\nenter service name\n";
              cout <<"\nservice->";
              cin >>ser2;
              fo+="\nRUN apt update && apt install -y supervisor "+w;
              fo+= "\nADD /"+ s2 +" /src/supervisor";
              fo+="\nCMD [\"supervisord\",\"-c\",\"/src/supervisor/service_script.conf\"]";
              system("clear");



        }

    }
    dffille.open(dockerfile);
    dffille << fo;
    dffille.close();

return fo;
}

int main()
{

    fun fon;
    string inx;
    ofstream dcom;

    int nameofserviceset=0;
    for (int i = 0;i<9;i++)
        fon.opft[i]=0;

    int l = 0 ;
    int po = 0;
    string options;
    int req=0;

    string temp ="version: \"3.9\"\nservices:" ;
    string yam= temp;
    string opt[9] = {"ports","network","volumes","new_network","depends_on","quit","ip","environment","restart"};

    int nos;
    string comm = "hello";
    string exit= "exit";
    cout <<"enter number of service you want: ";

       while (true)
  {
    cin >> nos;
    if (!cin)
    {
      cout << "Please enter a number. Enter again:" << endl;
      cin.clear();
      cout<<"->";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    else break;
  }

    while(comm!=exit)
        {

        while(options!=exit){
            if (nameofserviceset!=1){
              cout <<"entre the name of " <<" service "<<l+1<<": ";
              cin>>fon.name ;
              system("clear");
              cout<<"options(default image):\n - image\n - build \n" ;
              cout<<"\noptions->";
              cin>> fon.buildoption;
              if(fon.buildoption=="build")
                {
                    cout <<"building * * * *\n";
                    cout <<"enter dockerfile name:\n";
                    cout <<"dockerfile->";
                    cin>>fon.dockerfile;

                    system("clear");
                    cout <<fon.dockerfilecreate();

                    yam +=  fon.build();
                    nameofserviceset = 1;





                }


                else {
                  cout <<"entre the image name of " <<fon.name<<" ";
                  cout<<"\ncomsa-> ";
                  cin>>fon.image;
                  yam += fon.sername1();
                  system("clear");
                  nameofserviceset = 1;
            }

            }
            system("clear");
           fon.optn();

           cout<< "\noptions->";
           cin >> options;
           system("clear");

          if(options==opt[0]){ //port
             system("clear");
             cout <<"entre the port of " <<fon.name<<" (local:docker)";
             cout<<"\ncomsa-> ";
             cin>> fon.ports;
              yam += fon.fup();
              system("clear");
              }// end


        if(options==opt[2]){ //volume
             system("clear");
             cout <<"\nentre the volumes of " <<fon.name<<"example: (/home/sam/www/:/var/www/html)";
             cout<<"\ncomsa-> ";
             cin>> fon.volume;
              yam += fon.volumes();
              system("clear");
              }// end

        if(options==opt[8]){ //restart
              string w="\n    restart: unless-stopped";

              yam += w;
            fon.opft[8]=1;


              }

      if(options==opt[4]){ //depends_on
             system("clear");
             cout <<"\nentre name of container:" ;
             cout<<"\ncomsa-> ";
             cin>> fon.depends_on;
            string w="\n    depends_on:\n     - \""+fon.depends_on+"\"";

              yam += w;
              system("clear");
              }// end


            if(options==opt[1]){ //interface
              if(fon.creatint==0){
                  fon.fun_interface();

             }

              cout <<"entre ip: " ;
              cout<<"\ncomsa-> ";
              cin>>fon.ip ;

              yam += fon.net(0,"0");
             system("clear");

              fon.opft[1]=1;
            }



            if(options==opt[3]){ //new interface

            fon.fun_interface();


             system("clear");


            }
            //end

                  if(options==opt[7]){ //environment
                        string w;
                         system("clear");
                         cout <<"\nentre environmentexample :(MYSQL_ROOT_PASSWORD: root)\n" ;
                         while(w!="exit"){
                                cout<<"\nenvironment (1:B)->  ";
                                cin>> w;
                                if(w!="exit")
                                    fon.environment+="\n        "+w;
                                cout<<"\nenvironment(A:2)-> ";
                                if(w!="exit")
                                {
                                    cin>> w;
                                    fon.environment+=": "+w;

                               }
                               cout<<"enter exit if you finsh\n";
                               }

                        yam += fon.environment;
                        system("clear");
              }// end



         if(options==opt[6]){ //ip

                if(fon.opft[1]==1){

              cout <<"\nlist of interface: \n";
              for (int kx=0;kx<fon.ibi;kx++)
              {
                    cout <<"\n"<<fon.listofinterface[kx];
              }
              cout <<"\nentre interface: " ;
              cout<<"\ncomsa-> ";
              cin>>inx ;
              cout <<"entre ip: " ;
              cout<<"\ncomsa-> ";
              cin>>fon.ip ;

              yam += fon.net(1,inx);
              system("clear");
              fon.opft[1]=1;


              }




            }


             }
             options= "";
             fon.opft[0]=0;
             fon.opft[1]=0;
             fon.opft[2]=0;
             fon.opft[3]=0;
             fon.opft[4]=0;
             fon.opft[5]=0;
             fon.opft[6]=0;
             fon.opft[8]=0;

             nameofserviceset =0;
             req = 0;
            l++;
             if (l ==nos){
                comm="exit";
             }
        }
            if(fon.creatint==1){
            yam+=fon.netconf;}
    dcom.open("docker-compose.yaml");
    dcom << yam;
    dcom.close();

        cout <<yam;
        return 0;


//    system(temp.c_str());

}

string fun::fun_interface()
{


                  cout <<"entre the name of interface " ;
                  cout<<"\ncomsa-> ";
                  cin>>interface;
                  listofinterface[ibi] = interface;
                  ibi++;
                  cout <<"\nentre the subnet (example:192.168.1.1/24): " ;
                  cout<<"\ncomsa-> ";
                  cin>>subnet ;

                  cout <<"\nentre the gateway (example:192.168.1.0): " ;
                  cout<<"\ncomsa-> ";
                  cin>>gateway ;
                  creatint=1;

return "";
}
