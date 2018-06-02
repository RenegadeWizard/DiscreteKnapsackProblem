//
//  BackPack.cpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 02.06.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "BackPack.hpp"
#include <iostream>

BackPack::BackPack(int wielkosc,int ile,int *wartosc,int *waga){
    C = wielkosc;
    n = ile;
    p = new int [n];
    w = new int [n];
    
    for (int i = 0;i < n;i++)
        p[i] = wartosc[i];
    
    for (int i = 0;i < n;i++)
        w[i] = waga[i];
    
}

BackPack::~BackPack(){
    
}

void BackPack::PrintElem(){
    std::cout<<"Weight: ";
    for (int i=0;i<n;i++)
        std::cout<<w[i]<<" ";
    std::cout<<"\nPrice: ";
    for (int i=0;i<n;i++)
        std::cout<<p[i]<<" ";
    std::cout<<"\n";
}

void BackPack::BruteForce(){
    int MaxPrice, CurrentPrice;
    int CurrentWeight;
    int CurrentMask, MaxMask;
    int temp;
    
    MaxPrice = MaxMask = 0;
    
    for (int i=0;i<(1<<n);i++){
        CurrentPrice = CurrentWeight = 0;
        CurrentMask = i;
        temp = 0;
        while(CurrentMask){
            if(CurrentMask & 1){
                CurrentPrice += p[temp];
                CurrentWeight += w[temp];
            }
            CurrentMask >>= 1;
            temp += 1;
        }
        if(CurrentWeight <= C && CurrentPrice > MaxPrice){
            MaxPrice = CurrentPrice;
            MaxMask = i;
        }
    }
    
    //Printing outcome
    
    std::cout<<"Wynik: ";
    int which = 1;
    while(MaxMask){
        if(MaxMask&1)
            std::cout<<which<<" ";
        which++;
        MaxMask >>= 1;
    }
    std::cout<<"\n";
    
    
}

void BackPack::DynamicProgramming(){
    return;
}
