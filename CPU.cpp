#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include <string.h>
#include <string>
#include <cstdlib>
#include<bits/stdc++.h>
#include <vector>
#include <sstream>
using namespace std;

int actual_size=0;
int actual_size2=0;
int actual_size3=0;
struct Process
{
    
    char name;
    int id;
    int arrivaltime;
    int servicetime;
    int work[30];
    int wait;
    int workk;
    int finishtime;
    float HRRN;
    int pry;
    int last_inst;
};
void print(vector<Process>& Processes,int numberofp,int type,string form,int last_inst,int quant)
{

    
    if(form == "trace")
    {   if(type==3)
        cout<<"SPN   ";
    if(type==4)
        cout<<"SRT"<<"   ";
    else if(type==5)
        cout<<"HRRN"<<"  ";
    else if(type==2)
        cout<<"RR"<<"-"<<quant<<"  ";
    else if(type==6)
        cout<<"FB"<<"-"<<"1"<<"  ";
    else if(type==7)
    {
        cout<<"FB"<<"-"<<"2i"<<" ";
    }
        for(int i=0; i<last_inst/10; i++)
        {
            cout<<"0 1 2 3 4 5 6 7 8 9 ";
        }
        cout<<"0 "<<"\n";
        cout<<"------------------------------------------------\n";
        for(int z=0; z<numberofp; z++)
        {
            cout<<Processes[z].name<<"     ";
            for(int x=0; x<last_inst; x++)
            {
                if(Processes[z].work[x]== -3)
                    cout<<"|.";
                else if(Processes[z].work[x]== 1)
                    cout<<"|*";
                else
                    cout<<"| "  ;

            }
            cout<<"| ";
            cout<<"\n";
        }
        cout << "------------------------------------------------\n\n";
    }

    if(form == "stats")
    {   if(type==3)
        cout<<"SPN";
    if(type==4)
        cout<<"SRT";
    else if(type==5)
        cout<<"HRRN";
    else if(type==2)
        cout<<"RR"<<"-"<<quant;
    else if(type==6)
        cout<<"FB"<<"-"<<"1";
    else if(type==7)
    {
        cout<<"FB"<<"-"<<"2i";
    }
         cout<<"\n";
        cout<<"Process  ";
        for(int z=0; z<numberofp; z++)
        {
            cout<<"  |  "<<Processes[z].name;
        }
        cout<<"  |";
        cout<<"\n";
        cout<<"Arrival  ";
        for(int z=0; z<numberofp; z++)
        {
            cout<<"  |  "<<Processes[z].arrivaltime;
        }
        cout<<"  |";
        cout<<"\n";
        cout<<"Service  ";
        for(int z=0; z<numberofp; z++)
        {
            cout<<"  |  "<<Processes[z].workk;
        }
        cout<<"  | Mean|\n";
        cout<<"Finish     ";
        for(int z=0; z<numberofp; z++)
        {   if( (Processes[z].finishtime/10)==0){
            cout<<"|  "<<Processes[z].finishtime<<"  ";
            }
            else{
                cout<<"| "<<Processes[z].finishtime<<"  ";
            }
        }
        cout<<"|-----|";
        cout<<"\n";
        cout<<"Turnaround ";
        float turnaround[numberofp];
        float meant=0.00;
        for(int i=0; i< numberofp; i++)
        {
            turnaround[i]=Processes[i].finishtime-Processes[i].arrivaltime;
            if( (int(turnaround[i])/10)==0){
            cout<<"|  "<<int(turnaround[i])<<"  ";
            }
            else{
                cout<<"| "<<int(turnaround[i])<<"  ";
            }
            meant=meant+turnaround[i];
        }
        meant=meant/numberofp;
        if( int(meant/10) == 0 ){
        cout<<"| "<<fixed<<setprecision(2)<<meant<<"|";
        }
        else{
            cout<<"|"<<fixed<<setprecision(2)<<meant<<"|";
        }
        cout<<"\n";
        cout<<"NormTurn   ";
        float norm2[numberofp];
        float meant2=0.00;

        for(int i=0; i< numberofp; i++)
        {
            norm2[i]=(turnaround[i]*1.00)/Processes[i].workk;
            cout<<"| "<<fixed<<setprecision(2)<<norm2[i];
            meant2=meant2+norm2[i];
        }
        meant2=meant2/numberofp;
        if( int(meant2/10) == 0 ){
        cout<<"| "<<fixed<<setprecision(2)<<meant2<<"|"<<"\n";
        }
        else {
            cout<<"|"<<fixed<<setprecision(2)<<meant2<<"|"<<"\n";
        }
        cout << endl;
    }
}



