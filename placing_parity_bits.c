char* addParity(int bitsq_length, char* bitsq){
    
    char static pariadded_array[1000000]={}; //assigning null to all positions of the array
    int no_of_parities,pos,position,count = 0;
    
    while(bitsq_length > (int)pow(2,pos)-(pos+1)) { no_of_parities++;  pos++; }  // checking the number of parity positions using the ineqality

    int parityPos = 0; int nonarityPos =0;
    for(int i=0;i < no_of_parities + bitsq_length; i++)
    {
        if(i==((int)pow(2,parityPos)-1))
        {   pariadded_array[i] = '0';  // assigning zeros to the indexes of powers of two
            parityPos++; }
        else
        {   pariadded_array[i]=bitsq[nonarityPos];
            nonarityPos++;   }
    }
    
// checking even parity and assigning the relevent bit to the indexes of powers of two
    for(int i=0;i<no_of_parities;i++) {
    position = (int)pow(2,i);
    int s,count = 0;
    s = position-1;
    while(s < no_of_parities + bitsq_length)
    {
        for(int j = s; j < s+position; j++)
        {     if(pariadded_array[j] == '1')
                {count++; }
        }
        s = s + 2*position;    
    }
        
    if(count%2 == 0)
        pariadded_array[position-1] = '0';
    else
        pariadded_array[position-1] = '1'; 
    }
    return pariadded_array;
}
