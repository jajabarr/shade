//
//  Support.cpp
//  Shade
//
//  Created by prog on 4/27/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
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