vector<Process> save(vector<Process>& Processes,int num_of_processes)
{
    vector<Process> vectorcopy(num_of_processes);

    for(int p=0; p<num_of_processes; p++)
    {
        vectorcopy[p].name=Processes[p].name;
        vectorcopy[p].id=Processes[p].id;
        vectorcopy[p].arrivaltime=Processes[p].arrivaltime;
        vectorcopy[p].servicetime=Processes[p].servicetime;
    }
    return vectorcopy;
}



int minimum(vector<int> v,vector<Process> Processes )
{
    int min=1000000;
    int IDMIN;
    for(int x=0; x<actual_size; x++)
    {
        int idd=v[x];
        // cout<<"HRRN of Processes["<<x<<"]= "<<Processes[idd].HRRN<<endl;
        if(min > Processes[idd].servicetime)
        {
            min=Processes[v[x]].servicetime;
            IDMIN=x;
            // cout<<"Minimum updated = "<<min<<"// ID// Process of max= "<<IDMIN<<endl;
        }


    }
    return IDMIN;
}
int minimumSRT(vector<int> v,vector<Process> Processes )
{
    int min=1000000;
    int IDMIN;
    for(int x=0; x<actual_size3; x++)
    {
        int idd=v[x];
        // cout<<"HRRN of Processes["<<x<<"]= "<<Processes[idd].HRRN<<endl;
        if(min > Processes[idd].servicetime)
        {
            min=Processes[v[x]].servicetime;
            IDMIN=x;
            // cout<<"Minimum updated = "<<min<<"// ID// Process of max= "<<IDMIN<<endl;
        }


    }
    return IDMIN;
}
int maximumHRRN(vector<int> v,vector<Process> Processes )
{
    float max=-1000000;
    int IDMAX;
    for(int x=0; x<actual_size; x++)
    {
        int idd=v[x];
        if(max< Processes[idd].HRRN)
        {
            max=Processes[v[x]].HRRN;
            IDMAX=x;
             }


    }
    return IDMAX;
}

int maximumFB(vector<int> v,vector<Process> Processes )
{
    int max=-1000000;
    int IDMAX;
    for(int x=0; x<actual_size2; x++)
    {
        int idd=v[x];
          if(max< Processes[idd].pry)
        {
           // cout<<"entered"<<endl;
            max=Processes[v[x]].pry;
            //cout<<"max = "<<max<<endl;
            IDMAX=x;
            //  cout<<"MAXIMUM updated = "<<max<<"// ID// Process of max= "<<IDMAX<<endl;
        }


    }
    return IDMAX;
}

int remove1stelementANDreturn(vector<int>& nums1,vector<Process>& Processes)

{
    int val=nums1[0];
    for(int s=1; s<actual_size; s++)
    {
        nums1[s-1]=nums1[s];
        nums1[s]=0;
    }
    actual_size--;
    Processes[val].HRRN=-1000;

    return val;
}
int remove1stelementFBANDreturn(vector<int>& nums,vector<Process>& ProcessFB)

{
    int val=nums[0];
    for(int s=1; s<actual_size2; s++)
    {
        nums[s-1]=nums[s];
        nums[s]=0;
    }
    actual_size2--;
    ProcessFB[val].HRRN=-1000;

    return val;
}
int remove1stelementSRTANDreturn(vector<int>& nums,vector<Process>& ProcessSRT)

