//
//  main.cpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 17.05.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include "BackPack.hpp"
#include <fstream>
#include "Timer.hpp"

int main(int argc, const char * argv[]) {
    int C;
    int n;
    
    std::fstream dane1;
    std::fstream dane2;
    std::fstream wynik1;
    std::fstream wynik2;
    dane1.open("dane_1.txt",std::ios_base::in);
    dane2.open("dane_2.txt",std::ios_base::in);
    wynik1.open("wynik_1.txt",std::ios_base::app);
    wynik2.open("wynik_2.txt",std::ios_base::app);
    
    Timer time;
    
//    int ile = sizeof(ilosc1);
    
    while(!dane1.eof()){
        dane1 >> C;
        dane1 >> n;
        int *weight = new int[n];
        int *price = new int [n];
        for (int j=0;j<n;j++){
            dane1 >> weight[j];
            dane1 >> price[j];
        }
        BackPack *plecak = new BackPack(C,n,price,weight);
        std::cout<<"Executing n: "<<n;
        time.StartTimer();
        plecak->BruteForce();
        time.EndTimer();
        wynik1<<time.GetDelta()<<"\t";
        time.StartTimer();
        plecak->DynamicProgramming();
        time.EndTimer();
        wynik1<<time.GetDelta()<<"\n";
        std::cout<<" DONE"<<"\n";
        delete [] weight;
        delete [] price;
        delete plecak;
    }
    while(!dane2.eof()){
        dane2 >> C;
        dane2 >> n;
        int *weight = new int[n];
        int *price = new int [n];
        for (int j=0;j<n;j++){
            dane2 >> weight[j];
            dane2 >> price[j];
        }
        BackPack *plecak = new BackPack(C,n,price,weight);
        std::cout<<"Executing C: "<<C;
        time.StartTimer();
        plecak->BruteForce();
        time.EndTimer();
        wynik2<<time.GetDelta()<<"\t";
        time.StartTimer();
        plecak->DynamicProgramming();
        time.EndTimer();
        wynik2<<time.GetDelta()<<"\n";
        std::cout<<" DONE"<<"\n";
        delete [] weight;
        delete [] price;
        delete plecak;
    }
    
    return 0;
}
