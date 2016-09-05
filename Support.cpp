//
//  Support.cpp
//  Shade
//
//  Created by prog on 4/27/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

int findMin(int cnt, double dists[]) {
    
    double min = dists[0];
    int index = 0;
    
    for (int i = 0; i < cnt; i++) {
        
        if (min > dists[i]) {
            
            min = dists[i];
            index = i;
        }
        
    }
    
    return index;
}

double findDoubleMin (int cnt, double dists[]) {
    
    double min = dists[0];
    
    for (int i = 0; i < cnt; i++) {
        
        if (min > dists[i]) {
            
            min = dists[i];
        }
        
    }
    
    return min;

}


double findDoubleMax(int cnt, double dists[]) {
    
    double max = dists[0];
    
    for (int i = 0; i < cnt; i++) {
        
        if (max < dists[i]) {
            
            max = dists[i];
        }
        
    }
    
    return max;
    
}


int findSecondMin(int cnt, double dists[]) {
    
    double max = findDoubleMax(cnt, dists);
    double min = findDoubleMin(cnt, dists);
    double secondMin = max;
    int index = 0;
    
    for (int i = 0; i < cnt; i++) {
        
        if ((secondMin > dists[i]) &&
            (dists[i] != min)){
            
            secondMin = dists[i];
            index = i;
            
        }
        
    }
    
    return index;

}