{
    int val=nums[0];
    for(int s=1; s<actual_size3; s++)
    {
        nums[s-1]=nums[s];
        nums[s]=0;
    }
    actual_size3--;
    
    return val;
}
void FCFS(string form,int last_inst,int numberofp,char process[100],float wt[100],float arrivalt[100],float servicet[100])
{
    
    if(form == "trace")
    {   cout << "FCFS  ";
        for(int l=0; l<last_inst/10; l++)
        {
            cout << "0 1 2 3 4 5 6 7 8 9 ";
        }
        cout << "0 ";
        cout << "\n";
        cout << "------------------------------------------------\n";
        for(int i=0; i<numberofp; i++)
        {
            cout << process[i] << "     ";
            for(int m=0; m<arrivalt[i]; m++)
            {
                cout << "| ";
            }
            for(int k=arrivalt[i]; k<wt[i]; k++)
            {
                cout << "|.";
            }
            for(int j=wt[i] ; j<servicet[i]+wt[i]; j++)
            {
                cout << "|*";
            }
            for(int n=wt[i]+servicet[i]; n<last_inst+1; n++)
            {
                cout << "| ";
            }
            cout << "\n";
        }
        cout << "------------------------------------------------\n\n";
    }
    else if(form=="stats")
    {   cout << "FCFS";
        cout <<"\n";
        cout <<"Process  ";
        for(int i=0; i<numberofp; i++)
        {
            cout <<"  |  "<<process[i];
        }
        cout <<"  |";
        cout <<"\n";
        cout <<"Arrival  ";

        for(int i=0; i<numberofp; i++)
        {
            cout <<"  |  "<<arrivalt[i];
        }
        cout <<"  |";
        cout <<"\n";
        cout <<"Service  ";
        for(int i=0; i<numberofp; i++)
        {
            cout <<"  |  "<<servicet[i];
        }
        cout <<"  | Mean|\n";
        cout <<"Finish     ";
        for(int i=0; i<numberofp; i++)
        {   if( (int(wt[i]+servicet[i])/10) == 0 ){
            cout <<"|  " <<(wt[i]+servicet[i])<<"  ";
            }
            else{
                cout <<"| " <<(wt[i]+servicet[i])<<"  ";
            }
        }
        cout <<"|-----|";
        cout <<"\n";
        cout <<"Turnaround ";
        float turnaround[numberofp];
        float meant=0.00;
        for(int i=0; i<numberofp; i++)
        {
            turnaround[i] = (wt[i]+servicet[i])-arrivalt[i];
            if((int(turnaround[i])/10) == 0){
            cout <<"|  "<<turnaround[i]<<"  ";
            }
            else{
                cout <<"| "<<turnaround[i]<<"  ";
            }
            meant=meant+turnaround[i];
        }
        meant = meant/numberofp;
        if( int(meant/10) == 0 ){
        cout << "| " <<fixed << setprecision(2)<< meant << "|" ;
        }
        else{
            cout << "|" <<fixed << setprecision(2)<< meant << "|" ;
        }
        cout << "\n";
        cout << "NormTurn   ";
        float norm[numberofp];
        float meann=0.00;
        for(int j=0; j<numberofp; j++)
        {
            norm[j]=0.00;
        }
        for(int i=0; i<numberofp; i++)
        {
            norm[i] =(((wt[i]+servicet[i])-arrivalt[i])/servicet[i]);
            cout << "| " << fixed << setprecision(2) << norm[i];
            meann=meann+norm[i];
        }
        meann=meann/numberofp;
         if( int(meann/10) == 0 ){
        cout << "| " <<fixed << setprecision(2)<< meann << "|" <<"\n\n";
        }
        else{
            cout << "|" <<fixed << setprecision(2)<< meann << "|" <<"\n\n";
        }
    }

}

