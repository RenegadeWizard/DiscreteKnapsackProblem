//
//  BackPack.cpp
//  DiscreteKnapsackProblem
//
//  Created by Krzysztof Sychla on 02.06.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "BackPack.hpp"
#include <iostream>
#include <list>

BackPack::BackPack(int wielkosc,int ile,int *wartosc,int *waga) {
    C = wielkosc;
    n = ile;
    p = new int [n];
    w = new int [n];
    
    for (int i = 0;i < n;i++)
        p[i] = wartosc[i];
    
    for (int i = 0;i < n;i++)
        w[i] = waga[i];
    
}

BackPack::~BackPack() {
    delete [] w;
    delete [] p;
}

/*
 Printing results on screen
*/
void BackPack::PrintElem() {
    std::cout<<"Weight: ";
    for (int i=0;i<n;i++)
        std::cout<<w[i]<<" ";
    std::cout<<"\nPrice: ";
    for (int i=0;i<n;i++)
        std::cout<<p[i]<<" ";
    std::cout<<"\n";
}

/*
 Brute-force way of solving the Knapsack problem
*/
void BackPack::BruteForce() {
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
}

/*
 Solving the Knapsack problem with dynammic programming
*/
void BackPack::DynamicProgramming() {
    int ** workfield = new int*[n + 1];
    std::list<int> sol;
    for (int i = 0; i < n + 1; i++) {
        workfield[i] = new int[C + 1];
    }
    for (int i = 0; i < C + 1; i++)
        workfield[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        workfield[i][0] = 0;
    
    
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < C + 1; j++) {
            if (j < w[i - 1]) { // if the elements does not fit
                workfield[i][j] = workfield[i - 1][j];
            }
            else { // if it fits
                int a = workfield[i-1][j];
                int b = workfield[i-1][j - w[i - 1]] + p[i - 1];
                workfield[i][j] = a > b ? a : b;
            }
        }
    }
    
    int i = n;
    int j = C;
    while (j>0 && i>0) {
        if (workfield[i-1][j] != workfield[i][j]) {
            // Chosen one
            
            sol.push_back(i);
            
            // Update
            i--;
            j -= w[i];
        }
        else {
            i--;
        }
    }
    delete [] workfield;
}