int main()
{

    int last_inst,quant;
    int typeoffs,numberofquants,numberofp;
    int flag =0;
    string type1;
    string form;
    cin >> form;
    //cout << "Enter type of schedule";
    cin >> type1;
    vector <string> type;
    stringstream check1(type1);

    string intermediate;

    while(getline(check1, intermediate, ','))
    {
        type.push_back(intermediate);
    }

      cin >> last_inst;
cin >> numberofp;
    vector <Process> Processes(numberofp);
    queue <int> ProcessIDQueue;
    int quantt,ii,st,flagID,flagIDD;
    int work[last_inst];
    int maxi;
    //char letter='A';
    int n=1;

    char process[numberofp];
    float arrivalt[numberofp];
    float servicet[numberofp];
    Process Pr ;
    int sum=0;
    char comma;
    for(int i=0; i< numberofp; i++)
    {
        Processes[i].id= i;

        cin >> Processes[i].name >> comma >> Processes[i].arrivaltime >> comma >> Processes[i].servicetime;

        process[i]=Processes[i].name;
        arrivalt[i]=Processes[i].arrivaltime;
        servicet[i]=Processes[i].servicetime;
       
    }
    float wt[numberofp];
    wt[0]=0;
    for(int i=1; i<numberofp; i++)
    {
        wt[i]=servicet[i-1]+wt[i-1];
    }
   
    vector<Process> Vectorcpy=save(Processes,numberofp);
    for(int i=0; i<type.size(); i++)
    {
        if(type[i]=="1" || type[i]=="3" || type[i]=="4" || type[i]=="5" || type[i]=="6" || type[i]=="7")
        {
            if (type[i]== "1")
            {
                FCFS(form,last_inst,numberofp,process,wt,arrivalt,servicet);
            }
            if(type[i]=="3")
            {
                Processes=Vectorcpy;
                actual_size=0;
                int ix;
                int idSPN;
                vector<int> PrvectorSPN(numberofp);
                for( int j =0; j< numberofp ; j++)
                {
                    if(Processes[j].arrivaltime == 0 )
                    {
                        PrvectorSPN[actual_size]= Processes[j].id;
                        actual_size++;
                         }
                }

                int mini=minimum(PrvectorSPN,Processes);

                  if(actual_size)
                {
                    //  cout<<"BEFORE swap Prvector[mini]= "<<PrvectorSPN[mini]<<"AND  Prvector[0]= "<<PrvectorSPN[0]<<endl;

                    swap(PrvectorSPN[mini],PrvectorSPN[0]);
                    //  cout<<"AFTER swap Prvector[mini]= "<<PrvectorSPN[mini]<<"AND  Prvector[0]= "<<PrvectorSPN[0]<<endl;

                }

                for(int i=0; i < last_inst;)

                {
                    if(actual_size)
                    {
                        idSPN = remove1stelementANDreturn(PrvectorSPN,Processes);
                        // cout<<idSPN<<endl;


                        int tem=Processes[idSPN].servicetime;
                        //   cout<<"service time of"<< idSPN <<" "<<Processes[idSPN].servicetime<<endl;
                        ix=i;
                        while(tem)
                        {
                            Processes[idSPN].work[ix]=1;
                            //   cout<< "at process "<<idSPN<<"at ix = "<<ix<<" : " <<Processes[idSPN].work[ix]<<endl;
                            tem--;
                            ix++;
                        }
                        Processes[idSPN].finishtime=ix;
                        if(ix > i+1)
                        {
                            //  cout<<"entered ix if condition"<<endl;
                            for( int j =0; j<actual_size; j++)
                            {
                                int id3=PrvectorSPN[j];
                                Processes[id3].work[i]=-3;
                             
                            }

                            for(int xx=i+1; xx<= ix; xx++)
                            {
//  cout<< Prvector.size()<<endl;
                                for( int j =0; j< numberofp ; j++)
                                {

                                    if(Processes[j].arrivaltime == xx)
                                    {
                                        PrvectorSPN[actual_size]=Processes[j].id;
                                        actual_size++;
                                        //        cout<<"pushed";
                                    }
                                }

                                // cout<< Prvector.size()<<endl;
                                for( int j =0; j<actual_size; j++)
                                {
                                    int id3=PrvectorSPN[j];
                                    Processes[id3].work[xx]=-3;
                                    //    cout<< "at process "<<id3<<"at xx = "<<xx<<" : " <<Processes[id3].work[xx]<<endl;


                                }

                            }
                        }
                        else
                        {
                            for( int j =0; j<actual_size; j++)
                            {
                                int id3=PrvectorSPN[j];
                                Processes[id3].work[i]=-3;
                                // cout<< "at process "<<id3<<"at xx = "<<i <<" : " <<Processes[id3].work[i]<<endl;


                            }
                            for( int j =0; j< numberofp ; j++)
                            {

                                if(Processes[j].arrivaltime == i+1)
                                {
                                    PrvectorSPN[actual_size]=Processes[j].id;
                                    actual_size++;
                                    //   cout<<"pushed";
                                }
                            }
                        }
                        mini=minimum(PrvectorSPN,Processes);
   if(actual_size)
                        {
                            for(int z=mini; z>0; z--)
                            {
                                swap(PrvectorSPN[z],PrvectorSPN[z-1]);
                                //cout<<"AFTER swap Prvector[mini]= "<<Prvector[z]<<"AND  Prvector[0]= "<<Prvector[z-1]<<endl;
                            }
                        }


                        i=ix;
                    }
                    else
                        i=i+1;
                }
                for(int z=0; z<numberofp; z++)
                {
                    for(int x=0; x<last_inst; x++)
                    {
                        if(Processes[z].work[x]== -3)
                            Processes[z].wait++;
                        else if(Processes[z].work[x]== 1)
                            Processes[z].workk++;
                        // cout<< Processes[z].work[x]<<" ";
                    }
                    //  cout<<"\n";
                }
                // void print(vector<Process>& Processes,int num_of_processes,int type,int last_inst,int quant)
                print(Processes,numberofp,3,form,last_inst,quant);


            }

            if(type[i]=="4")
            {
                int quanto=1;
                Processes=Vectorcpy;
                vector<int> PrvectorSRT(numberofp);
                for( int j =0; j< numberofp ; j++)
                {
                    if(Processes[j].arrivaltime == 0 )
                    {
                        PrvectorSRT[actual_size3]=Processes[j].id;
                        actual_size3++;
                    }
                }
                int id ;
                int ii;
                for(int i=0; i < last_inst;)
                {
                    if(actual_size3)
                    {
                        int id = remove1stelementSRTANDreturn(PrvectorSRT,Processes);


                        if(Processes[id].servicetime > quanto)
                        {
                            quantt = quanto,ii=i;
                            while(quantt)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                quantt --;
                                ii++;
                            }
                            // queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            quantt = quanto,ii=i;
                            while(quantt)
                            {
                                for( int j =0; j<actual_size3; j++)
                                {
                                    int id3=PrvectorSRT[j];
                                    Processes[id3].work[ii]=-3;
                                }
                                quantt --;
                                ii++;
                            }

                            Processes[id].servicetime= Processes[id].servicetime - quanto;
                            flag=1;
                            flagIDD=id;
                        }
                        else if((Processes[id].servicetime <= quanto) && (Processes[id].servicetime !=0) )
                        {
                            st = Processes[id].servicetime,ii=i;
                            while(st)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                Processes[id].finishtime=ii+1;
                                st --;
                                ii++;
                            }
                            // queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            st = Processes[id].servicetime ;
                            ii=i;
                            while(st)
                            {

                                //  int si=ProcessIDQueueCopy.size();
                                //  for(int x=0; x<si; x++)
                                //  {
                                for( int j =0; j<actual_size3; j++)
                                {
                                    int id3=PrvectorSRT[j];
                                    Processes[id3].work[ii]=-3;
                                }

                                st --;
                                ii++;
                            }
                            Processes[id].servicetime= 0;

                            flag=0;

                        }
                        // if(quanto==1)

                        // cout<<"Hello from quant = 1"<<endl;
                       // cout<<"i+1 ="<<i+1<<"  "<<endl;
                        for( int j =0; j< numberofp ; j++)
                        {
                            if(Processes[j].arrivaltime == i+1 )
                            {
                                PrvectorSRT[actual_size3]= Processes[j].id;
                                actual_size3++;
                            }
                        }
                        if(flag)
                        {
                            // ProcessIDQueue.push(flagID);
                            PrvectorSRT[actual_size3]= flagIDD;
                            // Processes[flagIDD].pry--;
                            actual_size3++;
                            flag=0;

                        }
                        //\ED\CF\E6\D1 \DA\E1\ED \C7\E6\E1 maximum priority
                        int minSRT=minimumSRT(PrvectorSRT,Processes);
                        if(actual_size3)
                        {
                            //cout<<"BEFORE swap Prvector[maxi]= "<<Prvector[maxi]<<"AND  Prvector[0]= "<<Prvector[maxi-1]<<endl;
                            for(int z=minSRT; z>0; z--)
                            {
                                swap(PrvectorSRT[z],PrvectorSRT[z-1]);
                            }


                        }

                        //    i=ii;
                        i++;
                        //}




                    }
                    else
                    {
                        i=i+1;
                    }
                }

                for(int z=0; z<numberofp; z++)
                {
                    for(int x=0; x<last_inst; x++)
                    {
                        if(Processes[z].work[x]== -3)
                            Processes[z].wait++;
                        else if(Processes[z].work[x]== 1)
                            Processes[z].workk++;
                        // cout<< Processes[z].work[x]<<" ";
                    }
                    //  cout<<"\n";
                }


                for(int z=0; z<numberofp; z++)
                {
                    Processes[z].servicetime=Processes[z].workk;
                }

                print(Processes,numberofp,4,form,last_inst,quant);



            }
            if(type[i]=="5")
            {
                Processes=Vectorcpy;
                int ix;
                int idHRRN;
                vector<int> Prvector(numberofp);
                for( int j =0; j< numberofp ; j++)
                {
                    if(Processes[j].arrivaltime == 0 )
                    {
                        Prvector[actual_size]=Processes[j].id;
                        actual_size++;
                    }
                }
                maxi=0;
                for(int i=0; i < last_inst;)

                {
                    if(actual_size)
                    {
                        idHRRN = remove1stelementANDreturn(Prvector,Processes);
                        //cout<<idHRRN<<endl;

                        int tem=Processes[idHRRN].servicetime;
                        // cout<<"service time of"<<idHRRN<<" "<<Processes[idHRRN].servicetime<<endl;
                        ix=i;
                        while(tem)
                        {
                            Processes[idHRRN].work[ix]=1;
                            //cout<< "at process "<<idHRRN<<"at ix = "<<ix<<" : " <<Processes[idHRRN].work[ix]<<endl;
                            tem--;
                            ix++;
                        }
                        Processes[idHRRN].finishtime=ix;
                        if(ix > i+1)
                        {
                            //cout<<"entered ix if condition"<<endl;
                            for( int j =0; j<actual_size; j++)
                            {
                                int id3=Prvector[j];
                                Processes[id3].work[i]=-3;
                                //  cout<< "at process "<<id3<<"at xx = "<<i<<" : " <<Processes[id3].work[i]<<endl;


                            }

                            for(int xx=i+1; xx<= ix; xx++)
                            {
//  cout<< Prvector.size()<<endl;
                                for( int j =0; j< numberofp ; j++)
                                {

                                    if(Processes[j].arrivaltime == xx)
                                    {
                                        Prvector[actual_size]=Processes[j].id;
                                        actual_size++;
                                        //    cout<<"pushed";
                                    }
                                }

                                for( int j =0; j<actual_size; j++)
                                {
                                    int id3=Prvector[j];
                                    Processes[id3].work[xx]=-3;
                                  
                                }

                            }
                        }
                        else
                        {
                            for( int j =0; j<actual_size; j++)
                            {
                                int id3=Prvector[j];
                                Processes[id3].work[i]=-3;
                                //cout<< "at process "<<id3<<"at xx = "<<i <<" : " <<Processes[id3].work[i]<<endl;


                            }
                            for( int j =0; j< numberofp ; j++)
                            {

                                if(Processes[j].arrivaltime == i+1)
                                {
                                    Prvector[actual_size]=Processes[j].id;
                                    actual_size++;
                                }
                            }
                        }



//calculate HRRN & FIND max &pop & push in front
                        int HRRN;
                        for(int xx=0; xx< actual_size; xx++)
                        {
                            int ids=Prvector[xx];
                            int ww=0;
                            for(int zz=0; zz< ix; zz++)
                            {
                                if(Processes[ids].work[zz]== -3)
                                    ww=ww+1;
                                //  cout<<ww<<endl;
                            }
                            Processes[ids].HRRN=(ww+Processes[ids].servicetime)*1.0/Processes[ids].servicetime;
                            // cout<<"AT ID "<<ids<<"HRRN = "<<Processes[ids].HRRN<<endl;
                        }

                        int maxi=maximumHRRN(Prvector,Processes);
                        if(actual_size)
                        {
                            //cout<<"BEFORE swap Prvector[maxi]= "<<Prvector[maxi]<<"AND  Prvector[0]= "<<Prvector[maxi-1]<<endl;
                            for(int z=maxi; z>0; z--)
                            {
                                swap(Prvector[z],Prvector[z-1]);
                            }
                        }
                        i=ix;
                    }
                    else
                        i=i+1;
                }





                for(int z=0; z<numberofp; z++)
                {
                    for(int x=0; x<last_inst; x++)
                    {
                        if(Processes[z].work[x]== -3)
                            Processes[z].wait++;
                        else if(Processes[z].work[x]== 1)
                            Processes[z].workk++;

                    }

                }
                print(Processes,numberofp,5,form,last_inst,quant);
                Processes=Vectorcpy;

            }
            if(type[i]=="6" || type[i]=="7" )
            {
                //numberofp=5;
                int quanto;
                if(type[i]=="6")
                {
                    quanto=1;
                }
                else
                {
                    quanto=2;
                }
                Processes=Vectorcpy;
                for(int x=0; x<numberofp; x++)
                {
                    Processes[x].pry=numberofp+1;
                }
                vector<int> PrvectorFB(numberofp);
                for( int j =0; j< numberofp ; j++)
                {
                    if(Processes[j].arrivaltime == 0 )
                    {
                        PrvectorFB[actual_size2]=Processes[j].id;
                        actual_size2++;
                    }
                }
                int id ;
                int ii;
                for(int i=0; i < last_inst;)
                {
                    if(actual_size2)
                    {
                        int id = remove1stelementFBANDreturn(PrvectorFB,Processes);


                        // ProcessIDQueue.pop();
                        if(Processes[id].servicetime > quanto)
                        {
                            quantt = quanto,ii=i;
                            while(quantt)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                quantt --;
                                ii++;
                            }
                            // queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            quantt = quanto,ii=i;
                            while(quantt)
                            {
                                for( int j =0; j<actual_size2; j++)
                                {
                                    int id3=PrvectorFB[j];
                                    Processes[id3].work[ii]=-3;
                                }
                                quantt --;
                                ii++;
                            }

                            Processes[id].servicetime= Processes[id].servicetime - quanto;
                            flag=1;
                            flagIDD=id;
                        }
                        else if((Processes[id].servicetime <= quanto) && (Processes[id].servicetime !=0) )
                        {
                            st = Processes[id].servicetime,ii=i;
                            while(st)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                Processes[id].finishtime=ii+1;
                                st --;
                                ii++;
                            }
                            // queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            st = Processes[id].servicetime ;
                            ii=i;
                            while(st)
                            {

                              
                                for( int j =0; j<actual_size2; j++)
                                {
                                    int id3=PrvectorFB[j];
                                    Processes[id3].work[ii]=-3;
                                }

                                st --;
                                ii++;
                            }
                            Processes[id].servicetime= 0;

                            flag=0;

                        }
                        if(quanto==1)
                        {
                            // cout<<"Hello from quant = 1"<<endl;
                           // cout<<"i+1 ="<<i+1<<"  "<<endl;
                            for( int j =0; j< numberofp ; j++)
                            {
                                if(Processes[j].arrivaltime == i+1 )
                                {
                                    PrvectorFB[actual_size2]= Processes[j].id;
                                    actual_size2++;
                                }
                            }
                            //\ED\CF\E6\D1 \DA\E1\ED \C7\E6\E1 maximum priority
                            int maxiFB=maximumFB(PrvectorFB,Processes);
                            if(actual_size2)
                            {
                                //cout<<"BEFORE swap Prvector[maxi]= "<<Prvector[maxi]<<"AND  Prvector[0]= "<<Prvector[maxi-1]<<endl;
                                for(int z=maxiFB; z>0; z--)
                                {
                                    swap(PrvectorFB[z],PrvectorFB[z-1]);
                                }


                            }
                            if(flag)
                            {
                                // ProcessIDQueue.push(flagID);
                                PrvectorFB[actual_size2]= flagIDD;
                                Processes[flagIDD].pry--;
                                actual_size2++;
                                flag=0;

                            }
                            //    i=ii;
                            i++;
                        }


                        else if(quanto>1)
                        {

                            for(int q =i+1; q<=ii ; q++)
                            {
                                for( int j =0; j< numberofp ; j++)
                                {
                                    if(Processes[j].arrivaltime == q)
                                    {
                                        PrvectorFB[actual_size2]= Processes[j].id;
                                        actual_size2++;
                                        int qq=q;
                                        if(ii>i)
                                        {
                                            for(int x=i; x<ii; x++)
                                            {
                                                Processes[j].work[qq]=-3;
                                                qq++;
                                            }
                                        }
                                    }
                                }
                            }
                            if(flag)
                            {
                                // ProcessIDQueue.push(flagID);
                                PrvectorFB[actual_size2]= flagIDD;
                                Processes[flagIDD].pry--;
                                actual_size2++;
                                flag=0;

                            }
                            i=ii;
                        }

                    }
                    else
                    {
                        i=i+1;
                    }
                }

                for(int z=0; z<numberofp; z++)
                {
                    for(int x=0; x<last_inst; x++)
                    {
                        if(Processes[z].work[x]== -3)
                            Processes[z].wait++;
                        else if(Processes[z].work[x]== 1)
                            Processes[z].workk++;
                        // cout<< Processes[z].work[x]<<" ";
                    }
                    //  cout<<"\n";
                }


                for(int z=0; z<numberofp; z++)
                {
                    Processes[z].servicetime=Processes[z].workk;
                }

                if(type[i]=="6")
                {
                    print(Processes,numberofp,6,form,last_inst,1);
                }
                else
                {
                    print(Processes,numberofp,7,form,last_inst,2);
                }

            }

        }
        else
        {
            
            vector <string> round;
            stringstream check1(type[i]);

            string inter;

            while(getline(check1, inter, '-'))
            {
                round.push_back(inter);
            }
            string typo=round[0];
            //  string q=round[1];
            stringstream geek(round[1]);
            //int x = 0;
            geek >> quant;

            if(typo=="2")
            {
                Processes=Vectorcpy;
                for( int j =0; j< numberofp ; j++)
                {
                    if(Processes[j].arrivaltime == 0 )
                    {
                        ProcessIDQueue.push(Processes[j].id);
                    }
                }

                for(int i=0; i < last_inst;)
                {
                    if(!ProcessIDQueue.empty())
                    {
                        int id = ProcessIDQueue.front();
                        ProcessIDQueue.pop();
                        if(Processes[id].servicetime > quant)
                        {
                            quantt = quant,ii=i;
                            while(quantt)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                //cout<< "Process of "<< id<<"at "<< ii << " work = "<< Processes[id].work[ii]<< endl;
                                quantt --;
                                ii++;
                            }
                            queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            quantt = quant,ii=i;
                            while(quantt)
                            {
                                int s= ProcessIDQueueCopy.size();
                                for(int x=0; x<s; x++)
                                {
                                    int id2 =ProcessIDQueueCopy.front();
                                    ProcessIDQueueCopy.pop();
                                    Processes[id2].work[ii]=-3;
                                    //  cout<< "Process of "<< id2<<"at "<< ii << " work = "<< Processes[id2].work[ii]<< endl;
                                    ProcessIDQueueCopy.push(id2);
                                }
                                quantt --;
                                ii++;
                            }
                            Processes[id].servicetime= Processes[id].servicetime - quant;
                            //  ProcessIDQueue.pop();
                            //snew=ii;
                            /*////////////*/  flag=1;
                            flagID=id;
                        }
                        else if((Processes[id].servicetime <= quant) && (Processes[id].servicetime !=0) )
                        {
                            st = Processes[id].servicetime,ii=i;
                            while(st)
                            {
                                //work[ii]=1;
                                Processes[id].work[ii]=1;
                                //  cout<< "!!Process of "<< id<<"at "<< ii << " work = "<< Processes[id].work[ii]<< endl;
                                Processes[id].finishtime=ii+1;
                                st --;
                                ii++;
                            }
                            queue <int> ProcessIDQueueCopy = ProcessIDQueue;
                            st = Processes[id].servicetime ;
                            ii=i;
                            while(st)
                            {

                                int si=ProcessIDQueueCopy.size();
                                for(int x=0; x<si; x++)
                                {
                                    int id2 =ProcessIDQueueCopy.front();
                                    ProcessIDQueueCopy.pop();
                                    Processes[id2].work[ii]=-3;
                                    //  cout<< "!!Process of "<< id2<<"at "<< ii << " work = "<< Processes[id2].work[ii]<< endl;
                                    ProcessIDQueueCopy.push(id2);

                                }
                                st --;
                                ii++;
                            }
                            Processes[id].servicetime= 0;

                            flag=0;

                        }
                        if(quant==1)
                        {
                            for( int j =0; j< numberofp ; j++)
                            {
                                if(Processes[j].arrivaltime == i+1 )
                                {
                                    ProcessIDQueue.push(Processes[j].id);
                                    //cout<<"*"<<i+1<<"*";cout<<Processes[j].id<<" pushed";

                                }
                            }
                            if(flag)
                            {
                                ProcessIDQueue.push(flagID);
                                flag=0;
                            }
                            //    i=ii;
                            i++;
                        }


                        else if(quant>1)
                        {

                            for(int q =i+1; q<=ii ; q++)
                            {
                                for( int j =0; j< numberofp ; j++)
                                {
                                    if(Processes[j].arrivaltime == q)
                                    {
                                        ProcessIDQueue.push(Processes[j].id);
                                        int qq=q;
                                        if(ii>i)
                                        {
                                            for(int x=i; x<ii; x++)
                                            {
                                                Processes[j].work[qq]=-3;
                                                qq++;
                                            }
                                        }
                                    }
                                }
                            }
                            if(flag)
                            {
                                ProcessIDQueue.push(flagID);
                                flag=0;
                            }
                            i=ii;
                        }

                    }
                    else
                    {
                        i=i+1;
                    }
                }

                for(int z=0; z<numberofp; z++)
                {
                    for(int x=0; x<last_inst; x++)
                    {
                        if(Processes[z].work[x]== -3)
                            Processes[z].wait++;
                        else if(Processes[z].work[x]== 1)
                            Processes[z].workk++;
                        // cout<< Processes[z].work[x]<<" ";
                    }
                    //  cout<<"\n";
                }


                for(int z=0; z<numberofp; z++)
                {
                    Processes[z].servicetime=Processes[z].workk;
                }

                print(Processes,numberofp,2,form,last_inst,quant);


            }





        }

    }

    return 0;
}
